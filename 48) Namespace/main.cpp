#include <iostream>
using namespace std;

//You can also use one namespace from one file into another namespace of another header file
namespace huz
{
int a;
void f1();
class A
{
public :
    void display();
};
}

void huz::f1()
{
    cout<<"Its f1 function : "<<endl;
}
void huz::A::display()
{
    cout<<"Its display function from class A : "<<endl;
}

// using namespace huz; This allows you not to write name of the namespace globally but will become conflicting if two same named members from different namespaces are used in the same program .

int main()
{
    // using namespace huz; This allows you not to write the name of the namespace for only main() function

    huz::f1();
    huz::A a1;
    a1.display();

    return 0;
}




//Difference between Named and Unnamed Namespaces
//Unnamed Namespaces are used only in the file where they are made ( Equivalent to a Private Namespace like private in classes)
namespace
{
// This is "private" to this specific .cpp file
void localHelper() {}
}


//Named Namespaces can be used anywhere in other files as well (Always Public if you use in other files)
namespace MyLibrary //Can be used anywhere
{
void publicFunction()
{
    localHelper(); // Only usable here (unnamed namespace function)
}
}


//Hiding a Namespace :
//1) Use Unnamed Namespaces
//2) Use a namespace with names : "internal" , "detail" , "impl"
//In the 2nd option , the namespace is not actually hidden technically but socially.
//It relies on a widely accepted C++ convention: developers agree that anything inside a
//namespace named detail, internal, or impl is "private" and shouldn't be touched,
//even though the compiler allows it.
