import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.geom.Ellipse2D;

public class MovingObject extends JPanel implements KeyListener, ActionListener {

    Timer t = new Timer(5, this);
    int x = 0, y = 0;
    double cx = 0, cy = 0;

    public MovingObject() {

        t.start();
        addKeyListener(this);
        setFocusable(true);
        setFocusTraversalKeysEnabled(false);

    }

    @Override
    public void actionPerformed(ActionEvent e) {
        repaint();
        x += cx;
        y += cy;
    }

    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2 = (Graphics2D) g;
        g2.fill(new Ellipse2D.Double(x, y, 5, 5));
    }

    public void up() {
        cy = -1;
        cx = 0;
    }

    public void down() {
        cy = 1;
        cx = 0;
    }

    public void left() {
        cy = 0;
        cx = -1;
    }

    public void right() {
        cy = 0;
        cx = 1;
    }


    @Override
    public void keyTyped(KeyEvent e) {

    }

    @Override
    public void keyPressed(KeyEvent e) {

        int code = e.getKeyCode();

        if (code == KeyEvent.VK_UP) {
            up();
        }
        if (code == KeyEvent.VK_DOWN) {
            down();
        }
        if (code == KeyEvent.VK_LEFT) {
            left();
        }
        if (code == KeyEvent.VK_RIGHT) {
            right();
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {

    }


}
