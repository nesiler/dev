using System;

namespace learn
{
    class Program
    {
        static void Main(string[] args)
        {
            string nasd = "asd";
            Console.WriteLine(nasd);

            // int x = Convert.ToInt32(Console.ReadLine());
            // string y = Console.ReadLine();
            // System.Console.WriteLine(x);
            // System.Console.WriteLine(y);

            /*
            Math:
            Pow, Sqrt, Abs, Round, Ceiling, Floor, Max, Min
            */

            Random random = new Random();
            int m = random.Next(0, 10);
            double n = random.NextDouble();

            /*
            String
            str.ToUpper, ToLower, Replace(x , y),
            Insert(index, 'text'), Length, SubString(start,count)
            */

            if (2 > 1)
            {
                System.Console.WriteLine("false");
            }

            char[] xs = { 'a', 'b', 'c', 'd', 'e', 'f' };

            //params keyword!!!

            System.Console.WriteLine(CheckOut(1, 2, 3, 4, 5, 6.0, 7.0, 8.45, 89.123, 0.1234));

            static double CheckOut(params double[] prices)
            {
                double total = 0;
                foreach (double price in prices)
                {
                    total += price;
                }
                return total;
            }


            try
            {
                System.Console.WriteLine("Enter something: ");
                int r = Convert.ToInt32(Console.ReadLine());
                System.Console.WriteLine("You entered: " + r);
            }
            catch (FormatException e)
            {
                System.Console.WriteLine("Wtf is that you entered");
            }
            catch (Exception e)
            {
                System.Console.WriteLine("Something went wrong damn!");
            }
            finally
            {
                System.Console.WriteLine("thanks!");
            }

            Console.ReadKey();
        }
    }
}