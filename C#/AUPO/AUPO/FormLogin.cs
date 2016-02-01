using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Windows.Forms;
using System.Net;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;

namespace AUPO
{
    public partial class FormLogin : Form
    {

        public FormLogin()
        {
            InitializeComponent();
        }

        private void Kufar_sCookies()
        {
                
            // первый запрос на куки
            HttpWebRequest myHttpWebRequest = (HttpWebRequest)HttpWebRequest.Create("http://pass.pronto.ru/client/controller.php?test_cookie=9913&action=login&puid=fa02b8fb617554c9b89e606c2653cb5f&suid=542bb4fa78ee3f6714240000&login=deiviah@gmail.comm&password=z80951771223&return_path=http%3A%2F%2Firr.by%2Fcontrollers%2Fpassport%2Fauth.php&rnd=3431");
            myHttpWebRequest.AllowAutoRedirect = false;
            myHttpWebRequest.Host = "www.kufar.by";
            myHttpWebRequest.UserAgent = "Mozilla/5.0 (Windows NT 6.1; rv:41.0) Gecko/20100101 Firefox/41.0";
            myHttpWebRequest.Accept = "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8";
            myHttpWebRequest.Headers.Add("Accept-Language", "ru-RU,ru;q=0.8,en-US;q=0.5,en;q=0.3");
            myHttpWebRequest.Headers.Add("Accept-Encoding", "gzip, deflate");
            HttpWebResponse myHttpWebResponse = (HttpWebResponse)myHttpWebRequest.GetResponse();


            string sCookies = String.IsNullOrEmpty(myHttpWebResponse.Headers["Set-Cookie"]) ? "" : myHttpWebResponse.Headers["Set-Cookie"];
            richTextBox1.Text += sCookies;
            // второй запрос авторизация
            
            //Kufar_sesion(sCookies);

        }
        private void Kufar_sesion(string sCookies)
        {

            HttpWebRequest myHttpWebRequest = (HttpWebRequest)HttpWebRequest.Create("https://www.kufar.by/account/do_login");
            myHttpWebRequest.Method = "POST";
            myHttpWebRequest.Referer = "https://www.kufar.by/%D0%B1%D0%B5%D0%BB%D0%B0%D1%80%D1%83%D1%81%D1%8C/%D0%BF%D1%80%D0%BE%D0%B4%D0%B0%D0%B5%D1%82%D1%81%D1%8F";
            myHttpWebRequest.UserAgent = "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/46.0.2490.80 Safari/537.36";
            myHttpWebRequest.Accept = "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8";
            myHttpWebRequest.Headers.Add("Accept-Language", "ru-RU,ru;q=0.8,en-US;q=0.6,en;q=0.4");
            myHttpWebRequest.ContentType = "application/x-www-form-urlencoded";

            // передаем cookie, полученные в предыдущем запросе
            if (!String.IsNullOrEmpty(sCookies))
                myHttpWebRequest.Headers.Add(HttpRequestHeader.Cookie, sCookies);

            // ставим False, чтобы при получении кода 302 не делать 
            // автоматического перенаправления
            myHttpWebRequest.AllowAutoRedirect = false;

            // передаем параметры
            TimeSpan ts = DateTime.Now - new DateTime(1970, 1, 1);
            string sQueryString = "email=" + textBox1.Text + "&passwd=" + textBox2.Text + "&login=%D0%92%D0%BE%D0%B9%D1%82%D0%B8";
            byte[] ByteArr = System.Text.Encoding.GetEncoding(65001).GetBytes(sQueryString);
            myHttpWebRequest.ContentLength = ByteArr.Length;
            myHttpWebRequest.GetRequestStream().Write(ByteArr, 0, ByteArr.Length);

            // делаем запрос
            HttpWebResponse myHttpWebResponse = (HttpWebResponse)myHttpWebRequest.GetResponse();
            richTextBox1.Text += String.IsNullOrEmpty(myHttpWebResponse.Headers["Set-Cookie"]) ? "" : myHttpWebResponse.Headers["Set-Cookie"];
            richTextBox1.Text += myHttpWebResponse.Headers["Location"];
            // второй запрос авторизация

            string sLocation = myHttpWebResponse.Headers["Location"];
            // получам cookie
            sCookies = "";
            if (!String.IsNullOrEmpty(myHttpWebResponse.Headers["Set-Cookie"]))
            {
                sCookies = myHttpWebResponse.Headers["Set-Cookie"];
            }

            myHttpWebRequest = (HttpWebRequest)HttpWebRequest.Create("https://www.kufar.by/account/my_ads/published");
            myHttpWebRequest.Referer = "https://www.kufar.by/" + sLocation;
            myHttpWebRequest.UserAgent = "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/46.0.2490.80 Safari/537.36";
            myHttpWebRequest.Accept = "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8";
            myHttpWebRequest.Headers.Add("Accept-Language", "ru-RU,ru;q=0.8,en-US;q=0.6,en;q=0.4");
            myHttpWebRequest.ContentType = "text/plain";
            if (!String.IsNullOrEmpty(sCookies))
            {
                myHttpWebRequest.Headers.Add(HttpRequestHeader.Cookie, sCookies);
            }

            // выполняем запрос
            myHttpWebResponse = (HttpWebResponse)myHttpWebRequest.GetResponse();

            // выводим результат в консоль
            StreamReader myStreamReader =
              new StreamReader(myHttpWebResponse.GetResponseStream(),
              Encoding.GetEncoding(65001));

            string tml = myStreamReader.ReadToEnd();
            Match m = Regex.Match(tml, @"<b class=""popup_office__name"">(.*)<");
            richTextBox1.Text += m;
        }
        private void button1_Click(object sender, EventArgs e)
        {
            Kufar_sCookies();
        }
    }
}
