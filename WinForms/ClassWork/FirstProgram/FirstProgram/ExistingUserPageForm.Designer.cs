namespace FirstProgram
{
    partial class ExistingUserPageForm
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
            this.buttonChangePassword = new System.Windows.Forms.Button();
            this.buttonWatchGivenLessons = new System.Windows.Forms.Button();
            this.buttonStartNewLesson = new System.Windows.Forms.Button();
            this.labelDate = new System.Windows.Forms.Label();
            this.buttonLogOut = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // buttonChangePassword
            // 
            this.buttonChangePassword.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.buttonChangePassword.Font = new System.Drawing.Font("Segoe Script", 10.25F, System.Drawing.FontStyle.Bold);
            this.buttonChangePassword.Location = new System.Drawing.Point(45, 161);
            this.buttonChangePassword.Name = "buttonChangePassword";
            this.buttonChangePassword.Size = new System.Drawing.Size(177, 30);
            this.buttonChangePassword.TabIndex = 3;
            this.buttonChangePassword.Text = "Изменить пароль";
            this.buttonChangePassword.UseVisualStyleBackColor = true;
            this.buttonChangePassword.Click += new System.EventHandler(this.buttonChangePassword_Click);
            // 
            // buttonWatchGivenLessons
            // 
            this.buttonWatchGivenLessons.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.buttonWatchGivenLessons.Font = new System.Drawing.Font("Segoe Script", 10.25F, System.Drawing.FontStyle.Bold);
            this.buttonWatchGivenLessons.Location = new System.Drawing.Point(4, 110);
            this.buttonWatchGivenLessons.Name = "buttonWatchGivenLessons";
            this.buttonWatchGivenLessons.Size = new System.Drawing.Size(264, 39);
            this.buttonWatchGivenLessons.TabIndex = 0;
            this.buttonWatchGivenLessons.Text = "Просмотр проведенных уроков";
            this.buttonWatchGivenLessons.UseVisualStyleBackColor = true;
            this.buttonWatchGivenLessons.Click += new System.EventHandler(this.buttonWatchGivenLessons_Click);
            // 
            // buttonStartNewLesson
            // 
            this.buttonStartNewLesson.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.buttonStartNewLesson.Font = new System.Drawing.Font("Segoe Script", 10.25F, System.Drawing.FontStyle.Bold);
            this.buttonStartNewLesson.Location = new System.Drawing.Point(44, 64);
            this.buttonStartNewLesson.Name = "buttonStartNewLesson";
            this.buttonStartNewLesson.Size = new System.Drawing.Size(177, 36);
            this.buttonStartNewLesson.TabIndex = 1;
            this.buttonStartNewLesson.Text = "Начать новый урок";
            this.buttonStartNewLesson.UseVisualStyleBackColor = true;
            this.buttonStartNewLesson.Click += new System.EventHandler(this.buttonStartNewLesson_Click);
            // 
            // labelDate
            // 
            this.labelDate.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.labelDate.AutoSize = true;
            this.labelDate.Font = new System.Drawing.Font("Segoe Script", 10.25F, System.Drawing.FontStyle.Bold);
            this.labelDate.Location = new System.Drawing.Point(51, 24);
            this.labelDate.Name = "labelDate";
            this.labelDate.Size = new System.Drawing.Size(44, 22);
            this.labelDate.TabIndex = 4;
            this.labelDate.Text = "Date";
            this.labelDate.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // buttonLogOut
            // 
            this.buttonLogOut.Font = new System.Drawing.Font("Segoe Script", 10.25F, System.Drawing.FontStyle.Bold);
            this.buttonLogOut.Location = new System.Drawing.Point(93, 204);
            this.buttonLogOut.Name = "buttonLogOut";
            this.buttonLogOut.Size = new System.Drawing.Size(79, 28);
            this.buttonLogOut.TabIndex = 2;
            this.buttonLogOut.Text = "Выйти";
            this.buttonLogOut.UseVisualStyleBackColor = true;
            this.buttonLogOut.Click += new System.EventHandler(this.buttonLogOut_Click);
            // 
            // ExistingUserPageForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(270, 255);
            this.Controls.Add(this.buttonLogOut);
            this.Controls.Add(this.labelDate);
            this.Controls.Add(this.buttonStartNewLesson);
            this.Controls.Add(this.buttonWatchGivenLessons);
            this.Controls.Add(this.buttonChangePassword);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "ExistingUserPageForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Журнал";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.ExistingUserPageForm_FormClosed);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonChangePassword;
        private System.Windows.Forms.Button buttonWatchGivenLessons;
        private System.Windows.Forms.Button buttonStartNewLesson;
        private System.Windows.Forms.Label labelDate;
        private System.Windows.Forms.Button buttonLogOut;
    }
}