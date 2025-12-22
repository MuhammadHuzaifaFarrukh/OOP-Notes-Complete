#include <iostream>
#include<string>

using namespace std;
//Making an Abstract base class to a base class :
class StGamer
{
protected :
    string title;
    float rating;

public :
    //   StGamer(){} //Required if not initialized object in first line (Blank Constructor)
    StGamer(string, float);
    virtual void display()=0;  //It is a pure virtual function which says that if used , then it must be redefined in other derived classes which also violates the creation rule of virtual class .If we leave any one not redefine then it will throw error
    //Also the class where we make pure virtual functions cannot have any instances
    //Only objects not allowed , we can make its pointers , addresses , references etc


    //A class having at least one pure virtual function in base class is called an abstract base class
};
StGamer::StGamer(string t, float r)
{
    title = t;
    rating = r;
}


class StGamerVids : public StGamer
{
public :
    int vid_length;
    StGamerVids(int, string, float ) ;
    // StGamerVids(){}            //Required for blank constructor

    void display()
    {
        cout<<"The Title of the Video is  : "<<title<<endl;
        cout<<"The Length of the Video is  : "<<vid_length<<" minutes "<<endl;
        cout<<"The Rating of the Video is  : "<<rating<<endl<<endl;
    }

};

StGamerVids::StGamerVids(int vL, string t, float r ) : StGamer(t,r)    //Defining Constructor outside of class with initialization list and declare without initialization list in class
{
    vid_length=vL;
}






class StGamerWeb : public StGamer
{
public :
    int words;
    StGamerWeb(int txt, string t, float r) : StGamer(t,r)
    {
        words = txt;
    }
    // StGamerWeb(){}            //Required for blank constructor
    void display()
    {
        cout<<"The Title of the Video is  : "<<title<<endl;
        cout<<"The Words of the Text Tutorial is  : "<<words<<" words "<<endl;
        cout<<"The Rating of the Video is  : "<<rating<<endl<<endl;
    }
};



int main()
{
    string title;
    float rating;
    int vL;
    int words;

    //For Video
    title = "Sonic.exe";
    rating = 4;    //Considering it to be out of 5 star
    vL = 7;
    StGamerVids gamer1(vL,title,rating);

    gamer1.display();

    //For Text :
    title = "Sonic.exe";
    rating = 2.5f;    //Considering it to be out of 5 star
    words = 500;
    StGamerWeb gamer2(words, title, rating);
    gamer2.display();
    //Till here , there will be no problem even without virtual function

    //Now using pointers to check our virtual function .
    StGamer *tuts[2];   // Making an array of type StGamer with only 2 pointers , allowed as it stores addresses not objects
    tuts[0] = &gamer1;  //This pointer points to first object. You cannot write it like normal array of objects being pointed like tut = &gamer1. but here there are pointers in the array so writing tut[0] gives us first pointer and *tut[0] will give the value pointed by it
    tuts[1] = &gamer2;  //This pointer points to 2nd object

    //The Real Runtime Polymorphism happens here
    (*tuts[0]).display(); //This line is equivalent to tuts[1]->display();
    (*tuts[1]).display();



    return 0;
}









/*
//Making an Abstract base class to a derived class :
class A
{

public :
     void say()
    {
        cout<<"I am an Animal"<<endl;
    }
};

class B : public A
{
    public :
      virtual void say()=0; // Will not allow the objects of this class because it is a derived class and this pure virtual function should never be used on a derived class


};

class C : public B
{
    public :
    void say()
    {
        cout<<"I am a Cat"<<endl;
    }

};

int main()
{
    A *ptr_a;
    C c1;
//    B b1;// Creates error as we cannot make an object because the abstract base class is the derived class B.
    A a1;
    ptr_a = &c1;
    (*ptr_a).say();

    B * ptr_b; //Allowed as it is a pointer not object
    ptr_b=&c1;
    (*ptr_b).say();

    return 0;
}

*/
