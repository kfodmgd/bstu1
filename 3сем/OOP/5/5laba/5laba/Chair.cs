using System;
using System.Collections.Generic;
using System.Text;

namespace _5laba
{
    class Chair : Furniture
    {
        public int Arms { get; set; }
        public bool Bottom { get; set; }
        public Chair(string name, int price, int arms, bool bottom, string material, string color, string size) : base(name, price, material, color, size)
        {
            Arms = arms;
            Bottom = bottom;
        }
        //переопределение виртуального метода в производном классе
        public override void DisplayInfo()
        {
            Console.WriteLine($"Имя {Name}, материал {Material}, цвет {Color}");
        }
        public override string ToString()
        {
            return $"{this.GetType()} {Name} {Price} {Color} {Size} {Material} {Arms} {Bottom}";
        }

    }
}
