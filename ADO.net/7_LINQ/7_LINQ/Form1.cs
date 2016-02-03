using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Serialization;
using System.Xml;

namespace _7_LINQ
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            XmlReader xmlFile1;
            xmlFile1 = XmlReader.Create("../../cd_catalog _1.xml", new XmlReaderSettings());
            DataSet ds1 = new DataSet();
            ds1.ReadXml(xmlFile1);
            dataGridView1.DataSource = ds1.Tables[0];

            XmlReader xmlFile2;
            xmlFile2 = XmlReader.Create("../../cd_catalog _2.xml", new XmlReaderSettings());
            DataSet ds2 = new DataSet();
            ds2.ReadXml(xmlFile2);
            dataGridView2.DataSource = ds2.Tables[0];

            List<string> cd_catalog_1 = dataGridView1.Rows
                       .OfType<DataGridViewRow>()
                       .Where(x => x.Cells[1].Value != null)
                       .Select(x => x.Cells[1].Value.ToString())
                       .ToList();

            List<string> cd_catalog_2 = dataGridView2.Rows
                       .OfType<DataGridViewRow>()
                       .Where(x => x.Cells[1].Value != null)
                       .Select(x => x.Cells[1].Value.ToString())
                       .ToList();
        }
    }
}
