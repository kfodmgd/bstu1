using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using System.Collections.Concurrent;
using System.Diagnostics;
using System.Linq;
using System.Threading;
using System.Runtime.CompilerServices;

namespace _15laba
{
    class Program
    {
        public static BlockingCollection<string> bc;//7TASK

        //1
        //решето эратосфена
        public static void First()
        {
            int n = 1000;
            Console.WriteLine("Текущий ID таска: " + Task.CurrentId.ToString());
            var numbers = new List<uint>();
            // Заполнение списка numbers числами от 2 до n-1
            for (var i = 2u; i < n; i++)
            {
                numbers.Add(i);
            }
            for (var i = 0; i < numbers.Count; i++)
            {
                for (var j = 2u; j < n; j++)
                {
                    numbers.Remove(numbers[i] * j);
                }
            }
            foreach (int a in numbers)
            {
                Console.WriteLine(a);
            }
        }

        //3
        //3 функции с возвратом значения для вставки значений в 4 функцию
        public static int Rnd10()
        {
            Random rndm = new Random();
            return rndm.Next(10);
        }
        public static int Rnd20()
        {
            Random rndm = new Random();
            return rndm.Next(20);
        }
        public static int Rnd30()
        {
            Random rndm = new Random();
            return rndm.Next(30);
        }
        //4 функция, использующая резы 3 выше
        public static int TotalVal(int value1, int value2, int value3)
        {
            return (value1 + value2 + value3) / 3;
        }

        
        //7
        public static void AddProduct()
        {
            Random r = new Random();
            int x;
            List<string> products = new List<string>() { "Ёлка", "Гирлянда", "Шоколадка", "Шампанское", "Мандарины" };
            for (int i = 0; i < 5; i++)
            {
                x = r.Next(0, products.Count - 1);
                Console.WriteLine("Добавлен товар: " + products[x]);
                bc.Add(products[x]);
                products.RemoveAt(x);
                Thread.Sleep(r.Next(1, 3));
            }
            bc.CompleteAdding();
        }
        public static void PurchasedProduct()
        {
            string str;
            while (bc.IsAddingCompleted == false)
            {
                if (bc.TryTake(out str) == true)
                    Console.WriteLine("Был куплен товар: " + str);
                if (bc.TryTake(out str) != true)
                    Console.WriteLine("Покупатель ушел.");
            }
        }


        //8
        //async function
        public static void ForAsync()
        {
            for (int i = 0; i < 30; i++)
                if (i % 3 == 0)
                {
                    Console.Write(i + ", ");
                    Thread.Sleep(1000);
                }
        }
        public static async void Async()
        {
            Console.WriteLine("Асинхронная функция:");
            await Task.Run(() => ForAsync());
            Console.WriteLine("Готово!");
        }



        static void Main(string[] args)
        {
            //1
            //поиск простых чисел (желательно взять «решето Эратосфена»)
            Stopwatch sw = new Stopwatch();//измерение затраченного времени
            sw.Start();
            Task task = new Task(() => First());
            task.Start();
            Console.WriteLine($"ID: {task.Id}, статус: {task.Status}");
            task.Wait();
            Console.WriteLine($"ID: {task.Id}, статус: {task.Status}");
            sw.Stop();
            Console.WriteLine($"Производительность: {sw.ElapsedMilliseconds}ms");
            Console.WriteLine();


            //2
            //та же задача, что в первом, но с токеном отмены
            CancellationTokenSource cancellation = new CancellationTokenSource();
            Task task1 = Task.Run(() => First(), cancellation.Token);
            try
            {
                cancellation.Cancel();
                Console.WriteLine("сработал токен отмены");
            }
            catch(Exception)
            {
                if (task1.IsCanceled)
                    Console.WriteLine("ОТМЕНЕНО ERR");
            }


            //3
            //3 задачи для решения 4ой задачи
            Task<int> task2 = new Task<int>(Rnd10);
            Task<int> task3 = new Task<int>(Rnd20);
            Task<int> task4 = new Task<int>(Rnd30);
            task2.Start();
            task3.Start();
            task4.Start();
            Task<int> total = new Task<int>(()=>TotalVal(task2.Result,task3.Result,task4.Result));
            Console.WriteLine("ЗНАЧЕНИЯ: " + task2.Result + ' ' + task3.Result + ' ' + task4.Result);
            total.Start();
            Console.WriteLine("РЕЗУЛЬТАТ: " + total.Result);


            //4
            //continuation task
            Console.WriteLine("\ncontinuation task");
            //ожидание завершения предшествующих задач
            Task<int> conTask2 = new Task<int>(Rnd10);
            Task<int> conTask3 = new Task<int>(Rnd20);
            Task<int> conTask4 = new Task<int>(Rnd30);
            Task<int> conTotal = conTask4.ContinueWith((taskN)=>TotalVal(task2.Result, task3.Result, task4.Result));
            conTask2.Start();
            conTask3.Start();
            conTask4.Start();
            Console.WriteLine("ожидание завершения: "+conTotal.Result);
            conTask2.Dispose();

            //ожидание
            Console.WriteLine("Ожидающий");
            Random rnd = new Random();
            Task<int> wait = new Task<int>(() => rnd.Next(51));
            TaskAwaiter<int> awaiter = wait.GetAwaiter();
            awaiter.OnCompleted(() => Console.WriteLine("Res: "+wait.Result));
            wait.Start();
            wait.Wait();
            awaiter.GetResult();
            Thread.Sleep(500);


            //5
            //parallel
            Stopwatch stW = new Stopwatch();
            int[] arr1 = new int[10000000];
            int[] arr2 = new int[10000000];
            Random random = new Random();
            stW.Restart();
            for (int i = 0; i < arr1.Length; i++)
            {
                arr1[i] = random.Next(0, 300);
                arr2[i] = random.Next(0, 300);
            }
            stW.Stop();
            Console.WriteLine("For: " + stW.Elapsed);
            stW.Restart();
            Parallel.For(0, arr1.Length, i =>
            {
                arr1[i] = random.Next(0, 300);
                arr2[i] = random.Next(0, 300);
            });
            stW.Stop();
            Console.WriteLine("Параллельный for: " + stW.Elapsed);
            stW.Restart();
            Parallel.ForEach<int>(arr1, i =>
            {
                arr1[i] = random.Next(0, 300);
                arr2[i] = random.Next(0, 300);
            });
            stW.Stop();
            Console.WriteLine("Параллельный foreach: " + stW.Elapsed);


            //6
            //parallel.invoke
            Parallel.Invoke(() =>
            {
                for (int i = 0; i < 10; i++)
                {
                    Console.WriteLine("Параллельное выполнение блока 1 - " + i);
                }

                Console.WriteLine("1 готов!");
            },
            () =>
            {
                for (int i = 0; i < 10; i++)
                {
                    Console.WriteLine("Параллельное выполнение 2 - " + i);
                }

                Console.WriteLine("2 готов!");
            });


            //7
            //blockingCollection
           
            // Коллекция, которая осуществляет блокировку и ожидает, пока не появится возможность
            // выполнить действие по добавлению или извлечению элемента
            bc = new BlockingCollection<string>(5);
            Task Shop = new Task(AddProduct);
            Task Clients = new Task(PurchasedProduct);
            Shop.Start();
            Clients.Start();
            Shop.Wait();
            Clients.Wait();


            //8
            //async await
            // Tpl – библиотека параллельных задач.
            // Task –данный класс описывает отдельную задачу, которая запускается асинхронно
            //в одном из потоков пула потоков.
            Async();
            Console.ReadKey();


        }
    }
}
