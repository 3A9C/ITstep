using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
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

namespace WordArt
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public List<StyleRRR> Styles { get; set; }


        

        public MainWindow()
        {

            Styles = new List<StyleRRR>();
            Styles.Add(new StyleRRR() { Name="212121212121"});
            Styles.Add(new StyleRRR() { Name = "34343" });

            Styles.Add(new StyleRRR() { Name = "34rt" });
            Styles.Add(new StyleRRR() { Name = "rtrtrtrt" });
         
            InitializeComponent();
         
           
          // cmbStyle.ItemsSource = styles;
          // cmbStyle.SelectedIndex = 0;
        }
    }

    public class StyleRRR : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;
        void OnPropertyChanged(string NameProperty)
        {
            PropertyChangedEventHandler PropertyChanged = this.PropertyChanged;
            if (PropertyChanged != null)
                PropertyChanged(this, new PropertyChangedEventArgs(NameProperty));
        }

        string name;

        public string Name
        {
            get { return name; }
            set 
            { 
                name = value;
                OnPropertyChanged("Name");
            }
        }

        public StyleRRR()
        {
           
        }

        public StyleRRR(string name, string color, int size)
        {
            this.name = name;
            this.color = color;
            this.size = size;
        }

        string color;

        public string Color
        {
            get { return color; }
            set
            { 
                color = value;
                OnPropertyChanged("Color");
            }
        }

        int size;

        public int Size
        {
            get { return size; }
            set 
            { 
                size = value;
                OnPropertyChanged("Size");
            }
        }

        public override string ToString()
        {
            return name;
        }


    }
}
