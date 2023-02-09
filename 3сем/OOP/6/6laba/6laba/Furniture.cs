using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;//debug

namespace _6laba
{
    class Furniture : Tovar
    {
        private string color;
        public string Color
        {
            get
            {
                return color;
            }
            set
            {
                if (color == "прозрачный")
                {
                    throw new Exeptions.TovarArgExc("Неверное значение");
                }
                else
                {
                    color = value;
                }
            }
        }
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
        public static void MyMethod(string mat)
        {
            Debug.Assert(mat == "кожа", "материал не кожа");
        }

    }
}
