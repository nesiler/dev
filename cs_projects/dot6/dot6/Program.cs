using System;
using System.Collections;
using System.Diagnostics;
using System.Runtime.InteropServices.ComTypes;
using System.Security.Policy;
using System.Text;
using System.Text.RegularExpressions;
using System.Text.RegularExpressions;
using Microsoft.Extensions.Primitives;

internal class Program
{
    private static void Main(string[] args)
    {
        //repeat " / " 40 times
        Console.WriteLine(new String('\n', 20));
        int a = 123;
        //Console.WriteLine($"damn {a}");
        //deep copy
        int b = a;
        //Console.WriteLine("B: " + b);

        //shawollow copy (reference kopyalamak , heapteki ayni adresi tutuyorlar)
        //var keyword object ise turdur
        object integer = 12;
        object str = "asd";
        object isThat = true;
        object ch = 'a';

        //Console.WriteLine(integer);
        //Console.WriteLine(str);
        //Console.WriteLine(isThat);
        //Console.WriteLine(ch);
        //Console.WriteLine(isThat.GetType());

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

        //Console.WriteLine(dogru ^ yanlis); //true
        //Console.WriteLine(dogru ^ dogru); //false
        //Console.WriteLine(yanlis ^ yanlis); //true

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
        //Console.WriteLine(t.BaseType);
        //Console.WriteLine(t.FullName);
        //Console.WriteLine(t.IsPrimitive);

        //is operatoru
        object something = true;
        //is null yalinzca null olabilen turlerde ~is null ~is not null
        string somestr = null;

        //Console.WriteLine(something is bool);
        //Console.WriteLine(something is int);
        //Console.WriteLine(something is null);
        //Console.WriteLine(somestr is null);

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
        //Console.WriteLine(coalescing ?? "3");
        //degisken null ise 123 degerini degiskene ata ve yazdir
        //Console.WriteLine(coalescing1 ??= "123");
        //Console.WriteLine(coalescing1 ?? "456");

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
            > 5000 => "Kucukkk",
            4536 => "Esitt",
            _ => "nothing yani"
        };

        //array sinifi
        Array arr = new int[3];
        //metotlar
        //clear(deafult degerler) - copy - indexOf(deger yoksa -1 doner) - Reverse - Sort
        //Array.Copy();
        //Array.Reverse();
        //Array.IndexOf();

        //ozellikler
        //Length - Rank(derece - 2 boyutlu vs) - LongLength - isReadOnly - IsFixedSize
        arr.SetValue(123, 0);
        System.Console.WriteLine(arr.GetValue(0));

        //System.Index = index basina " ^ " isareti getirilerek sondan indexleme saglanir ve birden baslar 0 dan degil
        //index 3 = 0, 1, 2, -3- iken : index ^3 = sondan 4, -3-, 2, 1
        Index index = 5;
        Index indexx = ^4;
        //System.Range " .. " opeartoru ile range belirleme - onemli kisim! (index no .. sira no) seklinde olmasidir
        //yani .. nin solunda index (0,1,2,3), saginda ise sira no(1,2,3,4) vardir
        //belirtilen numaranin bir solunu aliyor gibi dusunulebilir
        Range range = 3..7;
        //sag kisimda ^ kullanilirsa sagdan -2-,1 elemani degil bir solu kullanilir yani -3-, 2, 1
        Range rangee = 5..^2;

        //create a 10 size number array and fill it with random number without loop
        int[] numbers = { 1, 5, 56, 1234, 653, 456768, 234, 51234, 3, 53425, 1657, 342, 65, 42, 8, 4567 };
        Range rangeee = 3..^7;
        int[] numberss = numbers[rangeee];
        System.Console.WriteLine(new string('>', 30));
        foreach (var item in numberss)
        {
            Console.WriteLine(item);
        }
        System.Console.WriteLine(new string('<', 30));

        //2 dimension integer array and fill
        int[,] arr2 = new int[3, 3];
        arr2[0, 0] = 1;
        //3 dimension integer array and fill
        int[,,] arr3 = new int[3, 3, 3];
        arr3[0, 0, 0] = 1;

        //jagged array
        int[][] jagged = new int[3][];
        jagged[0] = new int[3];
        jagged[1] = new int[2];
        jagged[2] = new int[4];

        //null string tanimlama 
        String strr = string.Empty;
        if (string.IsNullOrEmpty(strr))
        {
            if (strr is null)
                Console.WriteLine("null");
            else if (strr == string.Empty)
                Console.WriteLine("empty");

            if (string.IsNullOrWhiteSpace(strr))
                Console.WriteLine("whitespace");
        }

        string formatted = string.Format("Merhaba benim adim {0}, soyadim {1}, yasim {2}", ogrenci.Name, ogrenci.Soyadi, ogrenci.Yasi);
        System.Console.WriteLine(formatted);

        //string all escape character is \ backslash - o,a,b,t,r,n,v,fddd

        //verbatim basina koyulan @ isareti, alt satira gecmesine ragmen + isareti cikmiyor, ayrica " isaretleri kendil kendini yiyor
        string verbatim = @"alsdkfjalskdjf
        laskjdflaksjdf
        laskdjflaksjdlfj
        laksdjflaksjdlfkj";

        string meine = "asdifkashd kasdjhflkasdjhf kjhasdfkljahsd kjhasdlkfhasd";

        //bastan 4. index sondan 5. harf
        string aralik = meine[4..^5];
        //Console.WriteLine(aralik[0]);
        //Console.WriteLine(aralik[1]);
        //Console.WriteLine(aralik[aralik.Length - 1]);
        //Console.WriteLine(aralik);

        //ArraySegment define
        //array i referans olarak tutar ve bellektne kazandirir
        //asagidaki ornekte 2.indexten 4.siraya kadar yani 2,3 indexleri
        ArraySegment<int> segment = new ArraySegment<int>(numbers, 2, 4);
        //segment slice - 1.index ve 3.sira arasi referans alindi
        ArraySegment<int> segment2 = segment.Slice(1, 3);

        //string segment 
        //need to install ExtensionPrimitives
        string strSegment = "Hello World";
        //ArraySegment<char> segment3 = strSegment.AsSpan(6, 5);
        StringSegment stringSegment = new StringSegment(strSegment);

        //string builder
        StringBuilder sb = new StringBuilder();
        sb.Append("Hello");
        sb.Append(" ");
        sb.Append("World");
        sb.Append(" ");
        sb.Append("!");

        //span defining
        //span is a reference type
        Span<int> span = new Span<int>(numbers);
        Span<int> span2 = numbers;
        Span<int> span3 = new Span<int>(numbers, 1, 3);
        //asSpan define
        Span<int> span4 = numbers.AsSpan(1, 3);

        //eger string de asSpan kullanilirsa ReadOnlySpan lazim
        ReadOnlySpan<char> span5 = meine.AsSpan(6, 5);

        string regSample = "eneslaskjd0q3u9efijowc";
        Regex regex = new Regex("^enes");
        Match match = regex.Match(regSample);
        System.Console.WriteLine(match.Success);

        //alloc with span
        Span<int> span6 = stackalloc int[3];

        //Collections -> ArrayList vs.
        //ArrayList
        int toplamm = 0;
        ArrayList arrayList = new ArrayList();
        for (int i = 0; i < 10; i++)
            arrayList.Add(i);

        //ArrayList elemanlari OBJECT olarak tutar
        //bu sebeple islme yaparken unboxing (int) vs. yapmamiz lazim.
        for (int i = 0; i < arrayList.Count; i++)
            toplamm += (int)arrayList[i];

        //list icinde birden fazla tur mevcur ise kontrol yapmak lazim gelir
        ArrayList _multiType = new ArrayList(){
            "Enes",
            1,
            2.5,
            true
        };

        //print _multiType
        foreach (var item in _multiType)
        {
            if (item is string)
                Console.WriteLine("string");
            else if (item is int)
                Console.WriteLine("int");
            else if (item is double)
                Console.WriteLine("double");
            else if (item is bool)
                Console.WriteLine("bool");
        }

        //time span wnd date time
        DateTime dt = DateTime.Now;
        DateTime dt2 = new DateTime(2021, 1, 1);
        TimeSpan ts = dt - dt2;
        System.Console.WriteLine($"Aradaki gun {ts.TotalDays}");
        System.Console.WriteLine($"Aradaki dakika {ts.TotalMinutes}");

        //random - max deger dahil degil
        Random rnd = new Random();
        int rndInt = rnd.Next(1, 100);
        System.Console.WriteLine(rndInt);
        int billion = 0;
        int found = 0;

        //array list integer

        double[] arrList = new double[10000000];

        for (int j = 0; j < arrList.Length; j++)
        {
            arrList[j] = rnd.NextDouble();
        }

        if (arrList.Length != arrList.Distinct().Count())
        {
            Console.WriteLine("Contains duplicates");
            billion++;
            found++;
            System.Console.WriteLine($"{billion} Billion {found} value found");

        }
        else
        {
            Console.WriteLine("No duplicates");
        }

        //in paramater
        //in paramater ile methoda gonderilen degerin degistirilmesi engellenir
        static void inParam(in int a)
        {
            //a = 5;
            System.Console.WriteLine(a);
        }

        inParam(6);

        //ref paramater
        int refA = 5;
        ref int refB = ref a;
        System.Console.WriteLine(refB);

        x(ref refA);

        void x(ref int a)
        {
            a = 6;
        }

        ref int Y(ref int y)
        {
            y = 25;
            return ref y;
        }

        //out keyword
        int _a;
        string _b = "";
        outKeyword(5, out _a, out _b);

        void outKeyword(int i, out int a, out string b)
        {
            a = i;
            b = "Hello";
            System.Console.WriteLine($"inside out: {i}");
        }
        System.Console.WriteLine($"outside out: {_a} {_b}");

        //try parse
        string str = "123";
        int.TryParse(str, out int result);
        System.Console.WriteLine(result);
    






        Console.WriteLine("=======Finish=======");
        // Console.ReadKey();
    }
}

class Ogrenci
{
    public string? Name;
    public string? Soyadi;
    public string? Meslek;
    public int Yasi;
}

class Other
{
    public string? Stuff;
}