#include <iostream>
#include <string>
#include "Finance.h"
#include "class.h"
#include "global.h"

using namespace std;

int Finance::count_ss = 0;

//Finance::Finance() {} //Will Create Ambiguity on declaration if below one is not used with overwritten parameters

Finance::Finance(int id  = 0, double total = 0, double paid= 0)
{
    remainingfee = 0;
    scholarshipstatus = false;
    if(id>=0)
    {
        StudentID = id;
    }
    if(totalfee>= 0)
    {
        totalfee = total;
    }
    if(paid >= 0 )
    {
        paidfee = paid;
    }
    remainingfee = totalfee - paidfee;
}

void Finance::displayfinance() const
{
    cout<<"Finances : "<<endl;
    cout<<"Student ID : "<<StudentID<<endl;
    cout<<"Total Fee : "<<totalfee<<endl;
    cout<<"Paid Fee : "<<paidfee<<endl;
    cout<<"Remaining Fee : "<<remainingfee<<endl;
    cout<<"Scholarship Status : "<<scholarshipstatus<<endl;
}

int Finance::get_sc_count()
{
    return count_ss;
}


//Will be called when dynamically allocated object is deleted
Finance::~Finance()
{

}
