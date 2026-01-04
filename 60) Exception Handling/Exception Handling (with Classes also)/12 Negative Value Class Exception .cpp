#include <iostream>
#include <exception>
using namespace std;

// Custom exception class
class NegativeValueException : public exception
{
private:
    int value;
public:
    // Constructor
    NegativeValueException(int val) : value(val) {}

    // Override what() method
    const char* what() const noexcept override
    {
        return "Negative value error occurred!"; ////Object-Based Throwing

    }

    // Optional: method to get the invalid value
    int getValue() const
    {
        return value;
    }
};

// Function that throws the custom exception
void checkValue(int x)
{
    if (x < 0)
    {
        throw NegativeValueException(x);
    }
    else
    {
        cout << "Value is: " << x << endl;
    }
}

int main()
{
    int numbers[] = {10, -5, 20};

    for (int n : numbers)
    {
        try
        {
            checkValue(n);
        }
        catch (NegativeValueException &e) //Catch by Reference , Object-Based Catching , better to use const here
        {
            cout << "Exception caught: " << e.what()
                 << " Value = " << e.getValue() << endl;
        }
    }

    return 0;
}
