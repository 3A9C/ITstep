using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _9_Metro
{
    class Transport
    {
        int transport_count_places = 100;
        public static int count = 0;

        public Transport()
        {
            transport_count_places = transport_count_places - count;

            Console.WriteLine(" Count {0} | Transport {1}", count, transport_count_places);
        }

    }
}