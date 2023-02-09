using System;
using System.Collections.Generic;
using System.Text;

namespace _6laba
{
    class Bed : Furniture
    {
        enum MyEnum
        {
            Red = 1,
            Apple,
            LingtApple,
            RedTree,
            WhiteYellow,
            DarkOak,
            Oak
        }
        public struct Customer
        {
            private string NameCust { get; set; }
            private int NumberCust { get; set; }
            private string DateCust { get; set; }

            public Customer(string nameCust, int numberCust, string dateCust)
            {
                this.NameCust = nameCust;
                this.NumberCust = numberCust;
                this.DateCust = dateCust;
            }

            public void PrintInfoStr()
            {
                Console.WriteLine($"имя:{NameCust}, номер:{NumberCust}, дата:{DateCust}");
            }
        }      

        public int NumPpl { get; set; }
        public Bed(string name, int price, string size, string color, string material, int numppl) : base(name, price, size, color, material)
        {
            NumPpl = numppl;
        }
        //переопределение виртуального метода в производном классе
        public override void DisplayInfo()
        {
            Console.WriteLine($"Имя {Name}, материал {Material}, цвет {Color}");
        }
        public override string ToString()
        {
            return $"{this.GetType()} {Name} {Price} {Color} {Size} {Material} {NumPpl}";
        }
        
    }
}
