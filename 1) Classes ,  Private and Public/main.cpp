#include <iostream>

using namespace std;

class emp
{ 
private:
    int a=1,b=2,c=3;
public:

    void setdata(int a,int b,int c);
    void getdata();
};

void emp:: getdata( )
{
    setdata(33,44,55);
    cout<<" The value of a is "<<a<<endl;
    cout<<" The value of b is "<<b<<endl;
    cout<<" The value of c is "<<c<<endl;
}
void emp :: setdata(int p,int q,int r)
{
     //Here using a,b,c in the formal arguments will only give the a,b,c the values of their class as declared as a,b,c in the member functions when used like this are treated as member variables not the formal arguments
     //We could also use this pointer if we want to put a,b,c as formal parameters
    a=p;
    b=q;
    c=r;
}
int main()
{
    emp huzaifa;
    // huzaifa.a=1; Error because a is private
    //huzaifa.setdata(33,44,55);
    huzaifa.getdata();


    return 0;

}

