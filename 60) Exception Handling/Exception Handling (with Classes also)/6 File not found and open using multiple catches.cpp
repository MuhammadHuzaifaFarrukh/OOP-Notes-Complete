#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

//Checking both File not found and not open inside same try catch block using multiple catches
//For using multiple catches we need multiple types so we make the file errors as runtime and logical ones
//Inside catch block you can make all the types as exception& instead of the specific ones which will work
//But we should always write specific class type & to catch errors as it makes code readable
int main()
{
    ifstream file;
    string filename = "data.txt";

    try
    {
        file.open(filename);

        // Scenario 1: File is Exists or not?
        if (!file)
        {
            throw logic_error("Stream State Error");
        }

        // Scenario 2: File failed to open
        if (!file.is_open())
        {
            throw runtime_error("File Not Open Error");
        }
    }
    // C++ looks at these top-to-bottom:
    catch (const runtime_error& e)
    {
        cout << "Specific Runtime Catch: " << e.what() << endl;
    }
    catch (const logic_error& e)
    {
        cout << "Specific Logic Catch: " << e.what() << endl;
    }
    catch (const exception& e)
    {
        // This is the 'Parent' - it catches anything else derived from exception
        cout << "General Exception Catch: " << e.what() << endl;
    }
    catch (...)
    {
        // The ultimate safety net
        cout << "Unknown error occurred!" << endl;
    }

    return 0;
}
