using System;
using System.Collections.Generic;
using System.Text;

namespace _4new
{
    class Cupboard : Furniture
    {
        Hanger hanger1;
        public int NumDoors { get; set; }
        public Cupboard(string name, int price, string size, string color, string material, int numdoors) : base(name, price, size, color, material)
        {
            NumDoors = numdoors;
            hanger1 = new Hanger(name, price, material);
            hanger1 = new Hanger("Деревянная вешалка",14,"дерево");
        }
        //переопределение виртуального метода в производном классе
        public override void DisplayInfo()
        {
            Console.WriteLine($"Имя {Name}, материал {Material}, цвет {Color}");
        }
        public override string ToString()
        {
            return $"{this.GetType()} {Name} {Price} {Color} {Size} {Material} {NumDoors}";
        }


    }
}
