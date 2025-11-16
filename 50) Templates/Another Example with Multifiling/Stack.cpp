#include <iostream>
#include "Stack.h"

using namespace std;

template <class T>
Stack<T> :: Stack(int s)
{
    size = s;
    p = 0;
    x = new T[size];
}

template <class T>
void Stack<T>::push(T element)
{
    if (p < size)	x[p++] = element;

}

template <class T>
T Stack<T> :: top() const
{
    return x[p-1];
}

template <class T>
void Stack<T> :: pop()
{
    if (p > 0)	p--;
}

template <class T>
Stack<T>::~Stack()
{
    delete[]x;
}
