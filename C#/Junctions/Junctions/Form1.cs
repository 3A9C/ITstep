using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Junctions
{
    public partial class Form1 : Form
    {
        public static List<Junction> junctions = new List<Junction>();
        public static List<Road> roads = new List<Road>();
        public static List<Car> cars = new List<Car>();

        public Form1()
        {
            InitializeComponent();

            junctions.Add(new Junction(15, this.ClientRectangle.Height - 15)); //1 точка
            junctions.Add(new Junction(15 + 20, this.ClientRectangle.Height - 15));  // 2 точка
            junctions.Add(new Junction(15 + 80, this.ClientRectangle.Height - 15)); //3 точка
            junctions.Add(new Junction(15 + 80, this.ClientRectangle.Height - 15 - 30)); //4 точка
            junctions.Add(new Junction(15 + 60, this.ClientRectangle.Height - 15 - 30)); //5 точка
            junctions.Add(new Junction(15 + 20, this.ClientRectangle.Height - 15 - 30)); //6 точка
            junctions.Add(new Junction(15, this.ClientRectangle.Height - 15 - 30)); //7 точка
            junctions.Add(new Junction(15 + 60, this.ClientRectangle.Height - 15 - 50)); //8 точка
            junctions.Add(new Junction(15 + 80, this.ClientRectangle.Height - 15 - 50)); //9 точка
            junctions.Add(new Junction(15 + 120, this.ClientRectangle.Height - 15 - 50)); //10 точка
            junctions.Add(new Junction(15 + 120, this.ClientRectangle.Height - 15 - 70)); //11 точка
            junctions.Add(new Junction(15 + 80, this.ClientRectangle.Height - 15 - 70)); //12 точка
            junctions.Add(new Junction(15 + 20, this.ClientRectangle.Height - 15 - 70)); //13 точка
            junctions.Add(new Junction(15 + 80, this.ClientRectangle.Height - 15 - 90)); //14 точка
            junctions.Add(new Junction(15 + 40, this.ClientRectangle.Height - 15 - 90)); //15 точка
            junctions.Add(new Junction(15, this.ClientRectangle.Height - 15 - 110)); //16 точка
            junctions.Add(new Junction(15 + 40, this.ClientRectangle.Height - 15 - 110)); //17 точка
            junctions.Add(new Junction(15 + 80, this.ClientRectangle.Height - 15 - 110)); //18 точка
            junctions.Add(new Junction(15 + 120, this.ClientRectangle.Height - 15 - 110)); //19 точка
            junctions.Add(new Junction(15 + 120, this.ClientRectangle.Height - 15 - 150)); //20 точка
            junctions.Add(new Junction(15 + 80, this.ClientRectangle.Height - 15 - 150)); //21 точка
            junctions.Add(new Junction(15 + 40, this.ClientRectangle.Height - 15 - 150)); //22 точка
            junctions.Add(new Junction(15 + 120, this.ClientRectangle.Height - 15 - 170)); //23 точка
            junctions.Add(new Junction(15 + 40, this.ClientRectangle.Height - 15 - 170)); //24 точка
            junctions.Add(new Junction(15, this.ClientRectangle.Height - 15 - 170)); //25 точка


            roads.Add(new Road(junctions[0], junctions[1], 70, 15)); // 1-2
            roads.Add(new Road(junctions[1], junctions[2], 70, 15)); // 2-3
            roads.Add(new Road(junctions[2], junctions[3], 70, 15)); // 3-4
            roads.Add(new Road(junctions[3], junctions[4], 70, 15)); // 4-5
            roads.Add(new Road(junctions[4], junctions[5], 70, 15)); // 5-6
            roads.Add(new Road(junctions[5], junctions[6], 70, 15)); // 6-7
            roads.Add(new Road(junctions[6], junctions[0], 70, 15)); // 7-1
            roads.Add(new Road(junctions[5], junctions[1], 70, 15)); // 6-2
            roads.Add(new Road(junctions[3], junctions[8], 70, 15)); // 4-9
            roads.Add(new Road(junctions[4], junctions[7], 70, 15)); // 8-5
            roads.Add(new Road(junctions[8], junctions[7], 70, 15)); // 8-7
            roads.Add(new Road(junctions[8], junctions[9], 70, 15)); // 9-10
            roads.Add(new Road(junctions[10], junctions[9], 70, 15)); // 10-11
            roads.Add(new Road(junctions[10], junctions[11], 70, 15)); // 12-11
            roads.Add(new Road(junctions[8], junctions[11], 70, 15)); // 12-9
            roads.Add(new Road(junctions[12], junctions[11], 70, 15)); // 12-13
            roads.Add(new Road(junctions[12], junctions[5], 70, 15)); // 6-13
            roads.Add(new Road(junctions[13], junctions[11], 70, 15)); // 14-12
            roads.Add(new Road(junctions[14], junctions[13], 70, 15)); // 15-14
            roads.Add(new Road(junctions[16], junctions[14], 70, 15)); // 17-15
            roads.Add(new Road(junctions[15], junctions[6], 70, 15)); // 16-7
            roads.Add(new Road(junctions[15], junctions[24], 70, 15)); // 16-25
            roads.Add(new Road(junctions[23], junctions[24], 70, 15)); // 24-25
            roads.Add(new Road(junctions[23], junctions[22], 70, 15)); // 24-23
            roads.Add(new Road(junctions[19], junctions[22], 70, 15)); // 23-20
            roads.Add(new Road(junctions[19], junctions[18], 70, 15)); // 19-20
            roads.Add(new Road(junctions[10], junctions[18], 70, 15)); // 11-19
            roads.Add(new Road(junctions[19], junctions[20], 70, 15)); // 20-21
            roads.Add(new Road(junctions[21], junctions[20], 70, 15)); // 22-21
            roads.Add(new Road(junctions[21], junctions[16], 70, 15)); // 22-17
            roads.Add(new Road(junctions[23], junctions[21], 70, 15)); // 24-22
            roads.Add(new Road(junctions[16], junctions[17], 70, 15)); // 17-18
            roads.Add(new Road(junctions[17], junctions[18], 70, 15)); // 18-19
            roads.Add(new Road(junctions[15], junctions[16], 70, 15)); // 16-17
            roads.Add(new Road(junctions[20], junctions[17], 70, 15)); // 20-17


            int amountOfCars = 17;
            for (int i = 0; i < amountOfCars; ++i)
            {
                cars.Add(new Car());
            }
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Pen penForRoads = new Pen(Color.DarkGreen, 7);
            
            SolidBrush brushForCars = new SolidBrush(Color.Orange);

            foreach (Road road in roads)
            {
                e.Graphics.DrawLine(penForRoads, road.junc1.x, road.junc1.y,
                    road.junc2.x, road.junc2.y);

                int lengthInXAxis = road.junc2.x - road.junc1.x;
                int lengthInYAxis = road.junc2.y - road.junc1.y;

                for (int i = 0; i < road.amountOfCars; ++i)
                {
                    int x = road.junc1.x + lengthInXAxis / (road.amountOfCars + 1) * (i + 1);
                    int y = road.junc1.y + lengthInYAxis / (road.amountOfCars + 1) * (i + 1);
                    e.Graphics.FillEllipse(brushForCars, x - 4, y - 4, 8, 8);
                }
            }

            SolidBrush br = new SolidBrush(Color.Black);

            foreach (Junction junc in junctions)
            {
                e.Graphics.FillEllipse(br,
                    new Rectangle(junc.x - 8, junc.y - 8, 16, 16));
            }
        }
    }
}
