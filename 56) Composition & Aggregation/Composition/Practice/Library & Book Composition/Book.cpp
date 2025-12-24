#include "Book.h"
#include "string"
#include <iostream>

using namespace std;

void Book::print()
{
    cout << "Title: " << title << ", Author: " << author << endl;
}

Book ::Book()
{
    title = "";
    author = "";
}

Book ::Book(string t, string a)
{
    title = t;
    author = a;
}

string Book::getTitle()
{
    return title;
}

string Book::getAuthor()
{
    return author;
}