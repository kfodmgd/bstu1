using System;
using System.Collections.Generic;
using System.Text;

namespace _5laba
{
    sealed class Hanger : Tovar
    {
        public string Material { get; set; }
        public Hanger(string name, int price, string material) : base(name, price)
        {
            Material = material;
        }
        //переопределение виртуального метода в производном классе
        public override void DisplayInfo()
        {
            Console.WriteLine($"Имя {Name}, материал {Material}");
        }
        public override string ToString()
        {
            return $"{this.GetType()} {Name} {Price} {Material}";
        }

        public override void boxName()
        {
            throw new NotImplementedException();
        }
    }
}
