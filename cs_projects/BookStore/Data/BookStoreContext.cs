using System;
using System.Collections.Generic;
using System.Reflection.Metadata;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Design;
using Microsoft.Extensions.DependencyInjection;
using Npgsql.EntityFrameworkCore.PostgreSQL;

namespace BookStore;

public class BookStoreContext : DbContext
{

    public DbSet<Book> Books { get; set; }

    private const string CONNECTION_STRING =
        "Host=localhost;Port=3434;" +
        "Username=postgres;" +
        "Password=postgres;" +
        "Database=postgres";

    protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
    {
        optionsBuilder.UseNpgsql(CONNECTION_STRING);
        base.OnConfiguring(optionsBuilder);
    }


    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        modelBuilder.Entity<Book>().ToTable("book");
        base.OnModelCreating(modelBuilder);

    }

    public int Add(Book game)
    {
        using (var db = new BookStoreContext())
        {
            db.Books.Add(game);
            return db.SaveChanges();
        }
    }

    public Book Get(int id)
    {
        using (var db = new BookStoreContext())
        {
            return db.Books.Find(id);
        }
    }

    public List<Book> GetAll()
    {
        using (var db = new BookStoreContext())
        {
            return db.Books.ToList();
        }
    }

    public void Update(int id, Book game)
    {
        using (var db = new BookStoreContext())
        {
            db.Books.Update(game);
            db.SaveChanges();

        }
    }

    public void Delete(int id)
    {
        using (var db = new BookStoreContext())
        {
            var game = db.Books.Find(id);
            if (game == null)
                return;

            db.Books.Remove(game);
            db.SaveChanges();
        }
    }

}

