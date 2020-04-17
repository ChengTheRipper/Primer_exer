#pragma once
//#include <iostream>
//#include <string.h>
using namespace std;



template<typename T>
class A
{
public:
    A(T num)
    {
        this->num = num;
    }
    T& getnum()
    {
        return num;
    }
    T printNUM();

private:
    T num;
};

template<class T>
T A<T>::printNUM()
{
    cout<<num<<" is the num."<<endl;
}

