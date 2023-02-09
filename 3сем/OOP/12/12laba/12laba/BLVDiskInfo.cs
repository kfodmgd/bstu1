using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace _12laba
{
    static class BLVDiskInfo
    {
        public static void DiskInfo()
        {
            DriveInfo[] drives = DriveInfo.GetDrives();
            foreach(DriveInfo drive in drives)
            {
                Console.WriteLine($"Имя: {drive.Name}");
                Console.WriteLine($"Файловая сисма: {drive.DriveFormat}");
                Console.WriteLine($"Свободное место: {Math.Round(drive.AvailableFreeSpace*1e-9,2)}");
                Console.WriteLine($"Всего места на диске: {Math.Round(drive.TotalSize*1e-9,2)}");
                Console.WriteLine($"Метка: {drive.VolumeLabel}");
                Console.WriteLine();
                Console.WriteLine();
            }
        }
    }
}
