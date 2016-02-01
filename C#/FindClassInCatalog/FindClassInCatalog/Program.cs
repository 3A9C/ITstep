using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApplication15
{
    class Program
    {

        static void Main(string[] args)
        {
            List<ClassFiles> fils = new List<ClassFiles>();

              var files = from file in Directory.EnumerateFiles(@"..\..\", "*.cs", SearchOption.AllDirectories) 
                          from line in File.ReadAllLines(file)
                          where line.Contains("class")
                          select new
                          {
                              File = file,
                              Line = line
                          };

              foreach (var f in files)
              {
                      Console.WriteLine("{0}", f.Line);
                      fils.Add(new ClassFiles() { OpenSource = f.Line});
              }
              Console.WriteLine("Чистим ---------------------");

              int yes = 0;
              for (int i = 0; i < fils.Count(); ++i )
              {
                  foreach (var f in fils)
                  {
                      if (f.OpenSource.Length > 26)
                      {
                          break;
                          yes = 1;
                      }
                  }
                  if(yes == 1)
                  {
                      fils.RemoveAt(i);
                      yes = 0;
                  }
              }

                  foreach (var f in fils)
                  {
                      Console.WriteLine("{0}", f.OpenSource);
                  }
      
          Console.ReadKey();
        }
    }

    class ClassFiles
    {
        public string OpenSource { get; set; }

    }
}