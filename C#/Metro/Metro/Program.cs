using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _9_Metro
{
    class Program
    {
        public static EventQueue event_queue1 = new EventQueue();
        public static Station[] stations = new Station[5] { new Station("Minsk", 5), new Station("Osipovichi", 17), new Station("Bobruisk", 7), new Station("Zhlobin", 12), new Station("Gomel", 4) };

        static void Main(string[] args)
        {
            for (int i = 0; i < stations.Length; ++i )
                event_queue1.Add(0, stations[i].AddPassengerOnArrival);

            event_queue1.Start(50); //processing EventQueue


            Console.ReadKey();
        }
    }
}