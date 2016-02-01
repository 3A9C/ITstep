using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VectorVector
{
    class Vector
    {
        int x, y, z;

        public Vector() { }
        public Vector(int vx, int vy, int vz)
        {
            x = vx;
            y = vy;
            z = vz;
        }
        public Vector addition(Program b)
        {
            Vector res = new Vector();
            res.x = x + b.x;
            res.y = y + b.y;
            res.z = z + b.z;
            return res;
        }
        public int DotProduct(Program a, Program b)
        {
            int res;
            res = a.x * b.x + a.y * b.y + a.z * b.z;
            return res;
        }
        public Vector VectorProduct(Program a, Program b)
        {
            Vector res = new Vector();

            res.x = a.y * b.z - a.z * b.y;
            res.y = a.x * b.z - a.z * b.x;
            res.z = a.x * b.y - a.y * b.x;
            return res;
        }
        public void Print(Program a, Program b)
        {
            Console.WriteLine("Массив двум : ", a);
        }
    }
}
