using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ERP.Logic
{
    class Employee
    {
        int id;
        public int Id
        {
          get { return id; }
        }
        StringBuilder name;
        public StringBuilder Name
        {
            get { return name; }
        }
        StringBuilder surname;

        public StringBuilder Surname
        {
            get { return surname; }
        }
        DateTime birthday;

        public DateTime Birthday
        {
            get { return birthday; }
        }
        StringBuilder address;

        public StringBuilder Address
        {
            get { return address; }
            set { address = value; }
        }
        StringBuilder photo;

        public StringBuilder Photo
        {
            get { return photo; }
            set { photo = value; }
        }

        int rating;

        public int Rating
        {
            get { return rating; }
            set { rating = value; }
        }

        StringBuilder position;

        public StringBuilder Position
        {
            get { return position; }
            set { position = value; }
        }

        int salary;

        public int Salary
        {
            get { return salary; }
            set { salary = value; }
        }

        int efficiency;

        public int Efficiency
        {
            get { return efficiency; }
            set { efficiency = value; }
        }

        public Employee(int id, StringBuilder name, StringBuilder surname, DateTime birthday, StringBuilder address, StringBuilder photo, int rating, StringBuilder position, int salary, int efficiency)
        {
            this.id = id;
            this.name = name;
            this.surname = surname;
            this.birthday = birthday;
            this.address = address;
            this.photo = photo;
            this.rating = rating;
            this.position = position;
            this.salary = salary;
            this.efficiency = efficiency;
                 
        }

    }
}
