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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave_As;
    QWidget *centralwidget;
    QPlainTextEdit *plainTextEdit_sfinfo;
    QPlainTextEdit *plainTextEdit_stats;
    QLabel *label_sfinfo;
    QLabel *label_stats;
    QLabel *label_filename;
    QGroupBox *groupBox;
    QRadioButton *radioButton_removedc;
    QRadioButton *radioButton_normalize;
    QRadioButton *radioButton_reverse;
    QRadioButton *radioButton_echo;
    QRadioButton *radioButton_changespeed;
    QRadioButton *radioButton_amplify;
    QRadioButton *radioButton_randomsnips;
    QStackedWidget *stackedWidget;
    QWidget *removedc;
    QLabel *label_9;
    QWidget *normalize;
    QLabel *label_dBnormalize;
    QDoubleSpinBox *doubleSpinBox_normalize;
    QLabel *label;
    QLabel *label_10;
    QWidget *amplify;
    QSlider *verticalSlider_amplify;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QDoubleSpinBox *doubleSpinBox_amplify;
    QWidget *reverse;
    QLabel *label_14;
    QWidget *echo;
    QSlider *horizontalSlider_echonum;
    QSlider *horizontalSlider_echodamp;
    QLabel *label_echonum;
    QSlider *horizontalSlider_echodelay;
    QLabel *label_echodelay;
    QLabel *label_echodamp;
    QLabel *label_15;
    QLabel *label_echonumval;
    QLabel *label_echodelayval;
    QLabel *label_echodampval;
    QWidget *changespeed;
    QSlider *horizontalSlider_speedChange;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_16;
    QLabel *label_speedVal;
    QWidget *page;
    QLabel *label_7;
    QSlider *horizontalSlider_maxlen;
    QSlider *horizontalSlider_reps;
    QLabel *label_maxlenvalue;
    QLabel *label_repsvalue;
    QLabel *label_maxlen;
    QLabel *label_reps;
    QLabel *label_seconds;
    QLabel *label_secondsval;
    QPushButton *pushButton_quit;
    QPushButton *pushButton_open;
    QPushButton *pushButton_Play;
    QPushButton *pushButton_save;
    QPushButton *pushButton_apply;
    QPushButton *pushButton_stop;
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
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        plainTextEdit_sfinfo = new QPlainTextEdit(centralwidget);
        plainTextEdit_sfinfo->setObjectName(QString::fromUtf8("plainTextEdit_sfinfo"));
        plainTextEdit_sfinfo->setGeometry(QRect(30, 20, 361, 241));
        plainTextEdit_stats = new QPlainTextEdit(centralwidget);
        plainTextEdit_stats->setObjectName(QString::fromUtf8("plainTextEdit_stats"));
        plainTextEdit_stats->setGeometry(QRect(410, 20, 361, 241));
        label_sfinfo = new QLabel(centralwidget);
        label_sfinfo->setObjectName(QString::fromUtf8("label_sfinfo"));
        label_sfinfo->setGeometry(QRect(30, 0, 59, 16));
        label_stats = new QLabel(centralwidget);
        label_stats->setObjectName(QString::fromUtf8("label_stats"));
        label_stats->setGeometry(QRect(410, 0, 59, 16));
        label_filename = new QLabel(centralwidget);
        label_filename->setObjectName(QString::fromUtf8("label_filename"));
        label_filename->setGeometry(QRect(90, 270, 641, 20));
        label_filename->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 280, 211, 261));
        radioButton_removedc = new QRadioButton(groupBox);
        radioButton_removedc->setObjectName(QString::fromUtf8("radioButton_removedc"));
        radioButton_removedc->setGeometry(QRect(20, 40, 100, 20));
        radioButton_removedc->setChecked(true);
        radioButton_normalize = new QRadioButton(groupBox);
        radioButton_normalize->setObjectName(QString::fromUtf8("radioButton_normalize"));
        radioButton_normalize->setGeometry(QRect(20, 70, 100, 20));
        radioButton_reverse = new QRadioButton(groupBox);
        radioButton_reverse->setObjectName(QString::fromUtf8("radioButton_reverse"));
        radioButton_reverse->setGeometry(QRect(20, 130, 100, 20));
        radioButton_echo = new QRadioButton(groupBox);
        radioButton_echo->setObjectName(QString::fromUtf8("radioButton_echo"));
        radioButton_echo->setGeometry(QRect(20, 160, 100, 20));
        radioButton_changespeed = new QRadioButton(groupBox);
        radioButton_changespeed->setObjectName(QString::fromUtf8("radioButton_changespeed"));
        radioButton_changespeed->setGeometry(QRect(20, 190, 121, 20));
        radioButton_amplify = new QRadioButton(groupBox);
        radioButton_amplify->setObjectName(QString::fromUtf8("radioButton_amplify"));
        radioButton_amplify->setGeometry(QRect(20, 100, 100, 20));
        radioButton_randomsnips = new QRadioButton(groupBox);
        radioButton_randomsnips->setObjectName(QString::fromUtf8("radioButton_randomsnips"));
        radioButton_randomsnips->setGeometry(QRect(20, 220, 131, 20));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(240, 300, 421, 241));
        stackedWidget->setFrameShape(QFrame::StyledPanel);
        removedc = new QWidget();
        removedc->setObjectName(QString::fromUtf8("removedc"));
        label_9 = new QLabel(removedc);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 10, 91, 16));
        stackedWidget->addWidget(removedc);
        normalize = new QWidget();
        normalize->setObjectName(QString::fromUtf8("normalize"));
        label_dBnormalize = new QLabel(normalize);
        label_dBnormalize->setObjectName(QString::fromUtf8("label_dBnormalize"));
        label_dBnormalize->setGeometry(QRect(240, 110, 59, 22));
        doubleSpinBox_normalize = new QDoubleSpinBox(normalize);
        doubleSpinBox_normalize->setObjectName(QString::fromUtf8("doubleSpinBox_normalize"));
        doubleSpinBox_normalize->setGeometry(QRect(131, 110, 91, 22));
        doubleSpinBox_normalize->setMinimum(-48.000000000000000);
        doubleSpinBox_normalize->setMaximum(0.000000000000000);
        doubleSpinBox_normalize->setSingleStep(1.000000000000000);
        label = new QLabel(normalize);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 110, 101, 22));
        label_10 = new QLabel(normalize);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 10, 71, 16));
        stackedWidget->addWidget(normalize);
        amplify = new QWidget();
        amplify->setObjectName(QString::fromUtf8("amplify"));
        verticalSlider_amplify = new QSlider(amplify);
        verticalSlider_amplify->setObjectName(QString::fromUtf8("verticalSlider_amplify"));
        verticalSlider_amplify->setGeometry(QRect(160, 20, 22, 201));
        verticalSlider_amplify->setMaximum(100);
        verticalSlider_amplify->setValue(50);
        verticalSlider_amplify->setOrientation(Qt::Vertical);
        label_11 = new QLabel(amplify);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 10, 59, 16));
        label_12 = new QLabel(amplify);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(120, 20, 31, 16));
        label_13 = new QLabel(amplify);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(120, 200, 31, 16));
        doubleSpinBox_amplify = new QDoubleSpinBox(amplify);
        doubleSpinBox_amplify->setObjectName(QString::fromUtf8("doubleSpinBox_amplify"));
        doubleSpinBox_amplify->setGeometry(QRect(190, 110, 62, 22));
        doubleSpinBox_amplify->setReadOnly(true);
        doubleSpinBox_amplify->setMaximum(1.000000000000000);
        doubleSpinBox_amplify->setSingleStep(0.010000000000000);
        doubleSpinBox_amplify->setValue(0.500000000000000);
        stackedWidget->addWidget(amplify);
        reverse = new QWidget();
        reverse->setObjectName(QString::fromUtf8("reverse"));
        label_14 = new QLabel(reverse);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 10, 59, 16));
        stackedWidget->addWidget(reverse);
        echo = new QWidget();
        echo->setObjectName(QString::fromUtf8("echo"));
        horizontalSlider_echonum = new QSlider(echo);
        horizontalSlider_echonum->setObjectName(QString::fromUtf8("horizontalSlider_echonum"));
        horizontalSlider_echonum->setGeometry(QRect(20, 60, 321, 22));
        horizontalSlider_echonum->setMinimum(1);
        horizontalSlider_echonum->setMaximum(10);
        horizontalSlider_echonum->setPageStep(1);
        horizontalSlider_echonum->setOrientation(Qt::Horizontal);
        horizontalSlider_echonum->setTickPosition(QSlider::TicksBothSides);
        horizontalSlider_echodamp = new QSlider(echo);
        horizontalSlider_echodamp->setObjectName(QString::fromUtf8("horizontalSlider_echodamp"));
        horizontalSlider_echodamp->setGeometry(QRect(20, 190, 321, 22));
        horizontalSlider_echodamp->setMaximum(100);
        horizontalSlider_echodamp->setOrientation(Qt::Horizontal);
        label_echonum = new QLabel(echo);
        label_echonum->setObjectName(QString::fromUtf8("label_echonum"));
        label_echonum->setGeometry(QRect(30, 40, 121, 16));
        horizontalSlider_echodelay = new QSlider(echo);
        horizontalSlider_echodelay->setObjectName(QString::fromUtf8("horizontalSlider_echodelay"));
        horizontalSlider_echodelay->setGeometry(QRect(20, 130, 321, 22));
        horizontalSlider_echodelay->setMaximum(1000);
        horizontalSlider_echodelay->setOrientation(Qt::Horizontal);
        label_echodelay = new QLabel(echo);
        label_echodelay->setObjectName(QString::fromUtf8("label_echodelay"));
        label_echodelay->setGeometry(QRect(30, 110, 121, 16));
        label_echodamp = new QLabel(echo);
        label_echodamp->setObjectName(QString::fromUtf8("label_echodamp"));
        label_echodamp->setGeometry(QRect(30, 170, 201, 16));
        label_15 = new QLabel(echo);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 10, 59, 16));
        label_echonumval = new QLabel(echo);
        label_echonumval->setObjectName(QString::fromUtf8("label_echonumval"));
        label_echonumval->setGeometry(QRect(350, 60, 59, 16));
        label_echonumval->setAlignment(Qt::AlignCenter);
        label_echodelayval = new QLabel(echo);
        label_echodelayval->setObjectName(QString::fromUtf8("label_echodelayval"));
        label_echodelayval->setGeometry(QRect(350, 130, 59, 16));
        label_echodelayval->setAlignment(Qt::AlignCenter);
        label_echodampval = new QLabel(echo);
        label_echodampval->setObjectName(QString::fromUtf8("label_echodampval"));
        label_echodampval->setGeometry(QRect(350, 190, 59, 16));
        label_echodampval->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(echo);
        changespeed = new QWidget();
        changespeed->setObjectName(QString::fromUtf8("changespeed"));
        horizontalSlider_speedChange = new QSlider(changespeed);
        horizontalSlider_speedChange->setObjectName(QString::fromUtf8("horizontalSlider_speedChange"));
        horizontalSlider_speedChange->setGeometry(QRect(20, 120, 291, 22));
        horizontalSlider_speedChange->setMinimum(0);
        horizontalSlider_speedChange->setMaximum(30);
        horizontalSlider_speedChange->setValue(10);
        horizontalSlider_speedChange->setOrientation(Qt::Horizontal);
        horizontalSlider_speedChange->setTickPosition(QSlider::TicksBothSides);
        horizontalSlider_speedChange->setTickInterval(10);
        label_5 = new QLabel(changespeed);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 100, 59, 16));
        label_6 = new QLabel(changespeed);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(250, 100, 59, 16));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_16 = new QLabel(changespeed);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 10, 111, 16));
        label_speedVal = new QLabel(changespeed);
        label_speedVal->setObjectName(QString::fromUtf8("label_speedVal"));
        label_speedVal->setGeometry(QRect(90, 90, 59, 16));
        label_speedVal->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(changespeed);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        label_7 = new QLabel(page);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 10, 111, 16));
        horizontalSlider_maxlen = new QSlider(page);
        horizontalSlider_maxlen->setObjectName(QString::fromUtf8("horizontalSlider_maxlen"));
        horizontalSlider_maxlen->setGeometry(QRect(90, 70, 281, 22));
        horizontalSlider_maxlen->setMinimum(50);
        horizontalSlider_maxlen->setMaximum(650);
        horizontalSlider_maxlen->setValue(400);
        horizontalSlider_maxlen->setOrientation(Qt::Horizontal);
        horizontalSlider_reps = new QSlider(page);
        horizontalSlider_reps->setObjectName(QString::fromUtf8("horizontalSlider_reps"));
        horizontalSlider_reps->setGeometry(QRect(90, 140, 281, 22));
        horizontalSlider_reps->setMinimum(1);
        horizontalSlider_reps->setMaximum(50);
        horizontalSlider_reps->setValue(15);
        horizontalSlider_reps->setOrientation(Qt::Horizontal);
        label_maxlenvalue = new QLabel(page);
        label_maxlenvalue->setObjectName(QString::fromUtf8("label_maxlenvalue"));
        label_maxlenvalue->setGeometry(QRect(380, 70, 31, 16));
        label_repsvalue = new QLabel(page);
        label_repsvalue->setObjectName(QString::fromUtf8("label_repsvalue"));
        label_repsvalue->setGeometry(QRect(380, 140, 31, 16));
        label_maxlen = new QLabel(page);
        label_maxlen->setObjectName(QString::fromUtf8("label_maxlen"));
        label_maxlen->setGeometry(QRect(10, 70, 81, 20));
        label_reps = new QLabel(page);
        label_reps->setObjectName(QString::fromUtf8("label_reps"));
        label_reps->setGeometry(QRect(10, 140, 71, 16));
        label_seconds = new QLabel(page);
        label_seconds->setObjectName(QString::fromUtf8("label_seconds"));
        label_seconds->setGeometry(QRect(160, 200, 59, 16));
        label_secondsval = new QLabel(page);
        label_secondsval->setObjectName(QString::fromUtf8("label_secondsval"));
        label_secondsval->setGeometry(QRect(230, 200, 59, 16));
        stackedWidget->addWidget(page);
        pushButton_quit = new QPushButton(centralwidget);
        pushButton_quit->setObjectName(QString::fromUtf8("pushButton_quit"));
        pushButton_quit->setGeometry(QRect(670, 500, 113, 32));
        pushButton_open = new QPushButton(centralwidget);
        pushButton_open->setObjectName(QString::fromUtf8("pushButton_open"));
        pushButton_open->setGeometry(QRect(670, 300, 113, 32));
        pushButton_Play = new QPushButton(centralwidget);
        pushButton_Play->setObjectName(QString::fromUtf8("pushButton_Play"));
        pushButton_Play->setGeometry(QRect(670, 420, 113, 32));
        pushButton_save = new QPushButton(centralwidget);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setGeometry(QRect(670, 380, 113, 32));
        pushButton_apply = new QPushButton(centralwidget);
        pushButton_apply->setObjectName(QString::fromUtf8("pushButton_apply"));
        pushButton_apply->setGeometry(QRect(670, 340, 113, 32));
        pushButton_stop = new QPushButton(centralwidget);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(670, 460, 113, 32));
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
        menuFile->addAction(actionSave_As);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "Open...", nullptr));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As...", nullptr));
        label_sfinfo->setText(QApplication::translate("MainWindow", "SF_INFO", nullptr));
        label_stats->setText(QApplication::translate("MainWindow", "Stats", nullptr));
        label_filename->setText(QApplication::translate("MainWindow", "filename", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Effects", nullptr));
        radioButton_removedc->setText(QApplication::translate("MainWindow", "Remove DC", nullptr));
        radioButton_normalize->setText(QApplication::translate("MainWindow", "Normalize", nullptr));
        radioButton_reverse->setText(QApplication::translate("MainWindow", "Reverse", nullptr));
        radioButton_echo->setText(QApplication::translate("MainWindow", "Echo", nullptr));
        radioButton_changespeed->setText(QApplication::translate("MainWindow", "Change speed", nullptr));
        radioButton_amplify->setText(QApplication::translate("MainWindow", "Amplify", nullptr));
        radioButton_randomsnips->setText(QApplication::translate("MainWindow", "Random snips", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Remove DC", nullptr));
        label_dBnormalize->setText(QApplication::translate("MainWindow", "dB", nullptr));
        label->setText(QApplication::translate("MainWindow", "Normalize to:", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Normalize", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Amplify", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "1.0", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "0.0", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "Reverse", nullptr));
        label_echonum->setText(QApplication::translate("MainWindow", "Number of echos", nullptr));
        label_echodelay->setText(QApplication::translate("MainWindow", "Delay milliseconds", nullptr));
        label_echodamp->setText(QApplication::translate("MainWindow", "Amplitude damping reduction %", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "Echo", nullptr));
        label_echonumval->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_echodelayval->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_echodampval->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Slow", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Fast", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "Change speed", nullptr));
        label_speedVal->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Random Snips", nullptr));
        label_maxlenvalue->setText(QApplication::translate("MainWindow", "400", nullptr));
        label_repsvalue->setText(QApplication::translate("MainWindow", "15", nullptr));
        label_maxlen->setText(QApplication::translate("MainWindow", "Max Length", nullptr));
        label_reps->setText(QApplication::translate("MainWindow", "Snip Reps", nullptr));
        label_seconds->setText(QApplication::translate("MainWindow", "Seconds:", nullptr));
        label_secondsval->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_quit->setText(QApplication::translate("MainWindow", "Quit", nullptr));
        pushButton_open->setText(QApplication::translate("MainWindow", "Open", nullptr));
        pushButton_Play->setText(QApplication::translate("MainWindow", "Play", nullptr));
        pushButton_save->setText(QApplication::translate("MainWindow", "Save", nullptr));
        pushButton_apply->setText(QApplication::translate("MainWindow", "Apply", nullptr));
        pushButton_stop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
