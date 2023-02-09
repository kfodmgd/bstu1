using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.IO.Compression;

namespace _12laba
{
    static class BLVFileManager
    {
        public static void AllAboutDrive(string disk)
        {
            string path;
            if (disk.ToLower() == "f")
            {
                path = @"F:\";
            }
            else
            {
                throw new Exception("Неверное имя диска");
            }
            DirectoryInfo dir = new DirectoryInfo(path);
            Console.WriteLine("список папок:");
            foreach(DirectoryInfo fold in dir.GetDirectories())
            {
                Console.WriteLine(fold.Name);
            }
            Console.WriteLine("Список файлов:");
            foreach(FileInfo fold in dir.GetFiles())
            {
                Console.WriteLine(fold.Name);
            }
        }
        public static void FileDirCreate(string dirName, string fileName, string fileCreate)
        {
            string dirPath = @"F:\" + dirName;
            DirectoryInfo dirInfo = new DirectoryInfo(dirPath);
            if (!dirInfo.Exists)
            {
                dirInfo.Create();
            }
            string filePath = dirPath + "\\" + fileName + ".txt";
            FileInfo fileInf = new FileInfo(filePath);
            if (!fileInf.Exists)
            {
                fileInf.Create();
            }
            try
            {
                using StreamWriter sw = new StreamWriter(filePath, false, System.Text.Encoding.Default);
                sw.WriteLine("ИНФА");
                sw.Close();
            }
            catch(Exception e)
            {
                Console.WriteLine(e.Message);
            }
            string filePathCreate = dirPath + "\\" + fileCreate + ".txt";
            File.Copy(filePath, filePathCreate, true);
            File.Delete(filePath);
        }
        public static void BLVFiles(string path, string ext)
        {
            string dirPath = @"F:\3 сем";
            DirectoryInfo dirInfo = new DirectoryInfo(dirPath);
            if (!dirInfo.Exists)
            {
                dirInfo.Create();
            }
            DirectoryInfo userDir = new DirectoryInfo(path);
            foreach(FileInfo file in userDir.GetFiles())
            {
                if (file.Extension == ("." + ext))
                {
                    file.CopyTo(dirPath + "\\" + file.Name, true);
                }
            }
            dirInfo.MoveTo(@"F:\3 сем\Inspect");
        }
        public static void Zip()
        {
            DirectoryInfo source = new DirectoryInfo(@"F:\3 сем\Inspect");
            ZipFile.CreateFromDirectory(source.FullName, source.FullName + ".zip");
            Console.WriteLine("АРХИВ СОЗДАН");
        }
        public static void UnZip(string foldName)
        {
            DirectoryInfo source = new DirectoryInfo(@"F:\3 сем\Inspect");
            ZipFile.ExtractToDirectory(source.FullName + ".zip", foldName);
            Console.WriteLine("РАЗАРХИВИРОВАНО");
        }
    }
}
