#include <iostream>
#include <fstream>
#include "Dozen.h" // Including the header file , sometimes needs full path inside " "

using namespace std;

int main()
{
    //Some functions' return type is changed just to follow chaining of functions by this pointer
    Dozen obj1(1,14);
    
    obj1.show();

    Dozen obj2(3,31);
    obj2.show();

    obj1.add(0, 1).show();
    obj1.add(obj2).show();

    obj1.subtract(obj2).show();

    cout << "Comparison : " << obj1.compare(obj2) << endl;
    obj1.swap(obj2);
    obj1.show();
    obj2.show();
    


    cout << "In float : " << obj1.toFloat() << endl;

    cout << "Round : " << obj1.round() << endl;

    cout << "Rough Comparison : " << obj1.rough_compare(obj2) << endl;




    return 0;
}