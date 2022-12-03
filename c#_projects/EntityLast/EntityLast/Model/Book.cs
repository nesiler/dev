using System;
namespace EntityLast;

public class Book
{
    public int BookId { get; set; }
    public string Title { get; set; }
    public string Condition { get; set; }
    public double Price { get; set; }
    public DateTime? DateSold { get; set; }
    public Author Author { get; set; }
    //public virtual ICollection<Review> Reviews { get; set; }
}

