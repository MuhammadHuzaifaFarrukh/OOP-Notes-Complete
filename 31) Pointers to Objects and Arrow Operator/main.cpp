#include <iostream>

using namespace std;


//Using Pointer to Access Object's public members.
//Arrow Operator used with stack allocated arrays , not variables
//Used with pointers either on stack or heap , pointing to arrays or variables or objects etc
// Arrow operator takes an address on its left side and a variable / function on its right side
// (Address) -> Variable / Function / Any other Member

// Can also be used if for making long chains like obj1->obj2-> and so on as long as the left sides are addresses/pointers
// Works in structs , unions , classes

class Complex
{
private :

    int real, imag;
public :
    int a ;

    void setdata(int, int );
    void getdata();
};

void Complex::setdata( int a, int b)
{
    real = a;
    imag = b;
}

void Complex::getdata()
{
    cout<<"The Complex number is : "<<real<<" + "<<imag<<"i "<<endl<<endl;
    cout<<"The real part is : "<<real<<endl;
    cout<<"The imaginary part is : "<<imag<<endl;

}

int main()
{
    //Complex c1;
    //Complex *ptr = &c1;  //Allowed
    Complex *ptr = new Complex;  //Dynamic allocation of Object.
    (*ptr).setdata(2,4);
    ptr->getdata();  //Arrow Operator is used to dereference a pointer  (Whether dynamic or not)
    //Used for only objects and accessing members of that class.
    delete ptr;
    ptr=nullptr;



    //(ARROW OPERATOR)
    //Arrow Operator is used when we have a pointer to object within that scope
    //Can also use (*) Derefernce Operator also to use them
    // -> has a pointer on its left side


    //Now Array through ->




    Complex *ptr1 = new Complex[6];  //Dynamic allocation of Object.
    (*ptr1).setdata(5,6);

    //Can access array with index like ptr1[0] or ptr1[3] with dot (.) like ptr[0].getdata() etc
    //Can't use (->) with dynamic array indexing like ptr[1]->getdata() WRONG
    //Only with dynamic array , we can use its name without index like ptr->getdata(); and then ptr++ points to next element so again ptr->getdata()


    ptr1->getdata();  //Arrow Operator is used to dereference a pointer  (Whether dynamic or not)
    //Used for only objects and accessing members of that class.
    ptr1->a = 10;   //Used to access member variables also
    cout<<ptr1->a;   //Prints member variable.
    delete ptr1;
    ptr1=nullptr;

    //The value after delete[] might still be there or waiting to be overwritten by other programs

    /*
    Complex *o1 = new Complex[4];
    Complex *o2;
    Either o2 = o1 ; or Complex *o2 = o1;
    The Above line assigns o2 to same memory location as o1 making both pointers same
    */


    //Another Example of using (->) :

    //Complex *c1[2]; //c1 contains two pointsrs so we can access as follows
    //c1[0] = any object; (Stack or heap by new keyword)
    //c1[0].member // Wrong
    //c1[0]->member // Correct as c1[0] contains address , not the object

    return 0;
}
