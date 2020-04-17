#include <iostream>

using namespace std;

class complex
{
//friend void operator<<(ostream &out, complex &c1);
friend ostream &operator<<(ostream &out, complex &c1);
private:
    int a;
    int b;
public:
    complex(int a = 0, int b = 0)
    {
        this->a = a;
        this->b = b;
    }
    void printT()
    {
        cout<<a<<'+'<<b<<'i'<<endl;
    }
    complex operator+(complex &c2)
    {
        complex tmp(this->a + c2.a, this->b + c2.b);
        return tmp;
    }
    complex &operator++()//前置++
    {
        this->a++;
        this->b++;
        return *this;
    }
    complex operator++(int)//后置++
    {
        //先保存，再自加
        complex tmp = *this;
        this->a++;
        this->b++;
        return *this;

    }
    complex operator-(complex &c2)
    {
        complex tmp(this->a - c2.a, this->b - c2.b);
        return tmp;
    }
    complex &operator--()
    {
        this->a--;
        this->b--;
        return *this;
    }
    //后置--
    complex operator--(int)
    {
        complex tmp = *this;
        this->a--;
        this->b--;
        return tmp;
    }

};
//全局函数

ostream &operator<<(ostream &out, complex &c1)
{
    out<<c1.a<<"+"<<c1.b<<"i"<<endl;
    return out;
}

int main()
{

    complex c1(1, 2), c2(3, 4);
    cout<<c1<<"abc"<<endl;
    //友元函数重载左移操作符 cout.operator
    //NO.2 成员函数实现 cout.operator(c1),在cout类（osstream）中添加成员函数
//    cout.operator<<(c1);
//      由于ostream 无法得到源码，所以无法添加

    return 0;

}
