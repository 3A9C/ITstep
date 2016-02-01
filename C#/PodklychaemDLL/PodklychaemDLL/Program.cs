using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ClassLibraryDLL;


namespace PodklychaemDLL
{
    class Program
    {
        static void Main(string[] args)
        {
            var p = new Person1(); // у нас беспараметрический конструктор

            p.Name = "Andrey";
            p.Surname = "Andreyev";
            p.Age = 27;

            //Console.WriteLine(p.Name);
            //Console.WriteLine(p.Surname);
            //Console.WriteLine(p.Age);

            Console.ReadKey();
        }
    }
}
