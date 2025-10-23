#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Parameterized constructors are simply the constructors that use parameters like any other function
//If we use paramterized or design any other type of constructor then compiler doesn't make the blank (default) constructor for us
//For this purpose , you should make a default or blank constructor by yourself whenever using the parameterized one

/*
class Complex
{
private :
    int a,b;
public :
    Complex();
    Complex(int , int );
    void printdata()
    {
        cout<<"Your number is : " <<a<< " + i"<<b<<endl;
    }
};

Complex :: Complex() Default Constructor : No Formal Parameters
{
    a=0;
    b=0;
}

Complex :: Complex(int x, int y) // Parameterized Constructors : Takes Formal Parameters and are initialized through implicit and explicit calls.
{
    a=x;
    b=y;
}

int main()
{
    Complex a(4,2);//Implicit Call
    //To change a value for next time or assign values after declaring an object
    //a = Complex(3,5);

    a.printdata();

    Complex b = Complex ( 6,5);//Explicit Call (Copy Epsilon , object b is constructed directly by calling the parameterized constructor in its final memory using the arg 6 and 5)
    //Although compiler uses Copy Epsilon Method here for optimization , we may think as parameterized constructor and compiler generated copy constructor called here , though it did happen in older C++ versions)
    b.printdata();
    return 0;
}
*/

//Also it is not mandatory that the blank (default) constructor by compiler or a default / blank by user with no operations in it will set the values of class member variables to zero as it sets them random (garbage) as well
//So you can either 1) Make a default constructor with setting value of each member set to zero or 2) Make a member initialization list in the blank / default constructor or you can also do that
//3) When making an instance of a class you can define it as : Point P = {} , this sets all the member variables to zero
//However this Point P = {} won't work if user has already made a default / blank constructor that does nothing

//4) Making a default constructor but using it like Point()=default and then when making an instance of a class use again Point P = {} , this ensures all member variables set to zero


//Also while using the myclass() = default constructor , this constructor is the one provided by compiler even if you have made / used parameterized constructors
//When you write myclass() = default;, you are telling the compiler, "I need a default constructor, but please generate it for me exactly the way you would have if I hadn't declared one."
//Only in this case the compiler makes a default constructor for you that does some operations (set values to zero)  even if you have made any constructor with parameters
//By using this constructor , you won't be able to use the constructor with no arguments , or a constructor with all default arguments for same class



class Point
{
private :
    int x;
    int y;
public:
    Point(int, int );
    void displaypoint();
    friend float squareroot(Point, Point);
};



Point :: Point (int a, int b)
{
    x=a;
    y=b;
}

void Point::displaypoint()
{
    cout<<"The Point is : ("<<x <<"," <<y<<")"<<endl;
}

float squareroot(Point p,Point q)
{
    return sqrt(((q.x-p.x)*(q.x-p.x))+((q.y-p.y)*(q.y-p.y)));
}

int main()
{
    Point p=Point(3,4); //p.x=3 , p.y=4
    p.displaypoint();

    Point q(1,2);   // q.x=1 ,  q.y=2
    q.displaypoint();

    float distance = squareroot(p,q);
    cout<<"The Distance between points p and q is : "<<setprecision(4)<<fixed<<distance<<" meters "<<endl;

    //setprecision(n) , where n is the number of significant figures
    //If used fixed after setprecision(n) , then n is the number of decimal places

    return 0;
}




 //Aggregate Initialization :

/*
if your class contains the member variables like int a , int arr[5] , int *p ;
    then you can initalize all them like this at the time of making instance
ClassObj Obj = {1, {1,2,3,4,5} , new int[10] } ;
//This is called Aggregate Initialization , and in this the order of the initialization must match

//For this to work , your variables must be public
//For this to work , constructor with no arguments must not be present (that's a blank / default one that does something)
//Your constructors should have no default arguments at all for this to work

//If you make a MyClass() = default then this syntax to initialize won't work in newer C++ versions


//If the data members are less than the values provided in the initialization list , then compiler issues errors
//If the data members are more than the values provided in the initialization list , then the remaining data members are initialized to zero or null pointer as per their data types

//Another point : 
//If we make myClass arr[10] which is an array of 10 objects then , first all their constructors will get called
//If this class only had x as its data member then we could init : myClass arr[10] = {1,2,3}; and rest of the objects would have x=0 and their constructors will be called and also due to this x , the constructors for first 3 objects will be called , if there is a parameterized one then that will be called on x value and if no constructor thn default one will be called for these 3 objects and also for the rest of them and set x=0 for them 
*/




