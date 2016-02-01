using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Net;
using System.IO;
using System.Web;
using Newtonsoft.Json.Linq;
using NAudio.Wave;
using System.Threading;
using VKaudio;

namespace PleerVKontakte
{
    public partial class Form1 : Form
    {
        List<Audio> audioList = new List<Audio>();
        public class Audio
        {
            public int aid { get; set; }
            public int owner_id { get; set; }
            public string artist { get; set; }
            public string title { get; set; }
            public int duration { get; set; }
            public string url { get; set; }
            public string lurics_id { get; set; }
            public int genre { get; set; }
        }
        int PlaySongNumber = 0;
        int PrevSongNubmer = 0;
        private int playSongNumber
        {
            get { return PlaySongNumber; }
            set
            {
                if (value < audioList.Count && value >= 0)
                {
                    PlaySongNumber = value;
                }
                else if (value >= audioList.Count)
                {
                    PlaySongNumber = 0;
                }
                else if (value < 0)
                {
                    PlaySongNumber = audioList.Count - 1;
                }

            }
        }
        bool isStopButton = false;

        public Form1()
        {
            new authVK().ShowDialog();
            InitializeComponent();
            if (!Settings1.Default.auth){Environment.Exit(0);}
            backgroundWorker1.RunWorkerAsync();
        }

        WaveStream blockAlignedStream;
        WaveOut waveOut;
        public void PlayMp3FromUrl(string url)
        {
            using (Stream ms = new MemoryStream())
            {
                using (Stream stream = WebRequest.Create(url).GetResponse().GetResponseStream())
                {
                    byte[] buffer = new byte[32768];
                    int read;
                    while ((read = stream.Read(buffer, 0, buffer.Length)) > 0)
                    {
                        ms.Write(buffer, 0, read);
                    }
                }
                ms.Position = 0;
                using (blockAlignedStream = new BlockAlignReductionStream(WaveFormatConversionStream.CreatePcmStream(new Mp3FileReader(ms))))
                {
                    waveOut = new WaveOut(WaveCallbackInfo.FunctionCallback());
                    waveOut.Init(blockAlignedStream);
                    this.Invoke((MethodInvoker)delegate { trackBar1.Maximum = (int)(blockAlignedStream.Length / 10); });
                    waveOut.Play();
                    long equalPosition = blockAlignedStream.Position;
                    int breakPlay = 0;
                    while ((waveOut.PlaybackState == PlaybackState.Playing) && (blockAlignedStream.Length != blockAlignedStream.Position) && (breakPlay != 5))
                    {
                        System.Threading.Thread.Sleep(100);
                        Invoke(new UpdDelegate(mbox), new object[] { blockAlignedStream.CurrentTime.Minutes + " : " + blockAlignedStream.CurrentTime.Seconds, blockAlignedStream.TotalTime.Minutes + " : " + blockAlignedStream.TotalTime.Seconds });
                        if (!isMousDown)
                        {
                            this.Invoke((MethodInvoker)delegate { trackBar1.Value = (int)(blockAlignedStream.Position / 10); });
                        }
                        if (blockAlignedStream.Position == equalPosition)
                        {
                            breakPlay++;
                        }
                        equalPosition = blockAlignedStream.Position;
                        System.Threading.Thread.Sleep(200);
                    }
                    if (!isStopButton)
                    {
                        Thread temp = new Thread(t => tempM());
                        temp.Name = "tempForward";
                        temp.Start();
                    }
                    
                }
            }

        }

        void tempM()
        {
            playSongNumber++;
            Play();
        }

        void mbox(string text, string text2)
        {
            label1.Text = text;
            label2.Text = text2;
        }
        protected delegate void UpdDelegate(string text, string text2);

        Thread playTh;
        private void Play()
        {
            this.Cursor = Cursors.WaitCursor;
            if (playTh != null)
            {
                playTh.Abort();
                playTh = null;
            }
            playTh = new Thread(t => PlayMp3FromUrl(audioList[playSongNumber].url));
            this.Invoke((MethodInvoker)delegate { label3.Text = audioList[playSongNumber].title; });
            //label3.Text = audioList[playSongNumber].title;
            playTh.Name = "MyThread";
            playTh.IsBackground = true;
            playTh.Start();
            listView1.Items[playSongNumber].ForeColor = Color.Blue;
            if (listView1.Items[playSongNumber].ForeColor == Color.Blue & PrevSongNubmer != PlaySongNumber)
            {
                listView1.Items[PrevSongNubmer].ForeColor = Color.Black;
            }

            PrevSongNubmer = PlaySongNumber;
            this.Cursor = Cursors.Default;
        }


        private void buttonBack_Click(object sender, EventArgs e)
        {
            isStopButton = true;
            if (waveOut != null)
            {
                waveOut.Stop();
            }
            playSongNumber--;
            Play();
        }

        private void buttonPlay_Click(object sender, EventArgs e)
        {
            Play();
            isStopButton = false;
            buttonStop.Visible = true;
            buttonPlay.Visible = false;
        }

        private void buttonStop_Click(object sender, EventArgs e)
        {
            isStopButton = true;
            if (waveOut != null)
            {
                waveOut.Stop();
            }
            buttonPlay.Visible = true;
            buttonStop.Visible = false;
        }

        private void buttonForward_Click(object sender, EventArgs e)
        {
            isStopButton = true;
            if (waveOut != null)
            {
                waveOut.Stop();
            }
            playSongNumber++;
            Play();
        }

        private void backgroundWorker1_DoWork(object sender, DoWorkEventArgs e)
        {
            while (!Settings1.Default.auth) { System.Threading.Thread.Sleep(500); }

            WebRequest requ = WebRequest.Create("https://api.vk.com/method/audio.get?owner_id=" + Settings1.Default.id + "&need_user=0&access_token=" + Settings1.Default.token);
            WebResponse resp = requ.GetResponse();
            Stream datas = resp.GetResponseStream();
            StreamReader reader = new StreamReader(datas);
            string resFrSer = reader.ReadToEnd();
            reader.Close();
            resp.Close();
            resFrSer = HttpUtility.HtmlDecode(resFrSer);

            JToken token = JToken.Parse(resFrSer);
            audioList = token["response"].Children().Skip(1).Select(c => c.ToObject<Audio>()).ToList();
            for (int i = 0; i < audioList.Count; i++)
            {
                this.Invoke((MethodInvoker)delegate { listView1.Items.Add(new ListViewItem(new string[] { i.ToString(), audioList[i].title })); });
            }
        }

        private void listView1_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            playSongNumber = int.Parse(listView1.SelectedItems[0].Text);
            Play();
        }

        private void trackBar1_MouseUp(object sender, MouseEventArgs e)
        {
            if (blockAlignedStream == null) { return; }
            long time = trackBar1.Value * 10;
            while (time % blockAlignedStream.BlockAlign != 0)
            {
                time++;
            }
            try
            {
                blockAlignedStream.Position = time;
            }
            catch (Exception) { }
            //label2.Text = (trackBar1.Value * 10).ToString();
            isMousDown = false;
        }
        
        bool isMousDown = false;
        private void trackBar1_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == System.Windows.Forms.MouseButtons.Left)
            {
                isMousDown = true;
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (waveOut != null)
            {
                waveOut.Stop();
            }
            Environment.Exit(0);
        }


        private void button1_Click(object sender, EventArgs e)
        {

            var item = listView1.FindItemWithText(" ");

            if (item != null)
            {
                MessageBox.Show(listView1.Items.IndexOf(item).ToString());
            }
        }

    }
}
