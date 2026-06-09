#include <iostream>
#include <vector>
#include <string>
#include <string_view>
using namespace std;

class Simple
{
    string x;

public:
    // Simple() {}  // This is required if we mention neither constexpr nor the inline keyword while declaring value<Simple>
    Simple(string x) : x(x) {}
    // If we want to use constexpr then write :
    // constexpr Simple(const char *data) : x(data){} where x is also a const char *.
    string getX() const { return x; }
};

/*
In C++, a variable template allows you to define a variable that depends on a template parameter.
Just as a function template allows you to create a function that works for any type, a variable template allows you to create a constant (or variable) that adapts its type or value based on the template argument provided.
*/

// Syntax (Define) ,  (constexpr is not necessary):
template <typename T>
constexpr T num = T(65.1415926535897932385);
// T before 'num' tells its data type (int,float,char,double etc) and T after it is the constructor.
// If we don't write the T of constructor , then
// But we place this 'T' constructor because to avoid compiler warnings and also if for some reason compiler doesn't know how to convert this data into type T (like when we write num<string>).

// The Benefit of using this is that we don't have to make 3 separate variables , we can just work with 1 variable of multiple types.

/*
With constexpr (or inline): The compiler treats the variable as implicitly inline.
This tells the linker: "If you see multiple definitions of this variable, just pick one and discard the others."
This allows you to safely use the variable across multiple .cpp files.
// Also if we try to write : int array[int(num<double>)] , then it gives errors without constexpr because its not a const.
// Using 'inline' still doesn't make it constant but will work for the multiple .cpp files.

*/

// We can also do specialization :
// This allows that we have maintained a specific variable for such values.
// 1. The General Template (The "General Rule")
template <typename T>
constexpr T value = T(0);

// 2. The Specialization (The "Exception")
template <>
constexpr int value<int> = 100; // If someone asks for value<int>, give them 100

// 3. The Specialization for another type
template <>
constexpr char value<char> = 'A'; // If someone asks for value<char>, give them 'A'

// 4. For Strings , use <string_view> Library
template <>
constexpr string_view value<string_view> = "Hello";

// 5. User Defined Classes : (We can use either inline)
template <>
inline Simple value<Simple> = Simple("100000");
// If you still want to use constexpr here , then put const char *x instead of string x and mark the constructor as constexpr.

// These are just templates so they don't take any space now.
// Once we start using them in main() , then they take space.
int main()
{
    // Use it :
    cout << num<int> << endl;
    cout << num<char> << endl;
    cout << num<float> << endl;
    cout << num<double> << endl;
    // You can change their values if they are not constexpr
    // value<int> = 1001;
    // value<double> = 2000;

    // Unlike function templates (which are executable code) or class templates (which define a structure), variable templates hold data.

    // num<string> = "Hello";  // We cannot use <string> , we need to use <string_view> and Specialization also for this.
    // Using specialization :
    // This uses the general template (T=0)

    cout << "General (double): " << value<double> << endl;

    // This uses the specialized 'int' version (value=100)
    cout << "Specialized (int): " << value<int> << endl;

    // This uses the specialized 'char' version (value='A')
    cout << "Specialized (char): " << value<char> << endl;

    cout << "Specialized (string): " << value<string_view> << endl;

    Simple s = value<Simple>;
    cout << "Specialized Simple Class (string): " << s.getX() << endl;

    // THese template variables can also be used inside the template functions also being very efficient (like a wrapping function or class).
    return 0;
}
