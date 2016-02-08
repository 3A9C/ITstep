using LinqToExcel;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace day_9LINQ_toXML_EXCEL
{
    class Program
    {
        static void Main(string[] args)
        {
            // Получение информации из Excel документа с именем SampleData.xls
            string pathFile = "PriceProductBase.xlsx";

            var excelFile = new ExcelQueryFactory(pathFile);

            string sheetName = "Orders";

            // Вывод списка листов (Worksheet) в Excel документе  

            var infoOrders = from a in excelFile.Worksheet(sheetName)
                             select a;

            foreach (var item in excelFile.GetWorksheetNames())
            {
                foreach (var itemRow in excelFile.GetColumnNames(item))
                {
                    Console.Write(itemRow + " ");
                }
                Console.Write("\n");
            }

            foreach (var item in infoOrders)
            {
                string pattern = "{0};{1};{2};{3};{4};{5};{6};";

                // Вывод информации из столбцов OrderDate и Total
                Console.WriteLine(string.Format(pattern, item["Номер заказа"],
                    item["Номер продукта"], item["F3"], 
                    item["F4"], item["F5"], 
                    item["F6"], item["F7"]));
            }


            // установка документа "только для чтения"
            excelFile.ReadOnly = true;

            Console.ReadKey();
        }
    }
}
