using System;
using System.Collections.Generic;
using System.Text;

namespace _5laba
{
    class Sklad
    {
        public List<Furniture> ListOfTovar { get; set; } = new List<Furniture>();
        public string Name { get; set; }
        public Sklad(string name,params Furniture[] tovars)
        {
            Name = name;
            foreach(Furniture A in tovars)
            {
                ListOfTovar.Add(A);
            }
        }
        public Sklad()
        {
            Name = "Default";
        }

        public void AddTovar(Furniture A)
        {
            ListOfTovar.Add(A);
        }
        public void DeleteTovar(Furniture A)
        {
            ListOfTovar.Remove(A);
        }
        public void GetInfo()
        {
            foreach(var a in ListOfTovar)
            {
                Console.WriteLine(a);
            }
        }
    }
}
