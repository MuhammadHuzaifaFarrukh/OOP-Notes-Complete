#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Writing to file using cout's behavior
    ofstream outfile("output.txt");

    // Save cout's buffer
    streambuf* cout_buffer = cout.rdbuf();

    // Redirect cout to file
    cout.rdbuf(outfile.rdbuf());

    // Now cout writes to file instead of screen
    cout << "Hello File!" << endl;
    cout << "This goes to output.txt" << endl;
    int x = 42;
    cout << "Value: " << x << endl;

    // Restore cout to screen
    cout.rdbuf(cout_buffer);
    cout << "Back to screen" << endl;

    outfile.close();

    // Reading from file using cin's behavior
    ifstream infile("output.txt");

    // Save cin's buffer
    streambuf* cin_buffer = cin.rdbuf();

    // Redirect cin to file
    cin.rdbuf(infile.rdbuf());

    // Now cin reads from file instead of keyboard
    string line;
    cout << "Reading from file using cin behavior:" << endl;
    while (getline(cin, line))
    {
        cout << "Read: " << line << endl;
    }

    // Restore cin to keyboard
    cin.rdbuf(cin_buffer);

    infile.close();

    return 0;
}
