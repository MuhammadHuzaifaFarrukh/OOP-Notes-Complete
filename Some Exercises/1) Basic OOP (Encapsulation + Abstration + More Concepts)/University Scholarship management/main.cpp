#include <iostream>
#include <string>
#include <fstream>

#include "class.h"
#include "Finance.h"
#include "global.h"


#include "class.cpp"
#include "Finance.cpp"
#include "global.cpp"


using  namespace std;

int main()
{
    int n;
    cout<<"Enter number of students : ";
    cin>>n;
    Student *students = new Student[n];
    Finance *finances= new Finance[n];

    //Level 1 + Level 2 Integration:

    for(int i = 0 ; i<n; i++)
    {
        cout<<"\n--- Enter details for each Student "<<i+1<<" ---\n";
        cin>>students[i];
        double total, paid;
        cout<<"Enter total Fee : ";
        cin>>total ;
        cout<<"Enter Paid Fee : ";
        cin>>paid;
        finances[i]= Finance(students[i].getrollNo(), total, paid);
        students[i].CalculateGPA();
        processcholarship(students[i], finances[i]);
    }

    //Level 3 :
    //Display All Records (from file) :
    //LoadFromFile();
    //Display All Records (from current Array) :
    for(int i = 0 ; i<n ; i++)
    {
        Summary(students[i] , finances[i]);
        cout<<endl<<endl;
    }


    //More Robust but Complex Method by using .find() and isdigit methods , (can use .substr() as well)
    //Find Topper and Display (from file) :
//    ifstream in("records.txt");
//    string line;
//    string topper;
//    double gpa = 0.0 , newgpa;
//    while(getline(in, line))
//    {
//        size_t pos = line.find("GPA:");
//        if(pos != string::npos)
//        {
//            // Start after "GPA:"
//            string numStr = "";
//            for(size_t i = pos + 4; i < line.length(); i++)
//            {
//                if(isdigit(line[i]) || line[i] == '.')
//                {
//                    numStr += line[i];
//                }
//                else if(!numStr.empty())
//                {
//                    break; // Stop when we hit non-numeric after getting numbers
//                }
//            }
//
//            if(!numStr.empty())
//            {
//                double newgpa = stod(numStr);
//                if(gpa < newgpa)
//                {
//                    gpa = newgpa;
//                    topper = line;
//                }
//            }
//        }
//    }
//    cout << "\n--- Topper ---\n";
//    cout<<topper<<endl;


    //Easy and Required :
    //Find Topper and Display (from current Array):
    int index = 0;
    for(int i = 1 ;i<n ; i++)
    {
        if(students[i]>students[index])
        {
            index = i;
        }
        else
        {
            index = i+1;
        }
    }
    cout << "\n--- Topper of the Current Batch ---\n";
    Summary(students[index] , finances[index]);


    cout<<"Total Scholarships Awarded : " <<Finance::get_sc_count()<<endl;

    //Deallocation :

    delete[] students;
    delete[] finances;

    return 0;
}
