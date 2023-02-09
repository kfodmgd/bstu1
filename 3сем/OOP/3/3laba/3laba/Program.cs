using System;
using System.Collections.Generic;
using System.Linq;

namespace _3laba
{
    class Mas
    {
        public int[] ar;
        public int[] br;

        public Mas(int[] a, int[] b)
        {
            ar = a;
            br = b;
        }
        public Mas(int[] a)
        {
            ar = a;
        }

        //перегрузка
        //*  умножение массивов;
        public static int[] operator *(Mas a, Mas b)
        {
            int[] rez = new int[a.ar.Length + b.ar.Length];
            int ln;
            if (a.ar.Length > b.ar.Length)
            {
                ln = a.ar.Length;
            }
            else
            {
                ln = b.ar.Length;
            }
            for (int i = 0; i < ln; i++)
            {
                rez[i] = a.ar[i] * b.ar[i];
            }
            return rez;
        }
        //true  истина если массив не сдержит отрицательных элементов,
        public static bool operator -(Mas a)
        {
            for (int i = 0; i < a.ar.Length; i++)
            {
                if (a.ar[i] < 0)
                {
                    return true;
                }
            }
            return false;
        }
        //int ()  операция приведения – возвращает размер массива;
        public static int operator +(Mas a)
        {
            return a.ar.Length;
        }
        //==  проверка на равенство;
        public static bool operator ==(Mas a, Mas b)
        {
            bool rez = a.ar.Equals(b.br);
            return rez;
        }
        //проверка на не равенство
        public static bool operator !=(Mas a, Mas b)
        {
            bool rez = a.ar.Equals(b.br);
            return rez;
        }

        //Добавьте в свой класс вложенный класс Developer (разработчик – фио,
        //id, отдел). Проинициализируйте
        public class Developer
        {
            private string name { get; set; }
            private string org { get; set; }
            private int id { get; set; }

            public Developer()
            {
                this.name = "Liza";
                this.org = "BSTU";
                this.id = 123456789;
            }
        }

        //Создайте статический класс StatisticOperation, содержащий 3 метода для
        //работы с вашим классом
        public static class StatisticOperation
        {
            //сумма
            public static int Summa(Mas a)
            {
                int sum = 0;
                for(int i = 0; i < a.ar.Length; i++)
                {
                    sum += a.ar[i];
                }
                return sum;
            }
            //разница между максимальным и минимальным
            public static int Razn(Mas a)
            {
                int min = a.ar[0];
                int max = a.ar[0];
                for (int i = 0; i < a.ar.Length; i++)
                {
                    if (a.ar[i] > max)
                    {
                        max = a.ar[i];
                    }
                    if (a.ar[i] < min)
                    {
                        min = a.ar[i];
                    }
                }
                return max - min;
            }
            // подсчет количества элементов
            public static int Size(Mas a)
            {
                return a.ar.Length;
            }

            //Удаление отрицательных элементов
            public static int[] Del(Mas a)
            {
                List<int> temp = a.ar.ToList();
                for(int i = 0; i < a.ar.Length; i++)
                {
                    if (a.ar[i] < 0)
                    {
                        temp.RemoveAt(i);
                    }
                }
                a.ar = temp.ToArray();
                return a.ar;
            }

            public static Production an;
        }
    }


    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("размер 1 массива:");
            int n1 = int.Parse(Console.ReadLine());
            int[] a = new int[n1];
            Console.WriteLine("Введите значения");
            for(int i = 0; i < n1; i++)
            {
                a[i] = int.Parse(Console.ReadLine());
            }
            Mas aa = new Mas(a);

            Console.Write("размер 2 массива:");
            int n2 = int.Parse(Console.ReadLine());
            int[] b = new int[n2];
            Console.WriteLine("Введите значения");
            for (int i = 0; i < n2; i++)
            {
                b[i] = int.Parse(Console.ReadLine());
            }
            Mas bb = new Mas(b);

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
            for(int i = 0; i < testLn; i++)
            {
                Console.WriteLine(test[i]);
            }

            //нет отр элементов в 1 массиве
            bool zn;
            zn = - aa;
            Console.WriteLine($"Наличие отр элементов:{zn}");

            //вывод размера
            int lnAr;
            lnAr = + aa;
            Console.WriteLine($"размер:{lnAr}");

            //проверка на равенство
            bool rz;
            rz = aa==bb;
            Console.WriteLine($"Проверка на равенство двух массивов:{rz}");

            //добавление строки
            string str;
            Console.WriteLine($"Введите значение строки:");
            str = Console.ReadLine();
            Console.WriteLine(str.Add());

            //создание объекта класса
            Production MyProd = new Production(1, "БГТУ");

            Mas.Developer MyDev = new Mas.Developer();

        }
    }
}
