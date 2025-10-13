#include<iostream>

using namespace std;

class MyClass
{
public:
    float data;

};

int main()
{
    MyClass obj; // Compiler-generated default constructor used here
    // ...
    cout<<obj.data;
    // Compiler-generated default destructor called here when obj goes out of scope


    //Default or you can say blank as compiler provides constructor which does nothing so it is blank but we usually call it default
    return 0;
}
