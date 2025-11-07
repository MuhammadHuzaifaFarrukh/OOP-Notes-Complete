#include <iostream>

using namespace std;

//Static Variables and Static Member Functions are used commonly in all the Objects
//As we make normal members of a class , each object has its own members taking space
//But static variables of a class are shared among each object of the same class
//Static Data members don't use member initialization list as well
//Static Member Functions only use static member variables

class emp
{
private:
    int id;
    static int count; //by default has value of zero , also give a reference outside the class to assign any value or to simply use it
    //Cannot initialize it here , where declared.
    //Give it value outside the class , where its reference is given


    //====CONST STATIC VARIABLE ============

    //For a Variable like :
    //static const int abc;
    //Can't be changed
    //Can be declared here and initialized outside but then , no reassigning values as it is const
    //Can be initialized right here , but if done here then no need to initalize in the refernce outside
    //Can be initialized right here only for integer and char data types only and use inline keyword with it to use with others as well
    //E.g : inline static const float p = 10.2;
    //Inline works with all const static data types 

    


    //For Const Non-Static Data Members
    //const int x;
    //Value can be given here (for any data type)
    //Value can be given using member initialization list
    //Can't change value afterwards

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

    //We can use local variables made by ourselves or the parameters passed from this static function
    //We generally can't use or call other member functions as this function is not called by a specific object
    //One way to call the non static member functions here is that we pass the object by reference in the paramter of this static function
    //Then we can call the non-static member function using the object passed
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
//A normal static function can use any type of variable
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

    gohan.getcount(); //We can use static data members or functions but it still is called as a shared for class only , not for particular object

    return 0;
}









//Normal Static Functions :

/*
#include <iostream>

static void hiddenFunction()    // Only visible in this file / program , Can use other variables as well
{
    std::cout << "I'm hidden from other files!" << std::endl;
}

void publicFunction()    // Visible to other files
{
    std::cout << "I'm public!" << std::endl;
}

int main()
{
    hiddenFunction();  // ✅ Works - same file
    publicFunction();  // ✅ Works
    return 0;
}
*/
