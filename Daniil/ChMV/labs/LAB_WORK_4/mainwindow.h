#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#include <QTableView>
#include <QStringList>
#include <QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QStringList list;
    QSqlDatabase db;
    QString uName, uPass;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnLogin_clicked();
    void on_btnForgot_clicked();
    QString decypher(QString s, int key);

signals:
    void sendData(QString uN, QString uP);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
