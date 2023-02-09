using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _9laba
{
    internal class Services
    {
        public string title;
        public string description;
        public int price;

        public Services(string title, string description, int price)
        {
            this.title = title;
            this.description = description;
            this.price = price;
        }

        public override string ToString()
        {
            return ($"\nНазвание услуги: {title} \nОписание: {description} \nЦена:{Convert.ToString(price)}");
        }

    }
}
