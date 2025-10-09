#include <iostream>
#include <string>
using namespace std;
class binary
{
private:
    string s;


public:
    void read();
    void ones_compliment();
    void chk_bin();
    void display();
};
void binary::read()
{
    cout<<"Enter a binary number: ";
    getline(cin,s);

}
void binary::chk_bin()
{
    for(int i=0 ; i<s.length() ; i++)
    {
        if(s.at(i)!='0' && s.at(i)!='1' )
        {
            cout<<"Not a Binary Number";
            exit(0);
        }
    }
}
void binary::ones_compliment()
{
    chk_bin();
    for(int i=0 ; i<s.length() ; i++)
    {
        if(s.at(i)=='0')
        {
            s.at(i)='1';
        }
        else if(s.at(i)=='1')
        {
            s.at(i)='0';
        }
    }
}
void binary::display()
{
    for(int i=0 ; i<s.length() ; i++)
    {
        cout<<s.at(i);
    }
}


int main()
{
    binary b;
    b.read();
    //b.chk_bin();
    b.ones_compliment();
    b.display();

    return 0;
}
