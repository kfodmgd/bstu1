using System;
using System.Collections.Generic;
using System.Text;

namespace _1ekz
{
    public class Stud
    {
        public int Key { get; set; }
        public string Name { get; set; }
        public int Group { get; set; }
        public int Course { get; set; }
        public enum Spec
        {
            poit,isit,mobile
        };
        public Spec Sp { get; set; }
        public List<int> Mark { get; set; }

        public Stud(string name, int group, int course,Spec sp,List<int> mark)
        {
            Name = name;
            Group = group;
            Course = course;
            Sp = sp;
            Mark = mark;
        }

        public void Print()
        {
            Console.WriteLine($"{this.Name}\n{this.Group}\n{this.Course}\n{this.Sp}\n");
            foreach(int a in Mark)
            {
                Console.WriteLine(a);
            }
        }

        public (int,int,float) Sec(Stud stud)
        {
            int min, max,sum=0;
            float avg;
            min = stud.Mark[0]; max = stud.Mark[0];
            foreach (int a in stud.Mark)
            {
                sum += a;
                if (a < min)
                {
                    min = a;
                }
                if (a > max)
                {
                    max = a;
                }
            }
            avg = sum / 3;
            var rez = (max, min, avg);
            return rez;
        }
    }
}
