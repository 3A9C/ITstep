using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace ReklamaBuildBord
{
    class Program
    {
        class Reklama
        {
            // Auto-implemented properties.
            public int Show { get; set; }
            public int Time { get; set; }
            public int TV1 { get; set; }
            public int TV2 { get; set; }
            public string Name { get; set; }
        }

        static void Main()
        {

            List<Reklama> Advertising = new List<Reklama>();
            Advertising.Add(new Reklama() { Name = "promo.mp4", Show = 0, Time = 666, TV1 = 0, TV2 = 0 }); // Наша реклама
            Advertising.Add(new Reklama() { Name = "1.mp4", Show = 50, Time = 1200, TV1 = 0, TV2 = 0 });//120
            Advertising.Add(new Reklama() { Name = "2.mp4", Show = 45, Time = 1000, TV1 = 0, TV2 = 0 }); // 100
            Advertising.Add(new Reklama() { Name = "3.mp4", Show = 40, Time = 1800, TV1 = 0, TV2 = 0 }); //180
            Advertising.Add(new Reklama() { Name = "4.mp4", Show = 15, Time = 800, TV1 = 0, TV2 = 0 }); // 80
            // Display results.
            System.Console.WriteLine("Show Advertising\n");// Какую рекламу будем показывать


            while(true)
            {
                for (int i = 0; i < Advertising.Count; ++i )
                {
                    Random rnd = new Random();
                    int TV = rnd.Next(1, 3);
                    if (TV == 1)
                        Advertising[i].TV1 += 1;
                    else
                        Advertising[i].TV2 += 1;
                    Advertising[i].Time -= Advertising[i].Show;
                    System.Console.WriteLine(Advertising[i].Name + " SHOW " + Advertising[i].Show + " TimeOut " + Advertising[i].Time + " ShowTV1 " + Advertising[i].TV1 + " ShowTV2 " + Advertising[i].TV2);
                    if (Advertising[i].Time <= 0)
                    {
                        Advertising.Remove(Advertising[i]);
                    }
                }

                Thread.Sleep(500);
                System.Console.WriteLine("\n\n");// Какую рекламу будем показывать
            }
        }
    }
}
