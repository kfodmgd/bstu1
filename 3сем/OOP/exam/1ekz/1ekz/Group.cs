using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace _1ekz
{
    public class Group:IEnumerable,ICleamable
    {
        private Stud[] s;
        public int Num { get; set; }
        public Group(Stud[] sArr)
        {
            s = new Stud[sArr.Length];
            for(int i = 0; i < sArr.Length; i++)
            {
                s[i] = sArr[i];
            }
        }
        IEnumerator IEnumerable.GetEnumerator()
        {
            return (IEnumerator)GetEnumerator();
        }
        public GroupEnum GetEnumerator()
        {
            return new GroupEnum(s);
        }

        public class GroupEnum : IEnumerator
        {
            public Stud[] s;
            int position = -1;
            public GroupEnum(Stud[] list)
            {
                s = list;
            }
            object IEnumerator.Current
            {
                get
                {
                    return Current;
                }
            }
            public Stud Current
            {
                get
                {
                    try
                    {
                        return s[position];
                    }
                    catch (IndexOutOfRangeException)
                    {
                        throw new InvalidOperationException();
                    }
                }
            }
            public bool MoveNext()
            {
                position++;
                return (position < s.Length);
            }
            public void Reset()
            {
                position = -1;
            }
        }


        public Group AddElem(Stud[] mas,Stud el)
        {
            Num++;
            Stud[] tmp = new Stud[mas.Length+1];
            mas.CopyTo(tmp, 0);
            tmp[mas.Length] = el;
            Group temp = new Group(tmp);
            return temp;
        }
        public void Print(Group mas)
        {
            foreach (var a in mas)
            {
                Console.WriteLine($"{a.Course}, {a.Group}, {a.Key}, {a.Mark}, {a.Name}, {a.Sp} ");
            }
        }

        public void Cleam()
        {
            Stud[] a={ };
            try
            {
                if (this.s.Length == 0)
                {
                    throw new Exception("EMPTY");
                }
            }
            catch (Exception)
            {
                Console.WriteLine("ERR EMPTY");
            }
            this.s = a;
        }

    }
}
