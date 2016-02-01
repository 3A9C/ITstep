using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Junctions
{
    public class Road
    {
        public Junction junc1, junc2;
        public int amountOfCars;
        public int maxSpeed;
        public int halfLoad;

        public Road(Junction junc1_, Junction junc2_, int maxSpeed_, int halfLoad_)
        {
            if (junc1_.relatedRoads.Count == 4 ||
                junc2_.relatedRoads.Count == 4)
            {
                throw new ArgumentException("In Road(Junction. Junction): one of junctions already has 4 roads!");
            }

            amountOfCars = 0;
            junc1 = junc1_;
            junc1_.relatedRoads.Add(this);
            junc2 = junc2_;
            junc2_.relatedRoads.Add(this);
            maxSpeed = maxSpeed_;
            halfLoad = halfLoad_;
        }
    }
}
