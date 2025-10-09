#include <iostream>

using namespace std;

class shop
{
private:
    //You may set the arrays here using dynamic memory allocations and then deallocate in the destructor of the class if you know the syntax and concept
    int item_id[100];
    int item_price[100];
    int counter;


public:
    void init_counter();
    void set_price();
    void display_price();
};
void shop::init_counter()
{
    counter=0;
}
void shop::set_price()
{
    cout<<"Enter Id of your item no "<<counter+1<<" : ";
    cin>>item_id[counter];
    cout<<"Enter Price of your item : ";
    cin>>item_price[counter];
    counter=counter+1;
}
void shop::display_price()
{
    for(   int i = 0 ; i<counter ; i++)
    {
        cout<<"The Price of your item no "<<item_id[i]<<" is "<<item_price[i]<<endl;
    }

}

int main()
{
    shop zstore;
    int j;
    cout<<"Enter the number of items you want to set id and price of : " ;
    cin>>j;
    zstore.init_counter();
    for(int l=1 ; l<=j ; l++ )
    {
        zstore.set_price();
    }

    zstore.display_price();
    return 0;
}
