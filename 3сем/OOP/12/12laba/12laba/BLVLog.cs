using System;
using System.Collections.Generic;
using System.Text;
using System.IO;


namespace _12laba
{
    public class BLVLog
    {
        readonly DateTime DateNow = DateTime.Now;
        public void WriteFile(string action, string path=@"F:\3 сем\log.txt", string fileName = "log.txt")
        {
            using(StreamWriter sw= new StreamWriter(path, true, Encoding.UTF8))
            {
                sw.WriteLine("Имя файла: " + fileName);
                sw.WriteLine("Путь : " + path);
                sw.WriteLine("Дата создания: " + DateNow);
                sw.WriteLine(action);
                sw.WriteLine();
                sw.WriteLine();
            }
        }

        private string actionOne;
        public string FreeSpace()
        {
            //driveInfo- позволяет получить инфу о диске
            DriveInfo[] drives = DriveInfo.GetDrives();
            foreach(DriveInfo drive in drives)
            {
                actionOne = "Свободное место на диске в байтах: " + drive.AvailableFreeSpace.ToString();
            }
            return actionOne;
        }
        public string FileSystem()
        {
            DriveInfo[] drives = DriveInfo.GetDrives();

            foreach (DriveInfo drive in drives)
            {
                actionOne = "Файловая сисма: " + drive.DriveFormat.ToString();
            }
            return actionOne;
        }
        public string Disk()
        {
            DriveInfo[] drives = DriveInfo.GetDrives();
            foreach(DriveInfo drive in drives)
            {
                actionOne = "Имя диска: " + drive.Name;
                actionOne += "Объём: " + drive.TotalFreeSpace;
                actionOne += "Свободное место: " + drive.AvailableFreeSpace;
                actionOne += "Метка тома: " + drive.VolumeLabel;
            }
            return actionOne;
        }
    }
}
