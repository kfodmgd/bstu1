using System;
using System.Collections.Generic;
using System.Text;

namespace _5laba
{
    class Controller: IComparable
    {
        public static int SumPrice(Sklad tovars)
        {
            int sum = 0;
            foreach (var A in tovars.ListOfTovar)
            {
                sum += A.Price;
            }
            return sum;
        }


        public static void SearchMaterial(Sklad tovars, string material)
        {
            foreach(var A in tovars.ListOfTovar)
            {
                if (A.Material == material)
                {
                    Console.WriteLine(A);
                }
            }
        }

        public static void SortByMoney(Sklad tov)
        {
            //tov.ListOfTovar.Sort();
            //tov.ListOfTovar.Reverse();
            tov.ListOfTovar.Sort((x, y) => x.Price.CompareTo(y.Price));
        }

        public int CompareTo(object obj)
        {
            if (obj == null) return 1;
            return CompareTo(obj);
        }
    }
}
