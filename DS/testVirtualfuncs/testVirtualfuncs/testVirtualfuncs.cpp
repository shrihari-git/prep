// testVirtualfuncs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class animal {
public:
    void run() { cout << "Animal running" << endl; }
    virtual void talk() { cout << "Animal talking" << endl; }
    void sleep() { cout << "Animal sleeping" << endl; }
};

class dog:public animal {
public:
    void run() { cout << "Dog running" << endl; }
    void talk() { cout << "Dog talking" << endl; }
};


int main()
{
    animal* a = new dog();
    dog* d = new dog();
    a->run();
    a->talk();
    a->sleep();
    d->run();
    d->talk();
    d->sleep();
    getchar();
    return 0;
}

