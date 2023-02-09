using System;

namespace _11laba
{
    class Program
    {
        static void Main(string[] args)
        {
            // Рефлексия - процесс выявления типов во время выполнения приложения.
            Tovar t1 = new Tovar("nothing",1576);
            Console.WriteLine("РЕФЛЕКТОР");
            Reflector.GetAssemblyName(t1);
            Reflector.IsPublicConstructors(t1);
            Reflector.GetAllMethods(t1);
            Reflector.GetFieldsProp(t1);
            Reflector.GetAllInterfaces(t1);
            Reflector.GetSpecialMethod(t1, "String");
            Reflector.Invoke<string>("DisplayInfo", "Tovar", "\nTEST");
            Console.WriteLine(Reflector.Create("Tovar").ToString());


        }
    }
}
