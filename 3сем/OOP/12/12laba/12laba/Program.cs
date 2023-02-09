using System;
using System.IO;

namespace _12laba
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("инфа в файле F:\\3 сем\\log.txt");
            BLVLog log = new BLVLog();
            BLVForFileInfo fileInfo = new BLVForFileInfo();
            log.WriteFile(fileInfo.FullPath());
            log.WriteFile(fileInfo.Info());
            log.WriteFile(fileInfo.Dates());
            BLVDiskInfo.DiskInfo();
            BLVFileInfo.FileInfo("log.txt");
            BLVDirInfo.DirInfo(@"F:\3 сем\ооп");
            BLVFileManager.AllAboutDrive("F");
            //BLVFileManager.FileDirCreate("Inspect", "dirInfo", "createTest");
            //BLVFileManager.BLVFiles(@"F:\3 сем", "png");
            BLVFileManager.Zip();
            BLVFileManager.UnZip(@"F:\3 сем\unzip");

        }
    }
}
