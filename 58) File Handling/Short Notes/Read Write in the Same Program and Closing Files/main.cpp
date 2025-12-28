#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //Connecting our file with hout stream
    ofstream hout("Sample.txt" );
    string s;
    cout<<"Enter your name : ";
    //cin>>s;  //Writing data into file at runtime
    getline( cin, s);   //Writing data into file at runtime (both are correct)

    hout<<"Your name is : " << s;
    hout.close();

    ifstream hin("Sample.txt");
    string content;
    // hin>>content;  //Will print only one word and leave when space occurs like cin
    getline(hin, content );
    //  cout<<content<<endl;  //Reading Data from our written file at runtime
    cout<<"The Content of this file is : "<<endl<<content<<endl;
    hin.close();

    //We can open one file with different names for different purposes but should close after using them by close() function







    return 0;
}






