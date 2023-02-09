using System;
using System.Collections.Generic;
using System.Text;

namespace кр2
{        
    public class User
        {
            public delegate void U();
            public event U Move;

            public void Trubka()
            {
                Console.WriteLine("двигает");
                Move();
            }
        }

        public class Window
        {
            public void Pod()
            {
                Console.WriteLine("изменил размер");
            }
        }
    }