// C++ Program to illustrate the use of
// noexcept move constructor

#include <vector>
#include <iostream>
using namespace std;

// Use noexcept for faster performance
/*
Why use noexcept?
It helps the compiler optimize our code, especially with STL containers like std::vector.
If a move constructor is not marked noexcept, some STL operations will fall back to slower copy
operations to avoid potential exceptions.
*/

class Test
{
public:
    Test() {}

    // Move constructor marked as noexcept
    Test(Test &&other) noexcept // Here it does nothing , but now compiler won't make one for you , no constructor
    {
        // Also this tells how vectors are resized or pushback using move constructors by compiler's default generated move constructor
        cout << "Move constructor  " << endl;
    }

    // Copy constructor
    Test(const Test &other)
    {
        cout << "Copy constructor  " << endl;
    }
};

int main()
{
    vector<Test> vec;

    vec.reserve(2); // Reserve space for at least two elements

    Test a;

    vec.push_back(Test()); // Test(): A temporary, nameless Test object is created. (Rvalue) , // Here compiler knows its an rvalue and thus calls move constructor without move()
    vec.push_back(Test());

    // When vector fills its capacity completely here , 2 objects and 2 cap

    cout << "Resize happens" << endl;

    // Now for 3rd obj , it resizes but before that , it will move its old data into new one , for that
    // it Call: new_vec[0] is constructed from std::move(old_vec[0]).
    // Call: new_vec[1] is constructed from std::move(old_vec[1]).
    // Now that vector is resized it will put the obj using move constructor
    vec.push_back(Test());

    // Very Important things regarding vector<T> and move
    /*
    If we use a vector<int> and keep using push_back(), it will reallocate and copy but usually it takes O(1) time.
    However if we use 2D vector and push a 1D vector in it , or if we push a string of length 'L' inside a vector<string> then it takes O(L) or the size of 1D Vector.
    This happens because now it tries to use copy which takes characters/numbers one by one increasing time.
    We can reduce this using move() by writing : ans.push_back(move(x)) where x can be a string for 1D vector or ith row or a 1D vector.
    Once this happens , 'x' may no longer be accessible.

    Still even if we don't use move(), we generally consider that push_back() operation takes O(1) time on average for our ease regardless of being 2D vector or vector of strings etc.

    */
    return 0;
}
