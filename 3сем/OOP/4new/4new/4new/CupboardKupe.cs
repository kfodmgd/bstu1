using System;
using System.Collections.Generic;
using System.Text;

namespace _4new
{
    class CupboardKupe:Cupboard
    {
        public int Height { get; set; }
        public int NumOfPol { get; set; }
        public CupboardKupe(string name, int price, string size, string color, string material, int numdoors, int height, int numofpol):base(name, price, size, color, material, numdoors)
        {
            Height = height;
            NumOfPol = numofpol;
        }
        //переопределение виртуального метода в производном классе
        public override void DisplayInfo()
        {
            Console.WriteLine($"Имя {Name}, материал {Material}, цвет {Color},высота {Height}, количество полок {NumOfPol}");
        }
        public override string ToString()
        {
            return $"{this.GetType()} {Name} {Price} {Color} {Size} {Material} {NumDoors} {Height} {NumOfPol}";
        }

    }
}
