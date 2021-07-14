/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *OpenFileButton;
    QComboBox *comboBox;
    QTextBrowser *FilePath;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QCustomPlot *widget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1061, 659);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        OpenFileButton = new QPushButton(widget_2);
        OpenFileButton->setObjectName(QString::fromUtf8("OpenFileButton"));

        verticalLayout_2->addWidget(OpenFileButton);

        comboBox = new QComboBox(widget_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout_2->addWidget(comboBox);

        FilePath = new QTextBrowser(widget_2);
        FilePath->setObjectName(QString::fromUtf8("FilePath"));

        verticalLayout_2->addWidget(FilePath);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        gridLayout->addWidget(widget_2, 0, 0, 2, 1, Qt::AlignLeft);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QCustomPlot(widget_3);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout->addWidget(widget);


        verticalLayout_3->addLayout(verticalLayout);


        gridLayout->addWidget(widget_3, 0, 1, 2, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1061, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        OpenFileButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
