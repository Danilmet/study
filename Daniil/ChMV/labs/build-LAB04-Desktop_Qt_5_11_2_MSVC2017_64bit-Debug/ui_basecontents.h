/********************************************************************************
** Form generated from reading UI file 'basecontents.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASECONTENTS_H
#define UI_BASECONTENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BaseContents
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *btnChangeUser;
    QPushButton *btnChangePass;
    QPushButton *btnAddUser;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnFind;
    QLineEdit *txtByName;

    void setupUi(QDialog *BaseContents)
    {
        if (BaseContents->objectName().isEmpty())
            BaseContents->setObjectName(QStringLiteral("BaseContents"));
        BaseContents->resize(400, 300);
        widget = new QWidget(BaseContents);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 381, 281));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnChangeUser = new QPushButton(widget);
        btnChangeUser->setObjectName(QStringLiteral("btnChangeUser"));

        gridLayout->addWidget(btnChangeUser, 0, 0, 1, 1);

        btnChangePass = new QPushButton(widget);
        btnChangePass->setObjectName(QStringLiteral("btnChangePass"));

        gridLayout->addWidget(btnChangePass, 0, 1, 1, 1);

        btnAddUser = new QPushButton(widget);
        btnAddUser->setObjectName(QStringLiteral("btnAddUser"));
        btnAddUser->setEnabled(false);

        gridLayout->addWidget(btnAddUser, 0, 2, 1, 1);

        tableView = new QTableView(widget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout->addWidget(tableView, 1, 0, 1, 3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnFind = new QPushButton(widget);
        btnFind->setObjectName(QStringLiteral("btnFind"));

        horizontalLayout->addWidget(btnFind);

        txtByName = new QLineEdit(widget);
        txtByName->setObjectName(QStringLiteral("txtByName"));

        horizontalLayout->addWidget(txtByName);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 3);


        retranslateUi(BaseContents);

        QMetaObject::connectSlotsByName(BaseContents);
    } // setupUi

    void retranslateUi(QDialog *BaseContents)
    {
        BaseContents->setWindowTitle(QApplication::translate("BaseContents", "Dialog", nullptr));
        btnChangeUser->setText(QApplication::translate("BaseContents", "Change User", nullptr));
        btnChangePass->setText(QApplication::translate("BaseContents", "Change Password", nullptr));
        btnAddUser->setText(QApplication::translate("BaseContents", "New User", nullptr));
        btnFind->setText(QApplication::translate("BaseContents", "Find By Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BaseContents: public Ui_BaseContents {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASECONTENTS_H
