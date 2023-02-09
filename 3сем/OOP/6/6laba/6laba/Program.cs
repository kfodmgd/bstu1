using System;

namespace _6laba
{
    class Program
    {
        static void Main(string[] args)
        {
            Hanger MyHanger = new Hanger("Вешалка", 124, "Пластик");
            Sofa MySofa = new Sofa("Драгоценный диван", 578, "Двухместный", "Красный", "Кожа", 4);
            Bed MyBed = new Bed("Уютная кровать", 541, "Двухместная", "Светлая яблоня", "Дерево", 2);
            Cupboard MyCupboard = new Cupboard("Вместитьная тумбочка", 174, "Метровая", "Тёмный дуб", "дерево", 2);
            Chair MyChair = new Chair("Удобный стул", 99, 2, true, "Дерево", "Светлая яблоня", "одноместный");
            Console.WriteLine($"{MyHanger}\n{MySofa}\n{MyBed}\n{MyCupboard}\n{MyChair}");
            Furniture tovar = new Furniture("Предмет", 145, "Чёрный", "Двухместный", "Кожа");
            Furniture tovar2 = new Furniture("Предмет", 145, "Чёрный", "Двухместный", "Кожа");


            Furniture? furniture = MySofa as Furniture;
            if (MySofa == null)
            {
                Console.WriteLine("FAIL");
            }
            else
            {
                Console.WriteLine(MySofa.NumPpl);
            }
            //-------------------------//
            if (tovar is Sofa sofa)
            {
                Console.WriteLine("FAIL");
            }
            else
            {
                Console.WriteLine(MySofa.NumPpl);
            }
            //-----------------------//
            theSameNameMethods cust = new theSameNameMethods();
            cust.boxName();//class
            ((InterfaceMethods)cust).boxName();//interface

            //7 task
            Tovar[] ArrObj = new Tovar[2];
            var fur = new Furniture("Фурнитура", 145, "белый", "одноместный", "Кожа");
            var hanger = new Hanger("Вешалка", 14, "Дерево");
            ArrObj[0] = fur;
            ArrObj[1] = hanger;
            var printer = new Printer();
            Printer.IAmPrinting(ArrObj[0]);
            Printer.IAmPrinting(ArrObj[1]);


            //5laba
            Console.WriteLine();
            Console.WriteLine();
            Console.WriteLine();
            //struct
            Bed.Customer cst = new Bed.Customer("Олежа", 1, "20.11.2022");
            cst.PrintInfoStr();

            Console.WriteLine();
            Sklad skladTovarov = new Sklad("test", MyBed, MySofa, MyCupboard, MyBed);
            //skladTovarov.GetInfo();
            skladTovarov.AddTovar(MyChair);
            Console.WriteLine();
            //skladTovarov.GetInfo();


            Controller.SearchMaterial(skladTovarov, "Кожа");
            skladTovarov.GetInfo();
            Console.WriteLine();
            Controller.SortByMoney(skladTovarov);
            skladTovarov.GetInfo();
            Console.WriteLine("\nИтого стоимость:");
            int sum = Controller.SumPrice(skladTovarov);
            Console.WriteLine(sum);


            //6laba
            Furniture TestTovar = new Furniture("Предмет", 145, "прозрачный", "Двухместный", "Кожа");
            Chair TestChair = new Chair("Удобный стул", 52, -1, null, "Дерево", "Светлая яблоня", "одноместный");

            //e1
            try
            {
                TestTovar.Color = "прозрачный";
            }
            catch(Exeptions.TovarArgExc er)
            {
                Console.WriteLine("Неверный цвет " + er);
                Console.WriteLine(er.Message);
            }
            Console.WriteLine();
            //e2
            try
            {
                TestChair.Arms = 0;
            }
            catch(Exeptions.TovarLessThenZero er)
            {
                Console.WriteLine("Неверное значение " + er);
                Console.WriteLine(er.Message);
            }
            Console.WriteLine();
            //e3
            try
            {
                TestChair.Bottom = null;
            }
            catch(NullReferenceException er)
            {
                Console.WriteLine("Значение=null " + er);
                Console.WriteLine(er.Message);
            }
            Console.WriteLine();
            //e4
            try
            {
                TestChair.Price = 0;
                int a = TestChair.Arms / TestChair.Price;
            }
            catch(DivideByZeroException er)
            {
                Console.WriteLine("деление на 0 " + er);
                Console.WriteLine(er);
            }
            Console.WriteLine();
            //e5
            try
            {
                int[] a = new int[2];
                a[3] = 5;
            }
            catch(IndexOutOfRangeException er)
            {
                Console.WriteLine("выход за диапазон " + er);
                Console.WriteLine(er);
            }
            Console.WriteLine();
            //универсальный обработчик catch
            try
            {
                checked
                {
                    int a = Int32.MaxValue;
                    a++;
                }
            }
            catch(OverflowException ex)
            {
                Console.WriteLine("какая-то ошибка");
                Console.WriteLine(ex);
            }
            Console.WriteLine();
            //try-catch-finally
            try
            {
                TestChair.Price = 0;
                int a = TestChair.Arms * TestChair.Price;
            }
            catch (DivideByZeroException er)
            {
                Console.WriteLine("деление на 0 " + er);
                Console.WriteLine(er);
            }
            finally
            {
                Console.WriteLine("БЛОК FINALLY");
            }
            Console.WriteLine();
            // Продемонстрируйте возможность многоразовой обработки одного исключения и проброс его выше по стеку вызовов
            try
            {                
                try
                {
                    int[] a = new int[2];
                    a[3] = 5;
                }
                catch(Exception er)
                {
                    Console.WriteLine("ВНУТРЕННИЙ БЛОК");
                    Console.WriteLine(er);
                    throw;
                }
                checked
                {
                    int a = Int32.MaxValue;
                    a++;
                }
            }
            catch(Exception ex)
            {
                Console.WriteLine("ВНЕШНИЙ БЛОК");
                Console.WriteLine(ex);
            }
            Console.WriteLine();
            //assert
            Furniture.MyMethod("пластик");

        }
    }
}
