#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    //File state can also result into go bad state if eof is reached and it still attempts to read char or if no delimiter is found after eof , or if the file is empty not even eof , or if the file is not created
    /*
    std::ifstream file("mydata.txt");
    std::string line;

    while (std::getline(file, line))
    {
        // Process the line
    }

    if (file.eof())
    {
        std::cout << "Reached end of file." << std::endl;
    }

    if (file.fail())
    {
        std::cerr << "Reading failed due to an error." << std::endl;
    }
    //Use file.clear() ; to clean the state of file


    file.close();
    */

    //.tellg () is used to know about the current position of write pointer (ofstream / fstream)
    //.tellp () is used to know about the current position of read pointer (ifstream / fstream)
    //Also use streampos type for storing these positions


    //.seekp () number of bytes , mode like ios::end , ios::beg , ios::cur ) is used to write at a specific point in a file using its own parameters
    //.seekp () number of bytes , mode like ios::end , ios::beg , ios::cur ) is used to read at a specific point in a file using its own parameters
    //ios::end moves the file pointer to the end of the file (Use negative value in no of bytes and in range of the file otherwise failbit is true and you need to use file.clear)
    //ios::beg moves the file pointer to the beg of the file (Use positive value in no of bytes and in range of the file otherwise failbit is true and you need to use file.clear)
    //ios::cur is used to read/write using file pointer at the current place


    //If you move your any one file pointer of read or write , the other one automatically moves at the same point for fstream object e.g if read pointer is at 13 bytes then so is write pointer
    //You may use .tellg() and .tellp() for this purpose

    //We can use these functions of .tellp , .tellg , .seekp , .seekg in text files as well but usually we don't


    //For an existing file with some text written , ios::app doesn't change the file pointer but ios::ate does as this moves the file pointer to the end
    std::fstream file("test.txt", std::ios::out | std::ios::in | std::ios::trunc);
    if (!file.is_open())
    {
        std::cout << "Error opening file!" << std::endl;
        return 1;
    }

    std::string sentence = "Hello, world!";
    file << sentence; // Write the string to the file

    // Use tellp() to get the current write pointer position
    std::streampos pos = file.tellp();
    std::cout << "Current write pointer position: " << pos << std::endl; // Output: 13

    // Now, let's read the file from the start
    file.seekg(0, std::ios::beg);

    // Use tellg() to get the current read pointer position
    std::streampos readPos = file.tellg();
    std::cout << "Current read pointer position: " << readPos << std::endl; // Output: 0

    std::string readData;
    file >> readData;
    std::cout << "Read data: " << readData << std::endl;

    file.close();



    //If you are using dynamically allocated char arrays to use in getline / read /write functions then don't use sizeof(ptr) as this one is pointer size , use sizeof(buffer_size)
    //Or use this instead of sizeof(ptr) : int buffer_size = strlen(ptr) , this will avoid printing garbage values
    //strlen(ptr) will only give size without \0 so null terminator is missed
    //Similar case with string.length() as it gives size without \0

    //sizeof(ptr) where ptr is not dynamic array , here it will write the number of bytes total in ptr with \0 terminator if it was in the original array

    //If not then you can simply use sizeof(ptr)
    //Binary files can also get failed if we use .read() for empty files so use file.clear()


    //For binary files , the delimiter should not be an issue as binary files are read/written on raw data so we can use 100 bytes to read/write char array even if we don't use total bytes , telling 100 bytes in size will handle our work (in normal char arrays )
    //Even if dynamic arrays we can use strlen(ptr) in buffer size and miss \0 as we don't need it bcz we're reading/writing raw data on it

    return 0;
}
