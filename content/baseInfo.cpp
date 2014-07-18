#include "baseinfo.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

BaseInfo::BaseInfo(QWidget *parent, Qt::WindowFlags f1):QWidget(parent,f1){

    QGridLayout *leftLayout1 = new QGridLayout;
	labelCourseId = new QLabel(tr("CourseId:"));
    labelCourseName = new QLabel(tr("CourseName"));
    labelCoursePoints = new QLabel(tr("CoursePoints"));
    labelCourseTeacher = new QLabel(tr("CourseTeacher"));
    labelCourseTimes = new QLabel(tr("CourseTimes"));

	lineCourseId = new QLineEdit;
    lineCourseName = new QLineEdit;
    lineCoursePoints = new QLineEdit;
    lineCourseTeacher = new QLineEdit;
    lineCourseTimes = new QLineEdit;

	QLabel *labelTeacherId;
    QLabel *labelTeacherName;
    QLabel *labelTeacherCourse;
    QLabel *labelTeacherJobTitle;

    QLabel *lineTeacherId;
    QLabel *lineTeacherName;
    QLabel *lineTeacherCourse;
    QLabel *lineTeacherJobTitle;

    labelUser = new QLabel(tr("User:"));
    labelName = new QLabel(tr("Name:"));
    labelSex = new QLabel(tr("Sex:"));
    labelDepart = new QLabel(tr("Department:"));
    labelAge = new QLabel(tr("Age:"));
    labelRemark = new QLabel(tr("Remark:"));
    labelRemark->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    lineUser = new QLineEdit;
    lineName = new QLineEdit;
    lineAge = new QLineEdit;
    comboSex = new QComboBox;
    comboSex->addItem(tr("Female"));
    comboSex->addItem(tr("Male"));
    textDepart = new QTextEdit;
    leftLayout1->addWidget(labelUser,0,0);
    leftLayout1->addWidget(lineUser,0,1);
    leftLayout1->addWidget(labelName,1,0);
    leftLayout1->addWidget(lineName,1,1);
    leftLayout1->addWidget(labelSex,2,0);
    leftLayout1->addWidget(comboSex,2,1);
    leftLayout1->addWidget(labelDepart,3,0,Qt::AlignTop);
    leftLayout1->addWidget(textDepart,3,1);
    leftLayout1->addWidget(labelAge,4,0);
    leftLayout1->addWidget(lineAge,4,1);
    leftLayout1->addWidget(labelRemark,5,0,1,2);
    leftLayout1->setColumnStretch(0,2);
    leftLayout1->setColumnStretch(1,3);
    leftLayout1->setMargin(10);
    leftLayout1->setSpacing(10);

    QHBoxLayout *rightUpLayout = new QHBoxLayout;
    labelHead = new QLabel(tr("Head:"));
    labelIcon = new QLabel;
    labelIcon->setPixmap(QPixmap("/home/lisl06/example/combine/images/icon.png"));
    buttonChange = new QPushButton;
    buttonChange->setText(tr("Change"));
    rightUpLayout->addWidget(labelHead);
    rightUpLayout->addWidget(labelIcon);
    rightUpLayout->addWidget(buttonChange);
    rightUpLayout->setSpacing(10);

    QVBoxLayout *rightLayout1 = new QVBoxLayout;
    labelIndivd = new QLabel(tr("Individual:"));
    textIndivd = new QTextEdit;
    rightLayout1->addLayout(rightUpLayout);
    rightLayout1->addWidget(labelIndivd);
    rightLayout1->addWidget(textIndivd);
    rightLayout1->setMargin(10);
    rightLayout1->setSpacing(10);

    QHBoxLayout *mainLayout1 = new QHBoxLayout(this);
    mainLayout1->addLayout(leftLayout1);
    mainLayout1->addLayout(rightLayout1);
    mainLayout1->setSpacing(10);
    mainLayout1->setMargin(10);
}