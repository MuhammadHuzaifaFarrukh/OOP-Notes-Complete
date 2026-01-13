#include <iostream>
#include <string>
#include "Rectangle.h"

using namespace std;


Rect::Rect() {} // Can be used to assign default values

Rect::Rect(double a, double b, double c, double d)
{
    x = a;
    y = b;
    width = c;
    height = d;
}

void Rect::scale(double factor_x, double factor_y) //Scale means that multiply
{
    width *= factor_x;
    height *= factor_y;

}

void Rect::move(double dx, double dy)  //Translation means to shift the coordinates accordingly
{
    this->x += dx;
    //this->x = dx;
    this->y += dy;
    //this->y = dy;
}

void Rect::display()
{
    cout<<"Details of the Rectangle : "<<endl;
    cout<<"Top Left Corner -> X : "<<x<<" , Y : "<<y<<endl;
    cout<<"Width : "<<width<<" , Height : "<<height<<endl;
}


void Rect::copy_from(const Rect &R)
{
    x = R.x;
    y = R.y;
    width = R.width;
    height = R.height;
}

Rect& Rect::operator=(const Rect &R)
{
    if(this != &R)
    {
        copy_from(R);
    }
    return *this;
}

Rect::Rect(const Rect &R)
{
    copy_from(R);
}


bool Rect::operator==(const Rect &R)
{
    if(x == R.x && y == R.y && width == R.width && height == R.height)
    {
        return 1;
    }
    return 0;
}


//It includes , overlaps or touching boundary lines , overlaps full , or half or even if a little bit
//Also we use the standard coordinates system not the mathematical coordinates that requires negative x and y
//If top left corner is (0,0) then bottom one is (0,5) with height 5 , not (0,-5)
//Also if top left corner is (0,0) then top right corner is (5,0) with width 5


bool Rect::operator&(const Rect &R)
{
    return (this->x <= R.x + R.width)     &&  // Left edge of *this is before or on R's right edge
           (this->x + this->width >= R.x) &&  // Right edge of *this is after or on R's left edge
           (this->y <= R.y + R.height)    &&  // Top edge of *this is before or on R's bottom edge
           (this->y + this->height >= R.y);   // Bottom edge of *this is after or on R's top edge
}


//If A rectangle is at the right of B or touching B boundary line or overlap , Overlaps possible
bool Rect::operator>=(const Rect &R)
{
    return (this->x >= R.x);
}

//If A rectangle is at the completely right of B  , Overlaps cannot happen here
bool Rect::operator>(const Rect &R)
{
    return (this->x > (R.x + R.width));
}



//If A rectangle is at the left of B or touching B boundary line , Overlap possible
bool Rect::operator<=(const Rect &R)
{
    return (this->x <= R.x);
}


//If A rectangle is at the completely left of B  , Overlaps cannot happen here
bool Rect::operator<(const Rect &R)
{
    return ((this->x + this->width) < R.x);
}






