using System;

internal class Program
{
    private static void Main(string[] args)
    {
        int a = 123;
        Console.WriteLine($"damn {a}");
        //deep copy
        int b = a;
        Console.WriteLine("B: " + b);

        //shawollow copy (reference kopyalamak , heapteki ayni adresi tutuyorlar)
        //var keyword object ise turdur
        object integer = 12;
        object str = "asd";
        object isThat = true;
        object ch = 'a';

        Console.WriteLine(integer);
        Console.WriteLine(str);
        Console.WriteLine(isThat);
        Console.WriteLine(ch);
        Console.WriteLine(isThat.GetType());

        //dynamic _a = "2";
        //dynamic yalnizca rintime da type alir
        // uzaktan gelen veriler icin kullanilaiblir.

        //parse adece string donustururuken kullanilir
        string num = "123";
        short num2 = short.Parse(num);

        string num4 = "3.14";
        double num3 = Convert.ToDouble(num4);

        Console.WriteLine($"1: {num} 2: {num2} 3: {num3} 4: {num4} ");

        //checked
        //{
        //    int altika = 600000000;
        //    byte altikey = (byte)altika;
        //    Console.WriteLine(altikey);
        //}

        // ^ operatoru (ya da)
        //kesinlikle bir tanesi dogruoanmis olacak
        bool dogru = true;
        bool yanlis = false;

        Console.WriteLine(dogru ^ yanlis); //true
        Console.WriteLine(dogru ^ dogru); //false
        Console.WriteLine(yanlis ^ yanlis); //true

        //ternary operatoru  `condition ? true:false`
        var terres = (123 / 4) >= 40 ? "yess" : "falsse";
        Console.WriteLine(terres);

        //input
        //Console.Write("Enter something: ");
        //string sayi = Console.ReadLine();
        //int _sayii = int.Parse(sayi);

        //Console.Write("again: ");
        //int direct = int.Parse(Console.ReadLine());

        //type - biyr type ait tum bilgileri tutar ( "." ile erisilir) ~ Type t
        Type t = typeof(int);
        Console.WriteLine(t.BaseType);
        Console.WriteLine(t.FullName);
        Console.WriteLine(t.IsPrimitive);

        //is operatoru
        object something = true;
        //is null yalinzca null olabilen turlerde ~is null ~is not null
        string somestr = null;

        Console.WriteLine(something is bool);
        Console.WriteLine(something is int);
        Console.WriteLine(something is null);
        Console.WriteLine(somestr is null);

        //cast => "(int)varname" yalnizca turune uygun bir sekilde yapmasi lazim "object to int" gibi
        // "as" uygun olmasi gerekmez, hata vermez yalnizca null deger doner (null alabilen degiskenlere ~reference)

        object asTest = "Enes";
        Program pro = asTest
                      as Program;
        //Program pro1 = asTest as int;

        Console.WriteLine($"Pro is: {pro}");

        //null coalescing - deger null ise farkli deger
        //her iki tarafta ayni tur olmailidir
        string coalescing = null;
        string coalescing1 = null;
        //degisken null ise 3 yazdir
        Console.WriteLine(coalescing ?? "3");
        //degisken null ise 123 degerini degiskene ata ve yazdir
        Console.WriteLine(coalescing1 ??= "123");
        Console.WriteLine(coalescing1 ?? "456");

        //switch expressions

        int ns = 34;
        string dlr = ns switch
        {
            5 => "Hilmi",
            25 => "Enes",
            var x when x == 34 && x % 2 == 0 => "Ahmet", //x degiskeni ns degerini aldi ve kosul kontrol edildi
            100 when (true ^ true) => "Diler", //deger 100 olup kosulu saglarsa girer
            var y => "Default tanimlama yerine gecer"
        };
        Console.WriteLine(dlr);

        //tuple da "_" isareti hicbisi anlamina geliyor


        //property patterns class propertisi ile switch
        Ogrenci ogrenci = new Ogrenci
        {
            Name = "Enes",
            Soyadi = "Diler",
            Meslek = "Ogrenci"
        };

        double maas = ogrenci switch
        {
            { Meslek: "Kasap" } => 50,
            { Meslek: "Tesisat Ustasi" } => 55,
            { Meslek: "Otobus Soforu" } => 65,
            { Meslek: "Yazilim" } => 75,
            var x when x.Meslek == "Ogrenci" && true ^ false => 10,
            var y => 123
        };
        Console.WriteLine(maas);

        //type pattern
        object xx = 123;
        if (xx is string)
        {
            Console.WriteLine($"x is string");
        }
        else if (xx is int xxxx)
        {
            Console.WriteLine($"pattern assign: {xxxx}");
        }
        else if (xx is 123)
        {
            Console.WriteLine($"is 123: {true}");
        }
        else if (xx is var yyy) //runtime da belirlenir tip
        {
            Console.WriteLine($"is var: {yyy}");
        }

        object strrr = "asdasdasdoijl";

        bool res = strrr is var o1; //null olma sansi yok deger kesinlikle atanir
        bool res1 = strrr is string o2; //null olabilir hatali

        Console.WriteLine(o1);
        //Console.WriteLine(o2); //null oldugu icin izin yok

        //simple type pattern
        object obj = new Ogrenci();
        switch (obj)
        {
            case Ogrenci:
                //...
                break;
            case Other:
                break;

        }

        //func
        //string GetType(Ogrenci p) => p switch
        //{
        //    Other => "diger",
        //    Ogrenci => "student",
        //};

        int number = 4536;
        string numres = number switch
        {
            < 4000 => "Buyukkk",
            > 4000 => "Kucukkk",
            _ => "nothing yani"
            4536 => "Esitt"
        };












        Console.WriteLine("=======Finish=======");
        Console.ReadKey();
    }
}

class Ogrenci
{
    public string? Name;
    public string? Soyadi;
    public string? Meslek;
}

class Other
{
    public string? Stuff;
}