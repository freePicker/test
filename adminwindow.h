#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include "stuinfoform.h"
#include "teainfoform.h"
#include "coursemanageerform.h"
#include "selectcourseform.h"

namespace Ui {
class adminWindow;
}

class adminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminWindow(QWidget *parent = 0);
    ~adminWindow();

private:
    Ui::adminWindow *ui;
    stuInfoForm *stuInfoform;
    teaInfoForm *teaInfoform;
    courseManageerForm *courseform;
    selectCourseForm *selectCourseform;

private slots:
    void stuInfoSlot();
    void teaInfoSlot();
    void courseSlot();
    void selectCourseSlot();
};

#endif // ADMINWINDOW_H
