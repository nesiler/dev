public class MyMath {

    long factorial(int n) {

        if (n == 0)
            return 1;

        return n * factorial(n - 1);

    }


    long fibonacci(int n) {

        if (n == 0)
            return 0;

        if (n == 1)
            return 1;

        return fibonacci(n - 1) + fibonacci(n - 2);

    }

    void printPyramidNumbers(int n) {

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= i; j++) {

                System.out.print(j);
            }
            System.out.println();
        }
    }

    int gcd(int a, int b) {

        if (a == 0)
            return b;

        if (b == 0)
            return a;

        if (a > b)
            return gcd(a - b, b);

        if (a < b)
            return gcd(a, b - a);

        else return a;

    }

    int lengthOfCollatzSeq(int n) {

        int counter = 1;

        while (n != 1) {

            if ((n % 2) == 0) {
                n = n / 2;
                counter++;
            } else if ((n % 2) != 0) {
                n = (3 * n) + 1;
                counter++;
            }
        }
        return counter;
    }

}

