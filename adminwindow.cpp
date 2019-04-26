#include "adminwindow.h"
#include "ui_adminwindow.h"

adminWindow::adminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminWindow)
{
    ui->setupUi(this);
    stuInfoform = new stuInfoForm;
    teaInfoform = new teaInfoForm;
    courseform = new courseManageerForm;
    selectCourseform = new selectCourseForm;
    ui->stackedWidget->addWidget(stuInfoform);
    ui->stackedWidget->addWidget(teaInfoform);
    ui->stackedWidget->addWidget(courseform);
    ui->stackedWidget->addWidget(selectCourseform);
    connect(ui->actionStuInfo,SIGNAL(triggered(bool)),this,SLOT(stuInfoSlot()));
    connect(ui->actionTeaInfo,SIGNAL(triggered(bool)),this,SLOT(teaInfoSlot()));
    connect(ui->actionCourseInfo,SIGNAL(triggered(bool)),this,SLOT(courseSlot()));
    connect(ui->actionSelectCourse,SIGNAL(triggered(bool)),this,SLOT(selectCourseSlot()));
}

adminWindow::~adminWindow()
{
    delete ui;
}
void adminWindow::stuInfoSlot()
{
    ui->stackedWidget->setCurrentWidget(stuInfoform);
}
void adminWindow::teaInfoSlot()
{
    ui->stackedWidget->setCurrentWidget(teaInfoform);
}
void adminWindow::courseSlot()
{
    ui->stackedWidget->setCurrentWidget(courseform);
    courseform->showCourseInfo();
}
void adminWindow::selectCourseSlot()
{
    ui->stackedWidget->setCurrentWidget(selectCourseform);
    selectCourseform->showSelectCourseInfo();
}
