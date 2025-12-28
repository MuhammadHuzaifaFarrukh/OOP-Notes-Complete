#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    //stream.put(char) is used to write a single character to an output file stream. It takes one character argument and inserts it into the stream.

    /*
    std::ofstream outFile("file.txt");
    if (outFile.is_open())
    {
        outFile.put('H');
        outFile.put('e');
        outFile.put('l');
        outFile.put('l');
        outFile.put('o');
        outFile.close();
    }
    */



    //stream.get() is used to read a single character from an input file stream. It reads the next character from the stream and returns it.


    /*
    std::ifstream inFile("file.txt");
    if (inFile.is_open())
    {
        //cout<<"File opened successfully "<<endl;

        char ch;
        while (inFile.get(ch))   // This version of get returns the stream object, which can be checked for validity
        {
            std::cout << ch;
        }
        if(inFile.fail())
        {cout<<"FAILURE"<<endl;}
        inFile.close();
    }
    */


    //Instead of using .get above we can also use the loop like :
    /*
    while(inFile >> ch)
    {
        std::cout<<ch;
    }
    */
    //But this would not be a good idea as it can cause fail bit to be true which we will discuss after another example



    //If we want to take numbers + characters as input then we can use >> with number variable and then >> with string or char variable
    //Now this (>>) is good for input for taking input from a file for different data types as well
    /*
    std::ifstream inFile("data.txt");
    if (!inFile.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    int myInt;
    float myFloat;
    std::string myString;

    // The stream extraction operator intelligently reads each data type
    inFile >> myInt;
    inFile >> myFloat;
    inFile >> myString;

    std::cout << "Integer: " << myInt << std::endl;
    std::cout << "Float: " << myFloat << std::endl;
    std::cout << "String: " << myString << std::endl;

    inFile.close();
    */



    //When we use while(file.get(ch)) , this reads until eof() is reached and is used for all data types
    //When we use while(file >> n) where n can be any data type then it will cause error those data types which are not relevant to n and also skip whitespaces as >> takes input skipping whitespaces
    //We can also use while(!file.eof()) which keeps reading till eof is not encountered and using getline to take input is a very good option to avoid any failbit setting to true


    //In some cases , the failbit is set to true
    //1) Reading any other data type in while(file>>n) or reading eof() marker , which makes read operation unsuccessful so use file.clear() and file.ignore( , )
    //2) Reading the eof() marker in while(file.get(ch)) , this reads all things but is unsuccessful when encounters eof marker making the failbit true so use file.clear()
    //3) Reading the file using getline(file , st) and again encountering the eof() marker so use file.clear()
    //4) No file exists and opening in reading mode of that file , use f1.clear()
    //5) If file exists then empty and trying to read that file using any of the above methods for text file or even .read() to read in binary mode , so you file.clear() (and file.ignore() if needed)

    //If we use while(!file.eof()) and use any of the above methods to take input for a file inside this while loop then the failbit is fine and not true


    //Some info related to failbit is relevant here:
    //The Failbit of file can also be true if .read() tries to read int from file but in code , we are reading by char var or array or the opposite
    //In this case we again need to use .clear() function

    return 0;
}
