using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SchoolJournal
{
    [Serializable]
    public class Teacher : Human
    {
        public int salary;
        public List<Subject> subjects;
        public string qualification;

        public Teacher(){}

        public Teacher(string name)
        {
            this.name = name;
        }


    }
}
