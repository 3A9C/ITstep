//------------------------------------------------------------------------------
// <auto-generated>
//     Этот код создан по шаблону.
//
//     Изменения, вносимые в этот файл вручную, могут привести к непредвиденной работе приложения.
//     Изменения, вносимые в этот файл вручную, будут перезаписаны при повторном создании кода.
// </auto-generated>
//------------------------------------------------------------------------------

namespace Example1DataBaseFirst
{
    using System;
    using System.Collections.Generic;

    // Сущность (класс). представаляющий запись  таблицы UsersInfo
    // базы данных PhoneStore
    public partial class UsersInfo
    {
        public long Id { get; set; }
        public string LastName { get; set; }
        public string FirstName { get; set; }
        public string Adres { get; set; }
        public string Phone { get; set; }
        public int Code { get; set; }
        public Nullable<long> UserId { get; set; }
    
        public virtual Users Users { get; set; }
    }
}
