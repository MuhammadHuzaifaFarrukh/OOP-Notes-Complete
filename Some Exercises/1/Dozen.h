#include <iostream>
#include <cmath>

using namespace std;

class Dozen
{
private:
    int dozen, units;  

public:
    
    //Optional Default Constructor
    //Dozen(){} // Default Constructor (Not required as we are not creating any object without parameters)
    
    // 1) Parameterized Constructor that calls setdata and getdata
    Dozen(int d , int u) 
    {
        dozen = 0;
        units = 0;
        setdata(d , u );
        getdata();
    }
    // 2) getdata() function :
    void getdata() const
    {
        if (dozen >= 0 && units >= 0)
        {
            cout << " Dozens : " << dozen << " and Units : " << units << endl;
        }
    }
    // 2) setdata() function :
    void setdata(int d, int u)
    {
        if (u >= 0 && d >= 0)
        {
            if (u >= 12)
            {
                d = d + (u / 12);
                u = u % 12;
            }
            units = u;
            dozen = d;
        }
        else
        {
            cout << "Dozen and units cannot be negative ";
        }
    }

    // 3) show() function :
    void show() const
    {
        if (dozen > 0 && units > 0)
        {
            cout << dozen << " Dozens and " << units << " Units " << endl;
        }
        else if (dozen == 0 && units > 0)
        {
            cout << units << " Units " << endl;
        }
        else if (dozen > 0 && units == 0)
        {
            cout << dozen << " Dozen " << endl;
        }
        else
        {
            cout << "Negative values not allowed " << endl;
        }
    }

    // 4) Add function that takes two integers as parameters
    Dozen& add(int d, int u)
    {
        dozen += d;
        units += u;
        dozen += units / 12; //(In case total units become 12 or more or user enters more than 12 units)
        units = units % 12;  //(In case total units become 12 or more or user enters more than 12 units)
        return *this;
    }

    // 5) Add function that takes another Dozen object as parameter
    Dozen& add(Dozen &d)
    {
        dozen += d.dozen;
        units += d.units;
        dozen += units / 12; //(In case total units become 12 or more or user enters more than 12 units)
        units = units % 12; //(In case total units become 12 or more or user enters more than 12 units)
        return *this;}

    // 6) Subtract function that takes another Dozen object as parameter
    Dozen& subtract(Dozen &d)
    {
        if ((dozen - d.dozen) < 0 || (dozen == d.dozen && units < d.units))
        {
            cout << "Cannot Subtract : Insufficient Quantity " << endl;
        }
        else
        {
            if ((units - d.units) < 0)
            {
                units = units + 12 - d.units;
                dozen--;
                dozen -= d.dozen;
            }
            else
            {
                units = units - d.units;
                dozen -= d.dozen;
            }
        }
        return *this;
    }

    // 7) Compare function that takes another Dozen object as parameter
    int compare(Dozen &d2) const // Comparing with D2
    {
        if ((dozen == d2.dozen) && (units == d2.units))
        {
            return 1;
        }
        else if ((dozen > d2.dozen) || (dozen == d2.dozen && units > d2.units))
        {
            return 2;
        }
        else
        {
            return -1;
        }
    }

    // 8)
    void swap(Dozen &d)
    {
        int temp = dozen;
        dozen = d.dozen;
        d.dozen = temp;

        temp = units;
        units = d.units;
        d.units = temp;
    }

    // 9) Float conversion function that returns the equivalent float value
    float toFloat()
    {
        return (dozen + (units / 12.0));
    }

    // 10) Integer conversion function that returns the rounded integer value
    int round()
    {
        return toFloat();
    }

    // 11) Rough compare function that takes another Dozen object as parameter
    bool rough_compare(Dozen &d)
    {
        if ((dozen == d.dozen) && (units - 1 == d.units || units == d.units - 1)) //Difference of only 1 unit
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};
