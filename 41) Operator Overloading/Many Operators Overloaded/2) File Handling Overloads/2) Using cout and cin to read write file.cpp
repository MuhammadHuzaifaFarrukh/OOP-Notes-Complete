#include <iostream>
#include <fstream>
using namespace std;

// Polymorphism is involved, and happens primarily at the std::streambuf level when
// the stream object uses its connection to perform the actual character transfer. It happens at initialization of streams with rdbuf()
// The ability of the std::ostream constructor to accept the pointer returned by std::ofstream.rdbuf() relies on inclusion polymorphism
// The ability of the constructor to accept any derived buffer pointer is a form of Polymorphism (Runtime)

// More Specifically : The ability of a stream object (like std::cout or std::ofstream) to dynamically accept and use any derived stream buffer pointer (std::streambuf*) is the mechanism of Runtime Polymorphism that allows I/O redirection.
// E.g : if we use cout to redirect its buffer to ofstream's buffer , then the streambuf* of cout is pointing to derived now instead of base class ( totally fine !)

int main()
{
    // Writing to file using cout's behavior
    ofstream outfile("output.txt");

    // Save cout's buffer
    streambuf* cout_buffer = cout.rdbuf();

    // Redirect cout to file
    cout.rdbuf(outfile.rdbuf());    //Runtime Polymorphism setup

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
    cin.rdbuf(infile.rdbuf());      //Runtime Polymorphism setup

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
