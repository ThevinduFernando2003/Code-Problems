import java.awt.BasicStroke;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.GradientPaint;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.RenderingHints;
import java.awt.event.ActionEvent;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;
import javax.swing.AbstractAction;
import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingConstants;
import javax.swing.Timer;

public class SnakeGame {
    private static final int CELL_SIZE = 24;
    private static final int COLS = 30;
    private static final int ROWS = 24;
    private static final int GAME_WIDTH = COLS * CELL_SIZE;
    private static final int GAME_HEIGHT = ROWS * CELL_SIZE;
    private static final int NORMAL_FOOD_POINTS = 10;
    private static final int BONUS_FOOD_POINTS = 100;
    private static final int BONUS_AFTER_NORMAL_FOODS = 5;
    private static final int BONUS_DURATION_SECONDS = 5;
    private static final int TICK_DELAY_MS = 105;

    private final JFrame frame;
    private final GameBoard board;
    private final JLabel scoreLabel;
    private final JLabel eatenLabel;
    private final JLabel bonusLabel;
    private final JLabel statusLabel;

    public SnakeGame() {
        frame = new JFrame("Snake Game - Level 1");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(false);
        frame.setLayout(new BorderLayout(0, 0));

        scoreLabel = createInfoLabel("Score: 0");
        eatenLabel = createInfoLabel("Balls: 0");
        bonusLabel = createInfoLabel("Bonus: --");
        statusLabel = createInfoLabel("Arrow keys to move | Space to pause | R to restart");

        JPanel topBar = new JPanel(new BorderLayout(12, 0));
        topBar.setBackground(new Color(20, 24, 35));
        topBar.setBorder(BorderFactory.createEmptyBorder(12, 14, 12, 14));
        topBar.add(scoreLabel, BorderLayout.WEST);
        topBar.add(eatenLabel, BorderLayout.CENTER);
        topBar.add(bonusLabel, BorderLayout.EAST);

        JPanel bottomBar = new JPanel(new BorderLayout());
        bottomBar.setBackground(new Color(20, 24, 35));
        bottomBar.setBorder(BorderFactory.createEmptyBorder(8, 14, 12, 14));
        bottomBar.add(statusLabel, BorderLayout.CENTER);

        JButton restartButton = new JButton(new AbstractAction("Restart") {
            @Override
            public void actionPerformed(ActionEvent e) {
                board.restart();
            }
        });
        restartButton.setFocusable(false);
        bottomBar.add(restartButton, BorderLayout.EAST);

        board = new GameBoard();
        frame.add(topBar, BorderLayout.NORTH);
        frame.add(board, BorderLayout.CENTER);
        frame.add(bottomBar, BorderLayout.SOUTH);
        frame.pack();
        frame.setLocationRelativeTo(null);
    }

    public void showGame() {
        frame.setVisible(true);
        board.requestFocusInWindow();
    }

    private JLabel createInfoLabel(String text) {
        JLabel label = new JLabel(text, SwingConstants.CENTER);
        label.setForeground(new Color(235, 241, 255));
        label.setFont(new Font("Segoe UI", Font.BOLD, 16));
        return label;
    }

    private enum Direction {
        UP(0, -1),
        DOWN(0, 1),
        LEFT(-1, 0),
        RIGHT(1, 0);

        final int dx;
        final int dy;

        Direction(int dx, int dy) {
            this.dx = dx;
            this.dy = dy;
        }

        boolean isOpposite(Direction other) {
            return dx + other.dx == 0 && dy + other.dy == 0;
        }
    }

    private class GameBoard extends JPanel {
        private final Random random = new Random();
        private final LinkedList<Point> snake = new LinkedList<>();
        private final List<Point> bonusFood = new ArrayList<>();
        private final Timer gameTimer;

        private Direction direction = Direction.RIGHT;
        private Direction nextDirection = Direction.RIGHT;
        private Point normalFood;
        private int score;
        private int normalFoodEaten;
        private int normalFoodsSinceBonus;
        private long bonusEndsAtMs;
        private boolean paused;
        private boolean gameOver;

        GameBoard() {
            setPreferredSize(new Dimension(GAME_WIDTH, GAME_HEIGHT));
            setBackground(new Color(13, 17, 27));
            setFocusable(true);
            setDoubleBuffered(true);
            addKeyListener(new MovementHandler());

            gameTimer = new Timer(TICK_DELAY_MS, e -> tick());
            restart();
        }

        void restart() {
            snake.clear();
            bonusFood.clear();
            direction = Direction.RIGHT;
            nextDirection = Direction.RIGHT;
            score = 0;
            normalFoodEaten = 0;
            normalFoodsSinceBonus = 0;
            bonusEndsAtMs = 0;
            paused = false;
            gameOver = false;

            int startX = COLS / 2;
            int startY = ROWS / 2;
            snake.add(new Point(startX, startY));
            snake.add(new Point(startX - 1, startY));
            snake.add(new Point(startX - 2, startY));

            normalFood = randomFreeCell();
            updateLabels();
            statusLabel.setText("Level 1: eat balls, avoid yourself, wrap through the walls");
            gameTimer.start();
            requestFocusInWindow();
            repaint();
        }

        private void tick() {
            if (paused || gameOver) {
                return;
            }

            if (isBonusExpired()) {
                bonusFood.clear();
                bonusEndsAtMs = 0;
            }

            direction = nextDirection;
            Point head = snake.getFirst();
            Point next = wrappedPoint(head.x + direction.dx, head.y + direction.dy);
            boolean eatsNormalFood = next.equals(normalFood);
            boolean eatsBonusFood = containsPoint(bonusFood, next);
            Point tail = snake.getLast();

            if (hitsOwnBody(next, tail, eatsNormalFood || eatsBonusFood)) {
                endGame();
                return;
            }

            snake.addFirst(next);

            if (eatsNormalFood) {
                score += NORMAL_FOOD_POINTS;
                normalFoodEaten++;
                normalFoodsSinceBonus++;
                normalFood = randomFreeCell();

                if (normalFoodsSinceBonus >= BONUS_AFTER_NORMAL_FOODS) {
                    normalFoodsSinceBonus = 0;
                    spawnBonusFood();
                }
            } else if (eatsBonusFood) {
                score += BONUS_FOOD_POINTS;
                bonusFood.clear();
                bonusEndsAtMs = 0;
            } else {
                snake.removeLast();
            }

            updateLabels();
            repaint();
        }

        private Point wrappedPoint(int x, int y) {
            int wrappedX = (x + COLS) % COLS;
            int wrappedY = (y + ROWS) % ROWS;
            return new Point(wrappedX, wrappedY);
        }

        private boolean hitsOwnBody(Point next, Point tail, boolean willGrow) {
            for (Point bodyPart : snake) {
                if (bodyPart.equals(tail) && !willGrow) {
                    continue;
                }
                if (bodyPart.equals(next)) {
                    return true;
                }
            }
            return false;
        }

        private void spawnBonusFood() {
            List<Point> possibleTopLeftCells = new ArrayList<>();

            for (int y = 0; y < ROWS - 1; y++) {
                for (int x = 0; x < COLS - 1; x++) {
                    List<Point> candidate = bonusCellsFor(x, y);
                    if (isAreaFree(candidate)) {
                        possibleTopLeftCells.add(new Point(x, y));
                    }
                }
            }

            if (possibleTopLeftCells.isEmpty()) {
                bonusFood.clear();
                bonusEndsAtMs = 0;
                return;
            }

            Point selected = possibleTopLeftCells.get(random.nextInt(possibleTopLeftCells.size()));
            bonusFood.clear();
            bonusFood.addAll(bonusCellsFor(selected.x, selected.y));
            bonusEndsAtMs = System.currentTimeMillis() + BONUS_DURATION_SECONDS * 1000L;
        }

        private List<Point> bonusCellsFor(int x, int y) {
            List<Point> cells = new ArrayList<>();
            cells.add(new Point(x, y));
            cells.add(new Point(x + 1, y));
            cells.add(new Point(x, y + 1));
            cells.add(new Point(x + 1, y + 1));
            return cells;
        }

        private boolean isAreaFree(List<Point> cells) {
            for (Point cell : cells) {
                if (containsPoint(snake, cell) || cell.equals(normalFood)) {
                    return false;
                }
            }
            return true;
        }

        private Point randomFreeCell() {
            List<Point> freeCells = new ArrayList<>();

            for (int y = 0; y < ROWS; y++) {
                for (int x = 0; x < COLS; x++) {
                    Point cell = new Point(x, y);
                    if (!containsPoint(snake, cell) && !containsPoint(bonusFood, cell)) {
                        freeCells.add(cell);
                    }
                }
            }

            if (freeCells.isEmpty()) {
                endGame();
                return new Point(0, 0);
            }

            return freeCells.get(random.nextInt(freeCells.size()));
        }

        private boolean containsPoint(List<Point> points, Point target) {
            for (Point point : points) {
                if (point.equals(target)) {
                    return true;
                }
            }
            return false;
        }

        private boolean isBonusExpired() {
            return !bonusFood.isEmpty() && System.currentTimeMillis() >= bonusEndsAtMs;
        }

        private int bonusSecondsLeft() {
            if (bonusFood.isEmpty()) {
                return 0;
            }
            long remainingMs = Math.max(0, bonusEndsAtMs - System.currentTimeMillis());
            return (int) Math.ceil(remainingMs / 1000.0);
        }

        private void updateLabels() {
            scoreLabel.setText("Score: " + score);
            eatenLabel.setText("Balls: " + normalFoodEaten + " | Length: " + snake.size());

            if (bonusFood.isEmpty()) {
                int left = BONUS_AFTER_NORMAL_FOODS - normalFoodsSinceBonus;
                bonusLabel.setText("Bonus in: " + left);
            } else {
                bonusLabel.setText("Big ball: " + bonusSecondsLeft() + "s");
            }
        }

        private void togglePause() {
            if (gameOver) {
                return;
            }

            paused = !paused;
            statusLabel.setText(paused ? "Paused" : "Level 1 running");
            repaint();
        }

        private void endGame() {
            gameOver = true;
            gameTimer.stop();
            statusLabel.setText("Game over! Press R or click Restart to play again.");
            repaint();
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            Graphics2D g2 = (Graphics2D) g.create();
            g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

            paintBackground(g2);
            paintGrid(g2);
            paintFood(g2);
            paintSnake(g2);
            paintOverlay(g2);

            g2.dispose();
        }

        private void paintBackground(Graphics2D g2) {
            GradientPaint gradient = new GradientPaint(
                0,
                0,
                new Color(12, 20, 34),
                GAME_WIDTH,
                GAME_HEIGHT,
                new Color(16, 41, 34)
            );
            g2.setPaint(gradient);
            g2.fillRect(0, 0, GAME_WIDTH, GAME_HEIGHT);
        }

        private void paintGrid(Graphics2D g2) {
            g2.setColor(new Color(255, 255, 255, 18));
            for (int x = 0; x <= GAME_WIDTH; x += CELL_SIZE) {
                g2.drawLine(x, 0, x, GAME_HEIGHT);
            }
            for (int y = 0; y <= GAME_HEIGHT; y += CELL_SIZE) {
                g2.drawLine(0, y, GAME_WIDTH, y);
            }
        }

        private void paintFood(Graphics2D g2) {
            paintCellOrb(g2, normalFood, new Color(255, 80, 88), new Color(255, 210, 105), 4);

            if (!bonusFood.isEmpty()) {
                int x = bonusFood.get(0).x * CELL_SIZE;
                int y = bonusFood.get(0).y * CELL_SIZE;
                int size = CELL_SIZE * 2;

                g2.setColor(new Color(255, 229, 87, 50));
                g2.fillOval(x - 5, y - 5, size + 10, size + 10);
                g2.setColor(new Color(255, 190, 50));
                g2.fillOval(x + 3, y + 3, size - 6, size - 6);
                g2.setColor(new Color(255, 247, 178));
                g2.fillOval(x + 11, y + 9, size / 3, size / 3);
                g2.setColor(new Color(123, 75, 12));
                g2.setStroke(new BasicStroke(2f));
                g2.drawOval(x + 3, y + 3, size - 6, size - 6);
            }
        }

        private void paintSnake(Graphics2D g2) {
            for (int i = snake.size() - 1; i >= 0; i--) {
                Point part = snake.get(i);
                boolean isHead = i == 0;
                int x = part.x * CELL_SIZE;
                int y = part.y * CELL_SIZE;

                if (isHead) {
                    g2.setColor(new Color(89, 255, 139));
                } else {
                    int shade = Math.max(95, 220 - i * 3);
                    g2.setColor(new Color(65, shade, 106));
                }

                g2.fillRoundRect(x + 2, y + 2, CELL_SIZE - 4, CELL_SIZE - 4, 9, 9);
                g2.setColor(new Color(10, 45, 22, 135));
                g2.drawRoundRect(x + 2, y + 2, CELL_SIZE - 4, CELL_SIZE - 4, 9, 9);

                if (isHead) {
                    paintEyes(g2, x, y);
                }
            }
        }

        private void paintEyes(Graphics2D g2, int x, int y) {
            int eyeSize = 4;
            int leftEyeX = x + 7;
            int rightEyeX = x + CELL_SIZE - 11;
            int eyeY = y + 7;

            if (direction == Direction.LEFT || direction == Direction.RIGHT) {
                eyeY = y + 6;
            } else {
                leftEyeX = x + 7;
                rightEyeX = x + 13;
                eyeY = direction == Direction.UP ? y + 6 : y + CELL_SIZE - 10;
            }

            g2.setColor(Color.BLACK);
            g2.fillOval(leftEyeX, eyeY, eyeSize, eyeSize);
            g2.fillOval(rightEyeX, eyeY, eyeSize, eyeSize);
        }

        private void paintCellOrb(Graphics2D g2, Point cell, Color main, Color highlight, int inset) {
            if (cell == null) {
                return;
            }

            int x = cell.x * CELL_SIZE + inset;
            int y = cell.y * CELL_SIZE + inset;
            int size = CELL_SIZE - inset * 2;
            g2.setColor(main);
            g2.fillOval(x, y, size, size);
            g2.setColor(highlight);
            g2.fillOval(x + 4, y + 3, Math.max(5, size / 3), Math.max(5, size / 3));
        }

        private void paintOverlay(Graphics2D g2) {
            String message = null;
            if (paused) {
                message = "PAUSED";
            } else if (gameOver) {
                message = "GAME OVER";
            }

            if (message == null) {
                return;
            }

            g2.setColor(new Color(0, 0, 0, 150));
            g2.fillRect(0, 0, GAME_WIDTH, GAME_HEIGHT);
            g2.setFont(new Font("Segoe UI", Font.BOLD, 46));
            FontMetrics metrics = g2.getFontMetrics();
            int textX = (GAME_WIDTH - metrics.stringWidth(message)) / 2;
            int textY = GAME_HEIGHT / 2;
            g2.setColor(new Color(245, 248, 255));
            g2.drawString(message, textX, textY);

            g2.setFont(new Font("Segoe UI", Font.PLAIN, 18));
            String hint = "Press R to restart";
            FontMetrics hintMetrics = g2.getFontMetrics();
            g2.drawString(hint, (GAME_WIDTH - hintMetrics.stringWidth(hint)) / 2, textY + 34);
        }

        private class MovementHandler extends KeyAdapter {
            @Override
            public void keyPressed(KeyEvent e) {
                int key = e.getKeyCode();

                if (key == KeyEvent.VK_R) {
                    restart();
                    return;
                }
                if (key == KeyEvent.VK_SPACE) {
                    togglePause();
                    return;
                }

                Direction requested = null;
                if (key == KeyEvent.VK_UP) {
                    requested = Direction.UP;
                } else if (key == KeyEvent.VK_DOWN) {
                    requested = Direction.DOWN;
                } else if (key == KeyEvent.VK_LEFT) {
                    requested = Direction.LEFT;
                } else if (key == KeyEvent.VK_RIGHT) {
                    requested = Direction.RIGHT;
                }

                if (requested != null && !requested.isOpposite(direction)) {
                    nextDirection = requested;
                }
            }
        }
    }
}
