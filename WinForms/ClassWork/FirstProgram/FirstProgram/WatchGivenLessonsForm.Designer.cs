﻿namespace FirstProgram
{
    partial class WatchGivenLessonsForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.LabelSelectDate = new System.Windows.Forms.Label();
            this.comboBoxWithGivenLessonsDates = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
            // 
            // LabelSelectDate
            // 
            this.LabelSelectDate.AutoSize = true;
            this.LabelSelectDate.Font = new System.Drawing.Font("Segoe Script", 10.25F, System.Drawing.FontStyle.Bold);
            this.LabelSelectDate.Location = new System.Drawing.Point(12, 19);
            this.LabelSelectDate.Name = "LabelSelectDate";
            this.LabelSelectDate.Size = new System.Drawing.Size(106, 22);
            this.LabelSelectDate.TabIndex = 0;
            this.LabelSelectDate.Text = "Выбор даты:";
            // 
            // comboBoxWithGivenLessonsDates
            // 
            this.comboBoxWithGivenLessonsDates.Font = new System.Drawing.Font("Segoe Script", 10.25F, System.Drawing.FontStyle.Bold);
            this.comboBoxWithGivenLessonsDates.FormattingEnabled = true;
            this.comboBoxWithGivenLessonsDates.Location = new System.Drawing.Point(124, 16);
            this.comboBoxWithGivenLessonsDates.Name = "comboBoxWithGivenLessonsDates";
            this.comboBoxWithGivenLessonsDates.Size = new System.Drawing.Size(170, 30);
            this.comboBoxWithGivenLessonsDates.TabIndex = 3;
            this.comboBoxWithGivenLessonsDates.SelectedIndexChanged += new System.EventHandler(this.comboBoxWithGivenLessonsDates_SelectedIndexChanged);
            // 
            // WatchGivenLessonsForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(719, 309);
            this.Controls.Add(this.comboBoxWithGivenLessonsDates);
            this.Controls.Add(this.LabelSelectDate);
            this.Name = "WatchGivenLessonsForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Уроки";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label LabelSelectDate;
        private System.Windows.Forms.ComboBox comboBoxWithGivenLessonsDates;
    }
}