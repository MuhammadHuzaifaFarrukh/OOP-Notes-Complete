#include <iostream>

using namespace std;

class Number
{
    int n , o;
public :
    Number()
    {
        n = 0;
        o = 5;
    }
    Number(int s , int t)
    {
        n = s;
        o = t;
    }
    void getdata()
    {
        cout<<"Value for n is : "<<n<<" and for o is : "<<o<< endl;
    }
    friend main();  //This makes the main() function a friend of the Number class
};

int main()
{
    Number N1(123,50);
    cout<<N1.o<<endl;   //Now main() function can easily access all the private data members of Number objects

    return 0;
}
