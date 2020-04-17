#include <cstdlib>
#include <iostream>
#include <string.h>
#include <set>
#include <vector>
#include <random>
#include <stdlib.h>
#include <algorithm>
using namespace std;


class Test
{
public:
	Test(int a=0, int b=0)
	{
		this->a = a;
		this->b = b;
		cout << "Test 构造函数执行" << "a:" << a << " b: " << b << endl;
	}
	void printT()
	{
		cout << "a:" << a << " b: " << b << endl;
	}
	~Test()
	{
		cout << "Test 析构函数执行" << "a:" << a << " b: " << b << endl;
	}
private:
	int a;
	int b;
};



int main1()
{
    int iarray[] = {233,999,6,3,5,6,9};
    vector<int> vecint(3, 9);

    vecint.assign(iarray, iarray + 3);

    vecint.push_back(1);
    vecint.push_back(iarray[4]);



    cout<<"first component of the Vec."<<vecint.front()<<endl;
    cout<<"l c of the vec "<<vecint.back()<<endl;

    vector<int> vecB(10, 0);

    vecB.insert(vecB.begin(),vecint.begin(),vecint.end());

    for(vector<int>::iterator it = vecB.begin();it != vecB.end(); )
    {
        if(*it == 0)
            it = vecB.erase(it);
        else
            it++;

    }
    cout<<vecB.size()<<endl;

    for(vector<int>::iterator it = vecB.begin();it != vecB.end(); it++)
    {
        cout<<*it<<endl;
    }
	return 1;
}


class student
{
public:
    student(int id, string name)
    {
        this->id = id;
        this->name = name;
    }
    void printT () const
    {
        cout<<"id:"<<id<<"  "<<"name:"<<name<<endl;
    }
    int getID () const
    {
        return id;
    }
private:
//public:
    int id;
    string name;
};


struct Cgreater
{
    bool operator()(const student& c1, const student& c2)
    {
        if(c1.getID() < c2.getID())
            return true;
        else
            return false;

    }
};



int main2()
{
    set<student, Cgreater> s1;
//    s1.insert(student(3, "aa"));
//    s1.insert(student(5, "bb"));
//    s1.insert(student(7, "cc"));
//    s1.insert(student(9, "dd"));

    student a1(3, "aa");
    student a2(5, "bb");
    student a3(7, "cc");
    student a4(9, "dd");
    s1.insert(a1);
    s1.insert(a2);
    s1.insert(a3);
    s1.insert(a4);

    a1.printT();



//    for(set<student, Cgreater>::iterator it = s1.begin();it != s1.end();it++)
//    {
//        it->printT();
//    }
    set<student, Cgreater>::iterator it = s1.find(a1);
    it->printT();

    pair<set<student, Cgreater>::iterator, set<student, Cgreater>::iterator> pair1 = s1.equal_range(a3);

    pair1.first->printT();
    pair1.second->printT();

    it = s1.lower_bound(a3);

    it->printT();

}

#include <map>
int main3()
{
    map<int, string> m1;
    m1.insert(pair<int, string>(1, "NO.1"));
    m1.insert(pair<int, string>(2, "NO.2"));
    m1.insert(pair<int, string>(3, "NO.3"));
    m1.insert(pair<int, string>(4, "NO.4"));

    for(map<int, string>::iterator it = m1.begin(); it != m1.end(); it++)
    {
        pair<int, string> p = *it;
        cout<<p.first<<p.second<<endl;
    }
    map<int, string> mapA;
    mapA.insert(pair<int,string>(3,"小张"));
    mapA.insert(pair<int,string>(1,"小杨"));
    mapA.insert(pair<int,string>(7,"小赵"));
    mapA.insert(pair<int,string>(5,"小王"));
    m1.swap(mapA);
    for(map<int, string>::iterator it = m1.begin(); it != m1.end(); it++)
    {
        pair<int, string> p = *it;
        cout<<p.first<<p.second<<endl;
    }

    m1.insert(pair<int, string>(10086, "peter"));
    map<int, string>::iterator it = m1.find(10086);
    pair<int, string> p = *it;
    cout<<p.first<<p.second<<endl;




}


template<class T>
class Isdiv
{
public:
    Isdiv(const T& divisor)
    {
        this->divisor = divisor;
    }
    bool operator()(T& t)
    {
        return (t % divisor == 0);
    }
private:
    T divisor;
};

int main5()
{
	vector<int> v2;
	for(int i = 10; i < 33; i++)
    {
        v2.push_back(i);
    }
    int a = 4;

    vector<int>::iterator it;
    Isdiv<int> mydiv(a);

    it = find_if(v2.begin(), v2.end(), mydiv);
    if(it != v2.end())
    {
        cout<<"the first number divisible by 4\t is"<<*it<<endl;
    }
    else
        cout<<"number not found"<<endl;
}


template<class T>
struct SumAdd
{
    T operator()(T &t1, T &t2)
    {
        return (t1 + t2);
    }
};

template<class T>
void printE(T &t)
{
    for(vector<int>::iterator it = t.begin();it != t.end(); it++)
    {
        cout<<*it<<" ";
    }
}


int main11()
{
    vector<int> v1, v2;
    vector<int> v3(10, 4);

    v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(6);



	vector<int>::iterator it = transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), SumAdd<int>());
	cout<<*it<<endl;
	printE(v3);


}



void printT(int& t)
{
    cout<<t<<' ';
}


bool MyCompare(const int& a, const int &b)
{
    return(a < b);
}


int main7()
{
    vector<int> v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(rand() % 100);
    }
    for_each(v.begin(), v.end(), printT);
    cout<<endl;
    sort(v.begin(), v.end(), MyCompare);
    cout<<endl;
    for_each(v.begin(), v.end(), printT);
}


#include <functional>

int main8()
{


    plus<int> intadd;

    int x = 3;
    int y = 4;

    int z = intadd(x, y);
    cout<<z<<endl;

    plus<string> stringadd;

    string s1 = "aaa";
    string s2 = "bbb";

    string s3 = stringadd(s1, s2);

    cout<<s3<<endl;

    vector<int> v1;

    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    negate<int> negateV;

    cout<<negateV(5)<<endl;

    for_each(v1.begin(), v1.end(), negateV);
    for_each(v1.begin(), v1.end(), printT);



}


int main44()
{
    vector<string> v1;
    v1.push_back("bbb");
	v1.push_back("aaa");
	v1.push_back("ccc");
	v1.push_back("zzzz");
	v1.push_back("ccc");

	string s1 = "ccc";

	int num = count_if(v1.begin(), v1.end(), bind2nd(equal_to<string>(), s1));//

	cout<<num<<endl;

}



class IsGreat
{
public:
    IsGreat(int i)
    {
        m_num = i;

    }
    bool operator()(int &num)
    {
        if(num > m_num)
        {
            return true;
        }
        return false;
    }
private:
    int m_num;
};
int main66()
{
    vector<int> v1;
    for(int i = 0; i < 5; i++)
    {
        v1.push_back(i + 1);
    }

    for_each(v1.begin(),v1.end(), printT);
    cout<<endl;

    int num1 = count(v1.begin(), v1.end(), 3);
    cout<<"num1: "<<num1<<endl;

    int num2 = count_if(v1.begin(), v1.end(), IsGreat(2));
    cout<<"num2: "<<num2<<endl;

    int num3 = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(), 2));
    cout<<"num3: "<<num3<<endl;

    int num4 = count_if(v1.begin(), v1.end(), bind2nd(modulus<int>(), 2));
    cout<<"num4: odd number"<<num4<<endl;

    int num5 = count_if(v1.begin(), v1.end(), not1(bind2nd(modulus<int>(), 2)));
    cout<<"num5: even number"<<num5<<endl;

    return 1;


}


