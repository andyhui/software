#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QMessageBox>
#include <QFileDialog>
#include <QMenuBar>
#include <QMainWindow>
#include <QAction>
#include <QActionGroup>
#include <QGroupBox>
#include <QMenu>
#include <QRadioButton>
#include <QTableWidget>
#include <QTextCodec>
#include <QSplitter>
#include <QListWidget>
#include <QMacStyle>
#include "AllClass.h"

class MainWindow:public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();

public slots:
    void addImages();
    void removeAllImages();
    //void changeIcon();

     void about();

private:

    void createActions();
    void createMenus();
    void addIconGrupBox();

    QWidget *centralWidget;

    QGroupBox *classGroupBox;
    AllClass *allClass;

    QMenu *fileMenu;
    QMenu *viewMenu;
    QMenu *helpMenu;

    QAction *addImagesAct;
    QAction *removeAllImagesAct;

    QAction *guessModeStateAct;

    QAction *exitAct;
    QAction *aboutAct;
    QAction *aboutQtAct;

    QPushButton *course;
    QPushButton *courseTable;
    QPushButton *chooseCourse;
    QPushButton *communicate;
    QPushButton *setting;


};

#endif // MAINWINDOW_H