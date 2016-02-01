using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SchoolJournal
{
    [Serializable]
    public class PupilsGroup
    {
        public string name;
        public List<Pupil> pupils;

        public PupilsGroup() { }

        public PupilsGroup(string name)
        {
            this.name = name;
            pupils = new List<Pupil>();
        }
    }
}
