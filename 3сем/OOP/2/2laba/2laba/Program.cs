using System;

namespace _2laba
{

    //Конструктор, который не принимает никаких параметров, называется 
    //конструктором без параметров.Конструкторы без параметров вызываются 
    //всякий раз, когда создается экземпляр объекта с помощью оператора new , 
    //а аргументы в new не передаются.
    partial class Vector
    {
        private string mas;
        private int sum;
        private int number_of_elements;
        private int state_variable;
        private readonly int id;//поле только для чтения

        //свойства
        
        public string Mas
        {
            get { return mas; }
            set { mas = value; }
        }
        public int Sum
        {
            get { return sum; }
            set { sum = value; }
        }
        public int Number_of_elements
        {
            get { return number_of_elements; }
            set { number_of_elements = value; }
        }
        public int State_variable
        {
            get { return state_variable; }
            set { state_variable = value; }
        }
        //ограниченно по set
        public int Id
        {
            get
            {
                if (id > 0) return id;
                else return 0;
            }
        }

        //конструкторы
        //с параметром
        public Vector(string mas, int number_of_elements, int state_variable, int id)
        {
            this.mas = mas;//ссылка, которая обеспечивает доступ к текущему экземпляру класса
            this.number_of_elements = number_of_elements;
            this.state_variable = state_variable;
            this.id = id;
        }
        //без параметров
        public Vector()
        {
            string mas = "1 2 4 0 5 1";
            number_of_elements = 6;
            state_variable = 0;
            id = 1;
        }
        //с параметром по умолчанию
        //конструктор по умолчанию - конструктор, который не имеет параметов и 
        //не имеет тела, создаётся автоматически средой разработки, если в
        //классе не определено ни одного конструктора

        /*public Vector()
        {

        }*/

        // статический
        //Статический конструктор используется для инициализации
        //любых статических данных или для выполнения определенного действия,
        //которое требуется выполнить только один раз.
        private static int numbOfObj;  //статическое поле, хранящее количество созданных объектов
                                       //функции, которые принадлежат классу, принято называть МЕТОДОМ
        static void classInfo()          //статический метод вывода информации о классе
        {
            Console.WriteLine(numbOfObj);
        }
        static Vector()                   //статический конструктор
        {
            Console.WriteLine("Cтатический конструктор");
            numbOfObj = 0;
        }


        // закрытый
        //Закрытые конструкторы используются, чтобы не допустить
        //создания экземпляров класса при отсутствии полей или методов экземпляра
        private Vector(int state_variable)
        {
            this.state_variable = state_variable;
        }

        public override string ToString() // переопределение метода ToString
        {
            return $"ID: {this.id}\n" +
                $"Значения: {this.mas}\n" +
                $"Кол-во элементов: {this.number_of_elements}\n" +
                $"Переменная состояния: {this.state_variable}\n";
        }

        // Метод вывода 
        /*public void Print(ref Vector vector, out int printValues)
        {
            printValues = 0;
            for (int i = 0; i < mas.Length; i++)
            {
                printValues = vector.mas[i];
                Console.Write(printValues);
            }
        }*/

        public void CheckRef(ref int i)
        {
            i++;  
        }
        public void CheckOut(out int j)
        {
            j=5;
        }
    }

    class Program
    {

        static void Main(string[] args)
        {
            int z = 0;
            Console.WriteLine($"До функции ref z={z}");
            Vector test = new Vector();
            test.CheckRef(ref z);
            Console.WriteLine($"Теперь z={z}");
            Console.WriteLine();
            int a;
            Console.WriteLine($"До функции out a ничему не равна");
            test.CheckOut(out a);
            Console.WriteLine($"Теперь a={a}");
            Console.WriteLine();
            Console.WriteLine();
            Console.Write("Введите количество:");
            int numb = int.Parse(Console.ReadLine());
            Vector[] DB = new Vector[numb];          //создаём массив классов с БД
            for(int i = 0; i < numb; i++)
            {
                DB[i] = new Vector();
                Console.WriteLine("Введите количество значений");
                DB[i].Number_of_elements = int.Parse(Console.ReadLine());
                Console.WriteLine("Введите значения в строку");
                DB[i].Mas = Console.ReadLine();
                Console.WriteLine("Введите значение");
                DB[i].State_variable = int.Parse(Console.ReadLine());
                Console.WriteLine();
            }
            //Вектора кот содержат 0
            for (int i = 0; i < numb; i++)
            {
                for (int j = 0; j < DB[i].Mas.Length; j++)
                {
                    if (DB[i].Mas[j] == '0')
                    {
                        int k = i + 1;
                        Console.WriteLine("Вектор под номером "+k+" имеет хотя бы одно значение, равное нулю");
                        Console.WriteLine("Значения:"+DB[i].Mas);
                        Console.WriteLine("Колво значений:"+DB[i].Number_of_elements);
                    }
                }
            }
            //вектор с наименьшем модулем
            for(int i = 0; i < numb; i++)
            {
                char[] splitchar = { ' ' };
                string[] ArrZn = DB[i].Mas.Split(splitchar);
                int[] ArrInt = new int[ArrZn.Length];
                for(int k = 0; k < ArrZn.Length; k++)
                {
                    ArrInt[k] = Convert.ToInt32(ArrZn[k]);
                    DB[i].Sum += ArrInt[k];
                }
                int min =DB[1].Sum;
                int minId = 1;
                if (DB[i].Sum < min)
                {
                    minId = i;
                    min = DB[i].Sum;
                }
                if (i == numb - 1)
                {
                    Console.WriteLine($"Вектор с наименьшей суммой значений:{min} под номером {minId+1}");
                }
            }
        }
    }
}
