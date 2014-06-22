#include <iostream>
#include <mysql/mysql.h>

using namespace std;

class administrator
{

public:
   int admin_id;
   string admin_name;

//   administrator();
//   administrator(int a_id,string a_name):admin_id(a_id),admin_name(a_name){}
 //  ~administrator(){}

//   void arrange_homework(int class_id);
   int del_student(MYSQL* mysql, int student_id);
   int add_student(MYSQL* mysql, int student_id,char* name,char* student_sex,char*
		   student_class,char* student_birthday);
   int del_teacher(MYSQL* mysql, int teacher_id);
   int add_teacher(MYSQL* mysql, int teacher_id,char* name,char* teach_sex,char*
		   teacher_phone,char* teacher_title,char*
		   teacher_department,char* birthday);
   int del_course(MYSQL* mysql, int course_id);
   int add_course(MYSQL* mysql, int course_id,char* name,int credit,int course_hours,int
		   tid,char* course_type);
   int update_course(MYSQL* mysql, int course_id,char* name,int credit,int course_hours,int
		   tid,char* course_type);
   MYSQL_RES* view_course(MYSQL* mysql, int course_id);

   int email_notice(char* to_email_address,char* from_email_address,char*
		   passwd,char* subject,char* message,char* email_server);

   int get_admin_id();
};
