#ifndef BASECONTENTS_H
#define BASECONTENTS_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#include <QTableView>
#include <QSortFilterProxyModel>
#include <QMessageBox>
#include <QInputDialog>
#include <QDir>
#include "mainwindow.h"
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QStringList>
#include <QWidget>
namespace Ui {
class BaseContents;
}

class BaseContents : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    QSqlTableModel *tModel;
    QString uName, uPass;
    QString newName, newPass;
    explicit BaseContents(QWidget *parent = 0);
    ~BaseContents();


private slots:
    void setData(QString uN, QString uP);
    void establish();
    void cypher(int key);
    //void decypher(int key);

    void writeToFile();

    void on_btnFind_clicked();

    void on_btnChangePass_clicked();

    void on_btnAddUser_clicked();

    void on_btnChangeUser_clicked();

private:
    Ui::BaseContents *ui;
};



#endif // BASECONTENTS_H
