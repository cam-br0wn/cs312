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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSlider *verticalSlider_wavetable;
    QLabel *label_tablesizeValue;
    QPushButton *pushButton_generate;
    QCustomPlot *customPlot;
    QPushButton *pushButton_save;
    QPushButton *pushButton_truncate;
    QPushButton *pushButton_round;
    QPushButton *pushButton_interpolate;
    QSlider *verticalSlider_frequency;
    QLabel *label_frequencyValue;
    QLabel *label_freq;
    QSlider *verticalSlider_amplitude;
    QLabel *label_amp;
    QLabel *label_amplitudeValue;
    QScrollBar *horizontalScrollBar_zoom;
    QLabel *label_sizeTable;
    QCheckBox *checkBox_440;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalSlider_wavetable = new QSlider(centralwidget);
        verticalSlider_wavetable->setObjectName(QString::fromUtf8("verticalSlider_wavetable"));
        verticalSlider_wavetable->setGeometry(QRect(60, 40, 22, 201));
        verticalSlider_wavetable->setMinimum(1);
        verticalSlider_wavetable->setMaximum(12);
        verticalSlider_wavetable->setPageStep(1);
        verticalSlider_wavetable->setValue(3);
        verticalSlider_wavetable->setOrientation(Qt::Vertical);
        label_tablesizeValue = new QLabel(centralwidget);
        label_tablesizeValue->setObjectName(QString::fromUtf8("label_tablesizeValue"));
        label_tablesizeValue->setGeometry(QRect(40, 20, 59, 16));
        label_tablesizeValue->setAlignment(Qt::AlignCenter);
        pushButton_generate = new QPushButton(centralwidget);
        pushButton_generate->setObjectName(QString::fromUtf8("pushButton_generate"));
        pushButton_generate->setGeometry(QRect(170, 210, 121, 32));
        customPlot = new QCustomPlot(centralwidget);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setGeometry(QRect(30, 290, 731, 231));
        pushButton_save = new QPushButton(centralwidget);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setGeometry(QRect(170, 170, 121, 32));
        pushButton_truncate = new QPushButton(centralwidget);
        pushButton_truncate->setObjectName(QString::fromUtf8("pushButton_truncate"));
        pushButton_truncate->setGeometry(QRect(170, 50, 121, 32));
        pushButton_round = new QPushButton(centralwidget);
        pushButton_round->setObjectName(QString::fromUtf8("pushButton_round"));
        pushButton_round->setGeometry(QRect(170, 90, 121, 32));
        pushButton_interpolate = new QPushButton(centralwidget);
        pushButton_interpolate->setObjectName(QString::fromUtf8("pushButton_interpolate"));
        pushButton_interpolate->setGeometry(QRect(170, 130, 121, 32));
        verticalSlider_frequency = new QSlider(centralwidget);
        verticalSlider_frequency->setObjectName(QString::fromUtf8("verticalSlider_frequency"));
        verticalSlider_frequency->setGeometry(QRect(530, 40, 22, 201));
        verticalSlider_frequency->setMinimum(1);
        verticalSlider_frequency->setMaximum(50);
        verticalSlider_frequency->setSingleStep(1);
        verticalSlider_frequency->setPageStep(10);
        verticalSlider_frequency->setValue(4);
        verticalSlider_frequency->setSliderPosition(4);
        verticalSlider_frequency->setOrientation(Qt::Vertical);
        label_frequencyValue = new QLabel(centralwidget);
        label_frequencyValue->setObjectName(QString::fromUtf8("label_frequencyValue"));
        label_frequencyValue->setGeometry(QRect(510, 20, 59, 16));
        label_frequencyValue->setAlignment(Qt::AlignCenter);
        label_freq = new QLabel(centralwidget);
        label_freq->setObjectName(QString::fromUtf8("label_freq"));
        label_freq->setGeometry(QRect(500, 250, 81, 16));
        label_freq->setAlignment(Qt::AlignCenter);
        verticalSlider_amplitude = new QSlider(centralwidget);
        verticalSlider_amplitude->setObjectName(QString::fromUtf8("verticalSlider_amplitude"));
        verticalSlider_amplitude->setGeometry(QRect(390, 40, 22, 201));
        verticalSlider_amplitude->setMinimum(0);
        verticalSlider_amplitude->setMaximum(100);
        verticalSlider_amplitude->setSingleStep(1);
        verticalSlider_amplitude->setPageStep(10);
        verticalSlider_amplitude->setValue(90);
        verticalSlider_amplitude->setSliderPosition(90);
        verticalSlider_amplitude->setOrientation(Qt::Vertical);
        label_amp = new QLabel(centralwidget);
        label_amp->setObjectName(QString::fromUtf8("label_amp"));
        label_amp->setGeometry(QRect(360, 250, 81, 16));
        label_amp->setAlignment(Qt::AlignCenter);
        label_amplitudeValue = new QLabel(centralwidget);
        label_amplitudeValue->setObjectName(QString::fromUtf8("label_amplitudeValue"));
        label_amplitudeValue->setGeometry(QRect(370, 20, 59, 16));
        label_amplitudeValue->setAlignment(Qt::AlignCenter);
        horizontalScrollBar_zoom = new QScrollBar(centralwidget);
        horizontalScrollBar_zoom->setObjectName(QString::fromUtf8("horizontalScrollBar_zoom"));
        horizontalScrollBar_zoom->setGeometry(QRect(310, 530, 160, 16));
        horizontalScrollBar_zoom->setMinimum(1);
        horizontalScrollBar_zoom->setMaximum(100);
        horizontalScrollBar_zoom->setOrientation(Qt::Horizontal);
        label_sizeTable = new QLabel(centralwidget);
        label_sizeTable->setObjectName(QString::fromUtf8("label_sizeTable"));
        label_sizeTable->setGeometry(QRect(30, 250, 81, 16));
        label_sizeTable->setAlignment(Qt::AlignCenter);
        checkBox_440 = new QCheckBox(centralwidget);
        checkBox_440->setObjectName(QString::fromUtf8("checkBox_440"));
        checkBox_440->setGeometry(QRect(160, 240, 131, 20));
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
        label_tablesizeValue->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_generate->setText(QApplication::translate("MainWindow", "Generate Table", nullptr));
        pushButton_save->setText(QApplication::translate("MainWindow", "Save", nullptr));
        pushButton_truncate->setText(QApplication::translate("MainWindow", "Truncate", nullptr));
        pushButton_round->setText(QApplication::translate("MainWindow", "Round", nullptr));
        pushButton_interpolate->setText(QApplication::translate("MainWindow", "Interpolate", nullptr));
        label_frequencyValue->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_freq->setText(QApplication::translate("MainWindow", "Frequency", nullptr));
        label_amp->setText(QApplication::translate("MainWindow", "Amplitude", nullptr));
        label_amplitudeValue->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_sizeTable->setText(QApplication::translate("MainWindow", "Table Size", nullptr));
        checkBox_440->setText(QApplication::translate("MainWindow", "440Hz Sample", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
