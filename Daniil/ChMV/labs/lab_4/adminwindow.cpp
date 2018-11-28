#include "adminwindow.h"
#include "ui_adminwindow.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    ui->textBrowser->hide();
    //    Создаем объект менеджера
    manager = new QNetworkAccessManager(this);

    //Получение всех пользователей
    //  Берем адрес введенный в текстовое поле
    QUrl url("http://study/getAll");

    //  Создаем объект для запроса
    QNetworkRequest request(url);

    //  Выполняем запрос, получаем указатель на объект ответственный за ответ
    QNetworkReply* reply = manager->get(request);

    connect(reply, SIGNAL(finished()), this, SLOT(get_users()));
}

void AdminWindow::get_users()
{
  QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
  if (reply->error() == QNetworkReply::NoError)
  {
    // Получаем содержимое ответа
    QByteArray content = reply->readAll();
    QJsonDocument document = QJsonDocument::fromJson(content);
    QJsonObject object = document.object();

    QString string = "";

    QStandardItemModel *model = new QStandardItemModel;
    QStandardItem *item;

    QStringList horizontalHeader;
    horizontalHeader.append("id");
    horizontalHeader.append("login");
    horizontalHeader.append("email");
    horizontalHeader.append("role");

    model->setHorizontalHeaderLabels(horizontalHeader);


    int i = 0;
    while(!document[i].isUndefined())
    {
        item = new QStandardItem(QString(QString::number(document[i]["id"].toInt())));
        model->setItem(i, 0, item);
        item = new QStandardItem(document[i]["login"].toString());
        model->setItem(i, 1, item);
        item = new QStandardItem(document[i]["email"].toString());
        model->setItem(i, 2, item);
        item = new QStandardItem(document[i]["role"].toString());
        model->setItem(i, 3, item);
//        string += "id: " + QString::number(document[i]["id"].toInt()) + " Login: " + document[i]["login"].toString()
//                + " Email: " + document[i]["email"].toString() + " Role: " + document[i]["role"].toString() + "\n";
        i++;
    }
    string += "\0";
    // Выводим результат

    ui->tableView->setModel(model);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();

//    ui->textBrowser->setText(string);
  }
  else
  {
    // Выводим описание ошибки, если она возникает.
    qDebug() << reply->errorString();
  }
  // разрешаем объекту-ответа "удалится"
  reply->deleteLater();
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::on_pushButton_clicked()
{
    //  Берем адрес введенный в текстовое поле
        QUrl url("http://study/store");

    //  Создаем объект для запроса
        QNetworkRequest request(url);

    //  Выполняем запрос, получаем указатель на объект ответственный за ответ
        QJsonObject json;
        json.insert("login", ui->add_login->text());
        json.insert("password", ui->add_password->text());
        json.insert("email", ui->add_email->text());
        json.insert("type", ui->add_role->text());
        QJsonDocument jsonDoc(json);
        QByteArray jsonData = jsonDoc.toJson();
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        qDebug() << jsonData;

        QNetworkReply* reply = manager->post(request, jsonData);

        connect(reply, SIGNAL(finished()), this, SLOT(add_user()));
}

void AdminWindow::add_user()
{
  QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
  if (reply->error() == QNetworkReply::NoError)
  {
    // Получаем содержимое ответа
    QByteArray content= reply->readAll();
    // Реализуем преобразование кодировки
    // (зависит от кодировки сайта)
    QTextCodec *codec = QTextCodec::codecForName("utf8");
    // Выводим результат
    ui->textBrowser->setText(content.data());
    qDebug() << codec->toUnicode(content.data());

    //Получение всех пользователей
    //  Берем адрес введенный в текстовое поле
    QUrl url("http://study/getAll");

    //  Создаем объект для запроса
    QNetworkRequest request(url);

    //  Выполняем запрос, получаем указатель на объект ответственный за ответ
    QNetworkReply* reply = manager->get(request);

    connect(reply, SIGNAL(finished()), this, SLOT(get_users()));
  }
  else
  {
    // Выводим описание ошибки, если она возникает.
    qDebug() << reply->errorString();
  }
  // разрешаем объекту-ответа "удалится"
  reply->deleteLater();
}

void AdminWindow::on_pushButton_2_clicked()
{
    //  Берем адрес введенный в текстовое поле
        QUrl url("http://study/editUser");

    //  Создаем объект для запроса
        QNetworkRequest request(url);

    //  Выполняем запрос, получаем указатель на объект ответственный за ответ
        QJsonObject json;
        json.insert("id", ui->edit_id->text());
        json.insert("login", ui->edit_login->text());
        json.insert("password", ui->edit_password->text());
        json.insert("type", ui->edit_role->text());
        json.insert("email", ui->edit_email->text());
        QJsonDocument jsonDoc(json);
        QByteArray jsonData = jsonDoc.toJson();
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        qDebug() << jsonData;

        QNetworkReply* reply = manager->post(request, jsonData);

        connect(reply, SIGNAL(finished()), this, SLOT(edit_user()));
}

void AdminWindow::edit_user()
{
  QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
  if (reply->error() == QNetworkReply::NoError)
  {
    // Получаем содержимое ответа
    QByteArray content= reply->readAll();
    // Реализуем преобразование кодировки
    // (зависит от кодировки сайта)
    QTextCodec *codec = QTextCodec::codecForName("utf8");
    // Выводим результат
    ui->textBrowser->setText(content.data());
    qDebug() << codec->toUnicode(content.data());

    //Получение всех пользователей
    //  Берем адрес введенный в текстовое поле
    QUrl url("http://study/getAll");

    //  Создаем объект для запроса
    QNetworkRequest request(url);

    //  Выполняем запрос, получаем указатель на объект ответственный за ответ
    QNetworkReply* reply = manager->get(request);

    connect(reply, SIGNAL(finished()), this, SLOT(get_users()));
  }
  else
  {
    // Выводим описание ошибки, если она возникает.
    qDebug() << reply->errorString();
  }
  // разрешаем объекту-ответа "удалится"
  reply->deleteLater();
}

void AdminWindow::on_pushButton_3_clicked()
{
    //  Берем адрес введенный в текстовое поле
        QUrl url("http://study/deleteUser");

    //  Создаем объект для запроса
        QNetworkRequest request(url);

    //  Выполняем запрос, получаем указатель на объект ответственный за ответ
        QJsonObject json;
        json.insert("id", ui->delete_id->text());
        QJsonDocument jsonDoc(json);
        QByteArray jsonData = jsonDoc.toJson();
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        qDebug() << jsonData;

        QNetworkReply* reply = manager->post(request, jsonData);

        connect(reply, SIGNAL(finished()), this, SLOT(delete_user()));
}

void AdminWindow::delete_user()
{
  QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
  if (reply->error() == QNetworkReply::NoError)
  {
    // Получаем содержимое ответа
    QByteArray content= reply->readAll();
    // Реализуем преобразование кодировки
    // (зависит от кодировки сайта)
    QTextCodec *codec = QTextCodec::codecForName("utf8");
    // Выводим результат
    ui->textBrowser->setText(content.data());
    qDebug() << codec->toUnicode(content.data());

    //Получение всех пользователей
    //  Берем адрес введенный в текстовое поле
    QUrl url("http://study/getAll");

    //  Создаем объект для запроса
    QNetworkRequest request(url);

    //  Выполняем запрос, получаем указатель на объект ответственный за ответ
    QNetworkReply* reply = manager->get(request);

    connect(reply, SIGNAL(finished()), this, SLOT(get_users()));
  }
  else
  {
    // Выводим описание ошибки, если она возникает.
    qDebug() << reply->errorString();
  }
  // разрешаем объекту-ответа "удалится"
  reply->deleteLater();
}
