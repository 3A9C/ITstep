namespace FirstProgram
{
    partial class NewUserForm
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
            this.labelFillFields = new System.Windows.Forms.Label();
            this.textBoxForLogin = new System.Windows.Forms.TextBox();
            this.textBoxForName = new System.Windows.Forms.TextBox();
            this.textBoxForPassword = new System.Windows.Forms.TextBox();
            this.labelLogin = new System.Windows.Forms.Label();
            this.labelName = new System.Windows.Forms.Label();
            this.labelPassword = new System.Windows.Forms.Label();
            this.buttonRegister = new System.Windows.Forms.Button();
            this.textBoxForSurname = new System.Windows.Forms.TextBox();
            this.labelSurname = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // labelFillFields
            // 
            this.labelFillFields.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.labelFillFields.AutoSize = true;
            this.labelFillFields.Font = new System.Drawing.Font("Segoe Script", 10.25F, System.Drawing.FontStyle.Bold);
            this.labelFillFields.Location = new System.Drawing.Point(80, 21);
            this.labelFillFields.Name = "labelFillFields";
            this.labelFillFields.Size = new System.Drawing.Size(191, 22);
            this.labelFillFields.TabIndex = 0;
            this.labelFillFields.Text = "Регистрация учителя";
            // 
            // textBoxForLogin
            // 
            this.textBoxForLogin.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.textBoxForLogin.Location = new System.Drawing.Point(100, 73);
            this.textBoxForLogin.Name = "textBoxForLogin";
            this.textBoxForLogin.Size = new System.Drawing.Size(200, 20);
            this.textBoxForLogin.TabIndex = 0;
            // 
            // textBoxForName
            // 
            this.textBoxForName.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.textBoxForName.Location = new System.Drawing.Point(100, 151);
            this.textBoxForName.Name = "textBoxForName";
            this.textBoxForName.Size = new System.Drawing.Size(200, 20);
            this.textBoxForName.TabIndex = 2;
            // 
            // textBoxForPassword
            // 
            this.textBoxForPassword.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.textBoxForPassword.Location = new System.Drawing.Point(100, 112);
            this.textBoxForPassword.Name = "textBoxForPassword";
            this.textBoxForPassword.Size = new System.Drawing.Size(200, 20);
            this.textBoxForPassword.TabIndex = 1;
            this.textBoxForPassword.UseSystemPasswordChar = true;
            // 
            // labelLogin
            // 
            this.labelLogin.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.labelLogin.AutoSize = true;
            this.labelLogin.Font = new System.Drawing.Font("Segoe Script", 10.25F, System.Drawing.FontStyle.Bold);
            this.labelLogin.Location = new System.Drawing.Point(34, 72);
            this.labelLogin.Name = "labelLogin";
            this.labelLogin.Size = new System.Drawing.Size(59, 22);
            this.labelLogin.TabIndex = 4;
            this.labelLogin.Text = "Логин";
            // 
            // labelName
            // 
            this.labelName.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.labelName.AutoSize = true;
            this.labelName.Font = new System.Drawing.Font("Segoe Script", 10.25F, System.Drawing.FontStyle.Bold);
            this.labelName.Location = new System.Drawing.Point(46, 150);
            this.labelName.Name = "labelName";
            this.labelName.Size = new System.Drawing.Size(47, 22);
            this.labelName.TabIndex = 5;
            this.labelName.Text = "Имя";
            // 
            // labelPassword
            // 
            this.labelPassword.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.labelPassword.AutoSize = true;
            this.labelPassword.Font = new System.Drawing.Font("Segoe Script", 10.25F, System.Drawing.FontStyle.Bold);
            this.labelPassword.Location = new System.Drawing.Point(32, 111);
            this.labelPassword.Name = "labelPassword";
            this.labelPassword.Size = new System.Drawing.Size(63, 22);
            this.labelPassword.TabIndex = 6;
            this.labelPassword.Text = "Пароль";
            // 
            // buttonRegister
            // 
            this.buttonRegister.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.buttonRegister.Font = new System.Drawing.Font("Segoe Script", 10.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)), true);
            this.buttonRegister.Location = new System.Drawing.Point(100, 227);
            this.buttonRegister.Name = "buttonRegister";
            this.buttonRegister.Size = new System.Drawing.Size(138, 28);
            this.buttonRegister.TabIndex = 4;
            this.buttonRegister.Text = "Создать";
            this.buttonRegister.UseVisualStyleBackColor = true;
            this.buttonRegister.Click += new System.EventHandler(this.buttonRegister_Click);
            // 
            // textBoxForSurname
            // 
            this.textBoxForSurname.Location = new System.Drawing.Point(100, 191);
            this.textBoxForSurname.Name = "textBoxForSurname";
            this.textBoxForSurname.Size = new System.Drawing.Size(200, 20);
            this.textBoxForSurname.TabIndex = 3;
            // 
            // labelSurname
            // 
            this.labelSurname.AutoSize = true;
            this.labelSurname.Font = new System.Drawing.Font("Segoe Script", 10.25F, System.Drawing.FontStyle.Bold);
            this.labelSurname.Location = new System.Drawing.Point(12, 190);
            this.labelSurname.Name = "labelSurname";
            this.labelSurname.Size = new System.Drawing.Size(86, 22);
            this.labelSurname.TabIndex = 9;
            this.labelSurname.Text = "Фамилия";
            // 
            // NewUserForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(340, 292);
            this.Controls.Add(this.labelSurname);
            this.Controls.Add(this.textBoxForSurname);
            this.Controls.Add(this.buttonRegister);
            this.Controls.Add(this.labelPassword);
            this.Controls.Add(this.labelName);
            this.Controls.Add(this.labelLogin);
            this.Controls.Add(this.textBoxForPassword);
            this.Controls.Add(this.textBoxForName);
            this.Controls.Add(this.textBoxForLogin);
            this.Controls.Add(this.labelFillFields);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "NewUserForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Регестрация";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelFillFields;
        private System.Windows.Forms.TextBox textBoxForLogin;
        private System.Windows.Forms.TextBox textBoxForName;
        private System.Windows.Forms.TextBox textBoxForPassword;
        private System.Windows.Forms.Label labelLogin;
        private System.Windows.Forms.Label labelName;
        private System.Windows.Forms.Label labelPassword;
        private System.Windows.Forms.Button buttonRegister;
        private System.Windows.Forms.TextBox textBoxForSurname;
        private System.Windows.Forms.Label labelSurname;
    }
}