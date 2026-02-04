#pragma once
#include <iostream>
#include <string>
#include "Storage.h"

using namespace std;

template <class T, class S>
Storage<T, S>::Storage()
{
    i = 0;
}

template <class T, class S>
void Storage<T, S>::add(T a, S b)
{
    if (i >= 0 && i < 1000)
    {
        a1[i] = a;
        a2[i] = b;
        i++;
    }
}
template <class T, class S>
void Storage<T, S>::update(T a, S b)
{
    for (int index = 0; index < i; index++)
    {
        if (a1[index].name == a.name) // assuming T has 'name'
        {
            a2[index] = b;
            return;
        }
    }
}

template <class T, class S>
S &Storage<T, S>::get(T a)
{
    for (int index = 0; index < i; index++)
    {
        if (a1[index].name == a.name)
            return a2[index];
    }
    cout << "Key not found";
}

template <class T, class S>
bool Storage<T, S>::exists(T a)
{
    for (int index = 0; index < i; index++)
    {
        if (a1[index].name == a.name)
            return true;
    }
    return false;
}

template <class T, class S>
void Storage<T, S>::remove(T a)
{
    for (int index = 0; index < i; index++)
    {
        if (a1[index].name == a.name)
        {
            // shift remaining elements left
            for (int j = index; j < i - 1; j++)
            {
                a1[j] = a1[j + 1];
                a2[j] = a2[j + 1];
            }
            i--;
            return;
        }
    }
}

template <class T, class S>
T &Storage<T, S>::minkey()
{
    if (i == 0)
        throw runtime_error("Storage empty");

    int minIndex = 0;
    for (int index = 1; index < i; index++)
    {
        if (a1[index] < a1[minIndex]) // now uses operator<
            minIndex = index;
    }
    return a1[minIndex];
}

template <class T, class S>
void Storage<T, S>::printall()
{
    for (int index = 0; index < i; index++)
        cout << a1[index].name << " -> " << a2[index].name << endl;
}
