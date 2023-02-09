using System;
using System.Linq;
using System.Collections.Generic;

namespace _10laba
{
    class Program
    {
        static void Main(string[] args)
        {
            //1
            string[] months = { "Janyary", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
            int n = 5;
            Console.WriteLine("\nмесяца с длиной названия=5");
            var z1 =
                from month in months
                where month.Length == n
                select month;
            foreach(string month in z1)
            {
                Console.WriteLine(month);
            }
            Console.WriteLine("\nлетние и зимние месяцы");
            var z2 =
                from month in months
                where month == months[0] || month == months[1] || month == months[5]|| month == months[6] || month == months[7] || month == months[11]
                select month;
            foreach (string month in z2)
            {
                Console.WriteLine(month);
            }
            Console.WriteLine("\nсортировка");
            var z3 =
                from month in months
                orderby month
                select month;
            foreach(string month in z3)
            {
                Console.WriteLine(month);
            }
            Console.WriteLine("\nбуква u+длина не более 4");
            var z4 =
                from month in months
                where month.Contains('u') && month.Length >= 4
                select month;
            foreach(string month in z4)
            {
                Console.WriteLine(month);
            }

            //2
            var collection = new List<Vector>();
            var vct1 = new Vector
            {
                Mas = "1 4 5 8 7",
                Number_of_elements = 5
            };
            collection.Add(vct1);
            var vct2 = new Vector
            {
                Mas = "0 4 5",
                Number_of_elements = 3
            };
            collection.Add(vct2);
            var vct3 = new Vector
            {
                Mas = "7 8 4 0 7",
                Number_of_elements = 5
            };
            collection.Add(vct3);
            var vct4 = new Vector
            {
                Mas = "1",
                Number_of_elements = 1
            };
            collection.Add(vct4);
            var vct5 = new Vector
            {
                Mas = "1 8 7",
                Number_of_elements = 3
            };

            //3
            collection.Add(vct5);
            Console.WriteLine("\nколво векторов с 0");
            int temp = 0;
            var zero = collection.Where(
                item => item.Mas.Contains('0'));
            foreach(var item in zero)
            {
                temp++;
            }
            Console.WriteLine(temp);
            Console.WriteLine("\nмин модуль");
            int min = collection.Min(a => a.Mas.Length);
            var minimal = collection.Where(
                item => item.Number_of_elements == min).OrderBy(item => item.Number_of_elements);
            foreach(var item in minimal)
            {
                Console.WriteLine(item);
            }
            Console.WriteLine("\nколво элементов 3,5,7");
            var numElem = collection.Where(
                item=>item.Number_of_elements==3 || item.Number_of_elements ==5 || item.Number_of_elements ==7
                );
            foreach(var item in collection)
            {
                Console.WriteLine(item);
            }
            Console.WriteLine("\nупорядоченные по размеру");
            var sortSize = collection.OrderBy(
                item=>item.Number_of_elements
                );
            foreach(var item in sortSize)
            {
                Console.WriteLine(item);
            }

            //4
            var collection1 = new List<Vector>();
            var vct6 = new Vector
            {
                Mas = "1 4 5 8 7",
                Number_of_elements = 5,
                State_variable = 1,
                Id = 1
            };
            collection1.Add(vct6);
            var vct7 = new Vector
            {
                Mas = "1 0 7",
                Number_of_elements = 3,
                State_variable = 0,
                Id = 2
            };
            collection1.Add(vct7);
            var vct8 = new Vector
            {
                Mas = "1",
                Number_of_elements = 1,
                State_variable = 1,
                Id = 3
            };
            collection1.Add(vct8);
            var vct9 = new Vector
            {
                Mas = "1 4 11 8 7",
                Number_of_elements = 5,
                State_variable = 0,
                Id = 4
            };
            collection1.Add(vct9);
            Console.WriteLine("\n\nоператоры");
            int min1 = collection1.Min(a => a.Mas.Length);
            var tsk4 = (from i in collection1
                        orderby i.Number_of_elements
                        where i.Id>1
                        where i.Mas.StartsWith('1')
                        where i.Number_of_elements>min1
                        group  i by i.Id);
            foreach(var item in collection1)
            {
                Console.WriteLine(item);
            }

            //join
            var res = from col in collection
                      join col1 in collection1
                      on col.Number_of_elements equals col1.Number_of_elements
                      select new { Number_of_elements = col.Number_of_elements, Mas = col.Mas };
            foreach(var item in res)
            {
                Console.WriteLine($"{item.Number_of_elements}-{item.Mas}");
            }




        }
    }
}
