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
using System.Text.RegularExpressions;

namespace ReportGasStation
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
            int summ = 0;
            double podchet = 0;

            //Бензин

            if (!String.IsNullOrEmpty(benzin_litr.Text) 
                & String.IsNullOrEmpty(benzin_money.Text)
                & Regex.Match(benzin_money.Text, @"\d+").Success
                & Convert.ToDouble(benzin_litr.Text) > 0)
            {
                podchet = Convert.ToDouble(((ComboBoxItem)(benzinv.SelectedItem)).Tag.ToString()) * Convert.ToDouble(benzin_litr.Text);
                summ += Convert.ToInt32(podchet);
                listok.Items.Add("Бензин: Сумма " + podchet);
            }
            else if (String.IsNullOrEmpty(benzin_litr.Text) 
                & !String.IsNullOrEmpty(benzin_money.Text) 
                & Regex.Match(benzin_money.Text, @"\d+").Success
                & Convert.ToDouble(benzin_litr.Text) > 0)
            {
                podchet = Convert.ToDouble(benzin_money.Text) / Convert.ToDouble(((ComboBoxItem)(benzinv.SelectedItem)).Tag.ToString());
                summ += Convert.ToInt32(podchet);
                listok.Items.Add("Бензин: Литров " + podchet);
            }
            else
            {
                MessageBox.Show("Впишите валюту или литры");
            }
           

            //Подкачка колёс
            if (pkoles.IsChecked == true)
            {
                listok.Items.Add("Подкачка колёс: 10000");
                summ += 10000;
            }

            //Помывка машины
            if (pCar.IsChecked == true)
            {
                listok.Items.Add("Помывка машины: 50000");
                summ += 50000;
            }

            //Чистка пылесосом
            if (Clearp.IsChecked == true)
            {
                listok.Items.Add("Чистка машины: 100000");
                summ += 100000;
            }

            //Вода
            if (!String.IsNullOrEmpty(water_count.Text))
            {
                podchet = Convert.ToDouble(water_count.Text) * Convert.ToDouble(((ComboBoxItem)(water.SelectedItem)).Tag.ToString());
                summ += Convert.ToInt32(podchet);
                listok.Items.Add("Вода: " + podchet);
            }


            //Батончики
            if (!String.IsNullOrEmpty(chocolates_count.Text))
            {
                podchet = Convert.ToDouble(chocolates_count.Text) * Convert.ToDouble(((ComboBoxItem)(chocolates.SelectedItem)).Tag.ToString());
                summ += Convert.ToInt32(podchet);
                listok.Items.Add("Шоколадки: " + podchet);
            }

            //Финальная сумма
            oksumm.Content = "Цена " + Convert.ToString(summ) + " б.р.";  
        }

        private void Image_Loaded(object sender, RoutedEventArgs e)
        {
            // ... Create a new BitmapImage.
            BitmapImage b = new BitmapImage();
            b.BeginInit();
            b.UriSource = new Uri("D:\\github\\Morshinin\\WPF\\ReportGasStation\\ReportGasStation\\fon.jpg",UriKind.Relative);
            b.CacheOption = BitmapCacheOption.OnLoad;
            b.EndInit();

            // ... Get Image reference from sender.
            var image = sender as Image;
            // ... Assign Source.
            image.Source = b;
        }
    }
}
