using System;
using System.Collections.Generic;
using System.Text;

namespace _2ekz
{
    public class _2dPath
    {
        public List<_2dPoint> Points { get; set; }

        public _2dPath(List<_2dPoint> points)
        {
            Points = points;
        }
        public _2dPath()
        {
            this.Points = new List<_2dPoint>();
        }
        public void Del()
        {
            try
            {
                this.Points.RemoveAt(Points.Count);
                if (this.Points.Count == 0)
                {
                    throw new Exception();
                }
            }
            catch (Exception)
            {
                Console.WriteLine("EMPTY");
            }
        }
        public void Add(_2dPoint item)
        {
            this.Points.Add(item);
        }
        public void Clear()
        {
            for(int i = 0; i < this.Points.Count; i++)
            {
                this.Points.RemoveAt(Points.Count);
            }
        }


        public static bool operator ==(_2dPath p1, _2dPath p2)
        {
            if (p1.Points.Equals(p2.Points))
            {
                Console.WriteLine("EQUALS");
            }
            return p1.Points.Equals(p2.Points);
        }
        public static bool operator !=(_2dPath p1, _2dPath p2)
        {
            if (!p1.Points.Equals(p2.Points))
            {
                Console.WriteLine("NOT EQUALS");
            }
            return !p1.Points.Equals(p2.Points);
        }


        public (int,int,int,int) CountPoints()
        {
            int fir=0, sec=0, thi=0, fou=0;
            _2dPoint t = new _2dPoint(0, 0);
            _2dPath temp = new _2dPath();
            temp.Add(t);
            _2dPoint[] pArr = new _2dPoint[this.Points.Count];
            pArr=this.Points.ToArray();
            for(int i = 0; i < pArr.Length; i++)
            {
                if (pArr[i].X < 0 && pArr[i].Y < 0)
                {
                    fir++;
                }
                if (pArr[i].X < 0 && pArr[i].Y > 0)
                {
                    sec++;
                }
                if (pArr[i].X > 0 && pArr[i].Y > 0)
                {
                    thi++;
                }
                if (pArr[i].X > 0 && pArr[i].Y < 0)
                {
                    fou++;
                }
            }
            (int, int, int, int) rez = (fir, sec, thi, fou);
            return rez;

        }
    }
}
