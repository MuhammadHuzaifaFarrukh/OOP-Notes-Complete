#pragma once
#include <iostream>
#include "Vector.h"
using namespace std;


    Vector::Vector()
    {
        capacity = 2;
        arr = new int[capacity];
        size = 0;
    }
    void Vector::PUSH_BACK(int x)
    {
        expand();
        arr[size] = x;
        size++;
    }
    void Vector::POP_BACK()
    {
        if (arr == nullptr || size == 0)
        {
            cout << "Vector is already empty" << endl;
        }
        size--;
    }
    int Vector::get(int ind)
    {
        if (ind < 0 || ind >= size)
        {
            cout << "Invalid Index" << endl;
        }
        return arr[ind];
    }
    void Vector::set(int i, int x)
    {
        if (i < 0 || i >= size)
        {
            cout << "Invalid Index" << endl;
        }
        arr[i] = x;
    }
    int Vector::SIZE()
    {
        return size;
    }
    bool Vector::isEmpty()
    {
        if (size != 0)
        {
            return 0;
        }
        return 1;
    }
    int Vector::minElement()
    {
        int x = arr[0];
        for (int i = 1; i < size; i++)
        {
            if (arr[i] < x)
            {
                x = arr[i];
            }
        }
        return x;
    }
    int Vector::maxElement()
    {
        int x = arr[0];
        for (int i = 1; i < size; i++)
        {
            if (arr[i] > x)
            {
                x = arr[i];
            }
        }
        return x;
    }
    void Vector::display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void Vector::expand()
    {
        if (size == capacity)
        {
            capacity *= 2;
            int *temp = new int[capacity];
            for (int i = 0; i < size; i++)
            {
                temp[i] = arr[i];
            }
            delete arr;
            arr = temp;
        }
    }
    Vector::~Vector()
    {
        delete[] arr;
    }
