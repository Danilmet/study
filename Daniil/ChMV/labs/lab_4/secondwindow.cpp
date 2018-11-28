#include "secondwindow.h"
#include "ui_secondwindow.h"

secondwindow::secondwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::secondwindow)
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

    connect(reply, SIGNAL(finished()), this, SLOT(getUsers()));
}

void secondwindow::getUsers()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    if (reply->error() == QNetworkReply::NoError)
    {
      // Получаем содержимое ответа
      QByteArray content = reply->readAll();
      QJsonDocument document = QJsonDocument::fromJson(content);
      QJsonObject object = document.object();

      QString string = "";
      int i = 0;
      while(!document[i].isUndefined())
      {
          string += "id: " + QString::number(document[i]["id"].toInt()) + " Login: " + document[i]["login"].toString()
                  + " Email: " + document[i]["email"].toString() + " Role: " + document[i]["role"].toString() + "\n";
          i++;
      }
      string += "\0";
      // Выводим результат
      ui->textBrowser->setText(string);
  }
  else
  {
    // Выводим описание ошибки, если она возникает.
    qDebug() << reply->errorString();
  }
  // разрешаем объекту-ответа "удалится"
  reply->deleteLater();
}

secondwindow::~secondwindow()
{
    delete ui;
}
