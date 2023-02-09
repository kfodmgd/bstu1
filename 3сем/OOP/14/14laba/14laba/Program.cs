using System;
using System.Reflection;
using System.Diagnostics;
using System.Threading;
using System.IO;

// Процесс — экземпляр программы во время выполнения, независимый объект,
//которому выделены системные ресурсы (например, процессорное время и память).

// Поток — определенный способ выполнения процесса. Когда один поток изменяет ресурс процесса,
//это изменение сразу же становится видно другим потокам этого процесса.

// В .NET исполняемые файлы не обслуживаются прямо внутри процесса Windows.
//Они обслуживаются в отдельном логическом разделе внутри процесса,
//который называется доменом приложения (Application Domain — AppDomain). 
//В процессе может содержаться несколько доменов приложений.
namespace _14laba
{
    class Program
    {
        //3
        static void WriteNums(object num)
        {
            int n = (int)num;
            using (StreamWriter sw =new StreamWriter("nums.txt", false, System.Text.Encoding.Default))
            {
                for(int i = 0; i < n; i++)
                {
                    sw.WriteLine(i);
                    Console.WriteLine(i);
                    Thread.Sleep(500);
                }
            }
        }


        //4 odd
        public static void OddNumbers(object num)
        {
            int n = (int)num;
            using (StreamWriter sw = new StreamWriter("numbersOdd.txt", false, System.Text.Encoding.Default))
            {
                for (int i = 0; i <= n; i++)
                {
                    if (i % 2 != 0)
                    {
                        sw.WriteLine(i);
                        Console.Write($"{i} ");
                        Thread.Sleep(120);
                    }
                }
            }
        }
        //even
        public static void EvenNumbers(object num)
        {
            int n = (int)num;
            using (StreamWriter sw = new StreamWriter("numbersEven.txt", true, System.Text.Encoding.Default))
            {
                for (int i = 0; i <= n; i++)
                {
                    if (i % 2 == 0)
                    {
                        sw.WriteLine(i);
                        Console.Write($"{i} ");
                        Thread.Sleep(120);
                    }
                }
            }
        }


        static void Main(string[] args)
        {
            //1 process
            Process[] proc = Process.GetProcesses();
            foreach(Process p in proc)
            {
                try
                {
                    Console.WriteLine("Id процесса: " + p.Id.ToString());
                    Console.WriteLine("Name процесса: " + p.ProcessName);
                    Console.WriteLine("Prioritet процесса: " + p.BasePriority.ToString());
                    Console.WriteLine("Власс приоритета процесса: " + p.PriorityClass.ToString());
                    Console.WriteLine("Время запуска процесса: " + p.StartTime.ToString());
                    Console.WriteLine("Время использования процессором: " + p.TotalProcessorTime.ToString());
                    if(p.StartTime.ToString()!=null)
                        Console.WriteLine("Состояние: запущен");
                    Console.WriteLine();
                }
                catch
                {
                    Console.WriteLine("ERROR");
                }
            }


            //2 domain
            AppDomain domain = AppDomain.CurrentDomain;
            Console.WriteLine($"Имя домена: {domain.FriendlyName}");
            Console.WriteLine($"Базовая директория: {domain.BaseDirectory}");
            Console.WriteLine($"Информация: {domain.SetupInformation}");
            Console.WriteLine();
            Assembly buf = null;
            foreach (Assembly x in domain.GetAssemblies())
            {
                Console.WriteLine(x.GetName().Name);
            }
            //AppDomain myNewDomain = AppDomain.CreateDomain("Мой новый домен");
            //Assembly buf2 = myNewDomain.Load(buf.GetName());---загрузка
            //AppDomain.Unload(myNewDomain);---выгрузка
            //Console.WriteLine(buf2.ToString());


            //3
            int n;
            bool check;
            Console.WriteLine("введите n");
            n = Convert.ToInt32(Console.ReadLine());
            Thread NumberThread = new Thread(new ParameterizedThreadStart(WriteNums));//создание потока
            Thread.Sleep(500);
            NumberThread.Start(n);//запуск
            Thread.Sleep(500);
            Console.WriteLine("\n");
            Console.WriteLine("Приоритет:   " + NumberThread.Priority);
            Thread.Sleep(100);
            Console.WriteLine("Имя потока:  " + NumberThread.Name);
            Thread.Sleep(100);
            Console.WriteLine("ID потока:   " + NumberThread.ManagedThreadId);


            //4
            //2 потока, один чётн, другой-неч
            Console.WriteLine("2 потока с чётн и нечётн");
            Console.WriteLine("введите n");
            n = Convert.ToInt32(Console.ReadLine());
            Thread threadE, threadO;
            threadE = new Thread(EvenNumbers);
            threadE.Priority = ThreadPriority.AboveNormal;//приоритет
            threadE.Start(n);
            //threadE.Join();//чётн потом неч

            Console.WriteLine();
            threadO = new Thread(OddNumbers);
            threadO.Priority = ThreadPriority.BelowNormal;
            threadO.Start(n);
            //threadO.Join();//чередование
            Console.WriteLine("END");


            //5
            TimerCallback timerCallback = new TimerCallback(WhatTimeIsIt);
            // позволяет запускать определенные действия по истечению некоторого периода времени:
            Timer timer = new Timer(timerCallback, null, 500, 1000);       /* null - параметр, которого нет, 500 - время, через которое запустится процесс с таймером, 
                                                                            * 1000 - периодичность таймера (интервал между вызовами метода делегата). */
            Thread.Sleep(5000);                                             // 500 - ждем и не закрываем поток
            timer.Change(Timeout.Infinite, 2000);                           // уничтожение таймера

            void WhatTimeIsIt(object obj)
            {
                Console.WriteLine($"It's {DateTime.Now.Hour}:{DateTime.Now.Minute}:{DateTime.Now.Second}");
            }
        }
    }
}
