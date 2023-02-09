using System;

namespace _8laba
{
    class Program
    {
        public delegate int Lamb(int a, int b);

        static void Main(string[] args)
        {
            // обработчики событий
            static void DisplayGreenMessage(string message)
            {
                // Устанавливаем красный цвет символов
                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine(message);
                Console.ResetColor();
            }
            static void DisplayRedMessage(String message)
            {
                // Устанавливаем красный цвет символов
                Console.ForegroundColor = ConsoleColor.Red;
                Console.WriteLine(message);
                Console.ResetColor();
            }


            User u1 = new User(35, "u1");
            User u2 = new User(120, "u2");
            User u3 = new User(87, "u3");
            User u4 = new User(11, "u4");
            User u5 = new User(97, "u5");

            Console.WriteLine(u1.ToString());
            u1.Say += DisplayGreenMessage;
            u1.Smesh(15);
            u1.Say -= DisplayGreenMessage;
            Console.WriteLine(u1.ToString());
            Console.WriteLine(u2.ToString());

            u2.Say += DisplayGreenMessage;
            u2.Smesh(8);
            u2.Say -= DisplayGreenMessage;
            Console.WriteLine(u2.ToString());
            Console.WriteLine(u3.ToString());

            u3.Say += DisplayGreenMessage;
            u3.Squizee(15);
            u3.Say -= DisplayGreenMessage;
            Console.WriteLine(u3.ToString());

            Console.WriteLine(u4.ToString());
            u4.Say += DisplayRedMessage;
            u4.Smesh(18);
            u4.Say -= DisplayRedMessage;
            Console.WriteLine(u4.ToString());

            Console.WriteLine(u5.ToString());
            u5.Say += DisplayGreenMessage;
            u5.Smesh(15);
            u5.Say -= DisplayGreenMessage;
            Console.WriteLine(u5.ToString());
            u5.Say += DisplayRedMessage;
            u5.Squizee(10);
            u5.Say -= DisplayRedMessage;
            Console.WriteLine(u5.ToString());
            //лямбда
            Console.WriteLine("сумма озиций 1 и 2");
            Lamb sum = (a, b) => a + b;
            Console.WriteLine(sum(u1.Position, u2.Position));

            string test = "asd KJFSdgh,fj JSDFBfzsd dfshza";
            // Делегат Action является обобщенным, принимает параметры (от 0 до 16) и возвращает значение void
            // Делегат Predicate<T> используется для сравнения, сопоставления некоторого объекта T определенному условию.
            // Делегат Func возвращает результат действия и может принимать параметры. Также часто используется в качестве параметра в методах
            Action<string> Oper1 = Str.Low;
            Action<string, char> Oper2 = Str.Add;
            Func<string, string> Oper3 = Str.Up;
            Oper1(test);
            Oper2(test, '0');
            Console.WriteLine(Oper3(test));

        }
    }
}
