#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int id;
    float marks;
};

int main() {
    Student s1 = {1, 85.5};
    Student s2 = {2, 90.2};
    Student s3 = {3, 76.8};

    ofstream out("students.bin", ios::binary);
    out.write((char*)&s1, sizeof(s1));
    out.write((char*)&s2, sizeof(s2));
    out.write((char*)&s3, sizeof(s3));
    out.close();
    //We can use either sizeof(data_type) or sizeof(identifier) , both work fine   
 
    cout << "Data written successfully.\n";
}
