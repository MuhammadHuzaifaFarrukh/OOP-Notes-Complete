#include "global.h"

using namespace std;

//We can declare and define these all in the class.h and class.cpp files but that would be a poor design

//Global Variables & Arrays (Definition)
const int ARRAY_SIZE = 4;
string currency[ARRAY_SIZE] = {"USD" , "PKR" , "EUR", "GBP"};
double rates[ARRAY_SIZE] = {1,1/280.0, 1.1 , 1.25 }; // 1PKR = 1/280$ , 1EUR = 1.1$ , 1GBP = 1.25 $


//Global Functions (Definition)
unsigned int find_index(string code)
{
    for(int i = 0 ; i< ARRAY_SIZE ;i++)
    {
        if(currency[i] == code)
        {
            return i;
        }
    }

    cout<<"Code is Invalid , Default Code USD "<<endl;
    return 0; //For Invalid Code , our default is USD so we make sure no other currency is returned if code is invalid and default is set only

}


double get_rate(unsigned int index)
{
    if(index >=0 && index <=ARRAY_SIZE)
    {
        return (rates[index]);
    }
    else
    {
        cout<<"Invalid Index"<<endl;
        return -1;
    }
}
