#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{

    //To Read all the file in a string :
    //Using stringstream
    //We use .rdbuf() that reads the entire file stream into sstream object
    //Then use .str() function to put this sstream contents into our string


    /*
    std::ifstream inFile("my_file.txt");
    if (!inFile)
    {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << inFile.rdbuf(); // Read the entire file stream into the stringstream
    inFile.close();

    std::string fileContent = buffer.str(); // Copy stringstream's content to a string

    std::cout << "File content:\n" << fileContent << std::endl;
    */





    //Use this to read the contents of file line by line :

    /*
    std::string filename = "my_file.txt";
    std::ifstream inFile(filename);

    if (!inFile.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    std::string line;
    // The loop continues as long as a line is successfully read
    while (std::getline(inFile, line))
    {
        // You can now use the 'line' variable for whatever you need
        std::cout << line << std::endl;
    }

    inFile.close();
    */


    //We can also use getline not just for line by line reading but for inputting whole file contents into string instead of sstream
    //Below program shows this and also to find a specific word in that file from the string
    /*
    std::string filename = "my_file.txt";
    std::string wordToFind = "specific";
    std::string fileContent;
    std::string line;

    // Read the entire file into a single string
    std::ifstream inFile(filename);
    if (inFile.is_open())
    {
        while (std::getline(inFile, line))
        {
            fileContent += line;
        }
        inFile.close();
    }
    else
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    // Search for the word in the entire string
    if (fileContent.find(wordToFind) != std::string::npos)
    {
        std::cout << "Method 1: The word was found in the file." << std::endl;
    }
    else
    {
        std::cout << "Method 1: The word was not found in the file." << std::endl;
    }
    */


    //Line by line is a very good method to find the word as it is memory efficient for not copying whole file contents directly into a string
    /*
    std::string filename = "my_file.txt";
    std::string wordToFind = "specific";
    std::string line;
    bool found = false;

    std::ifstream inFile(filename);
    if (inFile.is_open())
    {
        while (std::getline(inFile, line))
        {
            // Check each line for the word
            if (line.find(wordToFind) != std::string::npos)
            {
                found = true;
                break; // Exit the loop as soon as the word is found
            }
        }
        inFile.close();
    }
    else
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    if (found)
    {
        std::cout << "Method 2: The word was found in the file." << std::endl;
    }
    else
    {
        std::cout << "Method 2: The word was not found in the file." << std::endl;
    }
    */



    //To find all occurrences of a word in a File  :
    //Also it can find the sentences / phrases or even paragraphs as well
    /*
    std::string filename = "my_file.txt";
    std::string wordToFind = "specific";
    std::string fileContent;
    std::string line;
    int count = 0;

    // Read the entire file into a single string
    std::ifstream inFile(filename);
    if (!inFile.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }
    while (std::getline(inFile, line))
    {
        fileContent += line + "\n"; // Add a newline to preserve line breaks
    }
    inFile.close();

    // Find all occurrences using a loop
    size_t pos = fileContent.find(wordToFind, 0);
    while (pos != std::string::npos)
    {
        count++;
        // Start the next search from the position after the current match
        pos = fileContent.find(wordToFind, pos + 1);
    }

    std::cout << "The word '" << wordToFind << "' was found " << count << " times." << std::endl;
    */





    //Finding a word that is not a part of a larger word :
    //Also it can find the sentences / phrases or even paragraphs as well
    /*
    std::string filename = "my_file.txt";
    std::string wordToFind = "the"; // Case-sensitive word
    std::string line;
    int totalCount = 0;

    std::ifstream inFile(filename);
    if (!inFile.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    while (std::getline(inFile, line))
    {
        size_t pos = line.find(wordToFind);
        while (pos != std::string::npos)
        {
            // Check if the character before the word is a space or start of line
            bool pre_boundary = (pos == 0) || isspace(line[pos - 1]) || ispunct(line[pos - 1]);
            // Check if the character after the word is a space or end of line
            bool post_boundary = ((pos + wordToFind.length()) == line.length()) ||
                                 isspace(line[pos + wordToFind.length()]) ||
                                 ispunct(line[pos + wordToFind.length()]);

            if (pre_boundary && post_boundary)
            {
                totalCount++;
            }

            // Continue the search from the position after the current word
            pos = line.find(wordToFind, pos + 1);
        }
    }

    inFile.close();
    std::cout << "The standalone word '" << wordToFind << "' was found " << totalCount << " times." << std::endl;
    */

    return 0;
}
