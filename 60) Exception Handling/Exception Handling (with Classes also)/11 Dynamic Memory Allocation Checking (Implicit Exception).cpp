#include <iostream>
#include <stdexcept> // Standard exceptions
#include <new>      // Required specifically for std::bad_alloc

using namespace std;

//We use bad_alloc when we try to check our heap memory allocation enough on RAM or not
//So we can check that implicitly as well , no need to throw as Operating System does that internally

int main()
{
    try
    {
        cout << "Attempting to allocate a massive amount of memory..." << endl;

        // Attempting to allocate an array of 1 billion quadrillion integers
        // This is roughly 4,000 Petabytes of RAM.
        // Most computers will fail this immediately.
        long long size = 1000000000000000;
        int* myHugeArray = new int[size];

        // This line will never be reached if 'new' fails
        cout << "Success! (Wait, how much RAM do you have??)" << endl;
        delete[] myHugeArray;
    }
    catch (bad_alloc& e)    //or exception& e also works as these are in polymorphism
    {
        // e.what() will usually return "std::bad_alloc"
        cout << "Caught Exception: " << e.what() << endl;
        cout << "Reason: The system could not find a block of memory that large." << endl;
    }

    cout << "Program continues safely after handling the memory error." << endl;

    return 0;
}
