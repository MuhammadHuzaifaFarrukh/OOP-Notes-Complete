#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    //Removing a specific word from file involves many steps :
    //1) First copy all the contents in a string
    //2) Then Use .find() and .erase() functions on the copied string to modify it
    //3) Finally open that file in truncate mode so all contents are removed
    //4) And then write the modified string into the file opened in truncate mode

    /*
    std::string filename = "my_file.txt";
    std::string fileContent;
    std::string line;

    // Step 1: Read the file's content into memory
    std::ifstream inFile(filename);
    if (!inFile.is_open())
    {
        std::cerr << "Error opening file for reading!" << std::endl;
        return 1;
    }
    while (std::getline(inFile, line))
    {
        fileContent += line + "\n";
    }
    inFile.close();

    // Step 2: Modify the content in memory
    std::string toRemove = "GUYS";
    size_t pos = fileContent.find(toRemove);
    if (pos != std::string::npos)
    {
        fileContent.erase(pos, toRemove.length());
    }

    // Step 3 & 4: Overwrite the file with the modified content
    std::ofstream outFile(filename, std::ios::trunc);
    if (!outFile.is_open())
    {
        std::cout << "Error opening file for writing!" << std::endl;
        return 1;
    }
    outFile << fileContent;
    outFile.close();

    std::cout << "Successfully removed '" << toRemove << "' from the file." << std::endl;
    */





    //For removing a specific letter from specific point , you need to tell its specific position as well :
    /*
    std::string filename = "my_file.txt";
    std::string fileContent;
    std::string line;

    // Step 1: Read the file's content into memory
    std::ifstream inFile(filename);
    if (!inFile.is_open())
    {
        std::cerr << "Error opening file for reading!" << std::endl;
        return 1;
    }
    while (std::getline(inFile, line))
    {
        fileContent += line + "\n";
    }
    inFile.close();

    // Step 2: Modify the content in memory to remove a specific letter
    int position_to_remove = 3; // The index of the character to remove (e.g., 'G' in "HI GUYS")
    int num_characters_to_remove = 1; // You want to remove just one character

    if (position_to_remove >= 0 && position_to_remove < fileContent.length())
    {
        fileContent.erase(position_to_remove, num_characters_to_remove);
    }
    else
    {
        std::cerr << "Invalid position to remove." << std::endl;
        return 1;
    }

    // Step 3 & 4: Overwrite the file with the modified content
    std::ofstream outFile(filename, std::ios::trunc);
    if (!outFile.is_open())
    {
        std::cerr << "Error opening file for writing!" << std::endl;
        return 1;
    }
    outFile << fileContent;
    outFile.close();

    std::cout << "Successfully removed a character from position " << position_to_remove << " in the file." << std::endl;
    */







    //Modifying the above program further and this time , it will ask for the positions and number of characters to remove by user
    /*
    void displayFileContent(const std::string& filename)
    {
        std::ifstream inFile(filename);
        if (!inFile.is_open())
        {
            std::cerr << "Error: Could not open " << filename << std::endl;
            return;
        }
        std::cout << "\n--- File Content ---\n";
        std::string line;
        std::string fullContent;
        while (std::getline(inFile, line))
        {
            fullContent += line + "\n";
        }
        inFile.close();

        std::cout << fullContent;
        std::cout << "---------------------\n";
        std::cout << "  "; // For alignment
        for (size_t i = 0; i < fullContent.length(); ++i)
        {
            if (i % 10 == 0)
            {
                std::cout << (i / 10);
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
        std::cout << "  "; // For alignment
        for (size_t i = 0; i < fullContent.length(); ++i)
        {
            std::cout << (i % 10);
        }
        std::cout << std::endl;
    }

    int main()
    {
        std::string filename = "my_file.txt";
        std::string fileContent;
        std::string line;

        // Display file content and indices to the user
        displayFileContent(filename);

        // Step 1: Read the file's content into memory
        std::ifstream inFile(filename);
        if (!inFile.is_open())
        {
            std::cerr << "Error opening file for reading!" << std::endl;
            return 1;
        }
        while (std::getline(inFile, line))
        {
            fileContent += line + "\n";
        }
        inFile.close();

        // Get user input for position and length to remove
        int position_to_remove;
        int num_characters_to_remove;

        std::cout << "Enter the starting position to remove: ";
        std::cin >> position_to_remove;
        std::cout << "Enter the number of characters to remove: ";
        std::cin >> num_characters_to_remove;

        // Step 2: Modify the content in memory
        if (position_to_remove >= 0 && (position_to_remove + num_characters_to_remove) <= fileContent.length())
        {
            fileContent.erase(position_to_remove, num_characters_to_remove);
        }
        else
        {
            std::cerr << "Invalid position or number of characters." << std::endl;
            return 1;
        }

        // Step 3 & 4: Overwrite the file with the modified content
        std::ofstream outFile(filename, std::ios::trunc);
        if (!outFile.is_open())
        {
            std::cerr << "Error opening file for writing!" << std::endl;
            return 1;
        }
        outFile << fileContent;
        outFile.close();

        std::cout << "Successfully removed " << num_characters_to_remove << " character(s) from position " << position_to_remove << "." << std::endl;
        std::cout << "File content after removal:" << std::endl;
        displayFileContent(filename);

        return 0;
    }
    */



    // This method is not very efficient for very large files
    // You can also use rename and remove functions to rename or delete the files :

    //Here .c_str() is necessary and also the <cstdio> as well as they are functions of C Standard Library
    // std::remove(originalFilename.c_str()); This removes the originalFilename
    // std::rename(tempFilename.c_str(), originalFilename.c_str()); This renames the tempFilename to originalFilename


    //You can pass files in function arguments , by writing the filename in function calling and then in function parameter we write (const string& filename)
    //In this way , we are passing a filename and that function will open the file and do all the work , otherwise we have to perform all the work of opening and closing the file






    //To Remove an existing file , we use .remove() function that takes a const char * as argument and returns zero on successful deletion of file , we can't use string with it , if we use any string object then it must be like .remove( string_obj.c_str() )
    /*
    std::string filename = "Hello.txt";

    // You must use .c_str() here because 'filename' is a std::string object.
    if (std::remove(filename.c_str()) == 0)
    {
        std::cout << "File removed successfully." << std::endl;
    }
    else
    {
        std::cerr << "Error removing file." << std::endl;
    }

    if we had used remove("Hello.txt") then no need of .c_str()
    */

    return 0;
}
