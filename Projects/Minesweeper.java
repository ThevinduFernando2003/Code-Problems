import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.ArrayList;
import java.util.Random;
import javax.swing.*;
import javax.swing.border.BevelBorder;
import javax.swing.border.EmptyBorder;

public class Minesweeper {

    enum Difficulty {
        BEGINNER("Beginner", 9, 9, 10, 35),
        INTERMEDIATE("Intermediate", 16, 16, 40, 30),
        EXPERT("Expert", 30, 16, 99, 25);

        final String label;
        final int rows;
        final int cols;
        final int mines;
        final int tileSize;

        Difficulty(String label, int cols, int rows, int mines, int tileSize) {
            this.label = label;
            this.cols = cols;
            this.rows = rows;
            this.mines = mines;
            this.tileSize = tileSize;
        }
    }

    private class MineTile extends JButton {
        final int r;
        final int c;
        boolean flagged;
        boolean revealed;

        MineTile(int r, int c) {
            this.r = r;
            this.c = c;
            setFocusable(false);
            setMargin(new Insets(0, 0, 0, 0));
            setBorder(new BevelBorder(BevelBorder.RAISED));
            setBackground(UNREVEALED_COLOR);
            setOpaque(true);
        }

        void reset() {
            flagged = false;
            revealed = false;
            setEnabled(true);
            setText("");
            setBackground(UNREVEALED_COLOR);
            setForeground(Color.BLACK);
            setFont(new Font("Segoe UI", Font.BOLD, difficulty.tileSize / 2));
        }
    }

    private static final Color UNREVEALED_COLOR = new Color(189, 189, 189);
    private static final Color REVEALED_COLOR = new Color(220, 220, 220);
    private static final Color[] NUMBER_COLORS = {
        new Color(0, 0, 255),
        new Color(0, 128, 0),
        new Color(255, 0, 0),
        new Color(0, 0, 128),
        new Color(128, 0, 0),
        new Color(0, 128, 128),
        new Color(0, 0, 0),
        new Color(128, 128, 128)
    };

    private Difficulty difficulty;
    private int numRows;
    private int numCols;
    private int mineCount;
    private int tileSize;

    private JFrame frame;
    private JLabel statusLabel;
    private JLabel timerLabel;
    private JLabel minesLabel;
    private JLabel difficultyLabel;
    private JButton faceButton;
    private JPanel boardPanel;

    private MineTile[][] board;
    private ArrayList<MineTile> mineList;
    private final Random random = new Random();

    private boolean gameOver;
    private boolean firstClick = true;
    private int tilesRevealed;
    private int flagsPlaced;
    private int elapsedSeconds;
    private Timer gameTimer;

    Minesweeper() {
        difficulty = showDifficultyDialog();
        if (difficulty == null) {
            System.exit(0);
            return;
        }
        applyDifficulty(difficulty);
        buildUi();
        newGame();
    }

    private Difficulty showDifficultyDialog() {
        String[] options = {
            Difficulty.BEGINNER.label + " (9×9, 10 mines)",
            Difficulty.INTERMEDIATE.label + " (16×16, 40 mines)",
            Difficulty.EXPERT.label + " (30×16, 99 mines)"
        };

        int choice = JOptionPane.showOptionDialog(
            null,
            "Select a difficulty level:",
            "Minesweeper — Choose Difficulty",
            JOptionPane.DEFAULT_OPTION,
            JOptionPane.QUESTION_MESSAGE,
            null,
            options,
            options[0]
        );

        return switch (choice) {
            case 0 -> Difficulty.BEGINNER;
            case 1 -> Difficulty.INTERMEDIATE;
            case 2 -> Difficulty.EXPERT;
            default -> null;
        };
    }

    private void applyDifficulty(Difficulty d) {
        difficulty = d;
        numRows = d.rows;
        numCols = d.cols;
        mineCount = d.mines;
        tileSize = d.tileSize;
    }

    private void buildUi() {
        frame = new JFrame("Minesweeper");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new BorderLayout(0, 8));
        frame.getContentPane().setBackground(new Color(192, 192, 192));
        ((JComponent) frame.getContentPane()).setBorder(new EmptyBorder(8, 8, 8, 8));

        JPanel topPanel = createTopPanel();
        frame.add(topPanel, BorderLayout.NORTH);

        boardPanel = new JPanel(new GridLayout(numRows, numCols, 1, 1));
        boardPanel.setBackground(Color.DARK_GRAY);
        frame.add(boardPanel, BorderLayout.CENTER);

        JPanel bottomPanel = new JPanel(new FlowLayout(FlowLayout.CENTER, 16, 4));
        bottomPanel.setOpaque(false);
        difficultyLabel = new JLabel("Difficulty: " + difficulty.label);
        difficultyLabel.setFont(new Font("Segoe UI", Font.PLAIN, 13));
        bottomPanel.add(difficultyLabel);
        frame.add(bottomPanel, BorderLayout.SOUTH);

        resizeFrame();
        frame.setLocationRelativeTo(null);
        frame.setResizable(false);
        frame.setVisible(true);
    }

    private JPanel createTopPanel() {
        JPanel panel = new JPanel(new BorderLayout(12, 0));
        panel.setBackground(new Color(192, 192, 192));
        panel.setBorder(new EmptyBorder(4, 4, 8, 4));

        minesLabel = new JLabel(formatMines(mineCount), SwingConstants.CENTER);
        minesLabel.setFont(counterFont());
        minesLabel.setForeground(Color.RED);
        minesLabel.setBackground(Color.BLACK);
        minesLabel.setOpaque(true);
        minesLabel.setPreferredSize(new Dimension(72, 40));
        minesLabel.setBorder(BorderFactory.createLoweredBevelBorder());

        faceButton = new JButton("🙂");
        faceButton.setFont(new Font("Segoe UI Emoji", Font.PLAIN, 28));
        faceButton.setFocusable(false);
        faceButton.setPreferredSize(new Dimension(52, 52));
        faceButton.addActionListener(e -> newGame());

        timerLabel = new JLabel("000", SwingConstants.CENTER);
        timerLabel.setFont(counterFont());
        timerLabel.setForeground(Color.RED);
        timerLabel.setBackground(Color.BLACK);
        timerLabel.setOpaque(true);
        timerLabel.setPreferredSize(new Dimension(72, 40));
        timerLabel.setBorder(BorderFactory.createLoweredBevelBorder());

        statusLabel = new JLabel("Click a tile to begin", SwingConstants.CENTER);
        statusLabel.setFont(new Font("Segoe UI", Font.BOLD, 14));

        JPanel counters = new JPanel(new GridLayout(1, 3, 16, 0));
        counters.setOpaque(false);
        counters.add(minesLabel);
        counters.add(faceButton);
        counters.add(timerLabel);

        panel.add(counters, BorderLayout.CENTER);
        panel.add(statusLabel, BorderLayout.SOUTH);
        return panel;
    }

    private String formatMines(int count) {
        return String.format("%03d", Math.max(0, count));
    }

    private String formatTime(int seconds) {
        return String.format("%03d", Math.min(999, seconds));
    }

    private void resizeFrame() {
        int width = numCols * tileSize + 32;
        int height = numRows * tileSize + 160;
        frame.setSize(width, height);
    }

    private void newGame() {
        stopTimer();
        gameOver = false;
        firstClick = true;
        tilesRevealed = 0;
        flagsPlaced = 0;
        elapsedSeconds = 0;

        timerLabel.setText("000");
        minesLabel.setText(formatMines(mineCount));
        statusLabel.setText("Click a tile to begin");
        faceButton.setText("🙂");
        difficultyLabel.setText("Difficulty: " + difficulty.label);

        boardPanel.removeAll();
        board = new MineTile[numRows][numCols];
        mineList = new ArrayList<>();

        for (int r = 0; r < numRows; r++) {
            for (int c = 0; c < numCols; c++) {
                MineTile tile = new MineTile(r, c);
                board[r][c] = tile;
                tile.addMouseListener(createTileListener());
                boardPanel.add(tile);
            }
        }

        boardPanel.revalidate();
        boardPanel.repaint();
    }

    private MouseAdapter createTileListener() {
        return new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                if (gameOver) {
                    return;
                }

                MineTile tile = (MineTile) e.getSource();

                if (e.getButton() == MouseEvent.BUTTON1) {
                    handleLeftClick(tile);
                } else if (e.getButton() == MouseEvent.BUTTON3) {
                    handleRightClick(tile);
                }
            }
        };
    }

    private void handleLeftClick(MineTile tile) {
        if (tile.flagged || tile.revealed) {
            return;
        }

        if (firstClick) {
            placeMinesAvoiding(tile);
            firstClick = false;
            startTimer();
            statusLabel.setText("Good luck!");
        }

        if (mineList.contains(tile)) {
            revealAllMines(tile);
            endGame(false);
            return;
        }

        revealTile(tile);

        if (tilesRevealed == numRows * numCols - mineCount) {
            endGame(true);
        }
    }

    private void handleRightClick(MineTile tile) {
        if (tile.revealed || gameOver) {
            return;
        }

        if (!tile.flagged && flagsPlaced < mineCount) {
            tile.flagged = true;
            tile.setText("🚩");
            flagsPlaced++;
        } else if (tile.flagged) {
            tile.flagged = false;
            tile.setText("");
            flagsPlaced--;
        }

        minesLabel.setText(formatMines(mineCount - flagsPlaced));
    }

    private Font counterFont() {
        Font digital = new Font("Digital-7", Font.BOLD, 28);
        if (digital.getFamily().equals("Digital-7")) {
            return digital;
        }
        return new Font("Consolas", Font.BOLD, 28);
    }

    private void placeMinesAvoiding(MineTile safeTile) {
        mineList.clear();
        ArrayList<MineTile> candidates = new ArrayList<>();

        for (int r = 0; r < numRows; r++) {
            for (int c = 0; c < numCols; c++) {
                MineTile tile = board[r][c];
                if (tile != safeTile && !isNeighbor(tile, safeTile)) {
                    candidates.add(tile);
                }
            }
        }

        for (int i = candidates.size() - 1; i > 0; i--) {
            int j = random.nextInt(i + 1);
            MineTile temp = candidates.get(i);
            candidates.set(i, candidates.get(j));
            candidates.set(j, temp);
        }

        int minesToPlace = Math.min(mineCount, candidates.size());
        for (int i = 0; i < minesToPlace; i++) {
            mineList.add(candidates.get(i));
        }
    }

    private boolean isNeighbor(MineTile a, MineTile b) {
        return Math.abs(a.r - b.r) <= 1 && Math.abs(a.c - b.c) <= 1;
    }

    private void revealTile(MineTile tile) {
        if (tile.revealed || tile.flagged) {
            return;
        }

        tile.revealed = true;
        tile.setEnabled(false);
        tile.setBackground(REVEALED_COLOR);
        tile.setBorder(new BevelBorder(BevelBorder.LOWERED));
        tilesRevealed++;

        int adjacentMines = countAdjacentMines(tile.r, tile.c);

        if (adjacentMines > 0) {
            tile.setText(String.valueOf(adjacentMines));
            tile.setForeground(NUMBER_COLORS[adjacentMines - 1]);
        } else {
            floodReveal(tile.r, tile.c);
        }
    }

    private void floodReveal(int r, int c) {
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (dr == 0 && dc == 0) {
                    continue;
                }
                int nr = r + dr;
                int nc = c + dc;
                if (nr >= 0 && nr < numRows && nc >= 0 && nc < numCols) {
                    revealTile(board[nr][nc]);
                }
            }
        }
    }

    private int countAdjacentMines(int r, int c) {
        int count = 0;
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (dr == 0 && dc == 0) {
                    continue;
                }
                int nr = r + dr;
                int nc = c + dc;
                if (nr >= 0 && nr < numRows && nc >= 0 && nc < numCols
                        && mineList.contains(board[nr][nc])) {
                    count++;
                }
            }
        }
        return count;
    }

    private void revealAllMines(MineTile hitTile) {
        for (MineTile mine : mineList) {
            mine.setEnabled(false);
            mine.setBackground(REVEALED_COLOR);
            mine.setBorder(new BevelBorder(BevelBorder.LOWERED));
            if (mine == hitTile) {
                mine.setText("💥");
            } else {
                mine.setText("💣");
            }
        }
    }

    private void startTimer() {
        gameTimer = new Timer(1000, e -> {
            elapsedSeconds++;
            timerLabel.setText(formatTime(elapsedSeconds));
        });
        gameTimer.start();
    }

    private void stopTimer() {
        if (gameTimer != null) {
            gameTimer.stop();
            gameTimer = null;
        }
    }

    private void endGame(boolean won) {
        gameOver = true;
        stopTimer();

        if (won) {
            faceButton.setText("😎");
            statusLabel.setText("You cleared all mines!");
            flagAllMines();
            showResultPopup(
                "Victory!",
                "Congratulations! You cleared the board in " + elapsedSeconds + " seconds.",
                JOptionPane.INFORMATION_MESSAGE
            );
        } else {
            faceButton.setText("😵");
            statusLabel.setText("Game Over — you hit a mine!");
            showResultPopup(
                "Game Over",
                "You hit a mine! Time: " + elapsedSeconds + "s\nTry again?",
                JOptionPane.ERROR_MESSAGE
            );
        }
    }

    private void flagAllMines() {
        for (MineTile mine : mineList) {
            if (!mine.flagged) {
                mine.setText("🚩");
                mine.flagged = true;
            }
        }
        minesLabel.setText(formatMines(0));
    }

    private void showResultPopup(String title, String message, int messageType) {
        String[] options = {"Play Again", "Change Difficulty", "Quit"};
        int choice = JOptionPane.showOptionDialog(
            frame,
            message,
            title,
            JOptionPane.DEFAULT_OPTION,
            messageType,
            null,
            options,
            options[0]
        );

        switch (choice) {
            case 0 -> newGame();
            case 1 -> {
                Difficulty selected = showDifficultyDialog();
                if (selected == null) {
                    frame.dispose();
                    System.exit(0);
                    return;
                }
                applyDifficulty(selected);
                frame.dispose();
                buildUi();
                newGame();
            }
            default -> {
                frame.dispose();
                System.exit(0);
            }
        }
    }
}
