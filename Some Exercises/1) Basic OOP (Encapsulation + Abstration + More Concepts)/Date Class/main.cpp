#include <iostream>
#include "Date.h"
#include "Date.cpp"
using namespace std;

int main()
{
    int n;
    cout << "Enter how many dates you want to enter : ";
    cin >> n;
    while (n <= 0)
    {
        cout << "Enter positive number please : ";
        cin >> n;
    }
    Date *d = new Date[n];

    // Input for all the Dates :
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Enter the day month and year for Date index " << i << " : "<<endl;
        cin >> x;
        d[i].SetDay(x);
        cin >> x;
        d[i].SetMonth(x);
        cin >> x;
        d[i].SetYear(x);
    }

    // Displaying all the Dates :
    for (int i = 0; i < n; i++)
    {
        cout << "Current Date at index : " << i << endl;
        d[i].displayDate();
    }

    cout << "Number of Days you want to Add : ";
    cin >> n;
    d[0].addDays(n);

    d[0].displayDate();

    cout << "Number of Days you want to Subtract : ";
    cin >> n;
    d[0].subtractDays(n);
    d[0].displayDate();

    delete[] d;

    return 0;
}
