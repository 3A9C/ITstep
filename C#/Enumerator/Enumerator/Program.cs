using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Enumerator
{

    using System.Collections;

    public class Colors: IEnumerable
    {
        List<string> colors = new List<string>();

        public void Add(string color)
        {
            colors.Add(color);
        }
        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumrator();
        }

        public IEnumerator<string> GetEnumrator() 
        {
            foreach (var c in colors)
            {
                yield return c;
            }
        }

    }



    class Program
    {



        static void Main(string[] args)
        {
            Colors advertising = new Colors();
            advertising.Add("promo.mp4");
            var en = advertising.GetEnumrator();
            while (en.MoveNext())
            {
                Console.WriteLine(en.Current);
            }

            foreach (var x in advertising)
            {
                Console.WriteLine( x);
            }
            foreach (var x in advertising)
            {
                Console.WriteLine(x);
            }

        }
    }
}
