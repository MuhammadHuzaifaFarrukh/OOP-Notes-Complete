#include <iostream>
#include <stdexcept>

using namespace std;

//Double Deletion causes runtime errors
//We can only catch this double deletion error if we do ourselves explicitly
//So we will make a function and call it two times to check if our pointer is nullptr or not
//We can't catch the double deletion error that happens when we allocate on heap and then don't use custom copy constructor/assignment operator 
//to solve it in classes as that happens during destructor call which invokes by itself (not in our control)

void safeDelete(int* ptr)
{
    if (ptr == nullptr)
    {
        throw runtime_error("Double Deletion Attempted! Pointer is already null.");
    }
    delete ptr;
    ptr = nullptr; // Crucial: Set to null so we know it's gone
    cout << "Memory deleted successfully." << endl;
}

int main()
{
    int* data = new int(100);

    try
    {
        cout << "First deletion:" << endl;
        safeDelete(data);

        cout << "\nSecond deletion (this would normally crash):" << endl;
        safeDelete(data);
    }
    catch (exception& e)
    {
        cout << "Caught: " << e.what() << endl;
    }

    return 0;
}
