#include <iostream>

using namespace std;

int main()
{
    // const_cast<data_type>(address ) tells compiler to stop treating the addressed value as a constant and let me modify it
    // A const pointer can point to a const / non-const data but vice versa is not true
    //Changing *p here will change the value at address of the 'a' .

    const int a =10;
    int *p;
    p = const_cast<int *>(&a);  //Equivalent to p = (int *)(&a);
    *p = 20;
    cout<<a<<endl;      //This just replaces the 'a' with literal old value 10
    cout<<*p<<endl;     //This shows the actual changes
    //To get new value of 'a' using a , use const volatile int a = 10;


    // Works totally fine if the variable it is used on is a non-constant
    int x = 100;               // x is stored in Writable memory (non-const)
    const int* p1 = &x;       // We give ourselves a Read-Only view of x
    int* mod = const_cast<int*>(p1); // We remove the label
    //p1=300;   //Error
    //*mod = 200;               // SUCCESS: Memory was always writable.
    cout<<*mod<<endl;
    cout<<x<<endl;
    cout<<*p1<<endl;


    //The Variable is constant , like in our first case but without volatile
    const int x1 = 250;         // x is stored in Read-Only memory (or optimized away)
    const int* p2 = &x1;
    int* mods = const_cast<int*>(p2);
    *mods = 360;               // DANGER: Undefined Behavior.
    cout<<*mods<<endl;
    cout<<x1<<endl;
    cout<<*p2<<endl;

    //This Cast is safe only if the original object/variable is non-const
    //Doesn't even throw error if the original object/variable is constant so we should be careful ourselves
    //Also constant object means that we cannot reinitialize the data members of it by any means once we have done

    return 0;
}
