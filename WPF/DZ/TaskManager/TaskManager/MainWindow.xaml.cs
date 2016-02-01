using System;
using System.Diagnostics;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Threading;

namespace TaskManager
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public ProcessList process_manager = new ProcessList();
        public DispatcherTimer timer = new DispatcherTimer();

        public MainWindow()
        {
            InitializeComponent();

            timer.Tick += Update;
            timer.Interval = new TimeSpan(0, 0, 1);
            timer.Start();

        }

        private void Update(object sender, EventArgs e)
        {
            timer.Stop();
            process_manager.UpdateProcesses();
            dgMain.ItemsSource = process_manager.Processes;
            timer.Start();

        }


        private void Create_Process(object sender, RoutedEventArgs e)
        {
            Microsoft.Win32.OpenFileDialog dialog = new Microsoft.Win32.OpenFileDialog();
            dialog.DefaultExt = ".exe";
            dialog.Filter = "Applications (*.exe)|*.exe";
            if (dialog.ShowDialog() == true)
            {
                Process.Start(dialog.FileName);
                process_manager.UpdateProcesses();
                dgMain.ItemsSource = process_manager.Processes;
            }
        }

        private void Search_Process(object sender, RoutedEventArgs e)
        {
            timer.Stop();
            if (Find.Text != "")
            {
                dgMain.ItemsSource = process_manager.FindProcessesByName(Find.Text);
            }

        }


        private void Process_Killer(object sender, RoutedEventArgs e)
        {
                try
                {
                    timer.Stop();
                    var selectedProcess = dgMain.SelectedItem as Process;
                    process_manager.Processes.Remove(selectedProcess);
                    selectedProcess.Kill();
                    timer.Start();
                }
                catch
                {
                    MessageBox.Show("В доступе отказано.", "Нет доступа", MessageBoxButton.OK);
                }
        }


        private void Find_Process(object sender, TextChangedEventArgs e)
        {
            if (Find.Text == "")
            {
                process_manager.UpdateProcesses();
                dgMain.ItemsSource = process_manager.Processes;
                timer.Start();
            }
        }


        private void UseStyles(object sender, RoutedEventArgs e)
        {
            FrameworkElement feSource = e.Source as FrameworkElement;
            ResourceDictionary newDictionary = new ResourceDictionary();
            switch (feSource.Name)
            {
                case "RedStyle":
                    newDictionary.Source = new Uri("theme/RedSkin.xaml", UriKind.Relative);
                    this.Resources.MergedDictionaries[0] = newDictionary;
                    break;
                case "GreenStyle":
                    newDictionary.Source = new Uri("theme/GreenSkin.xaml", UriKind.Relative);
                    this.Resources.MergedDictionaries[0] = newDictionary;
                    break;
                case "BlueStyle":
                    newDictionary.Source = new Uri("theme/BlueSkin.xaml", UriKind.Relative);
                    this.Resources.MergedDictionaries[0] = newDictionary;
                    break;
                case "GrayStyle":
                    newDictionary.Source = new Uri("theme/GraySkin.xaml", UriKind.Relative);
                    this.Resources.MergedDictionaries[0] = newDictionary;
                    break;
            }
            e.Handled = true;
        }

    }
}