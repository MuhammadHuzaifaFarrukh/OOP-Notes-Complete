// CPP Program to demonstrate the use of copy constructor
// and assignment operator
#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

//Copy Assignment Operator :
//This operator is called when an already initialized object is assigned a new value from another existing object.
//Compiler generates if user does not
//Works with Lvalue (Left Value)

//Syntax : ClassName& operator=(const ClassName& other);


class Test
{
public:
    Test() {}
    Test(const Test& t)
    {
        cout << "Copy constructor called " << endl;
    }

    Test& operator=(const Test& t)
    {
        //Use (this !=&other) condition to check first before performing anything
        cout << "Assignment operator called " << endl;
        return *this;
    }
};

// Driver code
int main()
{
    Test t1, t2;
    t2 = t1;
    Test t3 = t1;
    //t1 = t1 will make trouble for us that's why we use this!=&other to check that both objects should never be same
    getchar();
    return 0;
}







//Real copy assignment operator job :
//Compiler generated copy constructor and copy assingment operator always not manage the deep copy
//The Issue with it is the same as with the Copy Constructor
//Both objects point to the same memory locations when copied , changing one value changes the other one and at the time of deletion , double deletion occurs so undefined behaviour or program crash !
//Here first we need to deallocate the heap memory for that object's data (existing object) then allocate it new one and copy all data as we do in copy constructor

//The difference lies only in that we copy object from another existing one

/*
class MyString
{
private:
    char* data; // This is the dynamic resource

public:
    // The copy assignment operator
    MyString& operator=(const MyString& other) //Use const as the calling const and non-const objects both can use it just like copy constructor
    {
        // 1. Self-Assignment Check**
        if (this != &other)
        {

            // 2. **Clean Up Current Resources (What to Delete)**
            //    We only delete the MEMORY pointed to by 'data', not the 'MyString' object being copied from.
            delete[] data;

            // 3. **Allocate and Copy (Deep Copy)**
            //    Allocate new memory for the destination object
            data = new char[strlen(other.data) + 1]; //+1 done for '\0' character only

            //    Copy the contents from the source object
            strcpy(data, other.data);
        }

        // 4. **Return Reference to Current Object**
        // 4. **Return Reference to Current Object**
        return *this;
    }

    // ... constructors, destructor, etc.
};
*/



//Copy Assignment also allows us to do the chaining (assignment of multiple objects in same line)
// Like a = b = c  , then first b = c is solved and then a = (b = c)

