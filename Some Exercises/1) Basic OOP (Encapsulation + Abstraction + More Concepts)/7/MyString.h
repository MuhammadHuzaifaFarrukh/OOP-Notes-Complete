#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
    int size;
    char *str;

public:
    MyString();
    MyString(int x, const char *s);
    MyString(const MyString &other);
    ~MyString();

    MyString negate();
    MyString remove_substr(char *x);
    bool palindrome();
    bool anagram(MyString x);

    MyString operator+(const MyString &obj);
    MyString addLargeEqual(const MyString &other);
    MyString addLargeExtend(const MyString &other);

    void show()const ;
};