using System;
using System.Collections.Generic;
using System.Text;

namespace _8laba
{
    class User
    {
        public delegate void Info(string mes);
        public event Info Say;
        public User(int position, string name)
        {
            Position = position;
            Name = name;
        }
        public int Position{ get; set; }
        public string Name { get; set; }
        public void Smesh(int smesh)
        {
            Position += smesh;
            Say?.Invoke($"Смещение на {smesh}. Позиция:{Position}");
        }
        public void Squizee(int squz)
        {
            if (squz >=Position)
            {
                Say?.Invoke("Превратился в 0");
                Position = 0;
            }
            else
            {
                Position /= squz;
                Say?.Invoke($"Сжался в {squz} раз, итог:{Position}");
            }
        }
        public override string ToString()
        {
            return $"{Name} {Position}";
        }

    }
}
