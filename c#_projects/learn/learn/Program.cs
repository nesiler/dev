using System;
using System.Threading;
using System.Collections.Generic;
namespace learn

{
    class Program
    {
        static void Main(string[] args)
        {
            // string nasd = "asd";
            // Console.WriteLine(nasd);

            double result = 14;
            var isConvert = double.TryParse("45.123", out result);
            System.Console.WriteLine($"Convert result : {isConvert}");

            // int x = Convert.ToInt32(Console.ReadLine());
            // string y = Console.ReadLine();
            // System.Console.WriteLine(x);
            // System.Console.WriteLine(y);

            float fuloot = 3.14F; //obdalikli sayilarin sonunda turu belirtilmeli.
            decimal desimal = 3.14M;
            double duble = 3.14; //defaultta double olarak tanimlanir.

            (int age, string name, bool isSomething) someone = (25, "John Doe", true);

            int tireliSayi = 1_000_000; //1000000 same 



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

            /////////////////////////////////////////

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
            /////////////////////////////////////////


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
            /////////////////////////////////////////

            Dog dog = new Dog();
            Cat cat = new Cat();

            dog.MakeSound();
            cat.MakeSound();


            /////////////////////////////////////////

            Person me = new Person();

            /////////////////////////////////////////

            Car car = new Car();
            Bicycle bicycle = new Bicycle();
            Plane plane = new Plane();

            Vehicle[] vehicles = new Vehicle[3];
            vehicles[0] = car;
            vehicles[1] = bicycle;
            vehicles[2] = plane;

            foreach (Vehicle vehicle in vehicles)
            {
                vehicle.Go();
            }
            /////////////////////////////////////////

            //Inheritance
            Rabbit rabbit = new Rabbit();
            Hawk hawk = new Hawk();
            Fish fish = new Fish();

            rabbit.Flee();
            hawk.Hunt();
            fish.Hunt();
            fish.Flee();
            /////////////////////////////////////////

            List<String> names = new List<String>();
            names.Add("John");
            names.Add("Mary");
            names.Add("Bob");
            names.Add("Alice");
            names.Remove("Bob");
            names.Insert(0, "Bob");

            System.Console.WriteLine(names[0]);
            System.Console.WriteLine(names.Count);
            System.Console.WriteLine(names.IndexOf("Alice"));
            System.Console.WriteLine(names.Contains("Bob"));
            names.Sort();
            foreach (string name in names)
            {
                System.Console.WriteLine(name);
            }

            names.Reverse();
            System.Console.WriteLine(names.LastIndexOf("Bob"));

            foreach (String name in names)
            {
                System.Console.WriteLine(name);
            }

            String[] nameArray = names.ToArray();
            names.Clear();
            /////////////////////////////////////////
            Runner runner = new Runner(400);
            runner.Speed = 100;

            runner.Run();

            System.Console.WriteLine(Planets.Mercury + " " + (int)Planets.Mercury);

            //generics
            int[] nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            String[] numbers = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

            Thread mainThread = Thread.CurrentThread;
            mainThread.Name = "Main Thread";

            CountDown("Main 1");
            CountUp("Main 2");

            Thread thread1 = new Thread(() => CountDown("Timer 1"));
            Thread thread2 = new Thread(() => CountUp("Timer 2"));
            thread1.Start();
            thread2.Start();

            Console.ReadKey();
        }
        
        public static void CountDown(String threadName){
                for(int i = 10; i > 0; i--){
                    System.Console.WriteLine(threadName + " " + i);
                    Thread.Sleep(100);
                }
            }

        public static void CountUp(String threadName){
            for(int i = 0; i < 10; i++){
                System.Console.WriteLine(threadName + " " + i);
                Thread.Sleep(100);
                }
            }

        public static void PrintArray<T>(T[] array)
        {
            foreach (T element in array)
            {                    
                System.Console.WriteLine(element);
            }
        }
    }

    enum Planets
    {
        Mercury = 1,
        Venus = 2,
        Earth = 3,
        Mars = 4,
        Jupiter = 5,
        Saturn = 6,
        Uranus = 7,
        Neptune = 8
        }

    class Runner
    {
        private int speed;
        //quick get set :
        //pulic int Speed {get; set;}
        public Runner(int speed)
        {
            Speed = speed;
        }
        
        //getter setter
        public int Speed
        {
            get { return speed; }
            set
            {
                if (value >= 500)
                {
                    speed = 500;
                }
                else if (value <= 0)
                {
                    speed = 0;
                }
                else { speed = value; }
            }
        }
        public void Run()
        {
            System.Console.WriteLine("Running at speed: " + speed);
        }
    }

    /////////////////////////////////////////
    interface IPredator
    {
        void Hunt();
    }

    interface IPrey
    {
        void Flee();
    }

    class Rabbit : IPrey
    {
        public void Flee()
        {
            System.Console.WriteLine("The rabbit flees");
        }
    }

    class Hawk : IPredator
    {
        public void Hunt()
        {
            System.Console.WriteLine("The hawk hunts");
        }
    }

    class Fish : IPrey, IPredator
    {
        public void Flee()
        {
            System.Console.WriteLine("The fish flees");
        }

        public void Hunt()
        {
            System.Console.WriteLine("The fish hunts");
        }
    }

    //abstract class
    // abstract class Animal
    // {
    //     public abstract void MakeSound();
    // }
    // class Dog : Animal
    // {
    //     public override void MakeSound()
    //     {
    //         System.Console.WriteLine("Woof");
    //     }
    // }

    /////////////////////////////////////////
    //polymorphism
    class Vehicle
    {
        public virtual void Go()
        {

        }

    }
    class Car : Vehicle
    {
        public override void Go()
        {
            System.Console.WriteLine("Car is moving forward");
        }


    }
    class Plane : Vehicle
    {
        public override void Go()
        {
            System.Console.WriteLine("Plane is moving forward");
        }

    }
    class Bicycle : Vehicle
    {
        public override void Go()
        {
            System.Console.WriteLine("Bicycle is moving forward");

        }
    }
    ////////////////////////////////////////       
    //method overloading
    class Animal
    {
        public virtual void MakeSound()
        {
            System.Console.WriteLine("Grrrr");
        }
    }

    class Dog : Animal
    {
        public override void MakeSound()
        {
            System.Console.WriteLine("Woof");
        }
    }

    class Cat : Animal
    {
        public override void MakeSound()
        {
            System.Console.WriteLine("Meow");
        }
    }
    /////////////////////////////////
    //toString override
    class Person
    {
        public string Name { get; set; }
        public int Age { get; set; }

        public override string ToString()
        {
            return Name + " " + Age;
        }
    }
}