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



