using System;
using System.Collections.Generic;
using System.Text;

namespace _5laba
{
    abstract class Tovar
    {
        public string Name { get; set; }
        public int Price { get; set; }
        public Tovar(string name, int price)
        {
            Name = name;
            Price = price;
        }

        //виртуальный метод
        virtual public void DisplayInfo()
        {
            Console.WriteLine($"Имя {Name}, цена {Price}");
        }
        public override string ToString()
        {
            return $"{this.GetType()} {Name} {Price}";
        }
        public abstract void boxName();
        public Tovar()
        {

        }

    }
}
