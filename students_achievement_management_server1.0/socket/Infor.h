struct USERINFOR
{
	int userId;
	char password[20];
}userInfor;

struct STUDENTINFOR
{
	char studentId[20];
	char studentName[20];
	char studentBirthday[20];
	char studentClass[20];
	char studentSex[4];
	char studentSthelse[40];
}studentInfor;

struct CLASSINFOR
{
	char classId[20];
	char className[20];
	char classCredit[4];
	char classTime[20];
	char classType[20];
	char classTeacher[20];
	char classWhen[20];
	char classSthelse[40];
	char classMark[20];
	char classHomework[100];
}classInfor;

struct TEACHERINFOR
{
	char teacherId[20];
	char teacherName[20];
	char teacherSex[4];
	char teacherPhone[4];
	char teacherLesson[40];
	char teacherSchool[20];
	char teacherLever[20];
	char teacherSthelse[20];
	char teacherClass[100];

}teacherInfor;
