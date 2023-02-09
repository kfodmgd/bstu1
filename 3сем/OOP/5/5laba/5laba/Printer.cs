using System;
using System.Collections.Generic;
using System.Text;

namespace _5laba
{
    class Printer
    {
        public static void IAmPrinting(Tovar tov)
        {
            Console.WriteLine($"get type:{tov.GetType()}");
            Console.WriteLine("----------------");
            Console.WriteLine(tov.ToString());
        }
    }
}
