using System;
using System.Linq;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters;
using System.Runtime.Serialization.Formatters.Binary;
//using System.Runtime.Serialization.Formatters.Soap;
using System.Xml.Serialization;
using System.Runtime.Serialization.Json;
using System.Xml.Linq;
using System.Xml.XPath;
namespace _13laba
{
    class Program
    {
        static void Main(string[] args)
        {
            BinaryFormatter formBin = new BinaryFormatter();
            //SoapFormatter formatter = new SoapFormatter();
            XmlSerializer formXml = new XmlSerializer(typeof(Group));
            DataContractJsonSerializer formLson = new DataContractJsonSerializer(typeof(Group));

            Tovar t1=new Tovar("qwe1", 152);
            Tovar t2 = new Tovar("asds1", 796);
            Group army = new Group();
            army.Add(t1);
            army.Add(t2);

            using (FileStream fs = new FileStream("groupD.dat", FileMode.OpenOrCreate))
            {
                formBin.Serialize(fs, army);
            }

            //TextWriter writer = new StreamWriter("groupX.xml");
            //formXml.Serialize(writer, army);
            //using (TextWriter fs = new StreamWriter("groupX.xml"))
            using (FileStream fs = new FileStream("groupX.xml", FileMode.OpenOrCreate))
            {
                formXml.Serialize(fs, army);
                //Console.Write("DONE");
            }

            using (FileStream fs = new FileStream("groupJ.json", FileMode.OpenOrCreate))
            {
                formLson.WriteObject(fs, army);
            }


            //десереализация
            using (FileStream fs = new FileStream("groupD.dat", FileMode.OpenOrCreate))
            {
                Group army1;
                army1 = (Group)formBin.Deserialize(fs);
                Console.WriteLine("Binary");
                army1.Print();
            }
            Console.WriteLine("\n");

            using (FileStream fs = new FileStream("groupX.xml", FileMode.OpenOrCreate))
            {
                Group army1;
                army1 = (Group)formXml.Deserialize(fs);
                Console.WriteLine("XML");
                army1.Print();
            }
            Console.WriteLine("\n");



            //2
            Console.WriteLine("\nВТОРОЕ ЗАДАНИЕ\n");
            Tovar[] humans = new Tovar[] { new Tovar("test", 188), new Tovar("test1", 155), new Tovar("test2", 158) };

            using (FileStream fs = new FileStream("array.xml", FileMode.OpenOrCreate))
            {
                formXml = new XmlSerializer(typeof(Tovar[]));
                formXml.Serialize(fs, humans);

            }

            using (FileStream fs = new FileStream("array.xml", FileMode.OpenOrCreate))
            {
                foreach (Tovar x in (Tovar[])formXml.Deserialize(fs))
                    Console.WriteLine(x.ToString());
            }



            //xpath
            XPathDocument xmldoc = new XPathDocument("array.xml");
            Console.WriteLine("XPATH");
            foreach (XPathItem x in xmldoc.CreateNavigator().Select("//Tovar/Name"))
                Console.WriteLine(x.Value);
            Console.WriteLine();
            Console.WriteLine("товар с ценой 155");
            foreach (XPathItem x in xmldoc.CreateNavigator().Select("//Tovar[Price = \"155\"]/Name"))
                Console.WriteLine(x.Value);


            //linq to xml
            using (FileStream fs = new FileStream("array.xml", FileMode.OpenOrCreate))
            {
                XDocument xdoc = XDocument.Load(fs);
                XElement root = xdoc.Element("ArrayOfTovar");
                foreach (XElement xe in root.Elements("Tovar").Where(x => x.Element("Name").Value.Contains("t")).ToList())
                {
                    if (Int32.Parse(xe.Element("Price").Value) > 160)
                    {
                        xe.Add(new XElement("END", "Yes"));
                    }
                    else
                    {
                        xe.Remove();
                    }
                }
                root.Add(new XElement("Tovar",
                            new XElement("Name", "ABC"),
                            new XElement("Price", "15963"),
                            new XElement("Desc", "NewItem"),
                            new XElement("New", "TRUE"),
                            new XElement("END", "Yes")));
                xdoc.Save("newArray.xml");
            }
        }
    }
}
