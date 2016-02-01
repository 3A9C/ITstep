using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using VKaudio;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace VKMusic
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {  
        [DllImport("wininet.dll", SetLastError = true)]
        static extern bool InternetCheckConnection(string lpszUrl, int dwFlags, int dwReserved);

        public authVK()
        {
            InitializeComponent();
        }

        private void AvtorizationForm_Load(object sender, EventArgs e)
        {


            if (!InternetCheckConnection(@"http://vk.com", 1, 0))
            {
                MessageBox.Show("Не могу соединиться Vkontakte.com\r\nПроверте соединения с интернетом\r\nПрограмма закроеться");
                Environment.Exit(0);
            }
            webBrowser1.ScriptErrorsSuppressed = true;    
            webBrowser1.Navigate(@"https://oauth.vk.com/authorize?" +
                                 "client_id=3687802&" +
                                 "scope=audio&" +
                                 "redirect_uri=https://oauth.vk.com/blank.html&" +
                                 "display=popup&" +
                                 "v=5.8&" +
                                 "response_type=token ");
        }

        private void webBrowser1_Navigating(object sender, WebBrowserNavigatingEventArgs e)
        {
            toolStripStatusLabel1.Text = "Загрузка ";
        }

        private void webBrowser1_DocumentCompleted(object sender, WebBrowserDocumentCompletedEventArgs e)
        {
            toolStripStatusLabel1.Text = "Загружено ";

            String url = webBrowser1.Url.ToString();
            try
            {
                string l = url.Split('#')[1];
                if (l[0] == 'a')
                {
                    Settings1.Default.token = l.Split('&')[0].Split('=')[1];
                    Settings1.Default.id = l.Split('=')[3];
                    Settings1.Default.auth = true;
                    //MessageBox.Show(Settings1.Default.token +"  "+ Settings1.Default.id);
                    System.Diagnostics.Process.Start("rundll32.exe", "InetCpl.cpl,ClearMyTracksByProcess 255");
                    this.Close();
                }
            }
            catch (Exception ex) { toolStripStatusLabel1.Text += ex.Message; }
        }
    }
}
