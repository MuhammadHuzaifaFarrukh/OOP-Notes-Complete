#include <iostream>
#include <fstream>
using namespace std;

class Student
{
private:
    int roll;
    string name;
    double marks;
public:
    Student(int r = 0, string n = "", double m = 0) : roll(r), name(n), marks(m) {}

    // Shows Polymorphic Behaviour
    // Overloaded ostream operator - works with cout, ofstream, etc because while calling we pass it the cout's/file object's buffer to it

    friend ostream& operator<<(ostream& os, const Student& s)
    {
        os << s.roll << " " << s.name << " " << s.marks;
        return os;
    }

    // Shows Polymorphic Behaviour
    // Overloaded istream operator - works with cin, ifstream, etc. because while calling we pass it the cin's/file object's buffer to it
    friend istream& operator>>(istream& is, Student& s)
    {
        is >> s.roll >> s.name >> s.marks;
        return is;
    }

    void display() const
    {
        cout << "Roll: " << roll << ", Name: " << name << ", Marks: " << marks << endl;
    }
};

int main()
{
    Student s1(101, "John", 85.5);
    Student s2(102, "Alice", 92.0);

    // 1. Console output
    cout << "Console output:" << endl;
    cout << s1 << endl;                 //cout when passed to istream , istream object remains istream and gets the buffer of cout (Polymorphism)
    cout << s2 << endl << endl;

    // 2. File output - USING overloaded <<
    ofstream outfile("students.txt");
    cout << "Writing to file..." << endl;
    outfile << s1 << endl;              //ofstream obj when passed to ostream , ostream object remains ostream and gets the buffer of ofstream object (Polymorphism)
    outfile << s2 << endl;
    outfile.close();

    // 3. File input - USING overloaded >>
    ifstream infile("students.txt");
    Student s3, s4;

    // This uses the overloaded operator>>
    infile >> s3;                       //ifstream obj when passed to istream , istream object remains istream and gets the buffer of ifstream object (Polymorphism)
    infile >> s4;
    infile.close();

    cout << "Read from file using >> overload:" << endl;
    s3.display();
    s4.display();

    return 0;
}


