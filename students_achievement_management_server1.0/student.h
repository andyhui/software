#include <iostream>
#include <string.h>
#include <stdio.h>
#include <mysql.h>

using namespace std;

#define MAXLEN 1024

class student{
    int student_id;
    string student_name;
    string student_sex;
    string student_class;
    string birthday;
    

public:

//    int modifyEmailInfo();  //修改邮箱信息
    int selectCourse(MYSQL* mysql, int cid, student stu);     //选课
    int deleteCourse(MYSQL* mysql, int cid, student stu);     //退课
    MYSQL_RES* veiwCourse(MYSQL* mysql, student stu);       //课程查询
    MYSQL_RES* queryScore(MYSQL* mysql, student stu, int cid, int hid);  //成绩查询，无参数查询所有课程所有作业成绩；1个参数表示课程ID，查询课程所有作业成绩；2个参数表示查询固定课程固定作业成绩
    
    
    int getStudent_id()
    {
        return student_id;
    }
    void setStudent_id(int id)
    {
        student_id = id;
    }
        
    string getStudent_name()
    {
        return student_name;
    }
    void setStudent_name(string name)
    {
        student_name = name;
    }
        
    string getStudent_sex()
    {
        return student_sex;
    }
    void setStudent_sex(string sex)
    {
        student_sex = sex;
    }
        
    string getStudent_class()
    {
        return student_class;
    }
    void setStudent_class(string cl)
    {
        student_class = cl;
    }
        
    string getStudent_birth()
    {
        return birthday;
    }
    void setStudent_birth(string birth)
    {
        birthday = birth;
    }
};        
        
        
