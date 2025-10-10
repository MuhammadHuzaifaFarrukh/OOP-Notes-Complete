#include <iostream>

using namespace std;

struct students
{
    int age;
    float marks;
    students()
    {
        cout<<"Hello World "<<endl;
    }
    //You can also have constructor and if you don't then compiler will automatically give a default constructor


} huzaifa ;  // Just like classes , you can make an object for struct data type here as well


int main()  // If you mention typedef and then mention huzaifa then huzaifa will become alias for struct students and serve as alternate name
{
    // students huzaifa;  By default , struct and union are typedef in C++
    // struct students huzaifa;
    huzaifa.age=17;
    cout<<huzaifa.age<<endl;

    return 0;
}
