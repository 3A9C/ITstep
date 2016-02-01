using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Delegate
{

    delegate int IntOperation(int i);


    class Program
    {


        static public int[] Map(int[] arr, IntOperation op)
        {
            int[] res = new int[arr.Length];
            for (int i = 0; i < arr.Length; i++)
            {
                res[i] = op(arr[i]);
            }
            return res;
        }

        static int Reduce(int x)
        {
            return x / 2;
        }
        static int Prime(int x)
        {

            bool prost = true;
            for (int i = 2; i <= x / 2; i++)
            {
                if (x % i == 0)
                {
                    prost = false;
                    break;
                }
            }
            if (prost)
            {
                x = 0;
            }
            return x;
        }
        static int Pow(int x)
        {
            return (long)Math.Pow(2, x);
        }

        static void Main()
        {
            Random rnd = new Random();

            IntOperation deleg = new IntOperation(Reduce);


            int size = 20;

            int[] massiv = new int[size];

            for (int ctr = 1; ctr < size; ctr++)
            {
                massiv[ctr] = rnd.Next(1, 99);
            }



           Console.WriteLine("Числа рандом");

           massiv = Map(massiv, x => x * x);

           Map(massiv, delegate(int x)
           {
               Console.WriteLine(x);
               return x;
           }

               );

           Map(massiv, Pow);



           for (int ctr = 0; ctr < size; ctr++)
           {
               int Reduces = deleg(massiv[ctr]); 
               Console.Write("{0} ",massiv[ctr]);
           }

           Console.WriteLine("\nУменьшение в 2");
           for (int ctr = 0; ctr < size; ctr++)
           {
               int Reduces = deleg(massiv[ctr]); 
               Console.Write("{0} ", Reduces);
           }

           deleg = new IntOperation(Pow);
           Console.WriteLine("\nВозводим в квадрат 2");
           for (int ctr = 0; ctr < size; ctr++)
           {
               int Pows = deleg(massiv[ctr]); 
               Console.Write("{0} ",Pows);
           }
           deleg = new IntOperation(Prime);
           Console.WriteLine("\nПростое число");
           for (int ctr = 0; ctr < size; ctr++)
           {
               int Primes = deleg(massiv[ctr]); 
               Console.Write("{0} ",Primes);
           }
           Console.ReadKey();
        }
    }
}
