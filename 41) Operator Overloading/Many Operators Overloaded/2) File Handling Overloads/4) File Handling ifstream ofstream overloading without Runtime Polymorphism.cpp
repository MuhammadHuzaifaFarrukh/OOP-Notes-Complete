#include <iostream>
#include <fstream>
using namespace std;

// Code uses compile time polymorphism only (Not Runtime)

class A
{
private:
    double x;
    string name;
public:
    A(double s = 0, string n = "") : x(s), name(n) {}

    // Overload ofstream << for writing to file
    friend ofstream& operator<<(ofstream& ofs, const A& obj);

    // Overload ifstream >> for reading from file
    friend ifstream& operator>>(ifstream& ifs, A& obj);

    void display() const
    {
        cout << "x: " << x << ", name: " << name << endl;
    }
};

ifstream& operator>>(ifstream& ifs, A& obj)
{
    ifs >> obj.x >> obj.name;
    return ifs;
}
ofstream& operator<<(ofstream& ofs, const A& obj)
{
    ofs << obj.x << " " << obj.name;
    return ofs;
}


int main()
{
    A a1(3.5, "Object1");
    A a2(7.2, "Object2");

    // Writing to file
    ofstream outfile("data.txt");
    outfile << a1 << endl;
    outfile << a2 << endl;
    outfile.close();

    // Reading from file
    ifstream infile("data.txt");
    A a3, a4;
    infile >> a3;
    infile >> a4;
    infile.close();

    cout << "Read from file:" << endl;
    a3.display();
    a4.display();

    return 0;
}
