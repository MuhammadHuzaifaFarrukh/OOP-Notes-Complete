#include <iostream>
#include <string>

using namespace std;

//Report Uses / Knows Printer

class Printer
{
public:
    void printHeader()
    {
        cout << "--- Report ---" << endl;
    }
};

class Report
{
public:
    void generate()
    {
        // LOCAL ASSOCIATION (Dependency)
        // This is not composition because 'p' is not a member of Report.
        Printer p;      //Stack-Based Allocation , object is only accessible in this function
        p.printHeader();
    } // 'p' is destroyed here, while the Report object lives on.
};

int main()
{
    Report r1;
    r1.generate();
    return 0;
}
