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
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_freq;
    QScrollBar *horizontalSlider_freq;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_play;
    QLabel *label_freqValue;
    QScrollBar *horizontalSlider_amp;
    QLabel *label_amp;
    QLabel *label_ampValue;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_freq = new QLabel(centralwidget);
        label_freq->setObjectName(QString::fromUtf8("label_freq"));
        label_freq->setGeometry(QRect(40, 40, 91, 16));
        horizontalSlider_freq = new QScrollBar(centralwidget);
        horizontalSlider_freq->setObjectName(QString::fromUtf8("horizontalSlider_freq"));
        horizontalSlider_freq->setGeometry(QRect(40, 80, 621, 16));
        horizontalSlider_freq->setMinimum(20);
        horizontalSlider_freq->setMaximum(4000);
        horizontalSlider_freq->setValue(220);
        horizontalSlider_freq->setOrientation(Qt::Horizontal);
        pushButton_stop = new QPushButton(centralwidget);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(460, 430, 113, 32));
        pushButton_play = new QPushButton(centralwidget);
        pushButton_play->setObjectName(QString::fromUtf8("pushButton_play"));
        pushButton_play->setGeometry(QRect(610, 430, 113, 32));
        label_freqValue = new QLabel(centralwidget);
        label_freqValue->setObjectName(QString::fromUtf8("label_freqValue"));
        label_freqValue->setGeometry(QRect(670, 80, 81, 16));
        horizontalSlider_amp = new QScrollBar(centralwidget);
        horizontalSlider_amp->setObjectName(QString::fromUtf8("horizontalSlider_amp"));
        horizontalSlider_amp->setGeometry(QRect(40, 250, 621, 16));
        horizontalSlider_amp->setMaximum(100);
        horizontalSlider_amp->setValue(50);
        horizontalSlider_amp->setOrientation(Qt::Horizontal);
        label_amp = new QLabel(centralwidget);
        label_amp->setObjectName(QString::fromUtf8("label_amp"));
        label_amp->setGeometry(QRect(40, 210, 71, 16));
        label_ampValue = new QLabel(centralwidget);
        label_ampValue->setObjectName(QString::fromUtf8("label_ampValue"));
        label_ampValue->setGeometry(QRect(670, 250, 81, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_freq->setText(QApplication::translate("MainWindow", "Frequency Hz", nullptr));
        pushButton_stop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        pushButton_play->setText(QApplication::translate("MainWindow", "Play", nullptr));
        label_freqValue->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_amp->setText(QApplication::translate("MainWindow", "Amplitude", nullptr));
        label_ampValue->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
