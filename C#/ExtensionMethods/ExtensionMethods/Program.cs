using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ExtensionMethods;
using System.Web.Script.Serialization;

namespace ExtensionMethod
{
    public class Student
    {
        public string Name { get; set; }
        public string Age { get; set; }
        public string AverageRating { get; set; }
    }
    class Program
    {
        static void Main(string[] args)
        {
            //Сравнить
            string s1 = "a";
            string s2 = "a";
            int iss = s1.CompareTo(s2);
            Console.WriteLine(iss == 0 ? true: false);
            //Сравнить

            // Вывести массив
            int[] ints = { 10, 45, 15, 39, 21, 26 };
            var result = ints.OrderBy(g => g);
            foreach (var i in result)
            {
                Console.Write(i + " ");
            }
            Console.WriteLine();
            
            // Вывести массив

            string s = "Hello Extension Methods Hello,Extension?Methods.";
            int i1 = s.WordCount();
            Console.WriteLine(i1);

            Console.WriteLine(MakeLine(0, 5, ", "));
            Console.WriteLine(MakeLine(1, 6, "  "));
            Console.WriteLine(MakeLine(9, 9, ": "));
            Console.WriteLine(MakeLine(4, 7, "< "));


            // объект для сериализации
            List<Student> students = new List<Student>();
            JavaScriptSerializer serializer = JavaScriptSerializer();
            string json = serializer.Serialize(students);

            Console.ReadKey();
        }
        private static string MakeLine(int initVal, int multVal, string sep)
        {

            string[] sArr = new string[10];

            for (int i = initVal; i < initVal + 10; i++)
                sArr[i - initVal] = String.Format("{0,-3}", i * multVal);

            return String.Join(sep, sArr);
        }
    }
    class Person
    {
        internal string name;

        internal int age;
    }
}

namespace ExtensionMethods
{
    public static class MyExtensions
    {
        public static int WordCount(this String str)
        {
            return str.Split(new char[] { ' ', '.', '?', ',' },
                             StringSplitOptions.RemoveEmptyEntries).Length;
        }
    }
}
