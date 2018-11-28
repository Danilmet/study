#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "basecontents.h"

QString MainWindow::decypher(QString s, int key) {
    char *str;
    QByteArray ba;
    ba = s.toLatin1();
    str = ba.data();
    for (int i = 0; (i < 100 && str[i] != '\0'); i++) {
        str[i] = str[i] - key;
    }

    return str;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//    db = QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName("localhost");
//    db.setDatabaseName("dbMovies");
//    db.setUserName("admin");
//    db.setPassword("55555");
//    bool ok = db.open();

//    QSqlQuery q;
//    q.exec("SELECT * from movieData");
//    tModel = new QSqlTableModel(this);
//    tModel->setTable("movieData");
//    tModel->select();
//    QTableView *view = new QTableView;
//    view->setModel(tModel);
//    view->show();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnLogin_clicked()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("dbMovies");
    db.setUserName(ui->nameField->text());
    db.setPassword(ui->passField->text());
    bool ok = db.open();
    qDebug() << ui->nameField->text();
    qDebug() << ui->passField->text();
    uName = ui->nameField->text();
    uPass = ui->passField->text();
    if (ok) {
        QSqlQuery q;
        q.exec("SELECT * from movieData");
        while (q.next()) {
            int id = q.value(0).toInt();
            QString name = q.value(1).toString();
            qDebug() << id << name;
        }

        uName = ui->nameField->text();
        uPass = ui->passField->text();
        q.clear();

        BaseContents *base = new BaseContents();
        base->show();
        connect(this, SIGNAL(sendData(QString,QString)), base, SLOT(setData(QString,QString)));
        emit sendData(uName, uPass);
        this->hide();
    }

    else {
        ui->passField->setText("Invalid password");
        ui->btnForgot->setEnabled(true);
    }
    db.close();
}

void MainWindow::on_btnForgot_clicked()
{
    bool ok;
    QString user = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                            tr("New User:"), QLineEdit::Normal,
                                            QDir::home().dirName(), &ok);
    int key = user.toInt();
    if (ok) {
        QFile file("passwords.txt");

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        QString line = file.readAll();
        qDebug() << line;
        list = QString(line).split(" ");
        QString toDecipher;
        for (int i = 0; i < list.length(); i++) {
            if (list.at(i) == uName) {
                toDecipher = list.at(i + 1);
            }
        }

        ui->passField->setText(decypher(toDecipher, key));
    }
}
