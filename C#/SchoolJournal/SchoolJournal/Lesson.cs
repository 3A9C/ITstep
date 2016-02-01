using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Xml.Serialization;

namespace SchoolJournal
{
    [Serializable]
    public class Lesson
    {
        public Subject subject;
        public string topic;
        public Teacher teacher;
        public PupilsGroup pupil_group;
        public List<Mark> marks;

        public Lesson(Subject subject, string theme, Teacher teacher, PupilsGroup pupil_group)
        {
            this.subject = subject;
            this.topic = theme;
            this.teacher = teacher;
            this.pupil_group = pupil_group;
            marks = new List<Mark>();
        }
        public void ManageLesson()
        {
            Console.WriteLine("Lesson is begins!");

            Mark mark1 = new Mark(teacher, pupil_group.pupils[0], "home work", 10);
            Mark mark2 = new Mark(teacher, pupil_group.pupils[1], "class work", 10);
            Mark mark3 = new Mark(teacher, pupil_group.pupils[2], "good actions", 10);
            Mark mark4 = new Mark(teacher, pupil_group.pupils[3], "home work", 10);
            Mark[] marksss = new Mark[] { mark1, mark2, mark3, mark4};

            marks.Add(mark1);
            marks.Add(mark2);
            marks.Add(mark3);
            marks.Add(mark4);

            foreach(var mark in marks)
            {
                mark.Show();
            }
            XmlSerializer formatter = new XmlSerializer(typeof(Mark[]));
            using (FileStream fs = new FileStream("../../people.xml", FileMode.OpenOrCreate))
            {
                formatter.Serialize(fs, marksss);
            }


            Console.WriteLine("Lesson is finished!");

        }


        
    }
}