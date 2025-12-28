#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // 1. Heap Allocate an std::ofstream object
    // We create a pointer to an ofstream object on the heap.
    ofstream* outfilePtr = new ofstream("heap_data.txt");

    cout << "Writing to heap_data.txt using pointer..." << endl;

    // Write data using the arrow operator (->)
    if (outfilePtr->is_open())
    {
        *outfilePtr << "Data written using a heap-allocated ofstream." << endl;
        *outfilePtr << "The number is: " << 42 << endl;
    }
    else
    {
        cerr << "Error: Could not open file for writing." << endl;
    }

    // 2. Close and deallocate the ofstream object
    outfilePtr->close();
    delete outfilePtr; // CRITICAL: Free the memory allocated with 'new'
    outfilePtr = nullptr; // Good practice to set the pointer to null

    cout << "Finished writing. Reading back data..." << endl;

    // 3. Heap Allocate an std::ifstream object
    // We create a pointer to an ifstream object on the heap.
    ifstream* infilePtr = new ifstream("heap_data.txt");

    string line;

    // Read data using the arrow operator (->)
    if (infilePtr->is_open())
    {
        cout << "Contents of file:" << endl;
        // Read line by line until end-of-file
        while (getline(*infilePtr, line))
        {
            cout << ">> " << line << endl;
        }
    }
    else
    {
        cerr << "Error: Could not open file for reading." << endl;
    }

    // 4. Close and deallocate the ifstream object
    infilePtr->close();
    delete infilePtr; // CRITICAL: Free the memory allocated with 'new'
    infilePtr = nullptr;

    return 0;
}

/*
In both cases—whether the stream is allocated on the stack or on the heap—when it successfully
reads or writes data to a file if done in a separate function, the stream's internal position indicator is changed.
*/

