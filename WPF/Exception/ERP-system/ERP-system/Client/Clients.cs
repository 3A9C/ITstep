using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Client
{
    public class Clients
    {
        private string id;
        public string Id
        {
            get { return id; }
            set { id = value; }
        }

        private string nameProject;
        public string NameProject
        {
            get { return nameProject; }
            set { nameProject = value; }
        }

        private string nameClient;
        public string NameClient
        {
            get { return nameClient; }
            set { nameClient = value; }
        }

        private string startDate;
        public string StartDate
        {
            get { return startDate; }
            set { startDate = value; }
        }

        private string endDate;
        public string EndDate
        {
            get { return endDate; }
            set { endDate = value; }
        }

        private string complete;
        public string Complete
        {
            get { return complete; }
            set { complete = value; }
        }

    }

}
