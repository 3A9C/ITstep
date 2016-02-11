namespace ConsoleApplication1.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class AddBlogUr : DbMigration
    {
        public override void Up()
        {
            AddColumn(
                "dbo.Cars", "Url", c => c.String()); 
        }
        
        public override void Down()
        {
            DropTable("dbo.Cars");
        }
    }
}
