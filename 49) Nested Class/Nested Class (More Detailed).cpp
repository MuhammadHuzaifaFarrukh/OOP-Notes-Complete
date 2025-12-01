#include <iostream>

using namespace std;

//Defining one class inside another is called Nested Class

class A
{
    int a = 1;
public :


    void fun();
// private:  //If we make class B private , then we need to call member functions of class B objects through nesting member functions of class A objects.
    class B; // Can be forward declared like this.


    // You may also create an object of class B here .
    //  B b2; // Now when we use class A , we already have an object of class B.
    //If you make an object of inner class in outer class , the accessiblity changes and you will use the inner class' member functions using nested member functions of outer class.
    //You cannot call the inner member function from main() by declaring an object here below

    //class B{   };

};

class A::B
{
    int a =6;
public :
    void display();


} b2; //If nested class is defined here , then object of inner class cannot be inside the outer class. It is considered to be inside outer class.

void A::B::display()
{
    A a5; // You can also make outer class objects inside inner class member functions and vice versa
    std::cout<<"Hello, I'm the nested class B member function :) "<<a5.a<<endl; //Inner Class can use the private data members of outer class without being friends


}
void A::fun()
{
//    B b4;
//    b4.a = 200;   //Outer Class cannot access inner class private data members without being friend
//    cout<<b4.a<<endl; //Outer Class cannot access inner class private data members without being friend
    std::cout<<"Hello , I'm the outer class A member function :) " <<endl;
    b2.display(); // If the inner class object is declared inside outer class or after the {} parenthesis of inner class ends , then we need to call member functions of inner class objects through outer class member function objects.
    // The above code will also work if the inner class is defined and declared in private visibility mode.
    B b3; //You can also make objects of inner class inside outer class member functions.
    b3.display();
    A a6;

}




int main()
{
    A::B b1;  //Make nested class objects like this ...
    b1.display(); //It cannot use the member functions of outer class .


    A a1;
    a1.fun();
//    std::cout<<"Value of b's a is : "<<b1.a<<endl;
//    std::cout<<"Value of A's a is : "<<a1.a<<endl;
//    b1.a=100;

    return 0;
}



