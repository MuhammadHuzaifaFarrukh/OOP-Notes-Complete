#include <iostream>
 
using namespace std;

class emp
{
private:  
    // Data Members :   
    int a=1,b=2,c=3;  
public:
    // Use Data Members Accessing by Member Functions which are in public section :  
    // Use setter and getter functions
    void setdata(int a,int b,int c);    // Setter function , its return is usually void 
    void getdata();    // Getter function , here its return type is void , usually it should return the data type that it should
    // E.g you may make three functions : 
    // int get_a(){return a;}
    // int get_b(){return b;}
    // int get_c(){return c;}
};

void emp:: getdata( )
{
    // Below line is equivalent to ( object_name which called getdata() ).setdata(33,44,55)
    setdata(33,44,55);    // You may use a function inside another function , and this function is called for the same object (current obj) for which the getdata was called
    cout<<" The value of a is "<<a<<endl;
    cout<<" The value of b is "<<b<<endl;
    cout<<" The value of c is "<<c<<endl;
}
void emp :: setdata(int p,int q,int r)
{
     // Here using a,b,c in the formal arguments will only give the a,b,c the values of their class as declared as a,b,c in the member functions when used like this are treated as member variables not the formal arguments
     // We could also use this pointer if we want to put a,b,c as formal parameters
    a=p;
    b=q;
    c=r;
}
int main()
{
    emp huzaifa;
    // huzaifa.a=1; Error because a is private
    //Use Member Functions -> object_name.member_function_name
    // huzaifa.setdata(33,44,55);
    
    huzaifa.getdata();
    //For having 3 Separate Setters :
    //E.g : cout<<" The value of a is "<<get_a()<<endl; and so on
    
    return 0;
}


