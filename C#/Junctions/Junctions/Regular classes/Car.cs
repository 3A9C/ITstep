using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Junctions
{
    public class Car
    {
        private static Random rand = new Random(DateTime.Now.Ticks.GetHashCode());

        public Junction to;
        public Road currentRoad;

        public Car()
        {
            to = Form1.junctions[rand.Next(Form1.junctions.Count)];
            this.makeDecision();
        }

        public void makeDecision()
        {
            // съехали со старой дороги
            if (currentRoad != null)
            {
                currentRoad.amountOfCars--;
            }

            // заехали на новую дорогу
            //currentRoad = to.relatedRoads[rand.Next(to.relatedRoads.Count)];
            //currentRoad.amountOfCars++;
            //var newJunction = currentRoad.junc1 == to ?
            //    currentRoad.junc2 : currentRoad.junc1;
            // расчет длины и времени (дописать)
            //to = newJunction;
        }
    }
}
