using System;
using System.Collections.Generic;
using System.Text;

namespace _4new
{
    class theSameNameMethods: Tovar,InterfaceMethods
    {
        void InterfaceMethods.boxName()
        {
            Console.WriteLine("----interface----");
        }
        public override void boxName()
        {
            Console.WriteLine("----method from class-----");
        }
    }
}
