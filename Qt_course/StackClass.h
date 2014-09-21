#ifndef STACKCLASS_H
#define STACKCLASS_H

#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QComboBox>
#include <QStackedWidget>
#include <QGroupBox>
#include "AllClass.h"
#include "MyClass.h"
#include "TreeView.h"

class StackClass :public QWidget{
    Q_OBJECT
public:
    StackClass(QWidget *parent = 0);

    QPushButton class4;
    QPushButton class5;
    QPushButton class6;
    QPushButton class7;
    QPushButton class8;
    QPushButton class9;
    QPushButton class10;
    QPushButton class11;
    QPushButton class12;
    QPushButton class13;
    QPushButton class14;
    QPushButton class15;
    QPushButton class16;

public slots:
    void showAllClassGroup();
    void showMyClassGroup();
    void showTreeGroup();
    void changeToAllStack();
    void changeToMyStack();
    void changeToTreeViewStack();


private:
    //void showAllClassGroup();
    //void showMyClassGroup();
    QLabel *createHeaderLabel(const QString &text);
    QLabel *createPixmapLabel();

    enum { NumModes = 4, NumStates = 4 };

    QLabel *stateLabels[NumStates][NumStates];
    //QLabel *modeLabels[NumModes];
    QLabel *pixmapLabels[NumModes][NumStates];

    QPushButton *createButton;
    QPushButton *deleteButton;
    QPushButton *otherButton;
    QPushButton *searchButton;

    QPushButton *allClassButton;
    QPushButton *myClassButton;
    QPushButton *smallView;
    QPushButton *treeView;

    QLineEdit *searEdit;

    QGroupBox *allClassGroup;
    QGroupBox *myClassGroup;
    QGroupBox *treeGroup;

    AllClass *allClass;
    MyClass *myClass;
    TreeCourse *tree;

    QStackedWidget *stack;

};

#endif // STACKCLASS_H
