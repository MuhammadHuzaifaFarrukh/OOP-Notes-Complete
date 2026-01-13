#include <iostream>
#include "MyString.h"
#include <cstring>

using namespace std;

MyString::MyString()
{
    size = 0;
    str = new char[1];
    str[0] = '\0';
}

MyString ::MyString(int x, const char *s)
{
    if (x >= 0 || x < strlen(s))
    {
        size = x;
    }
    else // if x is negative , as Size cannot be negative
    {
        size = strlen(s);
    }

    str = new char[size + 1];
    for (int i = 0; i < size; i++)
    {
        str[i] = s[i];
    }
    str[size] = '\0';
}

MyString ::MyString(const MyString &other)
{
    size = other.size;
    str = new char[size + 1];
    for (int i = 0; i < other.size; i++)
    {
        str[i] = other.str[i];
    }
    str[size] = '\0';
}

MyString::~MyString()
{
    delete[] str;
    str = nullptr;
}

MyString MyString::negate()
{
    MyString temp = *this;
    for (int i = 0; i < size; i++)
    {
        if (temp.str[i] >= 'A' && temp.str[i] <= 'Z')
            temp.str[i] += 32;
        else if (temp.str[i] >= 'a' && temp.str[i] <= 'z')
            temp.str[i] -= 32;
    }
    return temp;
}

MyString MyString::remove_substr(char *x)
{
    int subLen = 0;

    // manually find substring length
    while (x[subLen] != '\0')
        subLen++;

    // if substring empty → return copy
    if (subLen == 0)
        return MyString(*this);

    // create a temp array large enough
    char *out = new char[size + 1];
    int outIndex = 0;

    for (int i = 0; i < size;)
    {
        // try matching substring manually
        bool match = true;

        for (int j = 0; j < subLen; j++)
        {
            if (i + j >= size || str[i + j] != x[j])
            {
                match = false;
                break;
            }
        }

        if (match)
        {
            // skip the substring
            i += subLen;
        }
        else
        {
            out[outIndex++] = str[i];
            i++;
        }
    }

    out[outIndex] = '\0';

    MyString result(outIndex, out);

    delete[] out;

    return result;
}

bool MyString ::palindrome()
{
    int count = 0;
    for (int i = 0; i < size / 2; i++)
    {
        if (str[i] != str[size - 1 - i])
        {
            return false;
        }
    }
    return true;
}

/*
bool MyString::anagram(MyString x)
{
    if (size != x.size)
        return false;

    // manual frequency arrays
    int freq1[256] = {0};
    int freq2[256] = {0};

    // count chars in this->str
    for (int i = 0; i < size; i++)
        freq1[(unsigned char)str[i]]++;

    // count chars in x.str
    for (int i = 0; i < x.size; i++)
        freq2[(unsigned char)x.str[i]]++;

    // compare both freq arrays
    for (int i = 0; i < 256; i++)
    {
        if (freq1[i] != freq2[i])
            return false;
    }

    return true;
}
*/

// Alternative simpler but less efficient method
bool MyString::anagram(MyString x)
{
    if (size != x.size)
        return false;

    for (int i = 0; i < size; i++)
    {
        bool found = false;

        for (int j = 0; j < size; j++)
        {
            if (str[i] == x.str[j])
            {
                x.str[j] = '#';  // mark as used
                found = true;
                break;           // stop searching
            }
        }

        if (!found)
            return false;  // this character has no match
    }

    return true;  // all characters matched
}

MyString MyString::operator+(const MyString &obj)
{
    MyString temp;
    temp.size = size + obj.size;
    temp.str = new char[temp.size + 1];

    int i = 0;
    for (; i < size; i++)
        temp.str[i] = str[i];

    for (int j = 0; j < obj.size; j++, i++)
        temp.str[i] = obj.str[j];

    temp.str[temp.size] = '\0';
    return temp;
}

MyString MyString::addLargeEqual(const MyString &other)
{
    int max_len = (size > other.size) ? size : other.size;

    MyString temp;
    temp.size = max_len;
    temp.str = new char[max_len + 1];

    int carry = 0;
    int i = size - 1;
    int j = other.size - 1;
    int k = max_len - 1;

    while (k >= 0)
    {
        int digit1 = (i >= 0) ? str[i] - '0' : 0;
        int digit2 = (j >= 0) ? other.str[j] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        temp.str[k] = (sum % 10) + '0';
        carry = sum / 10;

        i--;
        j--;
        k--;
    }

    if (carry > 0)
    {
        delete[] temp.str; // size exceeded, return "0"
        temp.size = 1;
        temp.str = new char[2];
        temp.str[0] = '0';
        temp.str[1] = '\0';
    }
    else
    {
        temp.str[temp.size] = '\0';
    }

    return temp;
}

MyString MyString::addLargeExtend(const MyString &other)
{
    // Determine the maximum size between the two strings
    int max_len = (size > other.size) ? size : other.size;

    // Allocate temp string with max_len + 1 to account for possible carry
    MyString temp;
    temp.size = max_len;
    temp.str = new char[max_len + 2]; // +1 for possible carry, +1 for '\0'

    int carry = 0;
    int i = size - 1;
    int j = other.size - 1;
    int k = max_len - 1;

    // Add digits from right to left
    while (k >= 0)
    {
        int digit1 = (i >= 0) ? str[i] - '0' : 0;
        int digit2 = (j >= 0) ? other.str[j] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        temp.str[k] = (sum % 10) + '0';
        carry = sum / 10;

        i--;
        j--;
        k--;
    }

    // If there is leftover carry, shift digits right and add carry at front
    if (carry > 0)
    {
        for (int m = temp.size; m > 0; m--)
            temp.str[m] = temp.str[m - 1];

        temp.str[0] = carry + '0';
        temp.size += 1;
    }

    // Null-terminate the string
    temp.str[temp.size] = '\0';

    return temp;
}

void MyString ::show() const
{
    for (int i = 0; i < size; i++)
    {
        cout << str[i];
    }
    cout << endl;
}
