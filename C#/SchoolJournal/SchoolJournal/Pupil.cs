using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SchoolJournal
{
    [Serializable]
    public class Pupil : Human
    {
        public string parent_info;
        public Pupil() { }
        public Pupil(string name)
        {
            this.name = name;
        }
    }
}
