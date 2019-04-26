#ifndef BASEINFO_H
#define BASEINFO_H

#include <QWidget>
#include <QString>
#include "dbmanager.h"

namespace Ui {
class baseInfo;
}

class baseInfo : public QWidget
{
    Q_OBJECT

public:
    explicit baseInfo(QWidget *parent = 0);
    ~baseInfo();
    void getSno(QString Sno);
    void showInfo();
private:
    Ui::baseInfo *ui;
    QString Sno;              //保存登录用户的学号

};

#endif // BASEINFO_H
