using System;

namespace _4new
{
    class Program
    {
        static void Main(string[] args)
        {
            Hanger MyHanger = new Hanger("Вешалка", 124, "Пластик");
            Sofa MySofa = new Sofa("Драгоценный диван", 578, "Двухместный", "Кожа", "Красный", 4);
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

            //7
            Tovar[] ArrObj= new Tovar[2];
            var fur = new Furniture("Фурнитура", 145, "белый", "одноместный", "Кожа");
            var hanger = new Hanger("Вешалка", 14, "Дерево");
            ArrObj[0] = fur;
            ArrObj[1] = hanger;
            var printer = new Printer();
            Printer.IAmPrinting(ArrObj[0]);
            Printer.IAmPrinting(ArrObj[1]);
        }
    }
}
