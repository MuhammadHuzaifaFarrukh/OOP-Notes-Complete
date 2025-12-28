#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //Using Member function open() to open a file to write .
    ofstream out;
    out.open("Huji.txt", ios::out);  // Using open() in append mode
    out<<"Frieza , you can't live anymore here ! "<<endl;
    out.close();

    //Using Member Function open() to open a file to read from it.
    ifstream in;
    string message;
    in.open("Huji.txt");
    /*
     while( getline (in , message)  )
     {
         cout<<message<<endl;
     }
     */
    while( in.eof() == false  )  //Untill we don't encounter the end of file which means that eof() will remain zero.
    {
        //in.eof()== false or 0 (zero)
        getline(in, message);
        cout<<message<<endl;
    }
    //Both while loop approaches are correct.
    return 0;
}
