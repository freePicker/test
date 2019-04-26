#ifndef COURSE_H
#define COURSE_H

#include <QWidget>
#include "dbmanager.h"
#include <QTableWidget>
#include <QVariant>

namespace Ui {
class Course;
}

class Course : public QWidget
{
    Q_OBJECT

public:
    explicit Course(QWidget *parent = 0);
    ~Course();

private:
    Ui::Course *ui;
    QString Sno;              //保存登录用户的学号
private slots:
    void selectCourseSlot();
public:
    void showCourseInfo();
    void getSno(QString Sno);
};

#endif // COURSE_H
