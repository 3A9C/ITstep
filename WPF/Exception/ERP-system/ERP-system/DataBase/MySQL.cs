using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Client;
using Employees;

namespace ERP_system.DataBase
{
    public class Jobs
    {
        public static List<Clients> Alex = new List<Clients>()
        { 

                        new Clients() 
            { NameProject = "Аквариум (Unity)",  NameClient = "Александра", StartDate = "27.11.15", EndDate = "10.12.15", Complete = "100%" },
                        new Clients() 
            { NameProject = "Дракончики (Unity)",  NameClient = "Александра", StartDate = "15.12.15", EndDate = "30.01.16", Complete = "0%" },
                        new Clients() 
            { NameProject = "Корзина на сайт (PHP)",  NameClient = "Маша", StartDate = "10.11.15", EndDate = "30.12.15", Complete = "50%" },
                        new Clients() 
            { NameProject = "Диспечерз задач (WPF)",  NameClient = "Иван", StartDate = "25.11.15", EndDate = "25.12.15", Complete = "20" + "%" }
        };
        public static List<Clients> Max = new List<Clients>()
        { 

                        new Clients() 
            { NameProject = "Вк музыка (WinForms)",  NameClient = "Макс", StartDate = "01.11.15", EndDate = "30.11.15", Complete = "99%" },
                        new Clients() 
            { NameProject = "Симулятор акулы (Unity)",  NameClient = "Александра", StartDate = "09.11.15", EndDate = "30.01.16", Complete = "40%" },
                        new Clients() 
            { NameProject = "UI (WPF)",  NameClient = "Андрей", StartDate = "10.02.16", EndDate = "30.02.16", Complete = "0%" },
                        new Clients() 
            { NameProject = "Молния (JS)",  NameClient = "Вова", StartDate = "10.09.15", EndDate = "30.10.15", Complete = "100%" }
        };
        public static List<Clients> Maria = new List<Clients>()
        { 

                        new Clients() 
            { NameProject = "Анти вирус",  NameClient = "It Step", StartDate = "05.01.15", EndDate = "30.11.15", Complete = "100%" },
                        new Clients() 
            { NameProject = "Сбор баз данных (Анти вирус)",  NameClient = "It Step", StartDate = "02.12.15", EndDate = "30.04.16", Complete = "30%" }
        };
        public static List<Clients> Lagerta = new List<Clients>()
        { 

                        new Clients() 
            { NameProject = "Планировщик задач (WPF)",  NameClient = "Петр", StartDate = "27.11.15", EndDate = "30.11.15", Complete = "100%" },
                        new Clients() 
            { NameProject = "Плагин (photoshop)",  NameClient = "Олег", StartDate = "27.12.15", EndDate = "10.01.16", Complete = "0%" },
                        new Clients() 
            { NameProject = "Шахматы (unity)",  NameClient = "Геннадий", StartDate = "09.06.15", EndDate = "30.08.15", Complete = "100%" },
        };

    }

    public class Moneys
    {
        public static List<Money> Alex = new List<Money>()
        { 
            new Money() { Month = "08.2015", Salary= 400},
             new Money() { Month = "09.2015", Salary= 1400},
              new Money() { Month = "10.2015", Salary= 800},
               new Money() { Month = "11.2015", Salary= 2000},
                new Money() { Month = "12.2015", Salary= 1500}
        };
        public static List<Money> Max = new List<Money>()
        { 
            new Money() { Month = "08.2015", Salary= 1500},
             new Money() { Month = "09.2015", Salary= 1000},
              new Money() { Month = "10.2015", Salary= 2000},
               new Money() { Month = "11.2015", Salary= 3000},
                new Money() { Month = "12.2015", Salary= 500}
        };
        public static List<Money> Maria = new List<Money>()
        { 
            new Money() { Month = "08.2015", Salary= 650},
             new Money() { Month = "09.2015", Salary= 4321},
              new Money() { Month = "10.2015", Salary= 3200},
               new Money() { Month = "11.2015", Salary= 1500},
                new Money() { Month = "12.2015", Salary= 2000}
        };
        public static List<Money> Lagerta = new List<Money>()
        { 
            new Money() { Month = "08.2015", Salary= 2200},
             new Money() { Month = "09.2015", Salary= 1350},
              new Money() { Month = "10.2015", Salary= 3000},
               new Money() { Month = "11.2015", Salary= 2350},
                new Money() { Month = "12.2015", Salary= 1290}
        };

    }

    public class QualityIndicator{

        public static List<QualityIndicators> Alex = new List<QualityIndicators>()
        { 
            new QualityIndicators() { Quality = "Эффективность работы в команде", Indicators= 6},
             new QualityIndicators() { Quality = "Проекты выполеные в срок", Indicators= 7},
              new QualityIndicators() { Quality = "Эффективность Руководство командой", Indicators= 5},
               new QualityIndicators() { Quality = "Эффективность индвидуальной работы", Indicators= 9},
                new QualityIndicators() { Quality = "Инициативность в работе", Indicators= 4}
        };
        public static List<QualityIndicators> Max = new List<QualityIndicators>()
        { 
            new QualityIndicators() { Quality = "Эффективность работы в команде", Indicators= 8},
             new QualityIndicators() { Quality = "Проекты выполеные в срок", Indicators= 6},
              new QualityIndicators() { Quality = "Эффективность Руководство командой", Indicators= 7},
               new QualityIndicators() { Quality = "Эффективность индвидуальной работы", Indicators= 9},
                new QualityIndicators() { Quality = "Инициативность в работе", Indicators= 3}
        };
        public static List<QualityIndicators> Maria = new List<QualityIndicators>()
        { 
            new QualityIndicators() { Quality = "Эффективность работы в команде", Indicators= 6},
             new QualityIndicators() { Quality = "Проекты выполеные в срок", Indicators= 5},
              new QualityIndicators() { Quality = "Эффективность Руководство командой", Indicators= 10},
               new QualityIndicators() { Quality = "Эффективность индвидуальной работы", Indicators= 7},
                new QualityIndicators() { Quality = "Инициативность в работе", Indicators= 9}
        };
        public static List<QualityIndicators> Lagerta = new List<QualityIndicators>()
        { 
            new QualityIndicators() { Quality = "Эффективность работы в команде", Indicators= 3},
             new QualityIndicators() { Quality = "Проекты выполеные в срок", Indicators= 9},
              new QualityIndicators() { Quality = "Эффективность Руководство командой", Indicators= 4},
               new QualityIndicators() { Quality = "Эффективность индвидуальной работы", Indicators= 10},
                new QualityIndicators() { Quality = "Инициативность в работе", Indicators= 10}
        };
    }
}
