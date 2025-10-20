#include <iostream>

using namespace std;

class ShopItem
{

private:
    int id;
    float price;

public :
    void setdata(int,int);
    void getdata();


};
void ShopItem::setdata(int a, int b)
{
    id=a;
    price=b;
}

void ShopItem::getdata()
{
    cout<<"The Code of this item is : "<<id<<endl;
    cout<<"The Price of this item is : "<<price<<endl;
}

int main()
{

    int size = 3 ;
    int i, p;
    float q;
    //int *ptr  =  &size;        //
    //int *ptr  =   new int[34];  //
    ShopItem *ptr = new ShopItem[size];   //Makes a dynamic object in the form of array. A pointer of class Shopitem points to a dynamic memory in Shopitem to an array of 3 objects.
    //ptr[0].id = 2;  //We can initialize dynamic objects in the form of array like this.


    // ShopItem *ptrtemp = ptr;  // A Way of making two pointers pointing to exact same location


    ShopItem *ptrtemp;   //This is not pointer to pointer referencing .This is just to equal both pointers
    ptrtemp = ptr;  // This will make first pointer exactly as 2nd pointer before the first loop , so we have the old values.

    for( i = 0 ; i<size  ; i++  )
    {
        cout<<endl;
        cout<<"Enter ID of the item no "<<i+1 << " : ";
        cin>>p;
        cout<<"Enter Price of the item : ";
        cin>>q;
        ptr->setdata(p,q);   //This is equivalent to (*ptr).setdata(p,q);  or (ptr[i]).setdata(p,q) , Don't use ptr++ or ptr-- if using ptr[i].setdata()
        ptr++;
    }
    cout<<endl;
    cout<<"------------------------------";
    cout<<endl;


    /*
    //This method is for when we do this from only one pointer to a dynamic object array
    //This will print the codes and prices in reverse order. (not a good idea ) , because after first for loop , our ptr is pointing to the next memory location after the previous required value
     for(int i = 2 ; i>=0 ; i--  )
     {
         ptr--;
         cout<<"Item Number  : "<<(i+1)<<endl;


         ptr->getdata();  //This is equivalent to (*ptr).getdata();

     }
     */



    //This method is for when we do this from two pointers . One will be same and other will point to the first pointer.
    //This method will print the codes and prices in normal order.
    for(int i = 0 ; i<size ; i++  )
    {

        cout<<"Item Number  : "<<(i+1)<<endl;


        ptrtemp->getdata();  //This is equivalent to (*ptrtemp).getdata();   or (ptr[i]).getdata()
        ptrtemp++;

    }


    ptr = ptr - size;

    // ptrtemp = ptrtemp - size; This is also not necessary as ptrtemp is at a place beyond our objects and we have  freed up the space allocated by them so we will just set ptrtemp to nullptr so that it will point to non-valid memory instead of becoming a dangling pointer. This ptrtemp here already points to a non-valid memory location and setting it to nullptr will not change this but now it will not be a dangling pointer
    delete[] ptr; // Either this or delete [] ptrtemp as we only need to free the memory location


    ptr = nullptr;

    // delete ptrtemp ;  As the memory location is already freed so we don't need to use delete again with ptrtemp . otherwise , it will cause error
    ptrtemp = nullptr;


    // This can also be done by using ptr[i].setdata or getdata() and ptr[i] does not change the base location of ptr so we don't need to use ptr = ptr - size (index of array) for this
    return 0;
}












