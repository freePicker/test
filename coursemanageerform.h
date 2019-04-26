#ifndef COURSEMANAGEERFORM_H
#define COURSEMANAGEERFORM_H

#include <QWidget>
#include "dbmanager.h"
#include <QMessageBox>
#include <QMenu>
#include <QAction>
#include <QContextMenuEvent>
#include <QMessageBox>
#include <dbmanager.h>

namespace Ui {
class courseManageerForm;
}

class courseManageerForm : public QWidget
{
    Q_OBJECT

public:
    explicit courseManageerForm(QWidget *parent = 0);
    ~courseManageerForm();

private:
    Ui::courseManageerForm *ui;
    int rowCount;
    QString lastdata;
    bool flag;   //标记是否点击增加一行
    QMenu *menu;
    QAction *action;
public:
    void showCourseInfo();
    bool hasNull(int row);
    void contextMenuEvent(QContextMenuEvent *event);
    void creatMenu();
private slots:
    void addRowSlot();
    void on_tableWidget_cellChanged(int row, int column);
    void on_tableWidget_cellDoubleClicked(int row, int column);
    void deleteRow();
};

#endif // COURSEMANAGEERFORM_H
