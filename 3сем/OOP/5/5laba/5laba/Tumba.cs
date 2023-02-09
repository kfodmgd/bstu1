using System;
using System.Collections.Generic;
using System.Text;

namespace _5laba
{
    class Tumba:Furniture
    {
        public int Height;
        public int NumOfPol;
        public int Wigth;
        public Tumba(string name, int price, string material, string color, string size, int height,int numofpol,int width) :base(name, price, material, color, size)
        {
            Height = height;
            NumOfPol = numofpol;
            Wigth = width;
        }
        public override void DisplayInfo()
        {
            Console.WriteLine($"Имя {Name}, материал {Material}, цвет {Color}");
        }
        public override string ToString()
        {
            return $"{this.GetType()} {Name} {Price} {Color} {Size} {Material} {Height} {NumOfPol} {Wigth}";
        }
    }
}
