#include <iostream>

using namespace std;

//For Virtual Functions , the base class and derived class must have the same name , same no and type of parameters and almost same return type
//Different return type only accepted when a base class returns reference of base type and then derived class returns reference but of derived class type
//Also if a base class returns pointer of base type and then derived class returns pointer of derived type

// Base Class
class Shape
{
public:
    // Virtual function with return type 'void' and one parameter 'int'
    virtual void draw(int color_code)
    {
        cout << "Shape: Drawing a generic shape with color code " << color_code << endl;
    }
};

// Derived Class 1
class Circle : public Shape
{
public:
    // Overriding the function: Same name, same 'void' return type, same 'int' parameter
    void draw(int color_code) override
    {
        cout << "Circle: Drawing a red circle with color code " << color_code << endl;
    }
};

// Derived Class 2
class Rectangle : public Shape
{
public:
    // Overriding the function: Same name, same 'void' return type, same 'int' parameter
    void draw(int x)
    {
        cout << "Rectangle: Drawing a blue rectangle with color code "  <<x<< endl;
    }
    //Below Function becomes a separate function as it doesn't match the virtual function prototype
    void draw()
    {
        cout << "Rectangle: Drawing a blue rectangle with color code "  << endl;
    }
};

int main()
{
    // 1. Array of Base Class Pointers (Polymorphic container)
    Shape* shapes[3];
    shapes[0] = new Circle();
    shapes[1] = new Rectangle();    //Calls the Shape's Draw
    shapes[2] = new Shape(); // A base class object

    //(*shapes[1]).draw();  //Error
    (*shapes[1]).draw(5);  //No Error as this uses the Shape's virtual function

    int code = 5;

    cout << "--- Polymorphic Calls ---" << endl;

    // 2. Loop and Call (Runtime Polymorphism)
    // Even though we call through a Shape* pointer, the actual object's version is executed.
    for (int i = 0; i < 3; ++i)
    {
        shapes[i]->draw(code);
    }

    // Clean up
    for (int i = 0; i < 3; ++i)
    {
        delete shapes[i];
    }

    return 0;
}
