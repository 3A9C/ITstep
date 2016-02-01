using System;
using System.Collections.Generic;
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
using System.Windows.Media.Animation;

namespace WpfApplication1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {

        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            Ellipse ellipse1 = new Ellipse();
            ellipse1.Width = 50;
            ellipse1.Height = 20;
            ellipse1.ToolTip = "Touch Me / Потискай меня";
            ellipse1.StrokeThickness = 2;
            ellipse1.Stroke = Brushes.Black;
            ellipse1.Fill = Brushes.Red;
            Mygrid.Children.Add(ellipse1);

            Ellipse ellipse2 = new Ellipse();
            ellipse2.Width = 50;
            ellipse2.Height = 20;
            ellipse2.ToolTip = "Touch Me / Потискай меня";
            ellipse2.StrokeThickness = 2;
            ellipse2.Stroke = Brushes.Red;
            ellipse2.Fill = Brushes.Green;
            Mygrid.Children.Add(ellipse2);

            Random rand1 = new Random((int)DateTime.Now.Ticks);
            Random rand2 = new Random((int)DateTime.Now.Ticks);
            ThicknessAnimation TA1 = new ThicknessAnimation(); //Анимация перемещения
            TA1.From = ellipse1.Margin = new Thickness(10, 100, 0, 0); //Координаты начального положения
            TA1.To = ellipse1.Margin = new Thickness(1400, 100, 0, 0); //Координаты конечного положения
            TA1.Duration = TimeSpan.FromSeconds(rand1.Next(10, 20)); //Время анимации
            ellipse1.BeginAnimation(MarginProperty, TA1); //Запуск анимации

            ThicknessAnimation TA2 = new ThicknessAnimation(); //Анимация перемещения
            TA2.From = ellipse2.Margin = new Thickness(10, 200, 0, 0); //Координаты начального положения
            TA2.To = ellipse2.Margin = new Thickness(1400, 200, 0, 0); //Координаты конечного положения
            TA2.Duration = TimeSpan.FromSeconds(rand2.Next(10, 20)); //Время анимации
            ellipse2.BeginAnimation(MarginProperty, TA2); //Запуск анимации
        }
    }
}
