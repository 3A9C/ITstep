using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;   

namespace TestSpeedSimpleNumbers
{
    class Program
    {
        static void Main()
        {
            StreamWriter gen = new StreamWriter("../../NumberGeneric.csv");
            Random rnd = new Random();
            Stopwatch swatch = new Stopwatch(); // создаем объект   

            swatch.Start(); // старт
            for (int i = 0; i < 1000000; ++i)
            {
                if (isPrime(i) == true)
                {
                    gen.WriteLine(i + "; True;");
                }
            }
            gen.Close();
            swatch.Stop();
            Console.WriteLine("Конец " + swatch.Elapsed);
            Console.ReadKey();
        }
        static bool isPrime(int number)
        {
            if (number < 2) return false;
            for (int i = 2; i <= Math.Sqrt(number); i++)
            {
                if (number % i == 0) return false;
            }
            return true;
        }
    }
}
