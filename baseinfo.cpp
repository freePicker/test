#include "baseinfo.h"
#include "ui_baseinfo.h"

baseInfo::baseInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::baseInfo)
{
    ui->setupUi(this);
}

baseInfo::~baseInfo()
{
    delete ui;
}
void baseInfo::getSno(QString Sno)
{
    this->Sno = Sno;
}
void baseInfo::showInfo()
{
    QString name;
    QString age;
    QString number;
    QString sex;
    QString classno;
    QString image;
    QString tableName = "Stu_info";
    DBManager *manager = new DBManager;
    QSqlQuery *query = manager->query(Sno,tableName);
    query->next();
    number = query->value(0).toString();
    name = query->value(1).toString();
    sex = query->value(2).toString();
    age = query->value(3).toString();
    image = query->value(4).toString();
    classno = query->value(5).toString();
    ui->ageLabel->setText(age);
    ui->nameLabel->setText(name);
    ui->imageLabel->setStyleSheet("border-image: url(:/new/bg/images/wo.jpeg);");
    ui->numLabel->setText(number);
    ui->sexLabel->setText(sex);
    ui->classLabel->setText(classno);
}
