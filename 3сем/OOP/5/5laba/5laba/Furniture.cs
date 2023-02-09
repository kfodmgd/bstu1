using System;
using System.Collections.Generic;
using System.Text;

namespace _5laba
{
    class Furniture : Tovar
    {
        public string Color { get; set; }
        public string Size { get; set; }
        public string Material { get; set; }
        public Furniture(string name, int price, string color, string size, string material) : base(name, price)
        {
            Color = color;
            Size = size;
            Material = material;
        }
        //переопределение виртуального метода в производном классе
        public override void DisplayInfo()
        {
            Console.WriteLine($"Имя {Name}, материал {Material}, цвет {Color}");
        }
        public override string ToString()
        {
            return $"{this.GetType()} {Name} {Price} {Color} {Size} {Material}";
        }

        public override void boxName()
        {
            throw new NotImplementedException();
        }
    }
}
