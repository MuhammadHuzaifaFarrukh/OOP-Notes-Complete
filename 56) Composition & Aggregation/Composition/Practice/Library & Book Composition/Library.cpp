#pragma once
#include <string>
#include "Library.h"
#include "Book.h"
using namespace std;

void Library::addbook(const Book &b)
{
    if (bookCount < 10)
    {
        books[bookCount] = b;
        bookCount++;
    }
}

void Library::displaybooks()
{
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].getAuthor() != "" && books[i].getTitle() != "")
        {
            books[i].print();
        }
    }
}