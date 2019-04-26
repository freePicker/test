#include "course.h"
#include "ui_course.h"

Course::Course(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Course)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QObject::connect(ui->selectCourseButton,SIGNAL(clicked()),this,SLOT(selectCourseSlot()));
}

Course::~Course()
{
    delete ui;
}
void Course::showCourseInfo()
{
    DBManager *manager = new DBManager;
    QSqlQuery *query = manager->query();
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    while(query->next())
    {
        if(query->value(4).toInt()==1)
        {
            int rowCount = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(rowCount);
            for(int i=0;i<ui->tableWidget->columnCount();i++)
            {
                QTableWidgetItem *item = new QTableWidgetItem(query->value(i).toString());
                if(i<ui->tableWidget->columnCount()-1)
                {
                      item->setFlags(Qt::NoItemFlags);
                }

                if(i == ui->tableWidget->columnCount()-1)
                {
                    item->setCheckState(Qt::Unchecked);
                    item->setText("选择");
                }
                item->setBackgroundColor(QColor(0,60,10));
                item->setTextColor(QColor(200,111,100));
                item->setFont(QFont("Helvetica"));
                ui->tableWidget->setItem(rowCount,i,item);

            }
        }
    }
    manager->close();

}
void Course::selectCourseSlot()
{
    DBManager *manager = new DBManager;
    for(int i =0;i<ui->tableWidget->rowCount();i++)
    {
        if(ui->tableWidget->item(i,4)->checkState() == Qt::Checked)
        {
            manager->insert(Sno,ui->tableWidget->item(i,0)->text(),"0.0");
        }

    }

    manager->close();
}

void Course::getSno(QString Sno)
{
    this->Sno = Sno;
}
