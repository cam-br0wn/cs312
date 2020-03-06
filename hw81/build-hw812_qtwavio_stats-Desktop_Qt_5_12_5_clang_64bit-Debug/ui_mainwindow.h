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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

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
        label_sinfo->setGeometry(QRect(40, 40, 91, 16));
        label_stats = new QLabel(centralwidget);
        label_stats->setObjectName(QString::fromUtf8("label_stats"));
        label_stats->setGeometry(QRect(430, 40, 91, 16));
        plainText_sinfo = new QPlainTextEdit(centralwidget);
        plainText_sinfo->setObjectName(QString::fromUtf8("plainText_sinfo"));
        plainText_sinfo->setGeometry(QRect(40, 60, 361, 271));
        plainTextEdit_stats = new QPlainTextEdit(centralwidget);
        plainTextEdit_stats->setObjectName(QString::fromUtf8("plainTextEdit_stats"));
        plainTextEdit_stats->setGeometry(QRect(430, 60, 361, 271));
        pushButton_play = new QPushButton(centralwidget);
        pushButton_play->setObjectName(QString::fromUtf8("pushButton_play"));
        pushButton_play->setGeometry(QRect(40, 360, 113, 32));
        label_filename = new QLabel(centralwidget);
        label_filename->setObjectName(QString::fromUtf8("label_filename"));
        label_filename->setGeometry(QRect(160, 370, 581, 16));
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
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
