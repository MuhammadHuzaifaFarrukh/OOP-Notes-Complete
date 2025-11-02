#include <iostream>

using namespace std;

/*
An lvalue (short for "locator value" or "left value") is a C++ expression that refers to a
persistent object or function in memory and therefore has a verifiable memory address (identity)
that persists beyond the expression it is used in
*/

//The most intuitive way to think of it is: if you can take the address of an expression using the address-of operator (2$\&$), it's an lvalue
//An Lvalue can be used as Rvalue but rvalue is not used as an lvalue
//Remember , const before * in pointer shows that value cannot be changed using pointer , and const after * in pointer variable shows that the address that pointer variable holds cannot be changed


int arr[3] = {10, 20, 30};
// A Function that returns an lvalue , can be assigned to a value or can be assigned a value
// If the return type of function is const int & , then it can be assigned to a value (rvalue) but cannot be assigned a value and won't be able to use it as rvalue for non-const references e.g : int& bad_ref = getElement(1); gives errors
// In real-world C++, returning a const T& is the standard way to implement a non-mutating "getter" method for a class member.
int& getElement(int index)
{
    return arr[index]; // Returns a reference to an element in the global array.
}

int main()
{

    //Some Examples :

    //Variable Name :
    int x = 10;
    const int y = 10;

    //Dereferenced Pointer :
    int* ptr = &x;

    //Array Subscript Expression (the Element itself) :
    //arr[0]

    //++x or ++x = 10;


    //Although x , lvalue , here it is used as rvalue :
    //int f = x;

    //For Reference Variables :
    int& ref_ = x;  //Valid , non-const lvalue ref can be done to lvalue


    // int& ref_err = c ; where c is a const int
    // int& ref_err = 5;  //Both Statements are Error , non-const lvalue ref cannot bind to temporary / const lvalue / rvalue

    const int& ref_ok = 5; // Fine as const lvalue ref can bind to both const and non-const lvalue



    //Pointers :
    int a = 1, b = 2;
    int* p = &a; // p is a non-const lvalue

    // ref_p is a reference to a POINTER TO int (Like a Reference Variable / Alias)
    int*& ref_p = p;

    ref_p = &b; // OK: This changes 'p' to point to 'b' instead of 'a'.

    //Also a *const and *non-const pointer can point only to a non const variable
    //const int y = 20; int *p = &y;            //Error
    //const int y = 20; int *const p = &y;      //Error
    //Both allow changing of const variable which is not allowed , so variable must be non-const

    //Safe Case :
    //int x = 10; const int *p = &x;            //Value cannot be changed through p
    //const int y = 20; const int *p = &y;      //Value cannot be changed through p and y
    //Here const before * means that value can / cannot be changed , but pointer can be changed
    //The const before * can point to both const and non-const variables



    //Functions :
    //Function that returns lvalue reference :
    int g= getElement(1);   //Can be assigned to a value
    getElement(1) = g+5;    //Can be assigned a value
    //For this function that returns lvalue , value can be assigned if and only if the reference is not dangling , like our array should exist in main or in global , but not in function as the memory for array will not be there as soon as function ends



    return 0;
}
