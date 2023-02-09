using System;
using System.Collections.Generic;
using System.Linq;

namespace _3laba
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

