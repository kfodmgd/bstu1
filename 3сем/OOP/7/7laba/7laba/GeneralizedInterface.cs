using System;
using System.Collections.Generic;
using System.Text;

namespace _7laba
{
    interface IGener<T> where T:new()
    {
        T[] Add<T>(T[] array, T item);
        T[] Delete<T>(T[] array,T del);
        void ShowUp(T[] array);
    }
}
