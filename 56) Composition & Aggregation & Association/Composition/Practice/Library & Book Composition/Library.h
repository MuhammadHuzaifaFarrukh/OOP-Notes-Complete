#pragma once
#include <string>
#include "Book.h"
using namespace std;
class Library
{
private:
    Book books[10];
    int bookCount = 0;

public:
    void addbook(const Book &b);
    void displaybooks();
};