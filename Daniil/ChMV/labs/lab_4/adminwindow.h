#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QDebug>
#include <QDialog>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QTextCodec>
#include <QJsonObject>
#include <QJsonDocument>
#include <QHttpMultiPart>
#include <QStandardItem>
#include <QStandardItemModel>

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

private slots:
    void get_users();
    void add_user();
    void edit_user();
    void delete_user();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::AdminWindow *ui;
    QNetworkAccessManager *manager;
};

#endif // ADMINWINDOW_H
