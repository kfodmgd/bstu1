using System;
using System.Collections.Generic;
using System.Text;
using System.Xml.Serialization;
using System.Xml;

namespace _13laba
{
    [Serializable]
    public class Group
    {
        private List<Tovar> units = new List<Tovar>();
        [NonSerialized] private int count;
        public Group()
        {

        }
        public int Count => units.Count;
        public List<Tovar> ListTov
        {
            get;set;
        }
        public void Add(Tovar tov)
        {
            Tovar temp = tov;
            units.Add(temp);
        }
        public void Remove(Tovar tov)
        {
            Tovar temp = tov;
            units.Remove(temp);
        }
        public void Print()
        {
            Tovar[] arr = units.ToArray();
            for(int i = 0; i < arr.Length; i++)
            {
                Console.WriteLine((i + 1).ToString() + ' ' + arr[i].ToString());
            }
        }

    }
}
