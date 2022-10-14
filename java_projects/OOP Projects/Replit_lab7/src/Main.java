import javax.swing.*;

class Main {
    public static void main(String[] args) {
        JFrame f = new JFrame();
        MovingObject movingObject = new MovingObject();
        f.add(movingObject);
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setSize(800, 600);
    }
}