using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SchoolJournal
{
    class Program
    {
        static void Main(string[] args)
        {
            Teacher teacher = new Teacher("Maks");
            Pupil pupil1 = new Pupil("Andrew");
            Pupil pupil2 = new Pupil("Kolya");
            Pupil pupil3 = new Pupil("Olya");
            Pupil pupil4 = new Pupil("Ira");

            PupilsGroup pupils_group = new PupilsGroup("P11014");
            pupils_group.pupils.Add(pupil1);
            pupils_group.pupils.Add(pupil2);
            pupils_group.pupils.Add(pupil3);
            pupils_group.pupils.Add(pupil4);

            Subject subject = new Subject("C#");
            subject.topics.Add("Binary and xml serializations");
            subject.topics.Add("Global project");

            Lesson lesson1 = new Lesson(subject, subject.topics[0], teacher, pupils_group);
            lesson1.ManageLesson();

            Console.ReadLine();
        }
    }
}
