/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSlider *horizontalSlider_freq;
    QLabel *label_freq;
    QSlider *horizontalSlider_amp;
    QLabel *label_amp;
    QLabel *label_freqValue;
    QLabel *label_ampValue;
    QPushButton *pushButton_play;
    QPushButton *pushButton_stop;
    QCustomPlot *customPlot;
    QGroupBox *groupBox;
    QRadioButton *radioButton_square;
    QRadioButton *radioButton_sawup;
    QRadioButton *radioButton_sine;
    QRadioButton *radioButton_sawdown;
    QRadioButton *radioButton_triangle;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_plus;
    QSlider *horizontalSlider_harm;
    QLabel *label_numHarm;
    QLabel *label_harmValue;
    QToolButton *toolButton_GreenRed;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(782, 578);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalSlider_freq = new QSlider(centralwidget);
        horizontalSlider_freq->setObjectName(QString::fromUtf8("horizontalSlider_freq"));
        horizontalSlider_freq->setGeometry(QRect(30, 30, 611, 22));
        horizontalSlider_freq->setMinimum(20);
        horizontalSlider_freq->setMaximum(5000);
        horizontalSlider_freq->setValue(220);
        horizontalSlider_freq->setOrientation(Qt::Horizontal);
        label_freq = new QLabel(centralwidget);
        label_freq->setObjectName(QString::fromUtf8("label_freq"));
        label_freq->setGeometry(QRect(30, 10, 111, 16));
        horizontalSlider_amp = new QSlider(centralwidget);
        horizontalSlider_amp->setObjectName(QString::fromUtf8("horizontalSlider_amp"));
        horizontalSlider_amp->setGeometry(QRect(30, 90, 611, 22));
        horizontalSlider_amp->setMaximum(100);
        horizontalSlider_amp->setValue(50);
        horizontalSlider_amp->setOrientation(Qt::Horizontal);
        label_amp = new QLabel(centralwidget);
        label_amp->setObjectName(QString::fromUtf8("label_amp"));
        label_amp->setGeometry(QRect(30, 70, 91, 16));
        label_freqValue = new QLabel(centralwidget);
        label_freqValue->setObjectName(QString::fromUtf8("label_freqValue"));
        label_freqValue->setGeometry(QRect(660, 30, 59, 16));
        label_ampValue = new QLabel(centralwidget);
        label_ampValue->setObjectName(QString::fromUtf8("label_ampValue"));
        label_ampValue->setGeometry(QRect(660, 90, 59, 16));
        pushButton_play = new QPushButton(centralwidget);
        pushButton_play->setObjectName(QString::fromUtf8("pushButton_play"));
        pushButton_play->setGeometry(QRect(630, 490, 113, 32));
        pushButton_stop = new QPushButton(centralwidget);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(490, 490, 113, 32));
        customPlot = new QCustomPlot(centralwidget);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setGeometry(QRect(40, 240, 691, 241));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 170, 701, 61));
        groupBox->setFlat(true);
        radioButton_square = new QRadioButton(groupBox);
        radioButton_square->setObjectName(QString::fromUtf8("radioButton_square"));
        radioButton_square->setGeometry(QRect(150, 30, 100, 20));
        radioButton_sawup = new QRadioButton(groupBox);
        radioButton_sawup->setObjectName(QString::fromUtf8("radioButton_sawup"));
        radioButton_sawup->setGeometry(QRect(270, 30, 100, 20));
        radioButton_sine = new QRadioButton(groupBox);
        radioButton_sine->setObjectName(QString::fromUtf8("radioButton_sine"));
        radioButton_sine->setGeometry(QRect(30, 30, 100, 20));
        radioButton_sine->setChecked(true);
        radioButton_sawdown = new QRadioButton(groupBox);
        radioButton_sawdown->setObjectName(QString::fromUtf8("radioButton_sawdown"));
        radioButton_sawdown->setGeometry(QRect(390, 30, 100, 20));
        radioButton_triangle = new QRadioButton(groupBox);
        radioButton_triangle->setObjectName(QString::fromUtf8("radioButton_triangle"));
        radioButton_triangle->setGeometry(QRect(510, 30, 100, 20));
        pushButton_minus = new QPushButton(centralwidget);
        pushButton_minus->setObjectName(QString::fromUtf8("pushButton_minus"));
        pushButton_minus->setGeometry(QRect(720, 30, 31, 32));
        pushButton_plus = new QPushButton(centralwidget);
        pushButton_plus->setObjectName(QString::fromUtf8("pushButton_plus"));
        pushButton_plus->setGeometry(QRect(720, 10, 31, 31));
        horizontalSlider_harm = new QSlider(centralwidget);
        horizontalSlider_harm->setObjectName(QString::fromUtf8("horizontalSlider_harm"));
        horizontalSlider_harm->setGeometry(QRect(30, 155, 611, 22));
        horizontalSlider_harm->setMinimum(1);
        horizontalSlider_harm->setMaximum(50);
        horizontalSlider_harm->setValue(12);
        horizontalSlider_harm->setSliderPosition(12);
        horizontalSlider_harm->setOrientation(Qt::Horizontal);
        label_numHarm = new QLabel(centralwidget);
        label_numHarm->setObjectName(QString::fromUtf8("label_numHarm"));
        label_numHarm->setGeometry(QRect(30, 135, 101, 16));
        label_harmValue = new QLabel(centralwidget);
        label_harmValue->setObjectName(QString::fromUtf8("label_harmValue"));
        label_harmValue->setGeometry(QRect(660, 155, 71, 16));
        toolButton_GreenRed = new QToolButton(centralwidget);
        toolButton_GreenRed->setObjectName(QString::fromUtf8("toolButton_GreenRed"));
        toolButton_GreenRed->setGeometry(QRect(140, 130, 20, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 782, 22));
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
        label_freq->setText(QCoreApplication::translate("MainWindow", "Frequency in Hz", nullptr));
        label_amp->setText(QCoreApplication::translate("MainWindow", "Amplitude", nullptr));
        label_freqValue->setText(QCoreApplication::translate("MainWindow", "freqValue", nullptr));
        label_ampValue->setText(QCoreApplication::translate("MainWindow", "ampValue", nullptr));
        pushButton_play->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        groupBox->setTitle(QString());
        radioButton_square->setText(QCoreApplication::translate("MainWindow", "Square", nullptr));
        radioButton_sawup->setText(QCoreApplication::translate("MainWindow", "Saw Up", nullptr));
        radioButton_sine->setText(QCoreApplication::translate("MainWindow", "Sine", nullptr));
        radioButton_sawdown->setText(QCoreApplication::translate("MainWindow", "Saw Down", nullptr));
        radioButton_triangle->setText(QCoreApplication::translate("MainWindow", "Triangle", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        label_numHarm->setText(QCoreApplication::translate("MainWindow", "Num Harmonics", nullptr));
        label_harmValue->setText(QCoreApplication::translate("MainWindow", "harmValue", nullptr));
        toolButton_GreenRed->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
