using System;
using System.IO;
using System.Xml.Serialization;
using System.Runtime.Serialization.Formatters.Binary;

namespace Serialization
{
    // класс и его члены объявлены как public
    [Serializable]
    public class Pupils
    {
        public string Name { get; set; }
        public int Age { get; set; }
        public string School { get; set; }

        public int Lessons { get; set; }

        // стандартный конструктор без параметров
        public Pupils()
        { }

        public Pupils(string name, int age, string school, int lessons)
        {
            Name = name;
            Age = age;
            School = school;
            Lessons = lessons;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            // объект для сериализации
            Pupils pupils = new Pupils("Tom", 29, "#129", 6);
            Console.WriteLine("Объект создан");

            // передаем в конструктор тип класса XmlSerializer
            //XmlSerializer formatter = new XmlSerializer(typeof(Pupils));

            // создаем объект BinaryFormatter
            BinaryFormatter formatter = new BinaryFormatter();

            // получаем поток, куда будем записывать сериализованный объект
            //using (FileStream fs = new FileStream("../../pupils.xml", FileMode.OpenOrCreate)) //xml
            using (FileStream fs = new FileStream("../../pupils.dat", FileMode.OpenOrCreate)) //binar
            {
                formatter.Serialize(fs, pupils);

                Console.WriteLine("Объект сериализован");
            }

            // десериализация
            //using (FileStream fs = new FileStream("../../pupils.xml", FileMode.OpenOrCreate)) //xml 
            using (FileStream fs = new FileStream("../../pupils.dat", FileMode.OpenOrCreate)) //binar
            {
                Pupils newPupils = (Pupils)formatter.Deserialize(fs);

                Console.WriteLine("Объект десериализован");
                Console.WriteLine("Имя: {0} --- Возраст: {1} --- Школа: {2} --- Уроков: {3}", newPupils.Name, newPupils.Age, newPupils.School, newPupils.Lessons);
            }

            Console.ReadLine();
        }
    }
}