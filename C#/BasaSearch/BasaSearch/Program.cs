using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;



namespace DataBase
{
    class Program
    {
        static void Main(string[] args)
        {
<<<<<<< HEAD
            DataBase test = new DataBase("test.txt");

            Record rec = test.ReadRecord(6);

            test.indexes.Add(new Index("test.txt"));
            test.indexes[0].CreateIndex(0, test.file_keys);

            Console.ReadKey();
=======
            foreach (string line in File.ReadLines(@"..\\..\\text.txt"))
            {
                if (line.Contains("устал") & line.Contains("знакомых"))
                {
                    Console.WriteLine(line);
                }
            }
            Console.WriteLine("END");
            Console.Read();
>>>>>>> 487018a1e77dd68bee151360b770b915ee720faa
        }

    }
}