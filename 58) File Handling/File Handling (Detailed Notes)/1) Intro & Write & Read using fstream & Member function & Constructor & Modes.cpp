#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    //using fstream , we can open in any mode
    // either by constructor like below or by using .open(" ", mode if specify) and if mode not specified then usually it is openend in ios::in mode
    fstream f1("huz.txt",ios::in );
    string s;
    getline(cin ,s ); //Writing in a string until it encounters eof
    f1<<s; //Input into the f1 (To write in file)

    f1.close();

    //Opening the same file using function
    f1.open("huz.txt"); //By default it is in ios::in  , we can also use ios::in | ios::out with fstream (not individuals)


    //Doing f1>>s will only read one word until white space (To read / input from file)
    //Without while loop , it will read only one line
    while(getline(f1 , s)) // Keep loop until the whole file ends and storing each line in string s
    {
        cout<<s<<endl; // Printing each string s from f1 object
    }



    //To check if a file has opened correctly , use .is_open() function in an if , if(!file_object.is_open()){cout<<"Error opening the file";}
    //To check if file exists , use if(!file_object){ cout<<"File not exist }


    //There are many modes of file :
    //Read in a file : in , works with ifstream , fstream
    //Write in a file : out , works with ofstream , fstream
    //Append in a file : app , works with ofstream , fstream
    //To erase everything in a file : trunc , works with ofstream , fstream
    //To write at the end of the file : ate , works with ofstream , fstream

    //To open a file in binary mode : binary , works with all 3
    //To fail if file doesn't exist : nocreate , works with ofstream , fstream (Part of Older Compilers)
    //To fail if file already exists : noplace , works with ofstream , fstream (Part of Older Compilers)




    //You can combine the modes of file in opening mode parameter using bitwise OR (|)
    // E.g ios::in | ios::out or ios::in | ios::out | ios::trunc etc
    //For these combinations , the file should be in fstream not individuals
    //Also priorities to do what mode first is described in fstream class
    //E.g trunc is done before out or in and using both trunc and app should never be done as they both are each other's opposites
    //out should be done before in if the file is never created or empty
    // Good order can be like this :
    /*
    1) Open the file with the requested modes like out or in or binary mode
    2) If ios::trunc is present, immediately clear the file's contents.
    3) Set the stream's position based on flags like ios::ate or the default for the given modes.
    */


    //If we use ofstream / ifstream and choose any other operations like ios::in for ofstream and ios::out / app for ifstream then it will give errors
    //If we use fstream , then we need to specify each mode we are working with as it uses no default mode .
    //Even if we use app in fstream and try to read , it gives no errors but will not be successful
    //In fstream , read and write pointer are same so both of them move together , e.g if we move any one pointer the other one moves automatically

    return 0;
}
