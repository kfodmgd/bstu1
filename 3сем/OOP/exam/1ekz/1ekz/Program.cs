using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace _1ekz
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> l1 = new List<int> { 5, 7, 8 };
            Stud.Spec s1 = Stud.Spec.poit;
            Stud st1 = new Stud("abc", 1, 1, s1, l1);

            List<int> l2 = new List<int> { 9, 7, 4 };
            Stud.Spec s2 = Stud.Spec.isit;
            Stud st2 = new Stud("asd", 1, 2, s2, l2);
            
            List<int> l3 = new List<int> { 1, 7, 8 };
            Stud.Spec s3 = Stud.Spec.mobile;
            Stud st3 = new Stud("qwe", 2, 1, s3, l3);

            //Console.WriteLine(st1.Name,st1.Group,st1.Course,st1.Mark,st1.Sp);
            st1.Print();
            Console.WriteLine(st1.Sec(st1));
            
            //3
            Stud[] GrArr =
            {
                new Stud("qwe", 2, 1, s3, l3),
                new Stud("asd", 1, 2, s2, l2)
            };
            Group group = new Group(GrArr);
            group.Print(group);
            group.AddElem(GrArr,st1);
            group.Print(group);

            //4
            Stud[] GrArr1 =
            {
                new Stud("jhk", 2, 1, s3, l3),
                new Stud("yuk", 1, 2, s2, l2)
            };
            Group gr1 = new Group(GrArr1);
            List<Group> temp = new List<Group> { group };
            List<Group> temp1 = new List<Group> { gr1 };
            var rez = temp1.Concat(temp);
            foreach(var a in rez)
            {
                Console.WriteLine(a);
            }

            //5
            Console.WriteLine("\n\n\n\n\n");
            gr1.Cleam();
            gr1.Print(gr1);

            Stud[] emp = { };
            Group g = new Group(emp);
            g.Cleam();
        }
    }
}
