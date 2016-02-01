using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _9_Metro
{
    class Station
    {
        public string name;
        public readonly uint average_period;
        public Queue<Passenger> passengers_queue;

        public Station(string station_name, uint time_period)
        {
            average_period = time_period;
            passengers_queue = new Queue<Passenger>();
            name = station_name;
        }

        public void AddPassengerOnArrival(uint time)
        {
            Passenger passenger = new Passenger(time, this);
            passengers_queue.Enqueue(passenger);
            Console.WriteLine("{0}", passengers_queue.Count);
            Program.event_queue1.Add(time + average_period, AddPassengerOnArrival);
        }

    }
}