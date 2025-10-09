#include <iostream>

using namespace std;

//Static Variables and Static Member Functions are used commonly in all the Objects
//As we make normal members of a class , each object has its own members taking space
//But static variables of a class are shared among each object of the same class
//Static Member Functions only use static member variables

class emp
{
private:
    int id;
    static int count; //by default has value of zero , also give a reference outside the class to assign any value or to simply use it
public:

    void setdata();
    void getdata();
    static void getcount();

};
void emp::getcount()
{
    //id = 100;
    //Above line cannot be used as normal member variables / functions can't be used inside static member functions
    cout<<"The value of the count is " <<count<<endl;
}
void emp::setdata()
{
    cout<<"Enter your Id : ";
    cin>>id;
    count++;
}
void emp::getdata()
{
    cout<<"Your Employee Id is : "<<id<<" and the number of Employee is : "<<count<<endl;
}
int emp::count; //Necessary as all objects of this class will share the same static member variable named 'count'
//Static Member Variable has scope global here and lifetime global as well and its value is shared between all the objects
//Also these static member variables get memory and initialized any value once they are defined outside of their class before all other functions.

//Whereas a normal Static Variable in main or any other block has lifetime global but scope local.

int main()
{
    emp goku,vegeta,gohan;

    goku.setdata();
    goku.getdata();
    emp::getcount(); //No need to write the object name as it is called by specifying class_name and function name

    vegeta.setdata();
    vegeta.getdata();
    emp::getcount();

    gohan.setdata();
    gohan.getdata();
    emp::getcount();



    return 0;
}
