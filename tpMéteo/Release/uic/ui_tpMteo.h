/********************************************************************************
** Form generated from reading UI file 'tpMteo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TPMTEO_H
#define UI_TPMTEO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tpMteoClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *On;
    QPushButton *Off;
    QLabel *temp;
    QLabel *label_10;
    QLabel *bruteValue;
    QLabel *label_2;
    QLabel *tension;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *tpMteoClass)
    {
        if (tpMteoClass->objectName().isEmpty())
            tpMteoClass->setObjectName(QString::fromUtf8("tpMteoClass"));
        tpMteoClass->resize(600, 400);
        centralWidget = new QWidget(tpMteoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 50, 71, 16));
        On = new QPushButton(centralWidget);
        On->setObjectName(QString::fromUtf8("On"));
        On->setGeometry(QRect(40, 40, 75, 31));
        Off = new QPushButton(centralWidget);
        Off->setObjectName(QString::fromUtf8("Off"));
        Off->setGeometry(QRect(40, 80, 75, 31));
        temp = new QLabel(centralWidget);
        temp->setObjectName(QString::fromUtf8("temp"));
        temp->setGeometry(QRect(260, 130, 91, 21));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(180, 130, 71, 16));
        bruteValue = new QLabel(centralWidget);
        bruteValue->setObjectName(QString::fromUtf8("bruteValue"));
        bruteValue->setGeometry(QRect(260, 50, 61, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 90, 47, 21));
        tension = new QLabel(centralWidget);
        tension->setObjectName(QString::fromUtf8("tension"));
        tension->setGeometry(QRect(240, 92, 71, 21));
        tpMteoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(tpMteoClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        tpMteoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(tpMteoClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        tpMteoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(tpMteoClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        tpMteoClass->setStatusBar(statusBar);

        retranslateUi(tpMteoClass);
        QObject::connect(On, SIGNAL(clicked()), tpMteoClass, SLOT(On()));
        QObject::connect(Off, SIGNAL(clicked()), tpMteoClass, SLOT(Off()));

        QMetaObject::connectSlotsByName(tpMteoClass);
    } // setupUi

    void retranslateUi(QMainWindow *tpMteoClass)
    {
        tpMteoClass->setWindowTitle(QCoreApplication::translate("tpMteoClass", "tpMteo", nullptr));
        label->setText(QCoreApplication::translate("tpMteoClass", "Valeur brute :", nullptr));
        On->setText(QCoreApplication::translate("tpMteoClass", "Allumer", nullptr));
        Off->setText(QCoreApplication::translate("tpMteoClass", "Eteindre", nullptr));
        temp->setText(QString());
        label_10->setText(QCoreApplication::translate("tpMteoClass", "Temp\303\251rature :", nullptr));
        bruteValue->setText(QString());
        label_2->setText(QCoreApplication::translate("tpMteoClass", "Tension :", nullptr));
        tension->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class tpMteoClass: public Ui_tpMteoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TPMTEO_H
