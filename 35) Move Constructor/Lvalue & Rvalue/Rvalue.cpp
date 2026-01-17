#include <iostream>

using namespace std;

/*
An rvalue (short for "right value") is a C++ expression that represents a temporary value that is not
stored in a persistent memory location and therefore does not have an identifiable, persistent
address that your program can reliably access.
*/
//Rvalue can be either prvalue or xvalue
//prvalue is pure rvalue like : A temporary value that is not the result of a move operation (e.g., literals like 5, results of arithmetic expressions like a + b).
//xvalue (expiring lvalue ) is a temporary value that is the result of a move operation (e.g., the result of std::move(a)).
//Both fall in category of rvalue so we usually call them as rvalue (usually not categorize it)

//The term traditionally comes from the rule that rvalues are only allowed on the right-hand side of an assignment operation.//An Lvalue can be used as Rvalue but rvalue is not used as an lvalue


int get_value()
{
    return 42;
}

int main()
{
    //Rvalues primarily consist of literals and the temporary results of most computations.

    //Some Examples :

    //An Integer / Float Literal or Const :
    int a = 10;     //10 is Rvalue
    int b = a + 5;  ////a+5 is Rvalue

    //b++
    //Although the change is made in b like lvalue but still , a temporary copy is returned before incrementing making it temporary rvalue

    //Function that returns rvalue or lvalue as lvalue can also be used as rvalue
    //a = get_value();          //get_value()'s return type can be either int or int& , mainly int for rvalue

    //===== Wrong =====
    // Cannot assign to an rvalue:
    // 5 = x;           // ERROR: '5' is an rvalue.
    // get_value() = 10; // ERROR: get_value() returns a temporary rvalue.
    // (x + 1) = 2;     // ERROR: (x + 1) is a temporary rvalue.
    // Cannot take the address of an rvalue:
    // int* p = &5;    // ERROR: '5' is an rvalue.

    //Using && for rvalue :
    int&& ref_ = 5;  //This creates an lvalue variable that holds rvalue extending lifetime of rvalue
    int &alias = ref_;  //A Named rvalue can be given alias by lvalue reference variable
    // Here ref and alias are lvalues , named variables
    // int&& is an rvalued reference type
    // int&& just tells that the lifetime of rvalue is extended by a lvalue var (or rvalue reference)
    // rvalue reference  =  lvalue variable
    // 5 is called pure rvalue

    //If function return type is const int (rvalue) , then the value can only be assigned to const int , const int& or new int
    //If function return type is int , then the value can only be assigned to int or int&&
    //If function return type is int& , then can be assigned a value and can be assigned to a variable
    //If function return type is const int& , then value can only be at right side of expression and also assigned only to const reference


    // By using move(ref) ,xvalue  , you can bind an lvalue to rvalue

    //Using move(lvalue) , ( Move Constructor compiler generated but just for variables right now)
    //Move constructor here not utilized in a way that it steals the values , here it just copies as there is no dynamic allocation and class
    int x = 10; // 'x' is a simple lvalue variable
    cout << "Initial value of x: " << x <<endl;

    // 1. Cast 'x' (lvalue) to int&& (rvalue reference)
    int&& ref_to_x = std::move(x);

    // 2. The move operation (initialization) occurs here
    // The 'int' move constructor is trivial; it just copies the value.
    int y = ref_to_x;
    // Equivalent to: int b = std::move(a);

    cout << "Value of y after move: " << y << endl;

    // For simple types, 'x' remains unchanged because there was nothing to "steal"
    // (its internal state is simply the value 10).
    cout << "Value of x after move: " << x << endl;

    // We can prove 'y' holds a copy by modifying it, and 'x' remains unaffected.
    y = 20;
    cout << "New value of y: " << y << endl;
    cout << "Final value of x: " << x << endl;


    //const int&& f = x         //Wrong regardless of x being const or not
    //const int&& f = x+y      //Correct , as it assigned to rvalue

    //int* p = &(x + y);        //Wrong as Rvalues cannot have their address taken (&) unless they are bound to a const lvalue reference (const T&) which extends their lifetime.
    //const int* p = &(x + y);  //Wrong as Even though the pointer promises not to modify the data, the fundamental issue is that the rvalue is a temporary and does not have an addressable, persistent storage location in the way an lvalue does.
    //int&& r = x + y;          //Correct as This is the specific mechanism C++ uses for rvalues. The rvalue reference binds directly to the temporary, and extends the temporary's lifetime to the scope of the reference.


    //const int&r = x ;           //Directly at x (to Non-Constant Value)
    //const int& r = x + y;       //Both Correct as a const lvalue reference is special: it can bind to an rvalue and extends its lifetime. This is why passing objects by const T& is so flexible. It binds to rvalue and lvalue both

    //A const T& can bind to both const and non-const variables (lvalues {variables or objects} ), as well as rvalues.
    //A non-const T& (T&) can only bind to non-const variables  (lvalues {variables or objects} ).


    int&& rref_mutable = 5;      // Can change: rref_mutable = 10;
    const int&& rref_immutable = 5; // Cannot change: rref_immutable = 10; // ERROR




    //Objects that are returned as reference in functions *this , are lvalues.
    //Objects that are returned as temporary object copy are rvalues.

    //So Same Rule applies to the objects as well that :
    //Non-Const object and Const Objects can both go to Const Object Parameters Ref
    //Const Object only goes to Const Object Ref Parameter not Non-Const Object Ref Parameter

    return 0;
}









//Overloads :
// 1. Lvalue Overload (Accepts named variables for addition) ,
// Called when we write :
//int x = 1;
//int y = 2;

// Calls the Lvalue Overload (add(const int&, const int&))
//add(x, y);
int add(const int& a, const int& b)
{
    std::cout << "-> Lvalue (Copy) addition called." << std::endl;
    return a + b;
}

// 2. Rvalue Overload (Accepts temporaries/rvalues for addition)
// Calls the Rvalue Overload (add(int&&, int&&)) because (x+y) and (y+1) are temporaries.
//add(x + y, y + 1);
int add(int&& a, int&& b)
{
    std::cout << "-> Rvalue (Move) addition called." << std::endl;
    // For int, the 'move' is just a copy, but the overload is distinct.
    return std::move(a) + std::move(b);
}

