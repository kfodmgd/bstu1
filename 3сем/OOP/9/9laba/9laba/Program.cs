using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections.ObjectModel;
using System.Collections;
using System.Collections.Concurrent;
using System.Collections.Specialized;

namespace _9laba
{
    class Programm 
    {
        static void Main( string[] args )
        {
            //Создайте класс по варианту, определите в нем свойства и методы, реализуйте указанный интерфейс

            Services serv1 = new Services("Чистка ноутбуков и компьюторов", "Чистка от вирусов, проверка ноутбука на работоспособность", 80);
            Services serv2 = new Services("Ремонт телефонов Apple", "Ремонт телефонов,замена комплектующих, замена батереи, смена защитного стекла", 100);
            Services serv3 = new Services("Ремонт электронных книг", "Ремонт электронных книг любых моделей",40);

            CollectionQueue coll = new CollectionQueue();

            coll.Add("Чистка ноутбуков и компьюторов", serv1);
            coll.Add("Ремонт телефонов Apple", serv2);
            coll.Add("Ремонт электронных книг", serv3);


            Console.WriteLine("\tКлючи коллекции: ");
            foreach (var i in coll.Keys)
            { 
                Console.WriteLine(i);
            }

            Console.WriteLine("\n\tПолные значения коллекции:");
            foreach (var i in coll.Values)
            { 
                Console.WriteLine(i); 
            }

            coll.Remove("Ремонт электронных книг");
            Console.WriteLine("\n\tОчередь после удаления одной услуги");
            foreach (string i in coll.Keys)
                Console.WriteLine(i);
            Console.WriteLine("\n" + coll[1]);
            Console.WriteLine("\nЕсть услуга 'Чистка ноутбуков и компьюторов'" + coll.Contains("Чистка ноутбуков и компьюторов"));
            Console.WriteLine("\nЕсть услуга 'Ремонт электронных книг'" + coll.Contains("Ремонт электронных книг"));


            // Создайте универсальную коллекцию 

             Queue<int> q1 = new Queue<int>();
            q1.Enqueue(0);
            q1.Enqueue(3);
            q1.Enqueue(123131);
            q1.Enqueue(114);
            q1.Enqueue(31);
            q1.Enqueue(1);

            Console.WriteLine("\nКоллекция Queue<int> содержит:");
            foreach(var el in q1)
            {
                Console.WriteLine(el);
            }


            Console.WriteLine("\nВведите число n для удаления элементов");
            int n = Convert.ToInt32(Console.ReadLine());

            for (int i = 0; i < n; i++)
            {
                q1.Dequeue();//извлекает и возвращает первый элемент очереди

                if (q1.Count <= 0)
                {
                    Console.WriteLine("Очередь пуста!");
                    break;
                }
            }

            Console.WriteLine($"\nКоллекция Queue<int> после удаления {n} элементов:") ;
            foreach (var el in q1)
            {
                Console.WriteLine(el);
            }

            Console.WriteLine("Коллекцмя Stack:");
            var st = new Stack(q1);
            foreach (var el in st)
            {
                Console.WriteLine(el);
            }
            Console.WriteLine();
            Console.WriteLine("444? "+st.Contains(444));
            Console.WriteLine("114? " + st.Contains(114));


            //объект наблюдаемой коллекции

            var myCollection = new ObservableCollection<Services>(); // пользовательский интерфейс получает информацию об изменениях коллекции
            Services services4 = new Services("Замена корпуса", "Замена корпуса ПК", 99);
            Console.WriteLine("\nРабота с ObservableCollection<T>:");

            myCollection.CollectionChanged += CollectionChanged;
            myCollection.Add(services4);
            myCollection.Remove(services4);

        }


        private static void CollectionChanged( object sender, NotifyCollectionChangedEventArgs e )//Предоставляет данные о событии CollectionChanged.
        {
            switch (e.Action)
            {
                case NotifyCollectionChangedAction.Add:
                    Console.WriteLine($"Добавлен новый элемент");
                    break;

                case NotifyCollectionChangedAction.Remove:
                    Console.WriteLine($"Удален элемент");
                    break;
            }
        }



    }

 }
    
