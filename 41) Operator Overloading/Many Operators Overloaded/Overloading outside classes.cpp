#include <iostream>
using namespace std;

//Either use getdata() to access private members of classes as functions are not members this time
//Or use friend functions i.e make these functions friends of both classes , one example is commented in both classes
//If the return type of these functions is kept void  , then we can simply call a1+a2;

//Forward Declaration is necessary for using friend functions
//class B;
class A
{
private:
    double x;
public:
    A(double s)
    {
        x = s;
    }
    double getdata() const
    {
        return x;
    }
    //friend A operator+(const A& , const B& );

};

class B
{
private:
    int y;
public:
    B(int s)
    {
        y = s;
    }
    int getdata() const
    {
        return y;
    }
    //friend A operator+(const A& , const B& );
};

// A + B returns A
A operator+(const A& obj1, const B& obj2)
{
    //return A((obj1.x) + obj2.y);
    return A(obj1.getdata() + obj2.getdata());
}

// B + A returns A
A operator+(const B& obj1, const A& obj2)
{
    return A(obj1.getdata() + obj2.getdata());
}

// A - B returns A
A operator-(const A& obj1, const B& obj2)
{
    return A(obj1.getdata() - obj2.getdata());
}

// B - A returns A
A operator-(const B& obj1, const A& obj2)
{
    return A(obj1.getdata() - obj2.getdata());
}

// A * B returns A
A operator*(const A& obj1, const B& obj2)
{
    return A(obj1.getdata() * obj2.getdata());
}

// B * A returns A
A operator*(const B& obj1, const A& obj2)
{
    return A(obj1.getdata() * obj2.getdata());
}

// A / B returns A
A operator/(const A& obj1, const B& obj2)
{
    return A(obj1.getdata() / obj2.getdata());
}

// B / A returns A
A operator/(const B& obj1, const A& obj2)
{
    return A(obj1.getdata() / obj2.getdata());
}

int main()
{
    A a1(4.5);
    B b1(3);

    // All operations return type A
    A result1 = a1 + b1;  // A + B → A
    A result2 = b1 + a1;  // B + A → A
    A result3 = a1 - b1;  // A - B → A
    A result4 = b1 - a1;  // B - A → A
    A result5 = a1 * b1;  // A * B → A
    A result6 = b1 * a1;  // B * A → A
    A result7 = a1 / b1;  // A / B → A
    A result8 = b1 / a1;  // B / A → A

    cout << "A + B: " << result1.getdata() << endl;
    cout << "B + A: " << result2.getdata() << endl;
    cout << "A - B: " << result3.getdata() << endl;
    cout << "B - A: " << result4.getdata() << endl;
    cout << "A * B: " << result5.getdata() << endl;
    cout << "B * A: " << result6.getdata() << endl;
    cout << "A / B: " << result7.getdata() << endl;
    cout << "B / A: " << result8.getdata() << endl;
    return 0;
}


// Can use int/double return type for storing in that variable like
//double operator+(const A& obj1, const B& obj2)
//{
//    return obj1.getdata() + obj2.getdata();
//}
//
// Calling : double x = a1 + b1;  // Now x = 7.5


// Can use return type as void for calling a1+a2; and nothing
//void operator+(const A& obj1, const B& obj2)
//{
//    double result = obj1.getdata() + obj2.getdata();
//    cout << "Result: " << result << endl;
//    // No return statement - returns void
//}
//And Call : a1+a2;
