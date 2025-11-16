#include <iostream>
#include "Stack.h"
#include "Stack.cpp"
#include "Point.cpp"
#include "Point.h"
#include "global.h"
#include "global.cpp"

using namespace std;
int main()
{
    Stack<int> stack;
    stack.push(35);
    stack.push(48);
    stack.push(18);
    stack.push(26);
    cout << stack.top() << '\n';
    stack.pop();
    cout << stack.top() << '\n';
    stack.push(100);
    cout << stack.top() << '\n';
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.push(70);
    stack.push(80);
    stack.push(90);
    cout << stack.top() << '\n';
    Stack<Point> stackP;
    stackP.push(Point(3,4));
    stackP.push(Point(2,1));
    stackP.push(Point(3,7));
    stackP.push(Point(6,4));
    cout << stackP.top() << '\n';
    stackP.pop();
    cout << stackP.top() << '\n';
    return 0;
}





