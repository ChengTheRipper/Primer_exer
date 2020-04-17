#pragma once
#include <iostream>

using namespace std;

template<typename T>
class B : public A<T>
{

public:
    B(T x) : A<T>(x)
    {
        this->x = x;
    }
    friend ostream& operator<< (ostream &out, B& b1)
    {
        cout<<b1.x<<endl;
    }
private:
    T x;
};



