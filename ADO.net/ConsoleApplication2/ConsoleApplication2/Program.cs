using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using A = B;

namespace B
{
    struct str
    {
        public void metod()
        { 
        }
    }

    class Point

{

public int x; public int y;

public override string ToString()

{

return string.Format("X : {0}  Y : {1}\n", x, y);
}
    }

        class Program
        {

            static void Main()
            {
                Point p = new Point();

                p.x = 5;
                p.y = 6;

                fixed (int* ptr = &p.x)
                {

                    *ptr = 15; Console.WriteLine(p);

                }


                Console.WriteLine(p);
            }
        }
}