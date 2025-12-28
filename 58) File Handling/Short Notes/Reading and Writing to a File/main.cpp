#include <iostream>
#include<fstream>  //Used for working with files in C++

//The useful classes for working with files in C++ are :
// 1) fstreambase , 2) ifstream , 3) ofstream .


//You must open a file before working on it and we have ways to open it primarily :
// 1) By constructor , 2) By member function open() of the class



using namespace std;

int main()
{

    string s ="Huzaifa Is A Good Boy " ;  // Using a string to write , can also use char array , its up to you
    //Opening Files using constructor and reading it
    ofstream out("Sample.txt"); // Just opens the file for writing to it. This is Write Operation. It will create a new file if the file is not there or will overwrite the file if it contains some previous data.
    out<<s<<endl; //We can add some more to the opened file .



    //Opening File using Constructor and reading from it

    ifstream in("Sample.txt");  //Read Operation
    // in>>s;  //Reads only one word and leaves when encounters a space or new line
    getline(in, s);   // This will read whole line and using it again will read next line.
    cout<<s<<endl;




    string st2;
    //This overwrites the previous written text to a new file .
    //Opening Files using constructor and reading it
    ofstream opfile("CJ.txt");  //You can also use mode flag here. By default, it has flag mode ios::out
    opfile<<"Ye to Abdul Bari ha "<<endl<<" LALALA"<<endl;  //Using without string type to write.
    opfile<<"Ye"<<endl;  //Adds more to the opened file.

    ifstream ampifile("CJ.txt");
    while (getline(ampifile, st2))
    {
        cout << st2 << endl;  // Print each line read from the whole file
    }

//If a file is not in the folder then it will be created and data will be entered in it


    /*
    //You can also give full address of path like below :
    string st2;
        string filename = "C:/Users/.../Goku.txt "; //Add your own path if the file is not in the same folder
       ifstream ampifile(filename);
       while (getline(ampifile, st2))
        {
             cout << st2 << endl;  // Print each line read from the whole file
        }

    */









    /*
    //Writing using fstream using constructor
    string message = " Hi , I'm Goku " ;


    fstream file("Goku.txt", ios::out);  // or ios::app for appending
    file<<message;
    */




    /*
    //Reading using fstream using constructor
    string message ;


    fstream file("Goku.txt", ios::in);
    while(getline(file, message))
    {
        cout<<message<<endl;
    }
    */

    //ios::out for writing while overwriting the previous data
    //ios::in for reading the data
    //ios::app for appending meaning writing after the existing data while existing data exists.


    /*
    //You can use .is_open() member function to check if the file is opened successfully or not.

    ofstream hout("Huji.txt" , ios::out);
     if (hout.is_open()) {
        cout << "File opened successfully.\n";
        // Perform operations on the file here
         // Close the file when done
    } else {
        cout << "Failed to open file.\n";
    }



    //We can use many extensions for files like .txt , .xml , .dat , .cvs , .json , .html , .log , .bin and more but the way they are formatted in file handling is very different like .txt and .bin files may be handled here easily but to handle other files with different extensions , we use different methodologies
    */











    /*
    //Checking if the file is empty or not
    string s;
    int count = 0;
    ifstream hin;
    hin.open("Goku.txt",ios::in);
    while(getline(hin , s))
    {
       cout<<s;
       count++;
    }



    cout<<endl;

    if(count==0)
    {
        cout<<"The File's empty "<<endl;
    }
    else
    {
        cout<<"The File's not empty "<<endl;
    }
    */




    return 0;

}






