using System;
using System.Collections.Generic;
using System.Text;

namespace _8laba
{
    class Str
    {
        public static void Low(string str)
        {
            Console.WriteLine(str.ToLower());
        }
        public static void Add(string str, char let)
        {
            Console.WriteLine(str += let);
        }
        public static string Up(string str)
        {
            return str.ToUpper();
        }
        public static void Change(string str)
        {
            Console.WriteLine(str.Replace("a", "q"));
        }
        public static void Del(string str)
        {
            Console.WriteLine(str.Remove(' '));
        }




    }
}
