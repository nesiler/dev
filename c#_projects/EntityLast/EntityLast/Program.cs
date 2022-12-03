using System;
using System.Linq;
using Microsoft.EntityFrameworkCore;
using System.Collections.Generic;
using Npgsql.EntityFrameworkCore.PostgreSQL;

namespace EntityLast;

class Program
{
    static void Main(string[] args)
    {

        using var db = new BookStoreContext();

        int timestamp = Math.Abs((int)DateTime.Now.ToFileTime());

        Book book = new Book();
        Author author = new Author();

        book.BookId = timestamp / 50000;

        author.Name = "Meine Buk";
        author.AuthorId = timestamp / 40000;

        book.Author = author;
        book.Title = "Damn god";
        book.Condition = "Bravo!";
        book.Price = 10;
        book.DateSold = DateTime.UtcNow;

        //db.Add(book);
        //db.SaveChanges();

        //var book1 = db.Books
        //    .OrderBy(b => b.BookId)
        //    .Last();

        //var book2 = db.Books.Find(book1.BookId);

        //book2.Condition = $"--{timestamp * 30000}--";
        //db.SaveChanges();

        //var book2 = db.Books.Find(book1.BookId);

        //book2.Condition = $"--{timestamp * 30000}--";
        //db.Remove(book2);

        db.Add(book);

        foreach (Book b in db.GetAll()){
            Console.WriteLine($"Title: {b.Title} Author: {b.Author}\n" +
                $"Id: {b.BookId} Condition: {b.Condition} Price: {b.Price}");
        }

        var bookUpdate = db.Get(book.BookId);
        bookUpdate.Condition = "Renewed";
        db.Update(bookUpdate);

        db.Delete(book.BookId);

        //db.SaveChanges();

        //Console.WriteLine("Delete the blog");
        //db.Remove(blog);
        //db.SaveChangesAsync();

    }
}