#include <iostream>
#include "Vector.h"
#include "Vector.cpp"
using namespace std;

int main()
{
    Vector v;
    v.PUSH_BACK(10) ;
    v.PUSH_BACK(5);
    v.PUSH_BACK(30);

    v.PUSH_BACK(2);
    cout<<"Vector Elements are : "<<endl;
    v.display();
    cout<<"Size : "<<v.SIZE()<<endl;
    cout<<" IS EMPTY : "<<v.isEmpty()<<endl;
    cout<<"Element at index 2 : "<<v.get(2)<<endl;
    v.set(1,15);
    cout<<"After set operation : "<<endl;
    v.display();
    cout<<"Minimum Element : "<<v.minElement()<<endl;
    cout<<"Maximum Element : "<<v.maxElement()<<endl;
    v.POP_BACK();
    cout<<"After Pop Back : "<<endl;
    v.display();

    return 0;
}
