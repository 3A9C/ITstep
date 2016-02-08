using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    //class MyEventArgs : EventArgs
    //{
    //    public string ch;
    //}
    //public interface ISay
    //{
    //    void Say();
    //}
    //class Saymen: ISay
    //{
    //    public void Say()
    //    {
    //        Console.WriteLine("Spich");
    //    }
    //}
    //class Saybull: ISay
    //{
    //    public void Say()
    //    {
    //        Console.WriteLine("Mu");
    //    }
    //}
    //class Bull
    //{
    //    public event EventHandler<MyEventArgs> Event;
    //    public void an_object_which_sees_the_minotaur(string ch)
    //    {
    //        MyEventArgs c = new MyEventArgs();

    //            c.ch = ch;
    //            Event(this, c);
    //    }
    //    public ISay s { private get; set; }
    //    public void SetISay(ISay s)
    //    {
    //        this.s = s;
    //    }
    //    public Bull(ISay s)
    //    {
    //        this.s = s;
    //    }
    //    public void Say()
    //    {
    //        s.Say();
    //    }
    //}
    //class Man
    //{ 
    //     public ISay s { private get; set; }
    //     public Man(ISay s)
    //    {
    //        this.s = s;
    //    }
    //    public void Say()
    //    {
    //        s.Say();
    //    }
    //}
    static class Class1
    {
        static public int h;
        public Class1()
        {
            Console.WriteLine("Default");
        }
        public Class1(ref int r)
        {
                h = r;
                Console.WriteLine("Static");
        }
    }
    static class Class2
    {
        static public int h;
        public Class2()
        {
            Console.WriteLine("Default");
        }
        public Class2(ref int r)
        {
                h = r;
                Console.WriteLine("Static");
        }
    }
    class Program
    {
        int b = 10;
        static void Main(string[] args)
        {
            Class1 c1 = new Class1(ref b);

        //    Class1 c1 = new Class1(10);
        //    Console.WriteLine(c1.h);
        //    int h = 19;
        //    Class2 c2 = new Class2(ref h);
        //    Console.WriteLine(c2.h);
        ////    Man m = new Man(new Saymen());
        //    Bull b = new Bull(new Saybull());
        //    m.Say();
        //    b.Say();
        //    b.Event += (sender, e) =>
        //        {
        //            switch(e.ch)
        //            {
        //                case "cow":
        //                {
        //                    b.SetISay(new Saybull());
        //                    break;
        //                }
        //                case "men":
        //                {
        //                    b.SetISay(new Saymen());
        //                    break;
        //                }
        //                default: break;   
        //            }
        //        };
        //    b.an_object_which_sees_the_minotaur("men");
        //    b.Say();
        //    b.an_object_which_sees_the_minotaur("cow");
        //    b.Say();
        }
    }
}
