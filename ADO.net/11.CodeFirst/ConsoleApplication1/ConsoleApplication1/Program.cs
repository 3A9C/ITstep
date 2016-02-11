using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
           // Context db = new Context(ConfigurationManager.ConnectionStrings["ConnectionCarList"].ConnectionString);

            string CS = @"data source=(localdb)\v11.0;AttachDBFileName=D:\daa\First.mdf;Integrated Security=true;";
            Context db = new Context(CS);

            Car car = new Car() { Name = "BMW", Fuel = 50, Url = "car_url" };
            db.Cars.Add(car);
            db.SaveChanges();

            foreach (var item in db.Cars)
            {
                Console.WriteLine("{0}{1}", item.Name, item.Fuel);
            }

            Console.ReadKey();

        }
    }
}
