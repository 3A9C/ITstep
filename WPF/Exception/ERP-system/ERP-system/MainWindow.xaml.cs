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
using ERP_system.DataBase;

namespace EnterpriseResourcePlanning
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


        // Работники
        public List<Employees.Employees> Employees
        {
            get { return employees; }
            set { }
        }
        public List<Employees.Employees> employees = new List<Employees.Employees>()
        { 
            new Employees.Employees() { 
                Uid = "1", 
                FirstLastName = "Alex Glass", 
                Photo = "../../img/glass.jpg", 
                Projects = Jobs.Alex,
                Money = Moneys.Alex,
                QualityIndicator = QualityIndicator.Alex,
                Reting = 10
            }, 
            new Employees.Employees() { 
                Uid = "2", 
                FirstLastName = "Max shepard", 
                Photo = "../../img/shepard.jpg", 
                Projects = Jobs.Max, 
                Money = Moneys.Max,
                QualityIndicator = QualityIndicator.Max,
                Reting = 20 
            }, 
            new Employees.Employees() { 
                Uid = "3", 
                FirstLastName = "Maria Stuart", 
                Photo = "../../img/stuart.jpg", 
                Projects = Jobs.Maria, 
                Money = Moneys.Maria,
                QualityIndicator = QualityIndicator.Maria,
                Reting = 15 
            }, 
            new Employees.Employees() { 
                Uid = "4", 
                FirstLastName = "Lagerta Lodbrock",  
                Photo = "../../img/lodbrock.jpg", 
                Projects = Jobs.Lagerta, 
                Money = Moneys.Lagerta,
                QualityIndicator = QualityIndicator.Lagerta,
                Reting = 35 
            }
        };




    }
}