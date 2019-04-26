#include "database.h"
DataBase::DataBase()
{

}
bool DataBase::OpenDatabase()
{
    db = QSqlDatabase::addDatabase("QODBC"); //数据库驱动类型为SQL Server
    qDebug()<<"ODBC driver?"<<db.isValid();
    QString dsn = QString::fromLocal8Bit("SqlDataBase").arg("Student"); //数据源名称
    db.setHostName("localhost"); //选择本地主机，127.0.1.1
    db.setDatabaseName(dsn); //设置数据源名称
    db.setUserName("liyun"); //登录用户
    db.setPassword("liyun425109"); //密码
    return db.open();
}
void DataBase::close()
{
    db.close();
}
