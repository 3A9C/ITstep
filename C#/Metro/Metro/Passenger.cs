using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _9_Metro
{
    class Passenger
    {
        public Station from, to;
        public Passenger(uint time, Station station_from)
        {
            from = station_from;

            Random rand = new Random();
            int indexOfCurrentStation = Array.FindIndex(Program.stations, (st) => st == station_from);
            int indexOfLastStation = Program.stations.Length - 1;
            to = Program.stations[rand.Next(0, indexOfLastStation)];

            Console.Write("Time {0} | Station {1} | Passengers ", time, from.name);
        }
    }
}