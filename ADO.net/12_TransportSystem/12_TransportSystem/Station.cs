﻿using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _12_TransportSystem
{
    public class Station
    {
        [Key]
        public int Id { get; set; }
        public string Name { get; set; }
        public ICollection<RouteInfo> RoutesInfo { get; set; }   
    }
}
