#include <iostream>
#include <string>
#include "global.h"
#include "Money.h"

using namespace std;

Money::Money() {}


Money::Money(double amt, string cd)
{

    int ind = find_index(cd);

    if(ind>=0 && ind<=ARRAY_SIZE)
    {
        currency_code = ind;
    }
    //Else Part will not run as we are returning the code in find_index always 0 which is our default one and this is fine


    if(amount>=0)
    {
        amount = amt;
    }
    else
    {
        cout<<"Amount cannot be negative "<<endl;
    }
}

void Money::copy_from(const Money&M)
{
    amount = M.amount;
    currency_code =  M.currency_code;
}


Money::Money(const Money &M)
{
    copy_from(M);
}


Money& Money::operator=(const Money&M)
{
    if(this != &M)
    {
        copy_from(M);
    }
    return *this;
}


double Money::converter(const Money &M, int index)
{
    return (M.amount * (get_rate(index)));
}


double Money::converter_back(const Money &M, int index)
{
    return (M.amount / (get_rate(index)));
}


//Look for this CODE :
Money Money::operator+(const Money&M)
{
    // Convert both to a common currency (e.g USD) for calculation,
    // but return result in the original object's currency for which the function was called
    //E.g if we do total = salary + bonus , then total will be assigned salary's currency
    //E.g if we do salary = salary + bonus , then salary will be assigned salary's currency
    //E.g if we do total = bonus + salary , then salary will be assigned bonus' currency


    double curr_obj_amt = converter(*this, currency_code);
    double local_obj_amt = converter(M, M.currency_code);
    double sum;
    sum = curr_obj_amt + local_obj_amt;


    Money temp; //temp's currency already set to USD
    temp.amount = sum;

    if(currency_code != M.currency_code)
    {
        temp.currency_code = currency_code;
        temp.amount = converter_back( temp, temp.currency_code);
    }
    else
    {
        temp.currency_code = currency_code;
    }

    return temp;
}


Money Money::operator-(const Money&M)
{
    double curr_obj_amt = converter(*this, currency_code);
    double local_obj_amt = converter(M, M.currency_code);
    double diff;
    diff = curr_obj_amt - local_obj_amt;


    Money temp; //temp's currency already set to USD
    temp.amount = diff;

    if(currency_code != M.currency_code)
    {
        temp.currency_code = currency_code;
        temp.amount = converter_back( temp, temp.currency_code);
    }
    else
    {
        temp.currency_code = currency_code;
    }

    return temp;
}

//CODE DUPLICATION AVOIDED USING "this" POINTER
Money& Money::operator+=(const Money&M)
{
    *this = *this + M;
    return *this;
}

//PREFIX OPERATOR (CODE FOR += and + IS REUSED)
Money& Money::operator++()
{
    // 1. Create a temporary Money object representing 1 unit of the current currency.
    //    E.g., if *this is 100 PKR, this creates 1 PKR.
    Money one_unit;
    one_unit.amount = 1.0;
    one_unit.currency_code = this->currency_code;

    // 2. Use the existing += operator to add the 1 unit to the current object.
    *this += one_unit;

    // 3. Return a reference to the modified object.
    return *this;
}



//POSTFIX OPERATOR (CODE for PREFIX ++ or += and + IS RESUSED)
Money Money::operator++(int)
{

// 1. Create a copy of the current state BEFORE incrementing.

    Money original_value = *this;

    // 2. Perform the increment (by calling the prefix operator, or by reusing the += logic).
    //    Calling the prefix operator is the cleanest reuse strategy:

    ++(*this);

    // OR, by reusing += directly:
    // Money one_unit;
    // one_unit.amount = 1.0;
    // one_unit.currency_code = this->currency_code;

    // 3. Return the saved original value.

    return original_value;
}




Money& Money::operator-=(const Money&M)
{
    *this = *this - M;
    return *this;
}

//Only Check if they are same objects or not (Amount and Currencies must be same )
bool Money::operator==(const Money&M)
{
    if(amount == M.amount && currency_code == M.currency_code)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Now for != , < , > , <= , >= , we check if the amount is lesser , greater or not equal even if the currency is different
bool Money::operator!=(const Money&M)
{
    double curr_obj_amt = converter(*this, currency_code);
    double local_obj_amt = converter(M, M.currency_code);
    if(curr_obj_amt != local_obj_amt)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


bool Money::operator<=(const Money&M)
{
    double curr_obj_amt = converter(*this, currency_code);
    double local_obj_amt = converter(M, M.currency_code);
    if(curr_obj_amt <= local_obj_amt)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


bool Money::operator>=(const Money&M)
{
    double curr_obj_amt = converter(*this, currency_code);
    double local_obj_amt = converter(M, M.currency_code);
    if(curr_obj_amt >= local_obj_amt)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


bool Money::operator>(const Money&M)
{
    double curr_obj_amt = converter(*this, currency_code);
    double local_obj_amt = converter(M, M.currency_code);
    if(curr_obj_amt > local_obj_amt)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


bool Money::operator<(const Money&M)
{
    double curr_obj_amt = converter(*this, currency_code);
    double local_obj_amt = converter(M, M.currency_code);
    if(curr_obj_amt < local_obj_amt)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Money::display(string code)
{
    double temp_amt = converter(*this, currency_code);  //Convert Amount into USD

    int ind = find_index(code);

    Money temp ;
    temp.amount = temp_amt;
    temp.currency_code = ind; //Not necessary

    cout<<"Amount : "<<amount <<" in "<< code<<" is : "<<converter_back(temp, ind)<<endl;
}


