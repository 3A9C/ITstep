using System;
using System.Xml;
using System.Collections.Generic;
class MyApp
{
    //static void displayNode(XmlNode node, int level = 0)
    //{

    //    if (node.NodeType == XmlNodeType.Element)
    //    {
    //        Console.Write(new String(' ', level) + node.Name);
    //        foreach (XmlAttribute a in node.Attributes)
    //        {
    //            Console.Write(" {0}='{1}'", a.Name, a.Value);
    //        }
    //        Console.WriteLine();
    //    }
    //    if (node.NodeType == XmlNodeType.Text)
    //    {
    //        Console.WriteLine(new String(' ', level) + '*' + node.Value + '*');
    //    }


    //    foreach (XmlNode child in node.ChildNodes)
    //    {
    //        displayNode(child, level + 1);
    //    }
    //}

    class Automobile
    {
        public string Сompany { get; set; }

        public string Model { get; set; }

        public string Color { get; set; }

        public int Year { get; set; }

        public int Speed { get; set; }


    }


    static void Main()
    {
        XmlDocument doc = new XmlDocument();
        doc.Load(@"../../Cars.xml");
        //XmlNode root = doc.ChildNodes[1];
        //displayNode(root);
        List<Automobile> cars = new List<Automobile>();      


        XmlNodeList nodes = doc.GetElementsByTagName("Car");
        foreach (XmlNode node in nodes)
        {
            cars.Add(new Automobile() { 
                Сompany = node["Manufactured"].InnerText, 
                Model = node["Model"].InnerText, 
                Color = node["Color"].InnerText, 
                Year = Convert.ToInt32(node["Year"].InnerText), 
                Speed = Convert.ToInt32(node["Speed"].InnerText) 
            });   
        }

        foreach (Automobile aPart in cars)
        {
            Console.WriteLine(aPart.Сompany +" "+ aPart.Model +" "+ aPart.Color +" "+ aPart.Year +" "+ aPart.Speed);
        }
        Console.ReadKey();
    }
}
