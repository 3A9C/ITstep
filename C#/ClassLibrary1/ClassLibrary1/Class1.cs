using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassLibraryDLL
{
    public class Person1
    {
        private string _name;
        private string _surname;
        private int _age;

        public Person1()
        {
        }

        public string Name
        {
            get { return _name; }
            set { _name = value; }
        }
        public string Surname
        {
            get { return _surname; }
            set { _surname = value; }
        }
        public int Age
        {
            get { return _age; }
            set { _age = value; }
        }
        static void Main(string[] args)
        {
            var p = new Person1(); // у нас беспараметрический конструктор

            Console.WriteLine(p.Name);
            Console.WriteLine(p.Surname);
            Console.WriteLine(p.Age);

            Console.ReadKey();
        }
    }
}
