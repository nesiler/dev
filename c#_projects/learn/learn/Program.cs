using Internal;
using System;

namespace learn
{
    class Program
    {
        static void Main(string[] args)
        {
            string nasd = "asd";
            Console.WriteLine(nasd);

            double a = 3.14;
            int b = Convert.ToInt32(a);
            System.Console.WriteLine(b.GetType());

            int x = Convert.ToInt32(Console.ReadLine());
            string y = Console.ReadLine();
            System.Console.WriteLine(x);
            System.Console.WriteLine(y);

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

            if( 2 > 3){
                System.Console.WriteLine("false");
            }

            String[] xs = {'a', 'b', 'c', 'd', 'e', 'f'};
            Console.ReadKey();
        }
    }
}