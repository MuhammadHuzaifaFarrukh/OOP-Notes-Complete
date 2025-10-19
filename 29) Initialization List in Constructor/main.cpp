#include <iostream>

using namespace std;

/*
Member Initialization List Synatx :
constructor_name(argument List ...) : initialization section
{ .....  }
initialization section will be like   variable ( value ) or variable (variable ) or variable ( function / member function ).




*/



class Test
{
private :
    int b // , int a;   // Here declaration should be in the same order as the value initialization below otherwise output changes

    string name ; int a ; // Here we can write (b,a) as int b , a together or also like this with variables in between
public :

    Test(int i, int j) :   b(j) , a(i+b)  //Order Matters and changes output ; This line might create errors if you have declared a and b like this  : int a,b; . Declaration order matters here so declare like this int b,a; This might produce garbage value on some compilers.
    { //After (:) sign , initializations must be less than or equal to no of variables of that type in class with order

        cout<<"Value of a and b is  : "<<a <<" and " <<b <<endl;
    }
};

int main()
{
    Test t1(1,2);

    return 0;
}






/*
//We can also place member variable and dummy variable with same name
#include <iostream>

using namespace std;
class A
{

public:int a;
   A(int a, int b)  : a(a)  // Outer 'a' is member variable and inner is dummy. This is also valid in inheritance  like A (int a , int b ) : B(b) , a(a) {.... }
   {
       cout<<"Value of a is : "<<a<<endl;
   }



};



int main()
{
    A obj1(3,4);
    cout<<endl<<obj1.a;

    return 0;
}
*/










