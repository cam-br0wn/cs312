/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QCustomPlot *customPlot;
    QLabel *label_A;
    QLabel *label_D;
    QLabel *label_R;
    QSlider *verticalSlider_D;
    QSlider *verticalSlider_R;
    QSlider *verticalSlider_A;
    QLabel *label_Aval;
    QLabel *label_Dval;
    QLabel *label_Rval;
    QSlider *verticalSlider_SL;
    QLabel *label_SL;
    QLabel *label_SLval;
    QToolButton *toolButton_loC;
    QToolButton *toolButton_D;
    QToolButton *toolButton_Db;
    QToolButton *toolButton_B;
    QToolButton *toolButton_E;
    QToolButton *toolButton_Eb;
    QToolButton *toolButton_G;
    QToolButton *toolButton_Gb;
    QToolButton *toolButton_F;
    QToolButton *toolButton_Ab;
    QToolButton *toolButton_Bb;
    QToolButton *toolButton_A;
    QToolButton *toolButton_hiC;
    QSlider *verticalSlider_volume;
    QLabel *label;
    QLabel *label_volume;
    QPushButton *pushButton_Stop;
    QPushButton *pushButton_quit;
    QComboBox *comboBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(807, 590);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        customPlot = new QCustomPlot(centralwidget);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setGeometry(QRect(240, 100, 531, 181));
        label_A = new QLabel(centralwidget);
        label_A->setObjectName(QString::fromUtf8("label_A"));
        label_A->setGeometry(QRect(30, 290, 21, 31));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label_A->setFont(font);
        label_A->setAlignment(Qt::AlignCenter);
        label_D = new QLabel(centralwidget);
        label_D->setObjectName(QString::fromUtf8("label_D"));
        label_D->setGeometry(QRect(80, 290, 21, 31));
        label_D->setFont(font);
        label_D->setAlignment(Qt::AlignCenter);
        label_R = new QLabel(centralwidget);
        label_R->setObjectName(QString::fromUtf8("label_R"));
        label_R->setGeometry(QRect(180, 290, 21, 31));
        label_R->setFont(font);
        label_R->setAlignment(Qt::AlignCenter);
        verticalSlider_D = new QSlider(centralwidget);
        verticalSlider_D->setObjectName(QString::fromUtf8("verticalSlider_D"));
        verticalSlider_D->setGeometry(QRect(80, 30, 22, 251));
        verticalSlider_D->setMinimum(1);
        verticalSlider_D->setMaximum(1000);
        verticalSlider_D->setValue(50);
        verticalSlider_D->setOrientation(Qt::Vertical);
        verticalSlider_R = new QSlider(centralwidget);
        verticalSlider_R->setObjectName(QString::fromUtf8("verticalSlider_R"));
        verticalSlider_R->setGeometry(QRect(180, 30, 22, 251));
        verticalSlider_R->setMinimum(1);
        verticalSlider_R->setMaximum(1000);
        verticalSlider_R->setValue(50);
        verticalSlider_R->setSliderPosition(50);
        verticalSlider_R->setOrientation(Qt::Vertical);
        verticalSlider_A = new QSlider(centralwidget);
        verticalSlider_A->setObjectName(QString::fromUtf8("verticalSlider_A"));
        verticalSlider_A->setGeometry(QRect(30, 30, 22, 251));
        verticalSlider_A->setMinimum(1);
        verticalSlider_A->setMaximum(1000);
        verticalSlider_A->setValue(50);
        verticalSlider_A->setOrientation(Qt::Vertical);
        label_Aval = new QLabel(centralwidget);
        label_Aval->setObjectName(QString::fromUtf8("label_Aval"));
        label_Aval->setGeometry(QRect(30, 10, 31, 16));
        label_Dval = new QLabel(centralwidget);
        label_Dval->setObjectName(QString::fromUtf8("label_Dval"));
        label_Dval->setGeometry(QRect(80, 10, 31, 16));
        label_Rval = new QLabel(centralwidget);
        label_Rval->setObjectName(QString::fromUtf8("label_Rval"));
        label_Rval->setGeometry(QRect(180, 10, 31, 16));
        verticalSlider_SL = new QSlider(centralwidget);
        verticalSlider_SL->setObjectName(QString::fromUtf8("verticalSlider_SL"));
        verticalSlider_SL->setGeometry(QRect(130, 30, 22, 251));
        verticalSlider_SL->setMaximum(1000);
        verticalSlider_SL->setValue(25);
        verticalSlider_SL->setOrientation(Qt::Vertical);
        label_SL = new QLabel(centralwidget);
        label_SL->setObjectName(QString::fromUtf8("label_SL"));
        label_SL->setGeometry(QRect(130, 290, 21, 31));
        label_SL->setFont(font);
        label_SL->setAlignment(Qt::AlignCenter);
        label_SLval = new QLabel(centralwidget);
        label_SLval->setObjectName(QString::fromUtf8("label_SLval"));
        label_SLval->setGeometry(QRect(130, 10, 31, 16));
        toolButton_loC = new QToolButton(centralwidget);
        toolButton_loC->setObjectName(QString::fromUtf8("toolButton_loC"));
        toolButton_loC->setGeometry(QRect(250, 360, 31, 141));
        toolButton_D = new QToolButton(centralwidget);
        toolButton_D->setObjectName(QString::fromUtf8("toolButton_D"));
        toolButton_D->setGeometry(QRect(310, 360, 31, 141));
        toolButton_Db = new QToolButton(centralwidget);
        toolButton_Db->setObjectName(QString::fromUtf8("toolButton_Db"));
        toolButton_Db->setGeometry(QRect(280, 360, 31, 91));
        toolButton_B = new QToolButton(centralwidget);
        toolButton_B->setObjectName(QString::fromUtf8("toolButton_B"));
        toolButton_B->setGeometry(QRect(580, 360, 31, 141));
        toolButton_E = new QToolButton(centralwidget);
        toolButton_E->setObjectName(QString::fromUtf8("toolButton_E"));
        toolButton_E->setGeometry(QRect(370, 360, 31, 141));
        toolButton_Eb = new QToolButton(centralwidget);
        toolButton_Eb->setObjectName(QString::fromUtf8("toolButton_Eb"));
        toolButton_Eb->setGeometry(QRect(340, 360, 31, 91));
        toolButton_G = new QToolButton(centralwidget);
        toolButton_G->setObjectName(QString::fromUtf8("toolButton_G"));
        toolButton_G->setGeometry(QRect(460, 360, 31, 141));
        toolButton_Gb = new QToolButton(centralwidget);
        toolButton_Gb->setObjectName(QString::fromUtf8("toolButton_Gb"));
        toolButton_Gb->setGeometry(QRect(430, 360, 31, 91));
        toolButton_F = new QToolButton(centralwidget);
        toolButton_F->setObjectName(QString::fromUtf8("toolButton_F"));
        toolButton_F->setGeometry(QRect(400, 360, 31, 141));
        toolButton_Ab = new QToolButton(centralwidget);
        toolButton_Ab->setObjectName(QString::fromUtf8("toolButton_Ab"));
        toolButton_Ab->setGeometry(QRect(490, 360, 31, 91));
        toolButton_Bb = new QToolButton(centralwidget);
        toolButton_Bb->setObjectName(QString::fromUtf8("toolButton_Bb"));
        toolButton_Bb->setGeometry(QRect(550, 360, 31, 91));
        toolButton_A = new QToolButton(centralwidget);
        toolButton_A->setObjectName(QString::fromUtf8("toolButton_A"));
        toolButton_A->setGeometry(QRect(520, 360, 31, 141));
        toolButton_hiC = new QToolButton(centralwidget);
        toolButton_hiC->setObjectName(QString::fromUtf8("toolButton_hiC"));
        toolButton_hiC->setGeometry(QRect(610, 360, 31, 141));
        verticalSlider_volume = new QSlider(centralwidget);
        verticalSlider_volume->setObjectName(QString::fromUtf8("verticalSlider_volume"));
        verticalSlider_volume->setGeometry(QRect(180, 370, 22, 141));
        verticalSlider_volume->setMaximum(100);
        verticalSlider_volume->setValue(50);
        verticalSlider_volume->setOrientation(Qt::Vertical);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 520, 59, 16));
        label->setAlignment(Qt::AlignCenter);
        label_volume = new QLabel(centralwidget);
        label_volume->setObjectName(QString::fromUtf8("label_volume"));
        label_volume->setGeometry(QRect(160, 350, 59, 16));
        label_volume->setAlignment(Qt::AlignCenter);
        pushButton_Stop = new QPushButton(centralwidget);
        pushButton_Stop->setObjectName(QString::fromUtf8("pushButton_Stop"));
        pushButton_Stop->setGeometry(QRect(670, 360, 113, 32));
        pushButton_quit = new QPushButton(centralwidget);
        pushButton_quit->setObjectName(QString::fromUtf8("pushButton_quit"));
        pushButton_quit->setGeometry(QRect(670, 390, 113, 32));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(30, 340, 131, 32));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 807, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        comboBox->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_A->setText(QApplication::translate("MainWindow", "A", nullptr));
        label_D->setText(QApplication::translate("MainWindow", "D", nullptr));
        label_R->setText(QApplication::translate("MainWindow", "R", nullptr));
        label_Aval->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_Dval->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_Rval->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_SL->setText(QApplication::translate("MainWindow", "SL", nullptr));
        label_SLval->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        toolButton_loC->setText(QApplication::translate("MainWindow", "C", nullptr));
        toolButton_D->setText(QApplication::translate("MainWindow", "D", nullptr));
        toolButton_Db->setText(QApplication::translate("MainWindow", "C#", nullptr));
        toolButton_B->setText(QApplication::translate("MainWindow", "B", nullptr));
        toolButton_E->setText(QApplication::translate("MainWindow", "E", nullptr));
        toolButton_Eb->setText(QApplication::translate("MainWindow", "D#", nullptr));
        toolButton_G->setText(QApplication::translate("MainWindow", "G", nullptr));
        toolButton_Gb->setText(QApplication::translate("MainWindow", "F#", nullptr));
        toolButton_F->setText(QApplication::translate("MainWindow", "F", nullptr));
        toolButton_Ab->setText(QApplication::translate("MainWindow", "G#", nullptr));
        toolButton_Bb->setText(QApplication::translate("MainWindow", "A#", nullptr));
        toolButton_A->setText(QApplication::translate("MainWindow", "A", nullptr));
        toolButton_hiC->setText(QApplication::translate("MainWindow", "C", nullptr));
        label->setText(QApplication::translate("MainWindow", "Volume", nullptr));
        label_volume->setText(QApplication::translate("MainWindow", "0.5", nullptr));
        pushButton_Stop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        pushButton_quit->setText(QApplication::translate("MainWindow", "Quit", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "Start Note 24", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "Start Note 36", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "Start Note 48", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "Start Note 60", nullptr));
        comboBox->setItemText(4, QApplication::translate("MainWindow", "Start Note 72", nullptr));
        comboBox->setItemText(5, QApplication::translate("MainWindow", "Start Note 84", nullptr));
        comboBox->setItemText(6, QApplication::translate("MainWindow", "Start Note 96", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
