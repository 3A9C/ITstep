using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Employees
{
    public class QualityIndicators
    {
        private int indicators;
        public int Indicators
        {
            get { return indicators; }
            set { indicators = value; }
        }
        private string quality;
        public string Quality
        {
            get { return quality; }
            set { quality = value; }
        }
    }
}
