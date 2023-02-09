using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _7laba
{
    public class Mas<T>:IGener<T>where T:new()
    {
        public int[] ar;
        public int[] br;

        public Mas(int[] a, int[] b)
        {
            ar = a;
            br = b;
        }
        public Mas(int[] a)
        {
            ar = a;
        }

        //перегрузка
        //*  умножение массивов;
        public static int[] operator *(Mas<T> a, Mas<T> b)
        {
            int[] rez = new int[a.ar.Length + b.ar.Length];
            int ln;
            if (a.ar.Length > b.ar.Length)
            {
                ln = a.ar.Length;
            }
            else
            {
                ln = b.ar.Length;
            }
            for (int i = 0; i < ln; i++)
            {
                rez[i] = a.ar[i] * b.ar[i];
            }
            return rez;
        }
        //true  истина если массив не сдержит отрицательных элементов,
        public static bool operator -(Mas<T> a)
        {
            for (int i = 0; i < a.ar.Length; i++)
            {
                if (a.ar[i] < 0)
                {
                    return true;
                }
            }
            return false;
        }
        //int ()  операция приведения – возвращает размер массива;
        public static int operator +(Mas<T> a)
        {
            return a.ar.Length;
        }
        //==  проверка на равенство;
        public static bool operator ==(Mas<T> a, Mas<T> b)
        {
            bool rez = a.ar.Equals(b.br);
            return rez;
        }
        //проверка на не равенство
        public static bool operator !=(Mas<T> a, Mas<T> b)
        {
            bool rez = a.ar.Equals(b.br);
            return rez;
        }

        //Добавьте в свой класс вложенный класс Developer (разработчик – фио,
        //id, отдел). Проинициализируйте
        public class Developer
        {
            private string name { get; set; }
            private string org { get; set; }
            private int id { get; set; }

            public Developer()
            {
                this.name = "Liza";
                this.org = "BSTU";
                this.id = 123456789;
            }
        }
        public static Production an;



        //7laba
        public T[] Add<T>( T[] array,T item)
        {
            T[] res = new T[array.Length + 1];
            array.CopyTo(res, 0);
            res[array.Length] = item;
            return res;
        }
        public T[] Delete<T>( T[] array, T item)
        {
            T[] res = new T[array.Length];
            res = array.Except(new T[] { item }).ToArray();
            return res;
        }
        public void ShowUp( T[] array)
        {
            Console.WriteLine("Содержание массива");
            for(int i = 0; i < array.Length; i++)
            {
                Console.Write(array[i]+" ");
            }
        }
    }
}
