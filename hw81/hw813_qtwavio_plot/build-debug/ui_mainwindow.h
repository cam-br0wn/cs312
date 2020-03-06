/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave_as;
    QWidget *centralwidget;
    QLabel *label_sinfo;
    QLabel *label_stats;
    QPlainTextEdit *plainText_sinfo;
    QPlainTextEdit *plainTextEdit_stats;
    QPushButton *pushButton_play;
    QLabel *label_filename;
    QCustomPlot *customPlot;
    QLabel *label_zoom;
    QScrollBar *horizontalScrollBar_zoom;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_sinfo = new QLabel(centralwidget);
        label_sinfo->setObjectName(QString::fromUtf8("label_sinfo"));
        label_sinfo->setGeometry(QRect(20, 20, 91, 16));
        label_stats = new QLabel(centralwidget);
        label_stats->setObjectName(QString::fromUtf8("label_stats"));
        label_stats->setGeometry(QRect(390, 10, 91, 16));
        plainText_sinfo = new QPlainTextEdit(centralwidget);
        plainText_sinfo->setObjectName(QString::fromUtf8("plainText_sinfo"));
        plainText_sinfo->setGeometry(QRect(30, 40, 341, 201));
        plainTextEdit_stats = new QPlainTextEdit(centralwidget);
        plainTextEdit_stats->setObjectName(QString::fromUtf8("plainTextEdit_stats"));
        plainTextEdit_stats->setGeometry(QRect(390, 40, 391, 201));
        pushButton_play = new QPushButton(centralwidget);
        pushButton_play->setObjectName(QString::fromUtf8("pushButton_play"));
        pushButton_play->setGeometry(QRect(30, 260, 113, 32));
        label_filename = new QLabel(centralwidget);
        label_filename->setObjectName(QString::fromUtf8("label_filename"));
        label_filename->setGeometry(QRect(160, 270, 581, 16));
        customPlot = new QCustomPlot(centralwidget);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setGeometry(QRect(30, 310, 741, 181));
        label_zoom = new QLabel(centralwidget);
        label_zoom->setObjectName(QString::fromUtf8("label_zoom"));
        label_zoom->setGeometry(QRect(250, 510, 59, 16));
        horizontalScrollBar_zoom = new QScrollBar(centralwidget);
        horizontalScrollBar_zoom->setObjectName(QString::fromUtf8("horizontalScrollBar_zoom"));
        horizontalScrollBar_zoom->setGeometry(QRect(300, 510, 160, 16));
        horizontalScrollBar_zoom->setMaximum(100);
        horizontalScrollBar_zoom->setOrientation(Qt::Horizontal);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave_as);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "Open..", nullptr));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as", nullptr));
        label_sinfo->setText(QApplication::translate("MainWindow", "SF_INFO", nullptr));
        label_stats->setText(QApplication::translate("MainWindow", "Stats", nullptr));
        pushButton_play->setText(QApplication::translate("MainWindow", "Play", nullptr));
        label_filename->setText(QApplication::translate("MainWindow", "filename", nullptr));
        label_zoom->setText(QApplication::translate("MainWindow", "Zoom", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
