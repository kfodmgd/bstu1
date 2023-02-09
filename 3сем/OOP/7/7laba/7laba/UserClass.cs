using System;
using System.Collections.Generic;
using System.Text;

namespace _7laba
{
    public class Tovar<T>
    {
        public string Name { get; set; }
        public T Price { get; set; }
        public Tovar(string name, T price)
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
        public Tovar()
        {

        }
        public void Test<T>(Tovar<T> tov)
        {            
            Console.WriteLine("Параметр обобщённый класс");
            Console.WriteLine("Имя:"+tov.Name);
            Console.WriteLine("Цена:"+tov.Price);
        }
    }
}
