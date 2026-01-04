#include <iostream>

using namespace std;

//We use another class separately from inheriting from any exception class
//We can use the attributes inside it as codes to show for specific error detection values
//One thing is that we need to write our own function like show() or other as we can't use the what() function virtual 
//We achieve almost similar results when we use composition here just like we did with inheriting the customized classes 

class StackEmptyException
{
    int val;
public:
    StackEmptyException(int v)
    {
        val = v;
    }
    void show()
    {
        cout << "Stack is empty : "<< val << "\n";
    }
};
class Stack
{
public:
    int top()
    {
        StackEmptyException se(-1);
        throw se;
    }
};
int main()
{
    Stack s;
    try
    {
        int x = s.top();
        cout << x * x << '\n';
    }
    catch(StackEmptyException& s)
    {
        s.show();
    }
    cout << "End of Program\n";
    return 0;
}
