#include <iostream>
#include <string>
//Function Overloading is done on the basis of : Difference in number of arguments or type of arguments
//Same Named Functions
//Decision of Execution is decided at the Compile-Time

// 1. Overload for Integers: Calculates the sum of two integers
int add(int a, int b) 
{
    std::cout << "Using INT overload: ";
    return a + b;
}

// 2. Overload for Doubles: Calculates the sum of two doubles
double add(double a, double b) 
{
    std::cout << "Using DOUBLE overload: ";
    return a + b;
}

// 3. Overload for String: Concatenates (joins) two strings
std::string add(const std::string& a, const std::string& b) 
{
    std::cout << "Using STRING overload: ";
    return a + " " + b;
}

int main() 
{
    // Calls the INT overload (add(int, int))
    std::cout << add(5, 10) << std::endl;

    // Calls the DOUBLE overload (add(double, double))
    std::cout << add(3.5, 2.1) << std::endl;

    // Calls the STRING overload (add(std::string, std::string))
    std::cout << add("Hello", "World") << std::endl;

    return 0;
}