using System;
using System.Collections.Generic;
using System.Linq;

namespace _7laba
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("размер 1 массива:");
            int n1 = int.Parse(Console.ReadLine());
            int[] a = new int[n1];
            Console.WriteLine("Введите значения");
            for (int i = 0; i < n1; i++)
            {
                a[i] = int.Parse(Console.ReadLine());
            }
            Mas<int> aa = new Mas<int>(a);

            Console.Write("размер 2 массива:");
            int n2 = int.Parse(Console.ReadLine());
            int[] b = new int[n2];
            Console.WriteLine("Введите значения");
            for (int i = 0; i < n2; i++)
            {
                b[i] = int.Parse(Console.ReadLine());
            }
            Mas<int> bb = new Mas<int>(b);

            //умножение массивов
            int testLn;
            if (a.Length > b.Length)
            {
                testLn = a.Length;
            }
            else
            {
                testLn = b.Length;
            }
            int[] test = new int[testLn];
            test = aa * bb;
            Console.WriteLine("Итог");
            for (int i = 0; i < testLn; i++)
            {
                Console.WriteLine(test[i]);
            }

            //нет отр элементов в 1 массиве
            bool zn;
            zn = -aa;
            Console.WriteLine($"Наличие отр элементов:{zn}");

            //вывод размера
            int lnAr;
            lnAr = +aa;
            Console.WriteLine($"размер:{lnAr}");

            //проверка на равенство
            bool rz;
            rz = aa == bb;
            Console.WriteLine($"Проверка на равенство двух массивов:{rz}");

            //добавление строки
            string str;
            Console.WriteLine($"Введите значение строки:");
            str = Console.ReadLine();
            Console.WriteLine(str.Add());

            //создание объекта класса
            Production MyProd = new Production(1, "БГТУ");

            Mas<int>.Developer MyDev = new Mas<int>.Developer();

            //7laba
            try
            {
                int[] arr1 = new int[3] { 1, 5, 3 };
                int[] arr2 = new int[3] { 5, 8, 1 };
                Mas<int> TestMas = new Mas<int>(arr1);
                TestMas.ShowUp(TestMas.ar);
                TestMas.ar=TestMas.Add(TestMas.ar, 15);//add 15 into arr
                TestMas.ShowUp(TestMas.ar);
                TestMas.ar=TestMas.Delete(TestMas.ar, 5);//delete 5 from arr
                TestMas.ShowUp(TestMas.ar);
                

            }
            finally
            {
                Console.WriteLine("END");
            }
            Tovar<int> TestTovar = new Tovar<int>("qqq", 124);
            Mas<int> TestMas3 = new Mas<int>(b);
            TestTovar.Test<int>(TestTovar);
            //file
            string Path=@"f:\testik.txt";
            for (int i = 0; i < TestMas3.ar.Length; i++)
            {
                File1.Save(Path, Convert.ToString(TestMas3.ar[i]));
            }
            File1.Read(Path);
            System.Threading.Thread.Sleep(2000);
        }
    }
}
