//: C07:MemTest.cpp
// Testing the Mem class
//{L} Mem
#include "Mem.h"
#include <cstring>
#include <iostream>

using namespace std;

class MyString
{
    Mem *buf;

public:
    MyString();
    MyString(const char *str);
    ~MyString();
    void concat(const char *str);
    void print(ostream &os);
};

MyString::MyString() { buf = 0; }

MyString::MyString(const char *str)
{
    buf = new Mem(strlen(str) + 1);
    strcpy((char *)buf->pointer(), str);
}

void MyString::concat(const char *str)
{
    if (!buf)
        buf = new Mem;
    strcat((char *)buf->pointer(
               buf->msize() + strlen(str) + 1),
           str);
}

void MyString::print(ostream &os)
{
    if (!buf)
        return;
    os << buf->pointer() << endl;
}

MyString::~MyString() { delete buf; }

int main()
{
    MyString s("My test string");
    s.print(cout);
    s.concat(" some additional stuff");
    s.print(cout);
    MyString s2;
    s2.concat("Using default constructor");
    s2.print(cout);
} ///:~

/**
 * The problem occurs when you have a pointer to mem
 * and mem changes it's location via ensureMinSize();
 * I added *& before pointer(), and this will give a pointer
 * reference to the location of mem instead of where it is
 * pointing at.
*/
