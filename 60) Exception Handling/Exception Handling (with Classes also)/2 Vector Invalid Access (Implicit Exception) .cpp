#include <iostream>
#include <vector>
using namespace std;

//Now we learn how to throw exceptions to exception objects
//We know that there is a class of exception inside std::exception
//All the other classes like : runtime_error , logic_error then inherit this exception class

//Try to Catch Exceptions by Reference , not by value as it breaks the polymorphism and does object slicing which will not be beneficial
//We throw the child class object i.e runtime_error or any other objects and these are passed to the catch block
//Inside catch block , we have the exception & object that will provide set up for runtime polymorphism
//As we call e.what() function , due to runtime polymorphism , this e.what() is executed from the Child class instead of exception class

//Each class object that we pass , has a constructor , to whom we can pass our message of const char* type or a string
// .what() function has prototype : const char* what() const noexcept{...}
//This function returns a character pointer that will print the whole message till it encounters '\0' character

int main()
{
    try
    {
        vector<int> v = {1, 2, 3};
        int value = v.at(10); // Throws std::out_of_range implicitly (defined already inside the .at() function code)
    }
    catch (const std::out_of_range& e)
    {
        cout << "Array Error: " << e.what() << endl;
    }
    return 0;
}
