using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassLibraryDLL
{
    class Program
    {
        static void Main(string[] args)
        {
            var p = new Person1(); // у нас беспараметрический конструктор
            var l = new Person();

            if (l.Name == "Andrey")
                p.Name = l.Name;
            if (l.Surname == "Andreyev")
                p.Surname = l.Surname;
            if(l.Age >= 18)
                p.Age = l.Age;
        }
        public class Person
        {
            private string _name;
            private string _surname;
            private int _age;

            public Person()
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
        }
    }
}
