using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace _12laba
{
    static class BLVDirInfo
    {
        public static void DirInfo(string dirName)
        {
            DirectoryInfo dir = new DirectoryInfo(dirName);
            Console.WriteLine($"Название каталога: {dir.Name}");
            Console.WriteLine($"Полный путь каталога: {dir.FullName}");
            Console.WriteLine($"Время создания каталога: {dir.CreationTime}");
            Console.WriteLine($"Колво файлов: {dir.GetFiles().Length}");
            Console.WriteLine($"колво поддиректорий: {dir.GetDirectories().Length}");
            Console.WriteLine();
            Console.WriteLine();
        }
    }
}
