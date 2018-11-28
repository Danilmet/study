/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QTextBrowser *textBrowser;
    QLineEdit *delete_id;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLineEdit *add_login;
    QLineEdit *add_password;
    QLineEdit *add_email;
    QLineEdit *add_role;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *edit_id;
    QLineEdit *edit_login;
    QLineEdit *edit_password;
    QLineEdit *edit_email;
    QLineEdit *edit_role;
    QTableView *tableView;
    QGraphicsView *graphicsView;

    void setupUi(QDialog *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName(QStringLiteral("AdminWindow"));
        AdminWindow->resize(682, 546);
        textBrowser = new QTextBrowser(AdminWindow);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setEnabled(true);
        textBrowser->setGeometry(QRect(530, 480, 21, 16));
        delete_id = new QLineEdit(AdminWindow);
        delete_id->setObjectName(QStringLiteral("delete_id"));
        delete_id->setGeometry(QRect(480, 400, 137, 22));
        layoutWidget = new QWidget(AdminWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 360, 631, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        layoutWidget1 = new QWidget(AdminWindow);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(60, 400, 139, 111));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        add_login = new QLineEdit(layoutWidget1);
        add_login->setObjectName(QStringLiteral("add_login"));

        verticalLayout->addWidget(add_login);

        add_password = new QLineEdit(layoutWidget1);
        add_password->setObjectName(QStringLiteral("add_password"));

        verticalLayout->addWidget(add_password);

        add_email = new QLineEdit(layoutWidget1);
        add_email->setObjectName(QStringLiteral("add_email"));

        verticalLayout->addWidget(add_email);

        add_role = new QLineEdit(layoutWidget1);
        add_role->setObjectName(QStringLiteral("add_role"));

        verticalLayout->addWidget(add_role);

        layoutWidget2 = new QWidget(AdminWindow);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(260, 400, 139, 140));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        edit_id = new QLineEdit(layoutWidget2);
        edit_id->setObjectName(QStringLiteral("edit_id"));

        verticalLayout_2->addWidget(edit_id);

        edit_login = new QLineEdit(layoutWidget2);
        edit_login->setObjectName(QStringLiteral("edit_login"));

        verticalLayout_2->addWidget(edit_login);

        edit_password = new QLineEdit(layoutWidget2);
        edit_password->setObjectName(QStringLiteral("edit_password"));

        verticalLayout_2->addWidget(edit_password);

        edit_email = new QLineEdit(layoutWidget2);
        edit_email->setObjectName(QStringLiteral("edit_email"));

        verticalLayout_2->addWidget(edit_email);

        edit_role = new QLineEdit(layoutWidget2);
        edit_role->setObjectName(QStringLiteral("edit_role"));

        verticalLayout_2->addWidget(edit_role);

        tableView = new QTableView(AdminWindow);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(40, 10, 591, 331));
        graphicsView = new QGraphicsView(AdminWindow);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(220, 80, 256, 192));

        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QDialog *AdminWindow)
    {
        AdminWindow->setWindowTitle(QApplication::translate("AdminWindow", "Dialog", nullptr));
        delete_id->setPlaceholderText(QApplication::translate("AdminWindow", "id", nullptr));
        pushButton->setText(QApplication::translate("AdminWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        pushButton_2->setText(QApplication::translate("AdminWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        pushButton_3->setText(QApplication::translate("AdminWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        add_login->setPlaceholderText(QApplication::translate("AdminWindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        add_password->setPlaceholderText(QApplication::translate("AdminWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        add_email->setPlaceholderText(QApplication::translate("AdminWindow", "email", nullptr));
        add_role->setPlaceholderText(QApplication::translate("AdminWindow", "\320\240\320\276\320\273\321\214", nullptr));
        edit_id->setPlaceholderText(QApplication::translate("AdminWindow", "id", nullptr));
        edit_login->setPlaceholderText(QApplication::translate("AdminWindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        edit_password->setPlaceholderText(QApplication::translate("AdminWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        edit_email->setPlaceholderText(QApplication::translate("AdminWindow", "email", nullptr));
        edit_role->setPlaceholderText(QApplication::translate("AdminWindow", "\320\240\320\276\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
