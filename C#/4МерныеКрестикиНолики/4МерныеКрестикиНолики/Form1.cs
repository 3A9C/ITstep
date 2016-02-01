using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Text.RegularExpressions;

namespace _4МерныеКрестикиНолики
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        string winX = "0";
        string winO = "0";
        string step = "X";
        int[] arr = new int[3];
        int[, ,] CheckGames = new int[4, 4, 4];

        private void button_MouseClick(object sender, MouseEventArgs e)
        {
            Regex reg = new Regex(@"[0-9]", RegexOptions.IgnoreCase);
            MatchCollection mc = reg.Matches(((Button)sender).Name);

            foreach (Match mat in mc)
            {

                int s = 0;
                string ss = mat.Value;
                arr[s] = Convert.ToInt16(ss);
                MessageBox.Show(arr[s].ToString(), "Заголовок сообщения", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
            }

            ((Button)sender).Text = step;
            ((Button)sender).Enabled = false;

            check_game();
        }

        private void check_game()
        {
            for(int t = 1; t < 4; ++t)
            {
                for(int r = 1; r < 4; ++r)
                {
                    for(int c = 1; c < 4; ++c)
                    {

                    }
                }
            }
        }


    }
}
