namespace _6_ShopAuto
{
    partial class Form1
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
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.Label iDOLabel;
            System.Windows.Forms.Label iDLabel;
            System.Windows.Forms.Label famLabel;
            System.Windows.Forms.Label opytLabel;
            System.Windows.Forms.Label garantyLabel;
            System.Windows.Forms.Label dateLabel;
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.iDDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.markaDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.vDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.rDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.iDDDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.countryDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dateDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.tAutoBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.dBAutoDataSet = new _6_ShopAuto.DBAutoDataSet();
            this.bindingNavigator1 = new System.Windows.Forms.BindingNavigator(this.components);
            this.bindingNavigatorAddNewItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorCountItem = new System.Windows.Forms.ToolStripLabel();
            this.bindingNavigatorDeleteItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorMoveFirstItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorMovePreviousItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorSeparator = new System.Windows.Forms.ToolStripSeparator();
            this.bindingNavigatorPositionItem = new System.Windows.Forms.ToolStripTextBox();
            this.bindingNavigatorSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.bindingNavigatorMoveNextItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorMoveLastItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.tOwnerBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.iDOTextBox = new System.Windows.Forms.TextBox();
            this.iDTextBox = new System.Windows.Forms.TextBox();
            this.famTextBox = new System.Windows.Forms.TextBox();
            this.opytTextBox = new System.Windows.Forms.TextBox();
            this.garantyTextBox = new System.Windows.Forms.TextBox();
            this.dateTextBox = new System.Windows.Forms.TextBox();
            this.tMotorBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.tAutoTableAdapter = new _6_ShopAuto.DBAutoDataSetTableAdapters.TAutoTableAdapter();
            this.tOwnerTableAdapter = new _6_ShopAuto.DBAutoDataSetTableAdapters.TOwnerTableAdapter();
            this.tableAdapterManager = new _6_ShopAuto.DBAutoDataSetTableAdapters.TableAdapterManager();
            this.tMotorTableAdapter = new _6_ShopAuto.DBAutoDataSetTableAdapters.TMotorTableAdapter();
            this.dataGridView2 = new System.Windows.Forms.DataGridView();
            this.fKTAutoTMotorBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.iDDataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.markaDataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.vDataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.rDataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.iDDDataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.countryDataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dateDataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            iDOLabel = new System.Windows.Forms.Label();
            iDLabel = new System.Windows.Forms.Label();
            famLabel = new System.Windows.Forms.Label();
            opytLabel = new System.Windows.Forms.Label();
            garantyLabel = new System.Windows.Forms.Label();
            dateLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tAutoBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dBAutoDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.bindingNavigator1)).BeginInit();
            this.bindingNavigator1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.tOwnerBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tMotorBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.fKTAutoTMotorBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // iDOLabel
            // 
            iDOLabel.AutoSize = true;
            iDOLabel.Location = new System.Drawing.Point(67, 253);
            iDOLabel.Name = "iDOLabel";
            iDOLabel.Size = new System.Drawing.Size(29, 13);
            iDOLabel.TabIndex = 2;
            iDOLabel.Text = "IDO:";
            // 
            // iDLabel
            // 
            iDLabel.AutoSize = true;
            iDLabel.Location = new System.Drawing.Point(67, 279);
            iDLabel.Name = "iDLabel";
            iDLabel.Size = new System.Drawing.Size(21, 13);
            iDLabel.TabIndex = 4;
            iDLabel.Text = "ID:";
            // 
            // famLabel
            // 
            famLabel.AutoSize = true;
            famLabel.Location = new System.Drawing.Point(67, 305);
            famLabel.Name = "famLabel";
            famLabel.Size = new System.Drawing.Size(30, 13);
            famLabel.TabIndex = 6;
            famLabel.Text = "Fam:";
            // 
            // opytLabel
            // 
            opytLabel.AutoSize = true;
            opytLabel.Location = new System.Drawing.Point(67, 331);
            opytLabel.Name = "opytLabel";
            opytLabel.Size = new System.Drawing.Size(32, 13);
            opytLabel.TabIndex = 8;
            opytLabel.Text = "Opyt:";
            // 
            // garantyLabel
            // 
            garantyLabel.AutoSize = true;
            garantyLabel.Location = new System.Drawing.Point(67, 357);
            garantyLabel.Name = "garantyLabel";
            garantyLabel.Size = new System.Drawing.Size(47, 13);
            garantyLabel.TabIndex = 10;
            garantyLabel.Text = "Garanty:";
            // 
            // dateLabel
            // 
            dateLabel.AutoSize = true;
            dateLabel.Location = new System.Drawing.Point(67, 383);
            dateLabel.Name = "dateLabel";
            dateLabel.Size = new System.Drawing.Size(33, 13);
            dateLabel.TabIndex = 12;
            dateLabel.Text = "Date:";
            // 
            // dataGridView1
            // 
            this.dataGridView1.AutoGenerateColumns = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.iDDataGridViewTextBoxColumn,
            this.markaDataGridViewTextBoxColumn,
            this.vDataGridViewTextBoxColumn,
            this.rDataGridViewTextBoxColumn,
            this.iDDDataGridViewTextBoxColumn,
            this.countryDataGridViewTextBoxColumn,
            this.dateDataGridViewTextBoxColumn});
            this.dataGridView1.DataSource = this.tAutoBindingSource;
            this.dataGridView1.Location = new System.Drawing.Point(0, 28);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(748, 150);
            this.dataGridView1.TabIndex = 0;
            // 
            // iDDataGridViewTextBoxColumn
            // 
            this.iDDataGridViewTextBoxColumn.DataPropertyName = "ID";
            this.iDDataGridViewTextBoxColumn.HeaderText = "ID";
            this.iDDataGridViewTextBoxColumn.Name = "iDDataGridViewTextBoxColumn";
            // 
            // markaDataGridViewTextBoxColumn
            // 
            this.markaDataGridViewTextBoxColumn.DataPropertyName = "Marka";
            this.markaDataGridViewTextBoxColumn.HeaderText = "Marka";
            this.markaDataGridViewTextBoxColumn.Name = "markaDataGridViewTextBoxColumn";
            // 
            // vDataGridViewTextBoxColumn
            // 
            this.vDataGridViewTextBoxColumn.DataPropertyName = "V";
            this.vDataGridViewTextBoxColumn.HeaderText = "V";
            this.vDataGridViewTextBoxColumn.Name = "vDataGridViewTextBoxColumn";
            // 
            // rDataGridViewTextBoxColumn
            // 
            this.rDataGridViewTextBoxColumn.DataPropertyName = "R";
            this.rDataGridViewTextBoxColumn.HeaderText = "R";
            this.rDataGridViewTextBoxColumn.Name = "rDataGridViewTextBoxColumn";
            // 
            // iDDDataGridViewTextBoxColumn
            // 
            this.iDDDataGridViewTextBoxColumn.DataPropertyName = "IDD";
            this.iDDDataGridViewTextBoxColumn.HeaderText = "IDD";
            this.iDDDataGridViewTextBoxColumn.Name = "iDDDataGridViewTextBoxColumn";
            // 
            // countryDataGridViewTextBoxColumn
            // 
            this.countryDataGridViewTextBoxColumn.DataPropertyName = "Country";
            this.countryDataGridViewTextBoxColumn.HeaderText = "Country";
            this.countryDataGridViewTextBoxColumn.Name = "countryDataGridViewTextBoxColumn";
            // 
            // dateDataGridViewTextBoxColumn
            // 
            this.dateDataGridViewTextBoxColumn.DataPropertyName = "Date";
            this.dateDataGridViewTextBoxColumn.HeaderText = "Date";
            this.dateDataGridViewTextBoxColumn.Name = "dateDataGridViewTextBoxColumn";
            // 
            // tAutoBindingSource
            // 
            this.tAutoBindingSource.DataMember = "TAuto";
            this.tAutoBindingSource.DataSource = this.dBAutoDataSet;
            // 
            // dBAutoDataSet
            // 
            this.dBAutoDataSet.DataSetName = "DBAutoDataSet";
            this.dBAutoDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // bindingNavigator1
            // 
            this.bindingNavigator1.AddNewItem = this.bindingNavigatorAddNewItem;
            this.bindingNavigator1.BindingSource = this.tAutoBindingSource;
            this.bindingNavigator1.CountItem = this.bindingNavigatorCountItem;
            this.bindingNavigator1.DeleteItem = this.bindingNavigatorDeleteItem;
            this.bindingNavigator1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.bindingNavigatorMoveFirstItem,
            this.bindingNavigatorMovePreviousItem,
            this.bindingNavigatorSeparator,
            this.bindingNavigatorPositionItem,
            this.bindingNavigatorCountItem,
            this.bindingNavigatorSeparator1,
            this.bindingNavigatorMoveNextItem,
            this.bindingNavigatorMoveLastItem,
            this.bindingNavigatorSeparator2,
            this.bindingNavigatorAddNewItem,
            this.bindingNavigatorDeleteItem});
            this.bindingNavigator1.Location = new System.Drawing.Point(0, 0);
            this.bindingNavigator1.MoveFirstItem = this.bindingNavigatorMoveFirstItem;
            this.bindingNavigator1.MoveLastItem = this.bindingNavigatorMoveLastItem;
            this.bindingNavigator1.MoveNextItem = this.bindingNavigatorMoveNextItem;
            this.bindingNavigator1.MovePreviousItem = this.bindingNavigatorMovePreviousItem;
            this.bindingNavigator1.Name = "bindingNavigator1";
            this.bindingNavigator1.PositionItem = this.bindingNavigatorPositionItem;
            this.bindingNavigator1.Size = new System.Drawing.Size(891, 25);
            this.bindingNavigator1.TabIndex = 1;
            this.bindingNavigator1.Text = "bindingNavigator1";
            // 
            // bindingNavigatorAddNewItem
            // 
            this.bindingNavigatorAddNewItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorAddNewItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorAddNewItem.Image")));
            this.bindingNavigatorAddNewItem.Name = "bindingNavigatorAddNewItem";
            this.bindingNavigatorAddNewItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorAddNewItem.Size = new System.Drawing.Size(23, 22);
            this.bindingNavigatorAddNewItem.Text = "Add new";
            // 
            // bindingNavigatorCountItem
            // 
            this.bindingNavigatorCountItem.Name = "bindingNavigatorCountItem";
            this.bindingNavigatorCountItem.Size = new System.Drawing.Size(35, 22);
            this.bindingNavigatorCountItem.Text = "of {0}";
            this.bindingNavigatorCountItem.ToolTipText = "Total number of items";
            // 
            // bindingNavigatorDeleteItem
            // 
            this.bindingNavigatorDeleteItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorDeleteItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorDeleteItem.Image")));
            this.bindingNavigatorDeleteItem.Name = "bindingNavigatorDeleteItem";
            this.bindingNavigatorDeleteItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorDeleteItem.Size = new System.Drawing.Size(23, 22);
            this.bindingNavigatorDeleteItem.Text = "Delete";
            // 
            // bindingNavigatorMoveFirstItem
            // 
            this.bindingNavigatorMoveFirstItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorMoveFirstItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveFirstItem.Image")));
            this.bindingNavigatorMoveFirstItem.Name = "bindingNavigatorMoveFirstItem";
            this.bindingNavigatorMoveFirstItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorMoveFirstItem.Size = new System.Drawing.Size(23, 22);
            this.bindingNavigatorMoveFirstItem.Text = "Move first";
            // 
            // bindingNavigatorMovePreviousItem
            // 
            this.bindingNavigatorMovePreviousItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorMovePreviousItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMovePreviousItem.Image")));
            this.bindingNavigatorMovePreviousItem.Name = "bindingNavigatorMovePreviousItem";
            this.bindingNavigatorMovePreviousItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorMovePreviousItem.Size = new System.Drawing.Size(23, 22);
            this.bindingNavigatorMovePreviousItem.Text = "Move previous";
            // 
            // bindingNavigatorSeparator
            // 
            this.bindingNavigatorSeparator.Name = "bindingNavigatorSeparator";
            this.bindingNavigatorSeparator.Size = new System.Drawing.Size(6, 25);
            // 
            // bindingNavigatorPositionItem
            // 
            this.bindingNavigatorPositionItem.AccessibleName = "Position";
            this.bindingNavigatorPositionItem.AutoSize = false;
            this.bindingNavigatorPositionItem.Name = "bindingNavigatorPositionItem";
            this.bindingNavigatorPositionItem.Size = new System.Drawing.Size(50, 23);
            this.bindingNavigatorPositionItem.Text = "0";
            this.bindingNavigatorPositionItem.ToolTipText = "Current position";
            // 
            // bindingNavigatorSeparator1
            // 
            this.bindingNavigatorSeparator1.Name = "bindingNavigatorSeparator1";
            this.bindingNavigatorSeparator1.Size = new System.Drawing.Size(6, 25);
            // 
            // bindingNavigatorMoveNextItem
            // 
            this.bindingNavigatorMoveNextItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorMoveNextItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveNextItem.Image")));
            this.bindingNavigatorMoveNextItem.Name = "bindingNavigatorMoveNextItem";
            this.bindingNavigatorMoveNextItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorMoveNextItem.Size = new System.Drawing.Size(23, 22);
            this.bindingNavigatorMoveNextItem.Text = "Move next";
            // 
            // bindingNavigatorMoveLastItem
            // 
            this.bindingNavigatorMoveLastItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorMoveLastItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveLastItem.Image")));
            this.bindingNavigatorMoveLastItem.Name = "bindingNavigatorMoveLastItem";
            this.bindingNavigatorMoveLastItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorMoveLastItem.Size = new System.Drawing.Size(23, 22);
            this.bindingNavigatorMoveLastItem.Text = "Move last";
            // 
            // bindingNavigatorSeparator2
            // 
            this.bindingNavigatorSeparator2.Name = "bindingNavigatorSeparator2";
            this.bindingNavigatorSeparator2.Size = new System.Drawing.Size(6, 25);
            // 
            // tOwnerBindingSource
            // 
            this.tOwnerBindingSource.DataMember = "FK_TOwner_TAuto";
            this.tOwnerBindingSource.DataSource = this.tAutoBindingSource;
            // 
            // iDOTextBox
            // 
            this.iDOTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.tOwnerBindingSource, "IDO", true));
            this.iDOTextBox.Location = new System.Drawing.Point(120, 250);
            this.iDOTextBox.Name = "iDOTextBox";
            this.iDOTextBox.Size = new System.Drawing.Size(100, 20);
            this.iDOTextBox.TabIndex = 3;
            // 
            // iDTextBox
            // 
            this.iDTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.tOwnerBindingSource, "ID", true));
            this.iDTextBox.Location = new System.Drawing.Point(120, 276);
            this.iDTextBox.Name = "iDTextBox";
            this.iDTextBox.Size = new System.Drawing.Size(100, 20);
            this.iDTextBox.TabIndex = 5;
            // 
            // famTextBox
            // 
            this.famTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.tOwnerBindingSource, "Fam", true));
            this.famTextBox.Location = new System.Drawing.Point(120, 302);
            this.famTextBox.Name = "famTextBox";
            this.famTextBox.Size = new System.Drawing.Size(100, 20);
            this.famTextBox.TabIndex = 7;
            // 
            // opytTextBox
            // 
            this.opytTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.tOwnerBindingSource, "Opyt", true));
            this.opytTextBox.Location = new System.Drawing.Point(120, 328);
            this.opytTextBox.Name = "opytTextBox";
            this.opytTextBox.Size = new System.Drawing.Size(100, 20);
            this.opytTextBox.TabIndex = 9;
            // 
            // garantyTextBox
            // 
            this.garantyTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.tOwnerBindingSource, "Garanty", true));
            this.garantyTextBox.Location = new System.Drawing.Point(120, 354);
            this.garantyTextBox.Name = "garantyTextBox";
            this.garantyTextBox.Size = new System.Drawing.Size(100, 20);
            this.garantyTextBox.TabIndex = 11;
            // 
            // dateTextBox
            // 
            this.dateTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.tOwnerBindingSource, "Date", true));
            this.dateTextBox.Location = new System.Drawing.Point(120, 380);
            this.dateTextBox.Name = "dateTextBox";
            this.dateTextBox.Size = new System.Drawing.Size(100, 20);
            this.dateTextBox.TabIndex = 13;
            // 
            // tMotorBindingSource
            // 
            this.tMotorBindingSource.DataMember = "TMotor";
            this.tMotorBindingSource.DataSource = this.dBAutoDataSet;
            // 
            // tAutoTableAdapter
            // 
            this.tAutoTableAdapter.ClearBeforeFill = true;
            // 
            // tOwnerTableAdapter
            // 
            this.tOwnerTableAdapter.ClearBeforeFill = true;
            // 
            // tableAdapterManager
            // 
            this.tableAdapterManager.BackupDataSetBeforeUpdate = false;
            this.tableAdapterManager.TAutoTableAdapter = this.tAutoTableAdapter;
            this.tableAdapterManager.TMotorTableAdapter = this.tMotorTableAdapter;
            this.tableAdapterManager.TOwnerTableAdapter = this.tOwnerTableAdapter;
            this.tableAdapterManager.UpdateOrder = _6_ShopAuto.DBAutoDataSetTableAdapters.TableAdapterManager.UpdateOrderOption.InsertUpdateDelete;
            // 
            // tMotorTableAdapter
            // 
            this.tMotorTableAdapter.ClearBeforeFill = true;
            // 
            // dataGridView2
            // 
            this.dataGridView2.AutoGenerateColumns = false;
            this.dataGridView2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView2.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.iDDataGridViewTextBoxColumn1,
            this.markaDataGridViewTextBoxColumn1,
            this.vDataGridViewTextBoxColumn1,
            this.rDataGridViewTextBoxColumn1,
            this.iDDDataGridViewTextBoxColumn1,
            this.countryDataGridViewTextBoxColumn1,
            this.dateDataGridViewTextBoxColumn1});
            this.dataGridView2.DataSource = this.fKTAutoTMotorBindingSource;
            this.dataGridView2.Location = new System.Drawing.Point(294, 246);
            this.dataGridView2.Name = "dataGridView2";
            this.dataGridView2.Size = new System.Drawing.Size(454, 150);
            this.dataGridView2.TabIndex = 14;
            // 
            // fKTAutoTMotorBindingSource
            // 
            this.fKTAutoTMotorBindingSource.DataMember = "FK_TAuto_TMotor";
            this.fKTAutoTMotorBindingSource.DataSource = this.tMotorBindingSource;
            // 
            // iDDataGridViewTextBoxColumn1
            // 
            this.iDDataGridViewTextBoxColumn1.DataPropertyName = "ID";
            this.iDDataGridViewTextBoxColumn1.HeaderText = "ID";
            this.iDDataGridViewTextBoxColumn1.Name = "iDDataGridViewTextBoxColumn1";
            // 
            // markaDataGridViewTextBoxColumn1
            // 
            this.markaDataGridViewTextBoxColumn1.DataPropertyName = "Marka";
            this.markaDataGridViewTextBoxColumn1.HeaderText = "Marka";
            this.markaDataGridViewTextBoxColumn1.Name = "markaDataGridViewTextBoxColumn1";
            // 
            // vDataGridViewTextBoxColumn1
            // 
            this.vDataGridViewTextBoxColumn1.DataPropertyName = "V";
            this.vDataGridViewTextBoxColumn1.HeaderText = "V";
            this.vDataGridViewTextBoxColumn1.Name = "vDataGridViewTextBoxColumn1";
            // 
            // rDataGridViewTextBoxColumn1
            // 
            this.rDataGridViewTextBoxColumn1.DataPropertyName = "R";
            this.rDataGridViewTextBoxColumn1.HeaderText = "R";
            this.rDataGridViewTextBoxColumn1.Name = "rDataGridViewTextBoxColumn1";
            // 
            // iDDDataGridViewTextBoxColumn1
            // 
            this.iDDDataGridViewTextBoxColumn1.DataPropertyName = "IDD";
            this.iDDDataGridViewTextBoxColumn1.HeaderText = "IDD";
            this.iDDDataGridViewTextBoxColumn1.Name = "iDDDataGridViewTextBoxColumn1";
            // 
            // countryDataGridViewTextBoxColumn1
            // 
            this.countryDataGridViewTextBoxColumn1.DataPropertyName = "Country";
            this.countryDataGridViewTextBoxColumn1.HeaderText = "Country";
            this.countryDataGridViewTextBoxColumn1.Name = "countryDataGridViewTextBoxColumn1";
            // 
            // dateDataGridViewTextBoxColumn1
            // 
            this.dateDataGridViewTextBoxColumn1.DataPropertyName = "Date";
            this.dateDataGridViewTextBoxColumn1.HeaderText = "Date";
            this.dateDataGridViewTextBoxColumn1.Name = "dateDataGridViewTextBoxColumn1";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(891, 529);
            this.Controls.Add(this.dataGridView2);
            this.Controls.Add(iDOLabel);
            this.Controls.Add(this.iDOTextBox);
            this.Controls.Add(iDLabel);
            this.Controls.Add(this.iDTextBox);
            this.Controls.Add(famLabel);
            this.Controls.Add(this.famTextBox);
            this.Controls.Add(opytLabel);
            this.Controls.Add(this.opytTextBox);
            this.Controls.Add(garantyLabel);
            this.Controls.Add(this.garantyTextBox);
            this.Controls.Add(dateLabel);
            this.Controls.Add(this.dateTextBox);
            this.Controls.Add(this.bindingNavigator1);
            this.Controls.Add(this.dataGridView1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tAutoBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dBAutoDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.bindingNavigator1)).EndInit();
            this.bindingNavigator1.ResumeLayout(false);
            this.bindingNavigator1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.tOwnerBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tMotorBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.fKTAutoTMotorBindingSource)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private DBAutoDataSet dBAutoDataSet;
        private System.Windows.Forms.BindingSource tAutoBindingSource;
        private DBAutoDataSetTableAdapters.TAutoTableAdapter tAutoTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn iDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn markaDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn vDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn rDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn iDDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn countryDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn dateDataGridViewTextBoxColumn;
        private System.Windows.Forms.BindingNavigator bindingNavigator1;
        private System.Windows.Forms.ToolStripButton bindingNavigatorAddNewItem;
        private System.Windows.Forms.ToolStripLabel bindingNavigatorCountItem;
        private System.Windows.Forms.ToolStripButton bindingNavigatorDeleteItem;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMoveFirstItem;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMovePreviousItem;
        private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator;
        private System.Windows.Forms.ToolStripTextBox bindingNavigatorPositionItem;
        private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator1;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMoveNextItem;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMoveLastItem;
        private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator2;
        private System.Windows.Forms.BindingSource tOwnerBindingSource;
        private DBAutoDataSetTableAdapters.TOwnerTableAdapter tOwnerTableAdapter;
        private DBAutoDataSetTableAdapters.TableAdapterManager tableAdapterManager;
        private System.Windows.Forms.TextBox iDOTextBox;
        private System.Windows.Forms.TextBox iDTextBox;
        private System.Windows.Forms.TextBox famTextBox;
        private System.Windows.Forms.TextBox opytTextBox;
        private System.Windows.Forms.TextBox garantyTextBox;
        private System.Windows.Forms.TextBox dateTextBox;
        private DBAutoDataSetTableAdapters.TMotorTableAdapter tMotorTableAdapter;
        private System.Windows.Forms.BindingSource tMotorBindingSource;
        private System.Windows.Forms.DataGridView dataGridView2;
        private System.Windows.Forms.DataGridViewTextBoxColumn iDDataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn markaDataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn vDataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn rDataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn iDDDataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn countryDataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn dateDataGridViewTextBoxColumn1;
        private System.Windows.Forms.BindingSource fKTAutoTMotorBindingSource;
    }
}

