using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Resources;
using System.Globalization;
using System.Threading;

namespace Localization
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }


        private void button2_Click(object sender, EventArgs e)
        {
            // C#
            // Declare a Resource Manager instance.
            ResourceManager LocRM = new ResourceManager("Localization.WinFormStrings", typeof(Form1).Assembly);
            // Assign the string for the "strMessage" key to a message box.
            label1.Text = LocRM.GetString("strMessage");

            if (button2.Text == "ru-RU")
            {
                Thread.CurrentThread.CurrentUICulture = new CultureInfo("fr-FR");
                button2.Text = "fr-FR";
            }
            else if (button2.Text == "fr-FR")
            {
                Thread.CurrentThread.CurrentUICulture = new CultureInfo("de-DE");
                button2.Text = "de-DE";
            }
            else if (button2.Text == "de-DE")
            {
                Thread.CurrentThread.CurrentUICulture = new CultureInfo("ru-RU");
                button2.Text = "ru-RU";
            }
        }
    }
}
