#include <iostream>
#include <fstream>
#include <stdexcept> // Required for runtime_error

using namespace std;

//Checking both File not found and not open inside same try catch block but using only one catch

int main()
{
    string filename = "config.txt";
    ifstream file;

    try
    {
        //File Exists ?
        if (!file)
        {
            throw runtime_error("STREAM ERROR: File Doesn't Exist");
        }

        file.open(filename);

        // File Opened?
        if (!file.is_open())
        {
            throw runtime_error("CRITICAL: Could not open " + filename);
        }

        cout << "File opened successfully! Reading data..." << endl;
        // ... perform file operations ...

    }
    catch (const exception& e)
    {
        // This catches the runtime_error we threw above
        // Polymorphism ensures e.what() shows the correct message
        cout << "Caught Exception: " << e.what() << endl;
    }

    return 0;
}
