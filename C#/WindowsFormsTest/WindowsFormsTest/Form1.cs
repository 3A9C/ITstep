using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Net;
using System.Threading.Tasks;
using System.Windows.Forms;
using xNet;

namespace WindowsFormsTest
{
    public partial class Form1 : Form
    {
        Form2 Frm2;
        static PointTest user = new PointTest();
        public Form1()
        {
            InitializeComponent();
            Frm2 = new Form2(this);

            List<PointTest> user = new List<PointTest>();
            user.Add(new PointTest() { UserName = "1991", Password = "1234" });
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text == user.UserName & textBox2.Text == user.Password)
            {
                Frm2.label3.Text = user.UserName;
                Frm2.Show();//метод для отображения второй формы
                this.Hide();
            }
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
