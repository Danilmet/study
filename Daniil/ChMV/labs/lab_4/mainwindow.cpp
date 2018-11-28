#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"
#include "adminwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    Создаем объект менеджера
    manager = new QNetworkAccessManager(this);
    ui->label_3->hide();
    ui->label_5->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->pushButton_2->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
//  Берем адрес введенный в текстовое поле
    QUrl url("http://study/auth");

//  Создаем объект для запроса
    QNetworkRequest request(url);

//  Выполняем запрос, получаем указатель на объект ответственный за ответ
    QJsonObject json;
    json.insert("login", ui->lineEdit->text());
    json.insert("password", ui->lineEdit_2->text());
    QJsonDocument jsonDoc(json);
    QByteArray jsonData = jsonDoc.toJson();
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    qDebug() << jsonData;

    QNetworkReply* reply = manager->post(request, jsonData);

    connect(reply, SIGNAL(finished()), this, SLOT(auth()));
}

void MainWindow::auth()
{
  QNetworkReply *reply = qobject_cast<QNetworkReply *> (sender());

  if (reply->error() == QNetworkReply::NoError)
  {
    // Получаем содержимое ответа
    QByteArray content = reply->readAll();


    // Реализуем преобразование кодировки (зависит от кодировки сайта)
     QTextCodec *codec = QTextCodec::codecForName("utf8");

    // Выводим результат
    if (content == "admin")
    {
        type = "admin";
        qDebug() << codec->toUnicode(content.data());
        AdminWindow *window = new AdminWindow;
        window->show();
    }
    else if (content == "user")
    {
        type = "user";
        qDebug() << codec->toUnicode(content.data());
        secondwindow *window = new secondwindow;
        window->show();
    }
    else
    {
        tryToLogin = true;
        ui->label_3->show();
        ui->label_5->show();
        ui->lineEdit_3->show();
        ui->lineEdit_4->show();
        ui->pushButton_2->show();
        //Сделать восстановление пароля
        qDebug() << codec->toUnicode(content.data());
    }
  }
  else
  {
    // Выводим описание ошибки, если она возникает.
      qDebug() << reply->errorString();
  }

  // разрешаем объекту-ответа "удалится"
  reply->deleteLater();
}

void MainWindow::on_pushButton_2_clicked()
{
    //  Берем адрес введенный в текстовое поле
        QUrl url("http://study/setPassword");

    //  Создаем объект для запроса
        QNetworkRequest request(url);

    //  Выполняем запрос, получаем указатель на объект ответственный за ответ
        QJsonObject json;
        json.insert("email", ui->lineEdit_3->text());
        json.insert("password", ui->lineEdit_4->text());
        QJsonDocument jsonDoc(json);
        QByteArray jsonData = jsonDoc.toJson();
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        qDebug() << jsonData;

        QNetworkReply* reply = manager->post(request, jsonData);

        connect(reply, SIGNAL(finished()), this, SLOT(changePass()));
}

void MainWindow::changePass()
{
  QNetworkReply *reply = qobject_cast<QNetworkReply *> (sender());

  if (reply->error() == QNetworkReply::NoError)
  {
    // Получаем содержимое ответа
    QByteArray content = reply->readAll();


    // Реализуем преобразование кодировки (зависит от кодировки сайта)
     QTextCodec *codec = QTextCodec::codecForName("utf8");

     ui->label_3->hide();
     ui->label_5->hide();
     ui->lineEdit_3->hide();
     ui->lineEdit_4->hide();
     ui->pushButton_2->hide();

    // Выводим результат
     qDebug() << codec->toUnicode(content.data());
  }
  else
  {
    // Выводим описание ошибки, если она возникает.
      qDebug() << reply->errorString();
  }

  // разрешаем объекту-ответа "удалится"
  reply->deleteLater();
}
