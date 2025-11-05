#include <iostream>

using namespace std;

// For counting no of objects , we use a static data member and do count++ every time in each constructor , paramterized or non-paramterized
// If we are making an object from an existing one , then copy constructor is used
// But in copy constructor when compiler generates , data members are shared and static one is not touched as it is shared among the whole class
// So we make our own copy constructor and use count++ there also

class About
{
    static int count;
public:

    About()
    {
        count++;
    }
    About(const About &a)
    {
        count++;
    }
    static void about()
    {
        cout << "This is About class\n";
    }
    static int getCount()
    {
        return count;
    }
    ~About()
    {
        count--;
    }
};
int About:: count = 0;

int main()
{
    About a1;
    {
        About a2(a1);   //Copy Constructor Invoked
        cout<<"The No of Objects : "<<About::getCount()<<endl<<endl;
    }

    cout<<"The No of Objects : "<<About::getCount()<<endl<<endl;

    return 0;
}
