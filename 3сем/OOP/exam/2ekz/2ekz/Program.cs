using System;

namespace _2ekz
{
    class Program
    {
        static void Main(string[] args)
        {
            _2dPoint p1 = new _2dPoint(2, 53);
            _2dPoint p2 = new _2dPoint(15, -4);
            _2dPoint p3 = new _2dPoint(-5, 58);
            _2dPoint p4 = new _2dPoint(-10, -83);
            _2dPath path = new _2dPath();
            path.Add(p1);
            path.Add(p2);
            path.Add(p3);
            path.Add(p4);

            for(int i = 0; i < path.Points.Count; i++)
            {
                Console.WriteLine(path.Points);
            }
            _2dPath path1 = path;
            Console.WriteLine(path == path1);

            Console.WriteLine(path.CountPoints());



        }
    }
}
