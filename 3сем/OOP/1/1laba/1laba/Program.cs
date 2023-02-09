using System;
using System.Text;//for StringBuilder

namespace _1laba
{
    class Program
    {
        static void Main(string[] args)
        {
            //переменные примитивных типов
            sbyte tSbyte = -32;
            short tShort = 132;
            int tInt = 52;
            long tLong = 1745;
            byte tByte = 10;
            ushort tUshort = 102;
            uint tUint = 15;
            ulong tUlong = 14985;
            char tChar = 'A';
            bool tBool = true;
            float tFloat = 2.45f;
            double tDouble = 4.72;
            decimal tDecimal = 7.14m;
            string tString = "abc";
            object tObject = 315;

            //неявное приведение
            tLong = tInt;
            tInt = tShort;
            tUlong = tUint;
            tUint = tUshort;
            tInt = tByte;

            //явное
            tByte = (Byte)tSbyte;
            tFloat = (Single)tDouble;
            tDouble = (Double)tDecimal;
            tShort = (Int16)tUshort;
            tUint = (UInt32)tUshort;

            //возможности класса Convert
            int first;
            double second;
            first = Convert.ToInt32("44");
            second = Convert.ToDouble(tBool);
            Console.WriteLine($"возможности класса Convert\nfirst={first} second={second}\n");

            //упаковка значимых типов
            Int32 x = 15;
            Object obj = x;

            //распаковка
            byte b = (byte)(int)obj;

            //работа с неявно типизированной переменной
            var massiv1 = new[] { 1, 3, 5, 7, 9 };
            var massiv2 = new[] { 'a', 'b', 'c', 'd', 'e' };
            var massiv3 = new[] { 1, 1.11 };
            Console.WriteLine(massiv1.GetType());
            Console.WriteLine(massiv2.GetType());
            Console.WriteLine(massiv3.GetType());
            Console.WriteLine("");

            //nullable
            int? i = null;
            Console.Write("check is i a null ");
            Console.WriteLine(i == null);
            Console.WriteLine("");

            //var
            var check = 6544;
            //check = "hello";//не удаётся неявно преобразовать тип string в int

            //строки
            String str1 = "abc";
            String str2 = "Hello";
            //сравнение
            Console.Write("str1 and str2 are ");
            Console.WriteLine(str1.Equals(str2));
            Console.WriteLine("");

            //сцепление
            String st1 = "abc";
            String st2 = "Hello";
            String st3 = "World";
            String phrase = "something may happend soon";
            Console.Write("Сцепление:");
            Console.WriteLine(String.Concat(st2, st3));
            //копирование
            String st1copy = String.Copy(st1);
            Console.Write("Копирование:");
            Console.WriteLine(st1copy);
            //выделение подстроки
            String substr = st2.Substring(1, 3);
            Console.Write("Подстрока:");
            Console.WriteLine(substr);
            //разделение на слова
            string[] words = phrase.Split(' ');
            Console.Write("Разделение на слова:");
            foreach (var word in words)
            {
                Console.WriteLine($"{word}");
            }
            //вставка подстроки в опред позицию
            Console.Write("Вставка подстроки");
            Console.WriteLine(st3.Insert(3, "-"));
            //удаление подстроки
            Console.Write("Удаление подстроки");
            Console.WriteLine(st3.Remove(3));
            //интерполяция строк
            Console.Write("Интерполяция:");
            Console.WriteLine($"1-st word: {st2}, 2-nd word: {st3}");

            //string.IsNullOrEmpty
            string emptyStr = "";
            String nullStr = null;
            Console.Write("Проверки строка пустая или null:");
            Console.WriteLine(string.IsNullOrEmpty(emptyStr));
            Console.WriteLine(string.IsNullOrEmpty(nullStr));
            //что можно делать со строкой null
            Console.Write("Объединение:");
            Console.WriteLine(String.Concat(st1, nullStr));
            Console.Write("Сравнение:");
            Console.WriteLine(str1.Equals(nullStr));

            //StringBuilder
            //Инициализируем строкой ABC
            StringBuilder sb = new StringBuilder("ABC", 50);
            Console.WriteLine(sb);

            //Удалите определенные позиции
            sb.Remove(1, 1);
            Console.WriteLine(sb);

            //добавьте новые символы
            //в начало
            sb.Insert(0, "Alphabet: ");
            Console.WriteLine(sb);

            //и конец строки
            sb.Append(new char[] { 'D', 'E', 'F' });
            Console.WriteLine(sb);

            //массив
            //двумерный массив
            int[,] mas = new int[2, 3]
                {
                    { 1, 3, 5, },
                    { 2, 4, 6, },
                };
            Console.WriteLine("Двумерный массив");
            for (int y = 0; y < 2; y++)
            {
                for (int k = 0; k < 3; k++)
                {
                    Console.Write(mas[y, k] + "\t");
                }
                Console.WriteLine();
            }

            //одномерный массив
            String[] masStr = new String[] { "create", "new", "string", "array", "ehe" };
            Console.WriteLine($"размер массива строк: {masStr.Length}");
            foreach(var iStr in masStr)
            {
                Console.WriteLine($"{iStr}");
            }
            masStr[0] = "change";
            Console.WriteLine("Изменённый элемент:");
            foreach (var iStr in masStr)
            {
                Console.WriteLine($"{iStr}");
            }

            //ступенчатый массив
            Console.WriteLine("\nСтупенчатый массив:");
            double[][] stepArr =new double[3][];
            stepArr[0] = new double[2];
            stepArr[1] = new double[3];
            stepArr[2] = new double[4];
            for (int y = 0; y < 3; y++)
            {
                for(int z = 0; z < stepArr[y].Length; z++)
                {
                    stepArr[y][z] = Convert.ToDouble(Console.ReadLine());//через запятую
                }
            }
            foreach(double[] element in stepArr)
            {
                foreach(double element2 in element)
                {
                    Console.Write($"{element2} ");
                }
                Console.WriteLine();
            }

            //неявно типизированные переменные для хранения массива и строки
            var arr1 = new[] { "create", "new", "string", "array" };

            //кортежи
            (int, string, char, string, ulong) myTuple = (19,"Hello",'m',"World",35ul);
            Console.WriteLine($"Вывод всего кортежа:{myTuple}");
            Console.WriteLine($"Вывод некоторых элементов:{myTuple.Item1}, {myTuple.Item3}, {myTuple.Item4}");

            //распаковка кортежа
            Tuple<int, string, char, string, ulong> Method()
            {
                return Tuple.Create(39, "abc", 'b', "qwerty", 20ul);
            }
            Console.WriteLine("Пример элемента из распакованного кортежа:\t");
            Console.WriteLine($"Item 1: {Method().Item1}");


            //сравнение два кортежа
            var firstTuple = Tuple.Create(3, 9);
            var secondTuple = Tuple.Create(9, 3);
            ((IComparable)firstTuple).CompareTo(secondTuple);

            //локальная функция
            static Tuple<int,int,int,char> LocalFunc(int[] intArr, string str)
            {
                int len = intArr.Length;
                int sum = 0;
                int min = intArr[0];
                int max = intArr[0];
                for (int i = 0; i < len; i++)
                {
                    sum = sum + intArr[i];
                    if (intArr[i] < min)
                    {
                        min = intArr[i];
                    }
                    if (intArr[i] > max)
                    {
                        max = intArr[i];
                    }
                }
                return Tuple.Create<int,int,int,char>(max,min,sum,str[0]);
            }
            int[] intArr = new int[] { 5,20,8,6 };
            string strCheck = "imagination";
            Console.WriteLine($"{LocalFunc(intArr, strCheck)}");

            //checked and unchecked
            int FuncCheck()
            {
                checked
                {
                    int a = int.MaxValue;
                    //a += 3;
                    try
                    {
                        return a + 3;
                    }
                    catch (OverflowException)
                    {
                        Console.WriteLine($"ПЕРЕПОЛНЕННО\nзначение с проверкой на переполнение:{a}");
                        return a;
                    }
                }
            }
            int FuncNoCheck()
            {
                unchecked
                {
                    int b = int.MaxValue;
                    b += 3;
                    Console.WriteLine($"значение без проверки на переполнение:{b}");
                    return b;
                }
            }
            FuncNoCheck();
            FuncCheck();
        }
    }
}
