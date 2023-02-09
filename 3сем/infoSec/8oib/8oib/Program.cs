using System.IO;
using System;
using System.Security.Cryptography;
using System.Text;

namespace OIBLab9
{
    static class WriteColor
    {
        public static void Red(string message)
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine(message);
            Console.ForegroundColor = ConsoleColor.White;
        }
        public static void Green(string message)
        {
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine(message);
            Console.ForegroundColor = ConsoleColor.White;
        }
    }
    internal class Program
    {
        private static void EncryptFile(string source, string destination, string sKey)
        {
            using (FileStream fsInput = new FileStream(source, FileMode.Open, FileAccess.Read))
            {
                FileStream fsEncrypted = new FileStream(destination, FileMode.Create, FileAccess.Write);
                DES DES = DES.Create();
                try
                {
                    DES.Key = GetASCII().GetBytes(sKey);
                    DES.IV = GetASCII().GetBytes(sKey);
                    using (FileStream key = new FileStream("F:\\oib\\key.txt", FileMode.Create, FileAccess.Write))
                        key.Write(DES.Key, 0, DES.Key.Length);
                    CryptoStream cryptoStream = new CryptoStream(fsEncrypted, DES.CreateEncryptor(), CryptoStreamMode.Write);
                    byte[] buffer = new byte[fsInput.Length];
                    fsInput.Read(buffer, 0, buffer.Length);
                    cryptoStream.Write(buffer, 0, buffer.Length);
                    cryptoStream.Close();
                    WriteColor.Green("Шифровка выполнена успешно");
                }
                catch
                {
                    WriteColor.Red("Ключ неверный");
                }
                fsInput.Close();
                fsEncrypted.Close();
            }

        }
        private static void DecryptFile(string source, string destination, string sKey)
        {
            using (FileStream fsInput = new FileStream(source, FileMode.Open, FileAccess.Read))
            {
                FileStream fsDecrypted = new FileStream(destination, FileMode.Create, FileAccess.Write);
                DES DES = DES.Create();
                try
                {
                    DES.Key = GetASCII().GetBytes(sKey);
                    DES.IV = GetASCII().GetBytes(sKey);
                    CryptoStream cryptoStream = new CryptoStream(fsDecrypted, DES.CreateDecryptor(), CryptoStreamMode.Write);
                    byte[] buffer = new byte[fsInput.Length];
                    fsInput.Read(buffer, 0, buffer.Length);
                    cryptoStream.Write(buffer, 0, buffer.Length);
                    cryptoStream.Close();
                    WriteColor.Green("Дешифровка выполнена успешно");
                }
                catch
                {
                    WriteColor.Red("Ключ неверный");
                }
                fsInput.Close();
                fsDecrypted.Close();
            }
        }
        private static Encoding GetASCII()
        {
            return Encoding.ASCII;
        }
        private static void Hash()
        {
            using (SHA1 mysha = SHA1.Create())
            {
                byte[] hashValue = new byte[256];
                hashValue = mysha.ComputeHash(File.ReadAllBytes("F:\\oib\\Sha.txt"));
                File.WriteAllBytes("F:\\oib\\Hash.txt", hashValue);
            }
        }

        static void Main(string[] args)
        {
            string choose;
            while (true)
            {
                Console.WriteLine("Выберите действие");
                Console.WriteLine("1 - Зашифровать файл");
                Console.WriteLine("2 - Расшифровать файл");
                Console.WriteLine("3 - Хешировать файл");
                choose = Console.ReadLine();
                Console.Clear();
                switch (choose)
                {
                    case "1":
                        EncryptFile("F:\\oib\\File.txt", "F:\\oib\\EncryptedFile.txt", Console.ReadLine());
                        break;
                    case "2":
                        DecryptFile("F:\\oib\\EncryptedFile.txt", "F:\\oib\\DecryptedFile.txt", Console.ReadLine());
                        break;
                    case "3":
                        Hash();
                        break;
                }
            }
        }
    }
}
