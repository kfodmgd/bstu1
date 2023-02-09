using System;

namespace кр
{
    class Program
    {
        static void Main(string[] args)
        {
            //1A
            int ch1;
            int ch2;
            int sum;
            string str;
            ch1 = int.Parse(Console.ReadLine());
            ch2 = int.Parse(Console.ReadLine());
            sum = ch1 + ch2;
            str = Convert.ToString(sum);
            Console.WriteLine(str);

            //1B
            string[,] strMas=new string[2,2]{
                {"abc qwe","asd" },
                {"vns qwe","utr" }
            };
            int i=0;
            int j;
            int q=0;
            for (i = 0; i < 2; i++)
            {
                for (j = 0; j < 2; j++)
                {
                    for(int k=0;k< strMas[i, j].Length; k++)
                    {
                        if(strMas[i,j][k]!=' ')
                        {
                            q++;
                        }

                    }
                }
            }
            Console.WriteLine($"колво знаков в массиве: {q}");

            //2
            Point p1 = new Point { X = 3, Y = 5, Z = 10 };
            Point p2 = new Point { X = 5, Y = 2, Z = 4 };
            Console.WriteLine($"X:{(p1 + p2).X}, Y:{(p1 + p2).Y}, Z:{(p1 + p2).Z}");
            Console.WriteLine($"X:{(p1 - p2).X}, Y:{(p1 - p2).Y}, Z:{(p1 - p2).Z}");
        }
    }
}
