//#pragma once //只包含一次 和下面的相等

//#ifndef TEACHERCLASS_H__
//#define TEACHERCLASS_H__
//
//
//
//
//
//
//
//
//
//
//
//
//
//#endif // TEACHERCLASS_H__
//statement of the class
#pragma once

class MyTeacher
{
private:
    int m_age;
    char m_name[32];

public :
    void setAge(int t_age);
    int  getAge();
};
