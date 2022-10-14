/**
 * BIL122 - Lab 02
 * This class find the roots of the quadratic equation.
 * @TongueSoldier Enes Diler, <dilerenes@gmail.com>
 */

import java.util.Scanner;


public class Quadratic {
    double a;
    double b;
    double c;
    double x1;
    double x2;

    public Quadratic(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
        double d = getDiscriminant();
        setX1((-b + Math.sqrt(d)) / (2 * a));
        setX2((-b - Math.sqrt(d)) / (2 * a));

    }

    public static void main(String[] args) {
        /*Scanner scanner = new Scanner(System.in);
        double a = scanner.nextDouble();
        double b = scanner.nextDouble();
        double c = scanner.nextDouble();*/
        double a = 1;
        double b = 5;
        double c = 6;
        Quadratic q = new Quadratic(a, b, c);


        System.out.println("x1: " + q.getX1());
        System.out.println("x2: " + q.getX2());

    }

    public double getX1() {
        return x1;
    }

    public void setX1(double x1) {
        this.x1 = x1;
    }

    public double getX2() {
        return x2;
    }

    public void setX2(double x2) {
        this.x2 = x2;
    }

    public double getDiscriminant() {

        return (b * b) - (4 * a * c);

    }


}