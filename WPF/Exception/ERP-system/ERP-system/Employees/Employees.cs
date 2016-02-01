using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using Client;
using Employees;

namespace Employees
{
    public class Employees
    {

        // unique datas
        private string uid;
        public string Uid
        {
            get { return uid; }
            set { uid = value; }
        }


        private string firstLastName;
        public string FirstLastName
        {
            get { return firstLastName; }
            set { firstLastName = value; }
        }

        private List<Clients> projects = new List<Clients>();

        public List<Clients> Projects
        {
            get { return projects; }
            set { projects = value; }
        }

        private List<Money> money = new List<Money>();

        public List<Money> Money
        {
            get { return money; }
            set { money = value; }
        }

        private List<QualityIndicators> qualityIndicator = new List<QualityIndicators>();

        public List<QualityIndicators> QualityIndicator
        {
            get { return qualityIndicator; }
            set { qualityIndicator = value; }
        }

        private int reting;
        public int Reting
        {
            get { return reting; }
            set { reting = value; }
        }


        private string age;
        public string Age
        {
            get { return age; }
            set
            {
                if (age == null)
                {
                    age = value;
                }
            }
        }


        private string reside;
        public string Reside
        {
            get { return reside; }
            set { reside = value; }
        }


        private string photo;
        public string Photo
        {
            get { return photo; }
            set { photo = value; }
        }


        // business qualities
        private string position;
        public string Position
        {
            get { return position; }
            set { position = value; }
        }


        private int salary;
        public int Salary
        {
            get { return salary; }
            set { salary = value; }
        }


        public Employees()
        {
        }
    }
}