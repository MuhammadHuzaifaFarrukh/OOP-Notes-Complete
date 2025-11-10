//Friend Functions tell compiler that we can access private data or classes through a class
//We make these functions outside of a class and they are not members of the class whose data we want to access
//We give a reference in the class of them. They are not in the scope of that class
//It can't be called from objects like obj.funct()


/*1)
#include <iostream>

using namespace std;

class complex
{
private:
    int a,  b;
public:
    void complex_no_display(int,int );
    friend complex complex_no_sum(complex , complex ); //Give a Reference of the function in the class whose data we want to access
    void print_numbers();

};
void complex::complex_no_display( int a1, int b1 )
{
    a=a1;
    b=b1;
}

void complex::print_numbers()
{
   cout<<"The complex number is "<<a<<" + "<<b<<"i"<<endl;
}
complex complex_no_sum(complex o1 ,complex o2) //We can make objects inside their normal functions with or without their own return type or inside their own member functions with or without thier return type
{
    complex o3;
    //This below line will fail if this function is not friend of the class
    o3.complex_no_display((o1.a+o2.a),(o1.b+o2.b));

    //We can still implement this function without using friend here if we use public getters to get the values of private data
    //Like o1.get_a() or o2.get_b() etc
    return o3;
}

int main()
{
    complex c1 , c2 , sum;

    c1.complex_no_display(3,4);
    c1.print_numbers();

    c2.complex_no_display(5,6);
    c2.print_numbers();

    sum = complex_no_sum(c1,c2); //Called like a normal function
    sum.print_numbers();

    return 0;
}
*/



//2)
#include <iostream>

using namespace std;

class shape
{
    int width;
    int height;

public :
    void getm(int, int );
    friend int rect_area(shape ); //Can also use function prototype


};
int rect_area(shape rec)
{
    return (rec.width*rec.height);
    //We could also use rec.get_width() and rec.get_height() as public getters to take private data without using friend functions
    //Using friend function , we can easily call rec.width and rec.height
}


void shape::getm(int w,int h)
{
    width=w;
    height=h;
}



int main()
{
    shape rec;
    rec.getm(13,14);
    int  area = rect_area(rec);
    cout<<"Area is : " <<area<<endl;

    return 0;
}




/*3)
//Same program as above almost

#include <iostream>

using namespace std;

class Shape
{
    int width;
    int height;
public:


    // Public member function to set width and height
    void setDimensions(int w, int h)
    {
        width = w;
        height = h;

    }

    // Friend function to calculate area (using copy)
    friend int calculateArea(Shape s); // Friend declaration
};

// Friend function implementation (copies the object)
int calculateArea(Shape s)
{ // Takes a copy of the object

    return s.width * s.height;
}

int main()
{
    Shape rectangle;
    rectangle.setDimensions(13, 14);

    int area = calculateArea(rectangle); // Pass the object by value

    cout << "Area is: " << area << endl;

    return 0;
}






4)
#include <iostream>

using namespace std;
class demo
{
    int a,b;
public:
    void getdata()
    {
        cout<<"Enter two numbers : ";
        cin>>a>>b;
    }

    //You can define a friend function (not class member) inside the class whose data you want to access
    friend int sum( demo aa)
    {
        return (aa.a+aa.b);
    }
};
int main()
{
    demo aa;
    aa.getdata();
    cout<<"Addition : "<<sum(aa);

    return 0;
}

*/


//Friend functions break the principle of encapsulation so we try to use them as minimum as possible
//However we may use them :
//We generally use friend functions just to overload the stream operators << and >> for inputting and outputting objects (object data)
//We will learn this after discussing operator overloading in lec 41
