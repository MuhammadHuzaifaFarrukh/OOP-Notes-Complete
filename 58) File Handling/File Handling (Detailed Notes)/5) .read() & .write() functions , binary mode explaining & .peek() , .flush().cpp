#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    //The .read() and .write() functions are used to read / write the raw data into files
    //We generally use these in binary files where we manage memory
    // .write( (char *) identifier , number_of_bytes) and .write( (char *) identifier , number_of_bytes)
    //The first argument in .write() is a const char* pointer that points to the start of the data you want to write.
    //The first argument in .read() is a char* pointer that points to the memory location where you want the read data to be stored
    //The 2nd argument in both is streamsize which is an int or you can say the no of bytes


    //The below program shows how to use .read and .write functions to write some values
    //Data inside file might not what we expect to be , as it might be encrypted form

    //Bin Mode is generally used to preserve data integrity , manage memory , and best for objects , images , audios  and raw data files
    //No character translations like "\n->\r\n" occur which takes upto 2 bytes normally but 1 byte in bin mode
    //123456 in normal files takes 6 bytes but 4 bytes only for bin mode
    //You can either use .bin or .dat extensions , as C++ File handling treats these both different extensions , the same


    //We've used an array of int below
    //We can also use char array below or string



    // Data to write
    /*
    int numbers_to_write[] = {10, 20, 30, 40, 50};
    int array_size = sizeof(numbers_to_write);

    // --- Writing to a file ---
    std::ofstream outFile("numbers.dat", std::ios::out | std::ios::binary);
    if (outFile.is_open())
    {
        // Write the entire array as a block of raw bytes
        outFile.write((char *)(numbers_to_write), array_size);

        outFile.close();
        std::cout << "Data written successfully.\n";
    }



    // --- Reading from the file ---
    int numbers_read[5]; // Array to store the read data
    std::ifstream inFile("numbers.bin", std::ios::in | std::ios::binary);
    if (inFile.is_open())
    {
        // Read the exact number of bytes back into the new array
        inFile.read((char *)(numbers_read), array_size);

        inFile.close();
        std::cout << "Data read successfully.\n";
    }

    // Display the read data
    std::cout << "Numbers read from file: ";
    for (int i = 0; i < 5; ++i)
    {
        std::cout << numbers_read[i] << " ";
    }
    std::cout << std::endl;
    */







    //Below program is the one that shows how to write text from char array into file and read that text again from that file

    // A char array to write to the file.
    // Ensure the array is large enough for the string plus the null terminator.
    /*
    char wordToWrite[] = "BINARY";

    // --- Writing to a binary file ---
    std::ofstream outFile("data.bin", std::ios::binary);
    if (outFile.is_open())
    {
        // Use .write() with the char array and its length (excluding the null terminator)
        outFile.write(wordToWrite, strlen(wordToWrite));
        outFile.close();
        std::cout << "Successfully wrote '" << wordToWrite << "' to data.bin\n";
    }
    else
    {
        std::cerr << "Error: Could not open file for writing.\n";
        return 1;
    }

    // --- Reading from the binary file ---
    // A char array to store the read data. Must be large enough.
    char wordRead[20];
    // Set all bytes to 0 to ensure proper null-termination after reading
    memset(wordRead, 0, sizeof(wordRead)); //Initializes all places to '\0'

    // Open the file in binary mode for reading
    std::ifstream inFile("data.bin", std::ios::binary);
    if (inFile.is_open())
    {
        // Read the bytes into the array
        inFile.read(wordRead, sizeof(wordRead));
        inFile.close();

        std::cout << "Successfully read '" << wordRead << "' from data.bin\n";
    }
    else
    {
        std::cerr << "Error: Could not open file for reading.\n";
        return 1;
    }
    */








    //String used this time instead of char array :
    //While using string to write data , we use string_object.data() that converts it into char* as .write() only accepts char *
    //Also in .read() for string , we use & with string_obj_name , as it requires address from where to start like char *
    //We can use any one either & or .data() in both functions
    //No need to typecast the string , but for other data types its necessary

    /*
    std::streamsize is a signed integer type used for representing the size of a stream or the number of characters transferred in a stream operation.
    It's a more portable and robust alternative to simple types like int or long because its size is guaranteed to be large enough to hold the maximum number of bytes that can be transferred in a single stream operation, regardless of the system or compiler. You'll see it used as the second argument in functions like std::istream::read() and std::ostream::write(), where it specifies the number of characters or bytes to read or write.
    */


    /*
    // A string to write to the file
    std::string wordToWrite = "BINARY";

    // --- Writing to a binary file ---
    std::ofstream outFile("data.bin", std::ios::binary);
    if (outFile.is_open())
    {
        // Use .write() to put the raw bytes of the string into the file
        outFile.write(wordToWrite.data(), wordToWrite.length());
        outFile.close();
        std::cout << "Successfully wrote '" << wordToWrite << "' to data.bin\n";
    }
    else
    {
        std::cerr << "Error: Could not open file for writing.\n";
        return 1;
    }

    // --- Reading from the binary file ---
    // A string to store the read data
    std::string wordRead;

    // Open the file in binary mode and at the end to get its size
    std::ifstream inFile("data.bin", std::ios::binary | std::ios::ate);
    if (inFile.is_open())
    {

        // Get the size of the file
        std::streamsize fileSize = inFile.tellg();
        // Move back to the beginning of the file
        inFile.seekg(0, std::ios::beg);

        // Resize the string to hold all the data
        wordRead.resize(fileSize);

        // Read all the bytes from the file into the string
        inFile.read(&wordRead[0], fileSize);
        inFile.close();

        std::cout << "Successfully read '" << wordRead << "' from data.bin\n";
    }
    else
    {
        std::cerr << "Error: Could not open file for reading.\n";
        return 1;
    }
    */






    //To read a file whose contents are of mixed data type :
    //Use a vector of type char for this purpose

    /*
    std::string filename = "unknown_file.bin";

    // Open the file in binary mode and at the end of the file
    std::ifstream inFile(filename, std::ios::in | std::ios::binary | std::ios::ate);

    if (!inFile.is_open())
    {
        std::cerr << "Error: Could not open " << filename << std::endl;
        return 1;
    }

    // Get the file size
    std::streamsize fileSize = inFile.tellg();
    inFile.seekg(0, std::ios::beg);

    // Create a vector to hold the file contents
    std::vector<char> buffer(fileSize);

    // Read the entire file into the buffer
    if (!inFile.read(buffer.data(), fileSize))
    {
        std::cerr << "Error: Failed to read file." << std::endl;
        return 1;
    }

    inFile.close();

    std::cout << "File read successfully. Size: " << fileSize << " bytes." << std::endl;

    // You now have the file contents in the 'buffer' vector.
    // From here, you would have to write custom logic to interpret the bytes.
    // For example, you could print the first 10 bytes in hexadecimal.
    std::cout << "First 10 bytes (in hex): ";
    for (int i = 0; i < 10 && i < buffer.size(); ++i)
    {
        std::cout << std::hex << (int)(unsigned char)buffer[i] << " ";
    }
    std::cout << std::endl;
    */



    //The Failbit of file can also be true if .read() tries to read int from file but in code , we are reading by char var or array or the opposite
    //In this case we again need to use .clear() function









    //Also helpful to write or read from objects or userdefined data types like structs , classes etc:
    //Again like string we use , & sign with object of struct and also type cast as well because its not a string , in case of string we only .data() or & sign , anyone can be used
    //But here we need to typecast and use & signwith struct object like any other data type


    //We are writing a struct object contents in our file

    /*
    struct Person
    {
        int id;
        char name[20];
    };

    int main()
    {
        Person p = {101, "Alice"};

        // Open the file in binary mode for writing
        std::ofstream outFile("data.bin", std::ios::out | std::ios::binary);

        // Check if the file opened successfully
        if (outFile.is_open())
        {
            // Write the Person struct as a raw block of bytes
            outFile.write(reinterpret_cast<const char*>(&p), sizeof(Person));
            outFile.close();
            std::cout << "Data written to data.bin successfully." << std::endl;
        }
        else
        {
            std::cerr << "Error opening file for writing." << std::endl;
        }
        return 0;
    }
    */


    //We are reading struct contents from our file
    //Didn't write int main or struct as it was already done in previous example above

    /*
    Person p_read;

    // Open the file in binary mode for reading
    std::ifstream inFile("data.bin", std::ios::in | std::ios::binary);

    // Check if the file opened successfully
    if (inFile.is_open())
    {
        // Read the block of bytes into the p_read struct
        inFile.read(reinterpret_cast<char*>(&p_read), sizeof(Person));
        inFile.close();

        std::cout << "Data read from data.bin:" << std::endl;
        std::cout << "ID: " << p_read.id << std::endl;
        std::cout << "Name: " << p_read.name << std::endl;
    }
    else
    {
        std::cerr << "Error opening file for reading." << std::endl;
    }
    */










    //Using .peek() function allows to see the next character without moving the internal pointer of the file
    /*
    std::ifstream inFile("data.txt");
    char c;
    std::string s;

    while (inFile.get(c))
    {
        s += c;
        if (inFile.peek() == '\n')
        {
            std::cout << "The next character is a newline. Current string: " << s << std::endl;
        }
    }
    */



    //Using .flush() function allows us to write the contents in the file as soon as we get the input without closing the file
    //Very useful if we want to read the data as soon as we write without closing

    /*
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    char ch;

    // Read until end of file and flush after each write
    while (!in.eof())
    {
        in.get(ch);
        if (!in.eof())
        {
            out.put(ch);
            out.flush();  // Force write after each character
        }
    }

    in.close();
    out.close();
    */

    //We can also use an array to keep storing the data being read and then flush it in the file instead of using a variable


    return 0;
}
