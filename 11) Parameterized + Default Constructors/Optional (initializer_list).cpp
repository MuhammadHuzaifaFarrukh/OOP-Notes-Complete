#include <iostream>
#include <vector>
#include <initializer_list> //Used for initializer list

using namespace std;

/*
--- INITIALIZER LISTS AND BRACE INITIALIZATION ---

1) The Purpose of std::initializer_list<T>:
   It is a special type that allows a function or constructor to accept
   a list of values enclosed in curly braces {}. Unlike a regular
   parameterized constructor, it doesn't have a fixed number of arguments.

2) Single Value vs. Multiple Values (The "Constructor Trap"):
   The behavior changes significantly depending on whether you use () or {}.
*/

class MyVector
{
    int size;
    int* data;  //You can skip this if you don't know about dynamic initialization and see after lecture (30)
public:
    // Standard Parameterized Constructor
    MyVector(int s, int val = 0) : size(s)
    {
        data = new int[size];
        for(int i=0; i<size; i++) data[i] = val;
        cout << "Called (int, int) Constructor. Size: " << size << endl;
    }

    // Initializer List Constructor
    MyVector(initializer_list<int> list) : size(list.size())
    {
        data = new int[size];
        int i = 0;
        for (auto x : list)
        {
            data[i++] = x;
        }
        cout << "Called initializer_list Constructor. Elements: " << size << endl;
    }

    ~MyVector()
    {
        delete[] data;
    }
};

int main()
{
    // CASE A: Single value in braces
    // Even with one value, if an initializer_list constructor exists, it is preferred.
    MyVector v1 = {5};
    // Result: A vector containing one element: [5].
    // Without initializer_list: This would have called MyVector(5, 0) -> Size 5.

    // CASE B: Multiple values in braces
    MyVector v2 = {1, 2, 3, 4, 5};
    // Result: A vector containing [1, 2, 3, 4, 5].
    // Without initializer_list: This would be a COMPILER ERROR (no constructor takes 5 ints).

    // CASE C: Using parentheses () instead of braces {}
    MyVector v3(5, 10);
    // Result: Explicitly calls the (int, int) constructor.
    // Creates a vector of Size 5 filled with 10s.

    /*
    KEY TAKEAWAYS FOR YOUR NOTES:
    - {1, 2, 3}: Always looks for std::initializer_list first.
    - {10}: If initializer_list exists, it creates a list of 1 element (value 10).
    - (10): Always ignores initializer_list; looks for a constructor with one integer parameter (Size 10).
    - Aggregate Initialization (your previous notes) only works if NO constructors are defined.
      Once you define MyVector(initializer_list), that constructor "takes over" the {} syntax.
    */

    return 0;
}
