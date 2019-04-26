#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QString>
#include <QVariant>

class DataBase
{
public:
    DataBase();
public:
    bool OpenDatabase();
    void close();
public:
    QSqlDatabase db;
};

#endif // DATABASE_H
