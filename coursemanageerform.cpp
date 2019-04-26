#include "coursemanageerform.h"
#include "ui_coursemanageerform.h"

courseManageerForm::courseManageerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::courseManageerForm)
{
    ui->setupUi(this);
    rowCount = 0;
    lastdata = "";
    flag = false;
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    connect(ui->addRowButton,SIGNAL(clicked()),this,SLOT(addRowSlot()));
}

courseManageerForm::~courseManageerForm()
{
    delete ui;
}
void courseManageerForm::showCourseInfo()
{
    rowCount = 0;
    ui->tableWidget->blockSignals(true);
    DBManager *manager = new DBManager;
    QString str = "select Cno,Cname,Ctno,Cteacher,Cduration from Couse_info";
    QSqlQuery *query = manager->commonQuery(str);
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    while(query->next())
    {
            rowCount = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(rowCount);
            for(int i=0;i<ui->tableWidget->columnCount();i++)
            {
                QTableWidgetItem *item = new QTableWidgetItem(query->value(i).toString());
                item->setFont(QFont("Helvetica"));
                ui->tableWidget->setItem(rowCount,i,item);
            }
    }
    rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->blockSignals(false);
    manager->close();
}
void courseManageerForm::addRowSlot()
{
    qDebug()<<rowCount;
    ui->tableWidget->setRowCount(++rowCount);
    flag = true;
}

void courseManageerForm::on_tableWidget_cellChanged(int row, int column)
{
 if(row ==rowCount-1&&flag==true)
 {
    if(!hasNull(row))
    {
        QString Cno = ui->tableWidget->item(row,0)->text();
        QString Cname = ui->tableWidget->item(row,1)->text();
        QString Ctno = ui->tableWidget->item(row,2)->text();
        QString Cteacher = ui->tableWidget->item(row,3)->text();
        QString Cduration = ui->tableWidget->item(row,4)->text();
        QString Cstatus = "0";
        DBManager *manager = new DBManager;
        QString str = "insert into Couse_info(Cno,Cname,Ctno,Cteacher,Cduration,Cstatus) values ('"+ Cno+"','"+ Cname+"','"+ Ctno+"','"+Cteacher+"',"+Cduration+","+ Cstatus+")";
        manager->commonQuery(str);
        manager->close();
        flag = false;
    }
 }
 else
 {
     if(column ==0)
     {
         //修改的是关键字
         DBManager *manager = new DBManager;
         QString str = "select * from Couse_info where Cno = '"+ui->tableWidget->item(row,column)->text()+"';";
         QSqlQuery *query = manager->commonQuery(str);
         if(query->next())
         {
            QMessageBox *messageBox = new QMessageBox;
            messageBox->information(this,"error","it is existed!!!");
         }
         else
         {
             QString Cno = ui->tableWidget->item(row,0)->text();
             QString Cname = ui->tableWidget->item(row,1)->text();
             QString Ctno = ui->tableWidget->item(row,2)->text();
             QString Cteacher = ui->tableWidget->item(row,3)->text();
             QString Cduration = ui->tableWidget->item(row,4)->text();
             QString Cstatus = "0";
             QString str = "insert into Couse_info(Cno,Cname,Ctno,Cteacher,Cduration,Cstatus) values ('"+ Cno+"','"+ Cname+"','"+ Ctno+"','"+Cteacher+"',"+Cduration+","+ Cstatus+")";

             manager->commonQuery(str);
             str = "delete from Couse_info where Cno = '"+lastdata+"';";

             manager->commonQuery(str);
             manager->close();
         }

     }
     else
     {
         //没有修改关键字，则执行更新操作
         QString changed;
         switch(column)
         {
         case 1:changed = "Cname";break;
         case 2:changed = "Ctno";break;
         case 3:changed = "Cteacher";break;
         case 4:changed = "Cduration";break;
         }
         QString str = "update Couse_info set "+changed+" = '"+ui->tableWidget->item(row,column)->text()+"' where Cno = '"+ui->tableWidget->item(row,0)->text()+"';";
         DBManager *manager = new DBManager;
         manager->commonQuery(str);
         manager->close();
     }
 }
}
bool courseManageerForm::hasNull(int row)
{
    for(int i=0;i<ui->tableWidget->columnCount();i++)
    {
        if(ui->tableWidget->item(row,i)==NULL||ui->tableWidget->item(row,i)->text()=="")
        {
            return true;
        }
    }
    return false;
}

void courseManageerForm::on_tableWidget_cellDoubleClicked(int row, int column)
{
    if(ui->tableWidget->item(row,column)!=NULL)
    {
        lastdata = ui->tableWidget->item(row,column)->text();
    }
    else
    {
        lastdata = "";
    }

}
void courseManageerForm::deleteRow()
{
    QMessageBox msgBox;
    msgBox.setInformativeText("Sure you wang to delete?");
    msgBox.setStandardButtons(QMessageBox::Ok  | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    int ret = msgBox.exec();
    switch (ret) {
        case QMessageBox::Ok:
    {
        QString str;
        str = "delete from Couse_info where Cno = '"+ui->tableWidget->item(ui->tableWidget->currentRow(),0)->text()+"';";
        qDebug()<<str;
        DBManager *manager = new DBManager;
        manager->commonQuery(str);
        ui->tableWidget->removeRow(ui->tableWidget->currentRow());
        manager->close();
        rowCount--;
        break;
    }
        case QMessageBox::Cancel:
            msgBox.close();
            break;
        default:
            // should never be reached
            break;
      }


}
void courseManageerForm::creatMenu()
{
    menu = new QMenu(this);
    action = new QAction("删除该行",this);
    menu->addAction(action);
    connect(action,SIGNAL(triggered()),this,SLOT(deleteRow()));
}
void courseManageerForm::contextMenuEvent(QContextMenuEvent *event)
{
    creatMenu();
    //菜单出现的位置为当前鼠标的位置
    menu->exec(QCursor::pos());
    event->accept();
}
