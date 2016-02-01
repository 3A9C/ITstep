using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsTest
{
    public partial class Form2 : Form
    {
        Form1 Frm1;

        public Form2(Form1 F)
        {
            InitializeComponent();
            Frm1 = F;
        }
        private void button1_Click(object sender, EventArgs e)
        {
            user.Password = textBox1.Text;
            textBox1.Text = "";
            MessageBox.Show("Пароль изменен на " + user.Password, "Успешно", MessageBoxButtons.OK);
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Frm1.Show();
            this.Hide();
            Frm1.textBox2.Text = "";
        }
    }
}
