#include <iostream>
#include <string>

using namespace std;

class ClassB
{
private:
    string b_data;
public:
    ClassB(string val) : b_data(val) {}

    // Getter for ClassA to use
    string getData() const
    {
        return b_data;
    }
};

class ClassA
{
private:
    string a_data;
    ClassB b1;
public:
    ClassA() : a_data("Empty"), b1("B's string") {}

    ClassA& operator=(const ClassB& obj)
    {
        if( (void *)this != (void *)&obj )
        {
            this->b1 = obj;
        }
        return *this;
    }

    ClassA(const ClassB& obj) : b1("B's String")
    {
        this->a_data = "Empty";
        this->b1 = obj;
    }

    void display()
    {
        cout << "ClassA Data: " << a_data << endl;
        cout << "ClassA's B1 Data: " << b1.getData() << endl;
    }
};

int main()
{
    ClassA a;
    a.display();


    ClassB b("NEW B");
    a = b;      //We use copy assignment operator in composition to assign b1 part of a from an existing 'b'
    cout<<endl;
    a.display();
    cout<<endl;

    ClassA a1 = b;
    a1.display();
    //Similarly we can do this for aggregation and Association as well (if needed only otherwise we don't use it most of the time)
    return 0;
}
