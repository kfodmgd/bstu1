using System;
using System.Collections.Generic;
using System.Text;

namespace _5laba
{
    partial class Sofa
    {
        public override string ToString()
        {
            return $"{this.GetType()} {Name} {Price} {Color} {Size} {Material} {NumPpl}";
        }

    }
}
