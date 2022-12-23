namespace BookStore;
using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.EntityFrameworkCore;
using Npgsql.EntityFrameworkCore.PostgreSQL;

class Program
{
    static void Main(string[] args)
    {
        using var db = new BookStoreContext();

        printAll(db);

        // addBook(db);

        System.Console.WriteLine("Which book do you want to remove? \n Enter the book id:");
        int id = int.Parse(Console.ReadLine());
        db.Remove(db.Get(id));
        db.SaveChanges();

        printAll(db);

        // var book1 = db.Books
        //    .OrderBy(b => b.BookId)
        //    .Last();

        // // var book2 = db.Books.Find(book1.BookId);

        // var bookUpdate = db.Get(book1.BookId);
        // bookUpdate.Condition = "Renewed";
        // db.Update(bookUpdate);

        // printAll(db);
    }

    public static void printAll(BookStoreContext db)
    {
        System.Console.WriteLine("*************************************************");
        foreach (Book b in db.GetAll())
        {
            Console.WriteLine($"Title: {b.Title} Author: {b.Author}\n" +
                $"Id: {b.BookId} Condition: {b.Condition} Price: {b.Price}");
        }
        System.Console.WriteLine("*************************************************");
    }

    public static void addBook(BookStoreContext db)
    {
        int timestamp = Math.Abs((int)DateTime.Now.ToFileTime());

        Author author = new Author();
        Book book = new Book();

        book.BookId = timestamp / 50000;
        author.AuthorId = timestamp / 40000;

        book.DateSold = DateTime.UtcNow;
        book.Author = author;

        // author.Name = "Enes D";
        // book.Title = "The Book";
        // book.Condition = "Nice";
        // book.Price = 10;

        Console.Write("Author name:");
        author.Name = Console.ReadLine();

        Console.Write("Book title:");
        book.Title = Console.ReadLine();

        Console.Write("Book condition:");
        book.Condition = Console.ReadLine();

        Console.Write("Book price:");
        book.Price = double.Parse(Console.ReadLine());

        db.Add(book);
        db.SaveChanges();

        printAll(db);
    }
}