#include <iostream>
#include <string>
#include "Library.h"
#include "Book.h"
#include "Library.cpp"
#include "Book.cpp"
using namespace std;

int main()
{
    cout<<"--- Library Books --- "<<endl;
    Library lib;
    lib.addbook(Book("C++ Basics", "Bjarne"));
    lib.addbook(Book("Algorithms", "CLRS"));
    lib.displaybooks();
    return 0;
}