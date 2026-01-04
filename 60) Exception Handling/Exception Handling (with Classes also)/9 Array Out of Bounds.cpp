#include <iostream>

using namespace std;

//Arrays don't throw any exception on index out of bounds
//So we will have to manually check for the index by user input

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int size = 5;
    int index;

    cout << "Enter index to access: ";
    cin >> index;

    try
    {
        // MANUAL GUARD: Raw arrays don't check this, so we must.
        if (index < 0)
        {
            throw out_of_range("Invalid Index: Negative indices are not allowed!");
        }
        if (index >= size)
        {
            throw out_of_range("Out of Index: You tried to reach past the array end!");
        }

        // If we pass the checks, it's safe to access
        cout << "Value at index " << index << " is " << arr[index] << endl;
    }
    catch (const out_of_range& e)
    {
        // e.what() will show the specific message we threw above
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
