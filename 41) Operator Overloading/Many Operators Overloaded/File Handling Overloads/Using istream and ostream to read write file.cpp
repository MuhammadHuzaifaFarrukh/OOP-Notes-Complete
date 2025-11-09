#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Polymorphism is involved, but not in the most obvious way. It happens primarily at the std::streambuf level when
// the stream object uses its connection to perform the actual character transfer. It happens at initialization of streams with rdbuf()
// The ability of the std::ostream constructor to accept the pointer returned by std::ofstream.rdbuf() relies on inclusion polymorphism
// The ability of the constructor to accept any derived buffer pointer is a form of Polymorphism


int main()
{
    std::string filename = "generic_io_test.txt";

    // --- 1. SETUP FOR WRITING (Output) ---
    // a. Create a specialized file output stream (which has the necessary file buffer)
    std::ofstream file_out(filename);

    // b. Create a generic ostream object and connect it to the file_out's buffer
    std::ostream os(file_out.rdbuf());

    // --- WRITE TO FILE using the generic ostream 'os' ---
    os << "Hello from a generic ostream object!" << std::endl;
    os << 12345 << " is a number." << std::endl;

    // Close the file output stream to ensure data is written to disk
    file_out.close();


    // --- 2. SETUP FOR READING (Input) ---
    // a. Create a specialized file input stream
    std::ifstream file_in(filename);
    std::string text_read;
    int number_read;

    // b. Create a generic istream object and connect it to the file_in's buffer
    std::istream is(file_in.rdbuf());

    // Check if the file was opened successfully
    if (file_in.is_open())
    {
        std::cout << "--- Reading File via Generic istream ---" << std::endl;

        // --- READ FROM FILE using the generic istream 'is' ---

        // Read the first word and the integer
        is >> text_read >> number_read;

        std::cout << "First word read: " << text_read << std::endl;
        std::cout << "Number read: " << number_read << std::endl;

        // The rest of the stream can be read line by line
        std::getline(is, text_read);
        std::cout << "Rest of the first line: " << text_read << std::endl;

    }
    else
    {
        std::cerr << "Error: Could not open file for reading." << std::endl;
    }

    file_in.close();

    return 0;
}
