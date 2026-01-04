#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string filename = "config.txt";
    ifstream file;

    try
    {
        file.open(filename);

        // Specific Check: Is the file actually open?
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
