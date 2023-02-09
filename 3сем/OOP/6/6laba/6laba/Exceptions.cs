using System;
using System.Collections.Generic;
using System.Text;

namespace _6laba
{
    class Exeptions
    {
        protected internal class TovarArgExc: ArgumentException//передачa некорректного значения
        {
            public TovarArgExc(string message) : base(message) { }
        }

        protected internal class TovarLessThenZero : Exception
        {
            public TovarLessThenZero(string message) : base(message) { }
        }

        protected internal class TovarOutOfRange:Exception
        {
            public TovarOutOfRange(string message) : base(message) { }
        }



    }
}
