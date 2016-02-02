using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _6_ShopAuto
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'dBAutoDataSet.TMotor' table. You can move, or remove it, as needed.
            this.tMotorTableAdapter.Fill(this.dBAutoDataSet.TMotor);
            // TODO: This line of code loads data into the 'dBAutoDataSet.TOwner' table. You can move, or remove it, as needed.
            this.tOwnerTableAdapter.Fill(this.dBAutoDataSet.TOwner);
            // TODO: This line of code loads data into the 'dBAutoDataSet.TAuto' table. You can move, or remove it, as needed.
            this.tAutoTableAdapter.Fill(this.dBAutoDataSet.TAuto);
            // TODO: This line of code loads data into the 'dBAutoDataSet.TOwner' table. You can move, or remove it, as needed.
            this.tOwnerTableAdapter.Fill(this.dBAutoDataSet.TOwner);
            // TODO: This line of code loads data into the 'dBAutoDataSet.TAuto' table. You can move, or remove it, as needed.
            this.tAutoTableAdapter.Fill(this.dBAutoDataSet.TAuto);

        }

    }
}
