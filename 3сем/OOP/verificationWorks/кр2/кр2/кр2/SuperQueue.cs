using System;
using System.Collections.Generic;
using System.Text;

namespace кр2
{
    class SuperQueue<T> where T : new()
    {
        public Queue<T> q{get;set;}
        private int num;
        public int Num
        {
            get
            {
                return num;
            }
            set
            {
                if (num >= 4)
                {
                    throw new exc.More("Больше 4");
                }
                else
                {
                    num = value;
                }
            }
        }
        public SuperQueue(int n)
        {
            if (n >= 4) { throw new exc.More("Больше 4"); }
            else { Num = n; }
        }

    }
}
