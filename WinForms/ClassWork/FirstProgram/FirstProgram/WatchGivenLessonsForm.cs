﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;

namespace FirstProgram
{
    public partial class WatchGivenLessonsForm : Form
    {
        XmlDocument xmlDocument;
        XmlNode relativeTeacher;
        XmlNodeList givenLessons;

        //GivenLessonInfo givenLessonInfo;

        public WatchGivenLessonsForm()
        {
            InitializeComponent();
        }

        public WatchGivenLessonsForm(XmlDocument xmlDocument_, XmlNode relativeTeacher_) : this()
        {
            xmlDocument = xmlDocument_;
            relativeTeacher = relativeTeacher_;

            XmlDocument lessonsDocument = new XmlDocument();
            lessonsDocument.Load(Data.lessonsLocation);

            XmlNode lessonsRoot = lessonsDocument.SelectSingleNode("root");
            var currentTeacherId = relativeTeacher.Attributes[0].Value;
            givenLessons = lessonsRoot.SelectNodes("lesson[teacher='" + currentTeacherId + "']");
            foreach (XmlNode lesson in givenLessons)
            {
                this.comboBoxWithGivenLessonsDates.Items.Add(lesson.SelectSingleNode("date").InnerText +
                    " " + lesson.SelectSingleNode("time").InnerText);
            }
        }

        private void comboBoxWithGivenLessonsDates_SelectedIndexChanged(object sender, EventArgs e)
        {
            int index = this.comboBoxWithGivenLessonsDates.SelectedIndex;
            XmlNode selectedLesson = givenLessons[index];

            XmlDocument subjectsDocument = new XmlDocument();
            subjectsDocument.Load(Data.subjectsLocation);
            XmlDocument groupsDocument = new XmlDocument();
            groupsDocument.Load(Data.groupsLocation);
            XmlDocument pupilsDocument = new XmlDocument();
            pupilsDocument.Load(Data.pupilsLocation);

            this.Controls.RemoveByKey("labelWithSubjectName");
            this.Controls.RemoveByKey("labelWithTopics");
            this.Controls.RemoveByKey("labelWithGroupName");
            this.Controls.RemoveByKey("tableWithLessonData");

            Label labelWithSubjectName = new Label();
            labelWithSubjectName.Name = "labelWithSubjectName";
            labelWithSubjectName.Text = "Урок: " + subjectsDocument.SelectSingleNode(
                "root/subject[@id='" + selectedLesson.SelectSingleNode("subject").InnerText + "']/name").InnerText;
            labelWithSubjectName.Location = new Point(LabelSelectDate.Location.X, LabelSelectDate.Location.Y 
                + LabelSelectDate.Size.Height + 15);
            labelWithSubjectName.Anchor = AnchorStyles.Left | AnchorStyles.Top;
            labelWithSubjectName.AutoSize = true;
            labelWithSubjectName.BringToFront();
            this.Controls.Add(labelWithSubjectName);

            Label labelWithTopics = new Label();
            labelWithTopics.Name = "labelWithTopics";
            XmlNodeList topics = selectedLesson.SelectNodes("topics/topic");
            labelWithTopics.Text = "Тема: " + topics[0].InnerText;
            for (int i = 1; i < topics.Count; ++i)
            {
                labelWithTopics.Text += ", " + topics[i].InnerText;
            }
            labelWithTopics.Location = new Point(labelWithSubjectName.Location.X + labelWithSubjectName.Size.Width + 10
                , labelWithSubjectName.Location.Y);
            labelWithTopics.Anchor = AnchorStyles.Left | AnchorStyles.Top;
            labelWithTopics.AutoSize = true;
            this.Controls.Add(labelWithTopics);

            Label labelWithGroupName = new Label();
            labelWithGroupName.Name = "labelWithGroupName";
            labelWithGroupName.Text = "Группа: " + groupsDocument.SelectSingleNode("root/group[@id='" +
                selectedLesson.SelectSingleNode("group").InnerText + "']/name").InnerText;
            labelWithGroupName.Location = new Point(labelWithTopics.Location.X + labelWithTopics.Size.Width + 10
                , labelWithTopics.Location.Y);
            labelWithGroupName.Anchor = AnchorStyles.Left | AnchorStyles.Top;
            labelWithGroupName.AutoSize = true;
            this.Controls.Add(labelWithGroupName);

            TableLayoutPanel tableWithLessonData = new TableLayoutPanel();
            tableWithLessonData.Name = "tableWithLessonData";
            tableWithLessonData.ColumnCount = 3;
            tableWithLessonData.RowCount = 1;
            tableWithLessonData.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 20f));
            tableWithLessonData.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 15f));
            tableWithLessonData.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 65f));
            tableWithLessonData.RowStyles.Add(new RowStyle(SizeType.Absolute, 30f));
            tableWithLessonData.Controls.Add(new Label() { Text = "Ученики", AutoSize = true, TextAlign = ContentAlignment.MiddleCenter, Dock = DockStyle.Fill }, 0, 0);
            tableWithLessonData.Controls.Add(new Label() { Text = "На уроке", AutoSize = true, TextAlign = ContentAlignment.MiddleCenter, Dock = DockStyle.Fill }, 1, 0);
            tableWithLessonData.Controls.Add(new Label() { Text = "Оценки", AutoSize = true, TextAlign = ContentAlignment.MiddleCenter, Dock = DockStyle.Fill }, 2, 0);
            tableWithLessonData.Location = new Point(this.LabelSelectDate.Location.X,
                labelWithSubjectName.Location.Y + labelWithSubjectName.Size.Height + 10);
            tableWithLessonData.CellBorderStyle = TableLayoutPanelCellBorderStyle.Single;
            tableWithLessonData.Anchor = AnchorStyles.Left | AnchorStyles.Right | AnchorStyles.Bottom | AnchorStyles.Top;
            //tableWithLessonData.Width = this.ClientRectangle.Width - labelWithSubjectName.Location.X * 2;
            tableWithLessonData.Size = new Size(this.ClientRectangle.Width - labelWithSubjectName.Location.X * 2,
                this.ClientRectangle.Height - tableWithLessonData.Location.Y - tableWithLessonData.Location.X);

            // add pupils

            XmlNode pupilIds = groupsDocument.SelectSingleNode("root/group[@id='" +
                selectedLesson.SelectSingleNode("group").InnerText + "']/pupils");
            int amountOfPupils = pupilIds.ChildNodes.Count;

            foreach (XmlNode pupilId in pupilIds.SelectNodes("id"))
            {
                tableWithLessonData.RowCount += 1;
                tableWithLessonData.RowStyles.Add(new RowStyle(SizeType.Percent, 100f / amountOfPupils));

                Label labelWithName = new Label() { AutoSize = true, TextAlign = ContentAlignment.MiddleCenter, Dock = DockStyle.Fill };
                XmlNode pupil = pupilsDocument.SelectSingleNode("root/pupil[@id='" + pupilId.InnerText + "']");
                labelWithName.Text = pupil.SelectSingleNode("name").InnerText +
                    " " + pupil.SelectSingleNode("surname").InnerText;
                tableWithLessonData.Controls.Add(labelWithName, 0, tableWithLessonData.RowCount - 1);

                var wasAbsent = selectedLesson.SelectSingleNode("absent[pupil='" + pupilId.InnerText + "']");
                tableWithLessonData.Controls.Add(new Label() { AutoSize = true, TextAlign = ContentAlignment.MiddleCenter,
                    Dock = DockStyle.Fill, Text = wasAbsent == null? "Был" : "Небыло" }, 1, tableWithLessonData.RowCount - 1);

                XmlNodeList marks = selectedLesson.SelectNodes("marks/mark[pupil='" + pupilId.InnerText + "']");

                if (marks.Count > 0)
                {
                    Label labelWithMarks = new Label() { AutoSize = true, TextAlign = ContentAlignment.MiddleLeft, Dock = DockStyle.Fill };
                    labelWithMarks.Text = marks[0].SelectSingleNode("point").InnerText + " (" + marks[0].SelectSingleNode("ground").InnerText + ")";

                    for (int i = 1; i < marks.Count; ++i)
                    {
                        labelWithMarks.Text += ", " + marks[i].SelectSingleNode("point").InnerText + " (" + marks[i].SelectSingleNode("ground").InnerText + ")";
                    }

                    tableWithLessonData.Controls.Add(labelWithMarks, 2, tableWithLessonData.RowCount - 1);
                }
            }

            this.Controls.Add(tableWithLessonData);
        }
    }
}
