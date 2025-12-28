#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int id;
    float marks;
};

int main() {
    ifstream in("students.bin", ios::binary);

    Student s;
    while (in.read((char*)&s, sizeof(s))) 
    {
        cout << "ID: " << s.id << ", Marks: " << s.marks << endl;
    }
    //We can use either sizeof(data_type) or sizeof(identifier) , both work fine 

    in.close();
}
