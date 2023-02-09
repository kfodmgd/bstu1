using System;
using System.Collections.Generic;

namespace кр2
{
    class Program

    {
        static void Main(string[] args)
        {
            List<int> tmp = new List<int> { 1, 2, 3, 4,5 };
            int n = 5;
            try
            {
                SuperQueue<int> qu = new SuperQueue<int>(3);
            }
            catch (exc.More er)
            {
                Console.WriteLine("Элементов больше 4");
                Console.WriteLine(er);
            }


            User.U tel;
            User us = new User();
            Window user = new Window();

            us.Move += user.Pod;

            tel = us.Trubka;

            tel();

        }
    }
}
