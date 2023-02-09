using System;
using System.Collections.Generic;
using System.Text;

namespace _6laba
{
    class Chair : Furniture
    {
        private int arms;
        public int Arms 
        {
            get 
            {
                return arms;
            }
            set 
            {
                if (arms < 0){
                    throw new Exeptions.TovarLessThenZero("Значение меньше");
                }
                else
                {
                    arms = value;
                }
            }
        }
        public bool? Bottom { get; set; }
        public Chair(string name, int price, int arms, bool? bottom, string material, string color, string size) : base(name, price, material, color, size)
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
