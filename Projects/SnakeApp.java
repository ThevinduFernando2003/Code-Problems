import javax.swing.SwingUtilities;

public class SnakeApp {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new SnakeGame().showGame());
    }
}
