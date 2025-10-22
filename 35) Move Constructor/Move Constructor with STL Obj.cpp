// C++ Program to illustrate the use of
// noexcept move constructor

#include <vector>
#include <iostream>
using namespace std;

//Use noexcept for faster performance
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
    Test(Test&& other) noexcept // Here it does nothing , but now compiler won't make one for you , no constructor
    {
        // Also this tells how vectors are resized or pushback using move constructors by compiler's default generated move constructor
        cout << "Move constructor  " << endl;
    }

    // Copy constructor
    Test(const Test& other)
    {
        cout << "Copy constructor  " << endl;
    }
};

int main()
{
    vector<Test> vec;

    vec.reserve(2);  // Reserve space for at least two elements

    Test a;

    vec.push_back(Test()); //Test(): A temporary, nameless Test object is created. (Rvalue) , // Here compiler knows its an rvalue and thus calls move constructor without move()
    vec.push_back(Test());

    //When vector fills its capacity completely here , 2 objects and 2 cap

    cout << "Resize happens" << endl;

    //Now for 3rd obj , it resizes but before that , it will move its old data into new one , for that
    //it Call: new_vec[0] is constructed from std::move(old_vec[0]).
    //Call: new_vec[1] is constructed from std::move(old_vec[1]).
    //Now that vector is resized it will put the obj using move constructor
    vec.push_back(Test());

    return 0;
}
