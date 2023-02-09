using System;
using System.Collections.Generic;
using System.Linq;


namespace _7laba
{
    //Создайте статический класс StatisticOperation, содержащий 3 метода для
    //работы с вашим классом
    public static class StatisticOperation
    {
        public static string Add(this string str)
        {
            Console.Write("Введите строку, которую надо добавить:");
            str += Console.ReadLine();
            return str;
        }

        //сумма
        public static int Summa(Mas<int> a)
        {
            int sum = 0;
            for (int i = 0; i < a.ar.Length; i++)
            {
                sum += a.ar[i];
            }
            return sum;
        }
        //разница между максимальным и минимальным
        public static int Razn(Mas<int> a)
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
        public static int Size(Mas<int> a)
        {
            return a.ar.Length;
        }

        //Удаление отрицательных элементов
        public static int[] Del(Mas<int> a)
        {
            List<int> temp = a.ar.ToList();
            for (int i = 0; i < a.ar.Length; i++)
            {
                if (a.ar[i] < 0)
                {
                    temp.RemoveAt(i);
                }
            }
            a.ar = temp.ToArray();
            return a.ar;
        }
        //Проверка на содержание определённого символа в строке
        public static string Check()
        {
            string str;
            char a;
            Console.Write("Введите строку:");
            str = Console.ReadLine();
            Console.Write("введите символ который надо найти:");
            a = Convert.ToChar(Console.ReadLine());
            for (int i = 0; i < str.Length; i++)
            {
                if (str[i] == a)
                {
                    Console.WriteLine($"Данный символ находится на позиции{i + 1}");
                }
            }
            return str;
        }
    }
}


