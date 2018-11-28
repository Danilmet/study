#include "basecontents.h"
#include "ui_basecontents.h"

void BaseContents::cypher(int key) {
    char *str;
    QByteArray ba;
    ba = newPass.toLatin1();
    str = ba.data();
    qDebug() << newPass.length();
    for (int i = 0; (i < 100 && str[i] != '\0'); i++) {
        str[i] = str[i] + key;
    }

    newPass = str;

}

void BaseContents::writeToFile() {
    QString fName = "passwords.txt";
    QFile file(fName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << newName << " " << newPass << " ";
    }
    file.close();
}

void BaseContents::establish() {
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("dbMovies");
    db.setUserName(uName);
    db.setPassword(uPass);
    bool ok = db.open();

    if (ok) {
        QSqlQuery q;
        q.exec("SELECT * from movieData");
        tModel = new QSqlTableModel(this);
        tModel->setTable("movieData");
        tModel->select();
        ui->tableView->setModel(tModel);
        if (uName == "admin") {
            ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
            ui->btnAddUser->setEnabled(true);
        }
        ui->tableView->viewport()->update();
    } else {
        qDebug() << "ERROR";
    }

    //    QSqlQuery q;
    //    q.exec("SELECT * from movieData");
    //    tModel = new QSqlTableModel(this);
    //    tModel->setTable("movieData");
    //    tModel->select();
    //    QTableView *view = new QTableView;
    //    view->setModel(tModel);
    //    view->show();
}

void BaseContents::setData(QString uN, QString uP) {
    uName = uN;
    uPass = uP;
    establish();
}

BaseContents::BaseContents(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BaseContents)
{

    ui->setupUi(this);
}

BaseContents::~BaseContents()
{
    delete ui;
}

void BaseContents::on_btnFind_clicked()
{
    QString toFind = ui->txtByName->text();
    qDebug() << toFind;

        QAbstractItemModel *modl = ui->tableView->model();
        QSortFilterProxyModel proxy;
        proxy.setSourceModel(modl);
        proxy.setFilterKeyColumn(1);
        proxy.setFilterFixedString(toFind);
        // now the proxy only contains rows that match the name
        // let's take the first one and map it to the original model
        QModelIndex matchingIndex = proxy.mapToSource(proxy.index(0,0));
        if(matchingIndex.isValid()){
            ui->tableView->scrollTo(matchingIndex,QAbstractItemView::EnsureVisible);
            ui->tableView->setCurrentIndex(matchingIndex);
            ui->tableView->selectRow(matchingIndex.row());
        } else {
            qDebug() << "NOT FOUND";
        }
}

void BaseContents::on_btnChangePass_clicked()
{
    QSqlQuery q;
    bool ok;
    QString pass = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                            tr("New Password:"), QLineEdit::Normal,
                                            QDir::home().dirName(), &ok);
    if (ok && !pass.isEmpty())
        q.exec("SET PASSWORD FOR '" + uName + "'@'localhost' = PASSWORD('" + pass + "');");
}

void BaseContents::on_btnAddUser_clicked()
{
    QSqlQuery q;
    bool ok;
    QString pass;
    QString user = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                            tr("New User:"), QLineEdit::Normal,
                                            QDir::home().dirName(), &ok);
    newName = user;
    if (ok) {
        pass = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                     tr("Password:"), QLineEdit::Normal,
                                     QDir::home().dirName(), &ok);
        newPass = pass;
    }
    if (ok && !pass.isEmpty()) {
        q.exec("CREATE USER '" + user + "'@'localhost' IDENTIFIED BY '" + pass + "'");
        q.exec("GRANT ALL PRIVILEGES ON *.* TO '" + user + "'@'localhost';");
        q.exec("FLUSH PRIVILEGES");
    }

    cypher(2);
    writeToFile();
}

void BaseContents::on_btnChangeUser_clicked()
{
    this->hide();
    MainWindow *win = new MainWindow();
    win->show();
}
