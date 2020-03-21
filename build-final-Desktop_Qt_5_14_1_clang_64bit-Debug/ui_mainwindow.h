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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSlider *volume_slider;
    QSlider *arp_rate_slider;
    QSlider *arp_notes_slider;
    QLabel *volume_label;
    QLabel *arp_rate_label;
    QLabel *arp_notes_label;
    QLabel *volume_reading;
    QLabel *arp_rate_reading;
    QLabel *arp_notes_reading;
    QToolButton *C_key;
    QToolButton *Csharp_key;
    QToolButton *D_key;
    QToolButton *Dsharp_key;
    QToolButton *E_key;
    QToolButton *F_key;
    QToolButton *Fsharp_key;
    QToolButton *G_key;
    QToolButton *A_key;
    QToolButton *Gsharp_key;
    QToolButton *B_key;
    QToolButton *Asharp_key;
    QRadioButton *major_button;
    QRadioButton *minor_button;
    QComboBox *instrument_select;
    QLabel *instrument_label;
    QSpinBox *spinBox;
    QLabel *octave_label;
    QPushButton *stop_button;
    QComboBox *arp_type_select;
    QLabel *label;
    QFrame *line;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(650, 683);
        MainWindow->setMouseTracking(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        volume_slider = new QSlider(centralwidget);
        volume_slider->setObjectName(QString::fromUtf8("volume_slider"));
        volume_slider->setGeometry(QRect(190, 310, 22, 261));
        volume_slider->setMaximum(100);
        volume_slider->setValue(100);
        volume_slider->setOrientation(Qt::Vertical);
        arp_rate_slider = new QSlider(centralwidget);
        arp_rate_slider->setObjectName(QString::fromUtf8("arp_rate_slider"));
        arp_rate_slider->setGeometry(QRect(320, 310, 22, 261));
        arp_rate_slider->setAutoFillBackground(false);
        arp_rate_slider->setMinimum(60);
        arp_rate_slider->setMaximum(240);
        arp_rate_slider->setValue(120);
        arp_rate_slider->setOrientation(Qt::Vertical);
        arp_notes_slider = new QSlider(centralwidget);
        arp_notes_slider->setObjectName(QString::fromUtf8("arp_notes_slider"));
        arp_notes_slider->setGeometry(QRect(440, 310, 22, 261));
        arp_notes_slider->setMinimum(3);
        arp_notes_slider->setMaximum(12);
        arp_notes_slider->setValue(6);
        arp_notes_slider->setOrientation(Qt::Vertical);
        arp_notes_slider->setInvertedAppearance(false);
        arp_notes_slider->setTickPosition(QSlider::TicksAbove);
        arp_notes_slider->setTickInterval(1);
        volume_label = new QLabel(centralwidget);
        volume_label->setObjectName(QString::fromUtf8("volume_label"));
        volume_label->setGeometry(QRect(160, 570, 81, 20));
        volume_label->setAlignment(Qt::AlignCenter);
        arp_rate_label = new QLabel(centralwidget);
        arp_rate_label->setObjectName(QString::fromUtf8("arp_rate_label"));
        arp_rate_label->setGeometry(QRect(290, 570, 81, 20));
        arp_rate_label->setAlignment(Qt::AlignCenter);
        arp_notes_label = new QLabel(centralwidget);
        arp_notes_label->setObjectName(QString::fromUtf8("arp_notes_label"));
        arp_notes_label->setGeometry(QRect(420, 570, 71, 21));
        arp_notes_label->setAlignment(Qt::AlignCenter);
        volume_reading = new QLabel(centralwidget);
        volume_reading->setObjectName(QString::fromUtf8("volume_reading"));
        volume_reading->setGeometry(QRect(170, 290, 61, 21));
        volume_reading->setAlignment(Qt::AlignCenter);
        arp_rate_reading = new QLabel(centralwidget);
        arp_rate_reading->setObjectName(QString::fromUtf8("arp_rate_reading"));
        arp_rate_reading->setGeometry(QRect(300, 290, 61, 21));
        arp_rate_reading->setAlignment(Qt::AlignCenter);
        arp_notes_reading = new QLabel(centralwidget);
        arp_notes_reading->setObjectName(QString::fromUtf8("arp_notes_reading"));
        arp_notes_reading->setGeometry(QRect(420, 290, 71, 21));
        arp_notes_reading->setAlignment(Qt::AlignCenter);
        C_key = new QToolButton(centralwidget);
        C_key->setObjectName(QString::fromUtf8("C_key"));
        C_key->setGeometry(QRect(30, 20, 41, 161));
        C_key->setCursor(QCursor(Qt::PointingHandCursor));
        C_key->setAutoFillBackground(false);
        C_key->setStyleSheet(QString::fromUtf8("QToolButton#C_key{\n"
"	background-color: white;\n"
"}"));
        Csharp_key = new QToolButton(centralwidget);
        Csharp_key->setObjectName(QString::fromUtf8("Csharp_key"));
        Csharp_key->setGeometry(QRect(70, 20, 41, 121));
        Csharp_key->setCursor(QCursor(Qt::PointingHandCursor));
        Csharp_key->setStyleSheet(QString::fromUtf8("QToolButton#Csharp_key{background-color: black}"));
        D_key = new QToolButton(centralwidget);
        D_key->setObjectName(QString::fromUtf8("D_key"));
        D_key->setGeometry(QRect(110, 20, 41, 161));
        D_key->setCursor(QCursor(Qt::PointingHandCursor));
        D_key->setStyleSheet(QString::fromUtf8("QToolButton#D_key{\n"
"	background-color: white;\n"
"}"));
        Dsharp_key = new QToolButton(centralwidget);
        Dsharp_key->setObjectName(QString::fromUtf8("Dsharp_key"));
        Dsharp_key->setGeometry(QRect(150, 20, 41, 121));
        Dsharp_key->setCursor(QCursor(Qt::PointingHandCursor));
        Dsharp_key->setStyleSheet(QString::fromUtf8("QToolButton#Dsharp_key{background-color: black}"));
        E_key = new QToolButton(centralwidget);
        E_key->setObjectName(QString::fromUtf8("E_key"));
        E_key->setGeometry(QRect(190, 20, 41, 161));
        E_key->setCursor(QCursor(Qt::PointingHandCursor));
        E_key->setStyleSheet(QString::fromUtf8("QToolButton#E_key{\n"
"	background-color: white;\n"
"}"));
        F_key = new QToolButton(centralwidget);
        F_key->setObjectName(QString::fromUtf8("F_key"));
        F_key->setGeometry(QRect(230, 20, 41, 161));
        F_key->setCursor(QCursor(Qt::PointingHandCursor));
        F_key->setStyleSheet(QString::fromUtf8("QToolButton#F_key{\n"
"	background-color: white;\n"
"}"));
        Fsharp_key = new QToolButton(centralwidget);
        Fsharp_key->setObjectName(QString::fromUtf8("Fsharp_key"));
        Fsharp_key->setGeometry(QRect(270, 20, 41, 121));
        Fsharp_key->setCursor(QCursor(Qt::PointingHandCursor));
        Fsharp_key->setStyleSheet(QString::fromUtf8("QToolButton#Fsharp_key{background-color: black}"));
        G_key = new QToolButton(centralwidget);
        G_key->setObjectName(QString::fromUtf8("G_key"));
        G_key->setGeometry(QRect(310, 20, 41, 161));
        G_key->setCursor(QCursor(Qt::SplitHCursor));
        G_key->setStyleSheet(QString::fromUtf8("QToolButton#G_key{\n"
"	background-color: white;\n"
"}"));
        A_key = new QToolButton(centralwidget);
        A_key->setObjectName(QString::fromUtf8("A_key"));
        A_key->setGeometry(QRect(390, 20, 41, 161));
        A_key->setCursor(QCursor(Qt::PointingHandCursor));
        A_key->setStyleSheet(QString::fromUtf8("QToolButton#A_key{\n"
"	background-color: white;\n"
"}"));
        Gsharp_key = new QToolButton(centralwidget);
        Gsharp_key->setObjectName(QString::fromUtf8("Gsharp_key"));
        Gsharp_key->setGeometry(QRect(350, 20, 41, 121));
        Gsharp_key->setCursor(QCursor(Qt::PointingHandCursor));
        Gsharp_key->setStyleSheet(QString::fromUtf8("QToolButton#Gsharp_key{background-color: black;}"));
        B_key = new QToolButton(centralwidget);
        B_key->setObjectName(QString::fromUtf8("B_key"));
        B_key->setGeometry(QRect(470, 20, 41, 161));
        B_key->setCursor(QCursor(Qt::PointingHandCursor));
        B_key->setStyleSheet(QString::fromUtf8("QToolButton#B_key{\n"
"	background-color: white;\n"
"}"));
        Asharp_key = new QToolButton(centralwidget);
        Asharp_key->setObjectName(QString::fromUtf8("Asharp_key"));
        Asharp_key->setGeometry(QRect(430, 20, 41, 121));
        Asharp_key->setCursor(QCursor(Qt::PointingHandCursor));
        Asharp_key->setStyleSheet(QString::fromUtf8("QToolButton#Asharp_key{background-color: black}"));
        major_button = new QRadioButton(centralwidget);
        major_button->setObjectName(QString::fromUtf8("major_button"));
        major_button->setGeometry(QRect(30, 220, 100, 20));
        major_button->setChecked(true);
        minor_button = new QRadioButton(centralwidget);
        minor_button->setObjectName(QString::fromUtf8("minor_button"));
        minor_button->setGeometry(QRect(30, 260, 100, 20));
        instrument_select = new QComboBox(centralwidget);
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->addItem(QString());
        instrument_select->setObjectName(QString::fromUtf8("instrument_select"));
        instrument_select->setGeometry(QRect(120, 240, 201, 32));
        instrument_label = new QLabel(centralwidget);
        instrument_label->setObjectName(QString::fromUtf8("instrument_label"));
        instrument_label->setGeometry(QRect(140, 220, 161, 16));
        instrument_label->setFrameShape(QFrame::StyledPanel);
        instrument_label->setTextFormat(Qt::AutoText);
        instrument_label->setAlignment(Qt::AlignCenter);
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(520, 70, 81, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier"));
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        spinBox->setFont(font);
        spinBox->setAlignment(Qt::AlignCenter);
        spinBox->setMaximum(6);
        spinBox->setValue(4);
        octave_label = new QLabel(centralwidget);
        octave_label->setObjectName(QString::fromUtf8("octave_label"));
        octave_label->setGeometry(QRect(510, 50, 101, 21));
        octave_label->setAlignment(Qt::AlignCenter);
        stop_button = new QPushButton(centralwidget);
        stop_button->setObjectName(QString::fromUtf8("stop_button"));
        stop_button->setGeometry(QRect(520, 130, 113, 31));
        arp_type_select = new QComboBox(centralwidget);
        arp_type_select->addItem(QString());
        arp_type_select->addItem(QString());
        arp_type_select->addItem(QString());
        arp_type_select->addItem(QString());
        arp_type_select->setObjectName(QString::fromUtf8("arp_type_select"));
        arp_type_select->setGeometry(QRect(360, 240, 161, 32));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(370, 220, 141, 16));
        label->setFrameShape(QFrame::StyledPanel);
        label->setAlignment(Qt::AlignCenter);
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(220, 20, 20, 161));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        line->setFont(font1);
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 650, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        volume_label->setText(QCoreApplication::translate("MainWindow", "Volume", nullptr));
        arp_rate_label->setText(QCoreApplication::translate("MainWindow", "Arp Rate", nullptr));
        arp_notes_label->setText(QCoreApplication::translate("MainWindow", "Arp Notes", nullptr));
        volume_reading->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        arp_rate_reading->setText(QCoreApplication::translate("MainWindow", "120", nullptr));
        arp_notes_reading->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        C_key->setText(QString());
        Csharp_key->setText(QString());
        D_key->setText(QString());
        Dsharp_key->setText(QString());
        E_key->setText(QString());
        F_key->setText(QString());
        Fsharp_key->setText(QString());
        G_key->setText(QString());
        A_key->setText(QString());
        Gsharp_key->setText(QString());
        B_key->setText(QString());
        Asharp_key->setText(QString());
        major_button->setText(QCoreApplication::translate("MainWindow", "Major", nullptr));
        minor_button->setText(QCoreApplication::translate("MainWindow", "Minor", nullptr));
        instrument_select->setItemText(0, QCoreApplication::translate("MainWindow", "Acoustic Grand Piano", nullptr));
        instrument_select->setItemText(1, QCoreApplication::translate("MainWindow", "Bright Acoustic Piano", nullptr));
        instrument_select->setItemText(2, QCoreApplication::translate("MainWindow", "Electric Grand Piano", nullptr));
        instrument_select->setItemText(3, QCoreApplication::translate("MainWindow", "Honky-tonk Piano", nullptr));
        instrument_select->setItemText(4, QCoreApplication::translate("MainWindow", "Electric Piano 1", nullptr));
        instrument_select->setItemText(5, QCoreApplication::translate("MainWindow", "Electric Piano 2", nullptr));
        instrument_select->setItemText(6, QCoreApplication::translate("MainWindow", "Harpsichord", nullptr));
        instrument_select->setItemText(7, QCoreApplication::translate("MainWindow", "Clavi", nullptr));
        instrument_select->setItemText(8, QCoreApplication::translate("MainWindow", "Celesta", nullptr));
        instrument_select->setItemText(9, QCoreApplication::translate("MainWindow", "Glockenspiel", nullptr));
        instrument_select->setItemText(10, QCoreApplication::translate("MainWindow", "Music Box", nullptr));
        instrument_select->setItemText(11, QCoreApplication::translate("MainWindow", "Vibraphone", nullptr));
        instrument_select->setItemText(12, QCoreApplication::translate("MainWindow", "Marimba", nullptr));
        instrument_select->setItemText(13, QCoreApplication::translate("MainWindow", "Xylophone", nullptr));
        instrument_select->setItemText(14, QCoreApplication::translate("MainWindow", "Tubular Bells", nullptr));
        instrument_select->setItemText(15, QCoreApplication::translate("MainWindow", "Dulcimer", nullptr));
        instrument_select->setItemText(16, QCoreApplication::translate("MainWindow", "Drawbar Organ", nullptr));
        instrument_select->setItemText(17, QCoreApplication::translate("MainWindow", "Percussive Organ", nullptr));
        instrument_select->setItemText(18, QCoreApplication::translate("MainWindow", "Rock Organ", nullptr));
        instrument_select->setItemText(19, QCoreApplication::translate("MainWindow", "Church Organ", nullptr));
        instrument_select->setItemText(20, QCoreApplication::translate("MainWindow", "Reed Organ", nullptr));
        instrument_select->setItemText(21, QCoreApplication::translate("MainWindow", "Accordion", nullptr));
        instrument_select->setItemText(22, QCoreApplication::translate("MainWindow", "Harmonica", nullptr));
        instrument_select->setItemText(23, QCoreApplication::translate("MainWindow", "Tango Accordion", nullptr));
        instrument_select->setItemText(24, QCoreApplication::translate("MainWindow", "Acoustic Guitar (nylon)", nullptr));
        instrument_select->setItemText(25, QCoreApplication::translate("MainWindow", "Acoustic Guitar (steel)", nullptr));
        instrument_select->setItemText(26, QCoreApplication::translate("MainWindow", "Electric Guitar (jazz)", nullptr));
        instrument_select->setItemText(27, QCoreApplication::translate("MainWindow", "Electric Guitar (clean)", nullptr));
        instrument_select->setItemText(28, QCoreApplication::translate("MainWindow", "Electric Guitar (muted)", nullptr));
        instrument_select->setItemText(29, QCoreApplication::translate("MainWindow", "Overdriven Guitar", nullptr));
        instrument_select->setItemText(30, QCoreApplication::translate("MainWindow", "Distortion Guitar", nullptr));
        instrument_select->setItemText(31, QCoreApplication::translate("MainWindow", "Guitar Harmonics", nullptr));
        instrument_select->setItemText(32, QCoreApplication::translate("MainWindow", "Acoustic Bass", nullptr));
        instrument_select->setItemText(33, QCoreApplication::translate("MainWindow", "Electric Bass (finger)", nullptr));
        instrument_select->setItemText(34, QCoreApplication::translate("MainWindow", "Electric Bass (pick)", nullptr));
        instrument_select->setItemText(35, QCoreApplication::translate("MainWindow", "Fretless Bass", nullptr));
        instrument_select->setItemText(36, QCoreApplication::translate("MainWindow", "Slap Bass 1", nullptr));
        instrument_select->setItemText(37, QCoreApplication::translate("MainWindow", "Slap Bass 2", nullptr));
        instrument_select->setItemText(38, QCoreApplication::translate("MainWindow", "Synth Bass 1", nullptr));
        instrument_select->setItemText(39, QCoreApplication::translate("MainWindow", "Synth Bass 2", nullptr));
        instrument_select->setItemText(40, QCoreApplication::translate("MainWindow", "Violin", nullptr));
        instrument_select->setItemText(41, QCoreApplication::translate("MainWindow", "Viola", nullptr));
        instrument_select->setItemText(42, QCoreApplication::translate("MainWindow", "Cello", nullptr));
        instrument_select->setItemText(43, QCoreApplication::translate("MainWindow", "Contrabass", nullptr));
        instrument_select->setItemText(44, QCoreApplication::translate("MainWindow", "Tremolo Strings", nullptr));
        instrument_select->setItemText(45, QCoreApplication::translate("MainWindow", "Pizzicato Strings", nullptr));
        instrument_select->setItemText(46, QCoreApplication::translate("MainWindow", "Orchestral Harp", nullptr));
        instrument_select->setItemText(47, QCoreApplication::translate("MainWindow", "Timpani", nullptr));
        instrument_select->setItemText(48, QCoreApplication::translate("MainWindow", "String Ensemble 1", nullptr));
        instrument_select->setItemText(49, QCoreApplication::translate("MainWindow", "String Ensemble 2", nullptr));
        instrument_select->setItemText(50, QCoreApplication::translate("MainWindow", "SynthStrings 1", nullptr));
        instrument_select->setItemText(51, QCoreApplication::translate("MainWindow", "SynthStrings 2", nullptr));
        instrument_select->setItemText(52, QCoreApplication::translate("MainWindow", "Choir Aahs", nullptr));
        instrument_select->setItemText(53, QCoreApplication::translate("MainWindow", "Voice Oohs", nullptr));
        instrument_select->setItemText(54, QCoreApplication::translate("MainWindow", "Synth Voice", nullptr));
        instrument_select->setItemText(55, QCoreApplication::translate("MainWindow", "Orchestra Hit", nullptr));
        instrument_select->setItemText(56, QCoreApplication::translate("MainWindow", "Trumpet", nullptr));
        instrument_select->setItemText(57, QCoreApplication::translate("MainWindow", "Trombone", nullptr));
        instrument_select->setItemText(58, QCoreApplication::translate("MainWindow", "Tuba", nullptr));
        instrument_select->setItemText(59, QCoreApplication::translate("MainWindow", "Muted Trumpet", nullptr));
        instrument_select->setItemText(60, QCoreApplication::translate("MainWindow", "French Horn", nullptr));
        instrument_select->setItemText(61, QCoreApplication::translate("MainWindow", "Brass Section", nullptr));
        instrument_select->setItemText(62, QCoreApplication::translate("MainWindow", "SynthBrass 1", nullptr));
        instrument_select->setItemText(63, QCoreApplication::translate("MainWindow", "SynthBrass 2", nullptr));
        instrument_select->setItemText(64, QCoreApplication::translate("MainWindow", "Soprano Sax", nullptr));
        instrument_select->setItemText(65, QCoreApplication::translate("MainWindow", "Alto Sax", nullptr));
        instrument_select->setItemText(66, QCoreApplication::translate("MainWindow", "Tenor Sax", nullptr));
        instrument_select->setItemText(67, QCoreApplication::translate("MainWindow", "Baritone Sax", nullptr));
        instrument_select->setItemText(68, QCoreApplication::translate("MainWindow", "Oboe", nullptr));
        instrument_select->setItemText(69, QCoreApplication::translate("MainWindow", "English Horn", nullptr));
        instrument_select->setItemText(70, QCoreApplication::translate("MainWindow", "Bassoon", nullptr));
        instrument_select->setItemText(71, QCoreApplication::translate("MainWindow", "Clarinet", nullptr));
        instrument_select->setItemText(72, QCoreApplication::translate("MainWindow", "Piccolo", nullptr));
        instrument_select->setItemText(73, QCoreApplication::translate("MainWindow", "Flute", nullptr));
        instrument_select->setItemText(74, QCoreApplication::translate("MainWindow", "Recorder", nullptr));
        instrument_select->setItemText(75, QCoreApplication::translate("MainWindow", "Pan Flute", nullptr));
        instrument_select->setItemText(76, QCoreApplication::translate("MainWindow", "Blown Bottle", nullptr));
        instrument_select->setItemText(77, QCoreApplication::translate("MainWindow", "Shakuhachi", nullptr));
        instrument_select->setItemText(78, QCoreApplication::translate("MainWindow", "Whistle", nullptr));
        instrument_select->setItemText(79, QCoreApplication::translate("MainWindow", "Ocarina", nullptr));
        instrument_select->setItemText(80, QCoreApplication::translate("MainWindow", "Lead 1 (square)", nullptr));
        instrument_select->setItemText(81, QCoreApplication::translate("MainWindow", "Lead 2 (sawtooth)", nullptr));
        instrument_select->setItemText(82, QCoreApplication::translate("MainWindow", "Lead 3 (calliope)", nullptr));
        instrument_select->setItemText(83, QCoreApplication::translate("MainWindow", "Lead 4 (chiff)", nullptr));
        instrument_select->setItemText(84, QCoreApplication::translate("MainWindow", "Lead 5 (charang)", nullptr));
        instrument_select->setItemText(85, QCoreApplication::translate("MainWindow", "Lead 6 (voice)", nullptr));
        instrument_select->setItemText(86, QCoreApplication::translate("MainWindow", "Lead 7 (fifths)", nullptr));
        instrument_select->setItemText(87, QCoreApplication::translate("MainWindow", "Lead 8 (bass + lead)", nullptr));
        instrument_select->setItemText(88, QCoreApplication::translate("MainWindow", "Pad 1 (new age)", nullptr));
        instrument_select->setItemText(89, QCoreApplication::translate("MainWindow", "Pad 2 (warm)", nullptr));
        instrument_select->setItemText(90, QCoreApplication::translate("MainWindow", "Pad 3 (polysynth)", nullptr));
        instrument_select->setItemText(91, QCoreApplication::translate("MainWindow", "Pad 4 (choir)", nullptr));
        instrument_select->setItemText(92, QCoreApplication::translate("MainWindow", "Pad 5 (bowed)", nullptr));
        instrument_select->setItemText(93, QCoreApplication::translate("MainWindow", "Pad 6 (metallic)", nullptr));
        instrument_select->setItemText(94, QCoreApplication::translate("MainWindow", "Pad 7 (halo)", nullptr));
        instrument_select->setItemText(95, QCoreApplication::translate("MainWindow", "Pad 8 (sweep)", nullptr));
        instrument_select->setItemText(96, QCoreApplication::translate("MainWindow", "FX 1 (rain)", nullptr));
        instrument_select->setItemText(97, QCoreApplication::translate("MainWindow", "FX 2 (soundtrack)", nullptr));
        instrument_select->setItemText(98, QCoreApplication::translate("MainWindow", "FX 3 (crystal)", nullptr));
        instrument_select->setItemText(99, QCoreApplication::translate("MainWindow", "FX 4 (atmosphere)", nullptr));
        instrument_select->setItemText(100, QCoreApplication::translate("MainWindow", "FX 5 (brightness)", nullptr));
        instrument_select->setItemText(101, QCoreApplication::translate("MainWindow", "FX 6 (goblins)", nullptr));
        instrument_select->setItemText(102, QCoreApplication::translate("MainWindow", "FX 7 (echoes)", nullptr));
        instrument_select->setItemText(103, QCoreApplication::translate("MainWindow", "FX 8 (sci-fi)", nullptr));
        instrument_select->setItemText(104, QCoreApplication::translate("MainWindow", "Sitar", nullptr));
        instrument_select->setItemText(105, QCoreApplication::translate("MainWindow", "Banjo", nullptr));
        instrument_select->setItemText(106, QCoreApplication::translate("MainWindow", "Shamisen", nullptr));
        instrument_select->setItemText(107, QCoreApplication::translate("MainWindow", "Koto", nullptr));
        instrument_select->setItemText(108, QCoreApplication::translate("MainWindow", "Kalimba", nullptr));
        instrument_select->setItemText(109, QCoreApplication::translate("MainWindow", "Bag pipe", nullptr));
        instrument_select->setItemText(110, QCoreApplication::translate("MainWindow", "Fiddle", nullptr));
        instrument_select->setItemText(111, QCoreApplication::translate("MainWindow", "Shanai", nullptr));
        instrument_select->setItemText(112, QCoreApplication::translate("MainWindow", "Tinkle Bell", nullptr));
        instrument_select->setItemText(113, QCoreApplication::translate("MainWindow", "Agogo", nullptr));
        instrument_select->setItemText(114, QCoreApplication::translate("MainWindow", "Steel Drums", nullptr));
        instrument_select->setItemText(115, QCoreApplication::translate("MainWindow", "Woodblock", nullptr));
        instrument_select->setItemText(116, QCoreApplication::translate("MainWindow", "Taiko Drum", nullptr));
        instrument_select->setItemText(117, QCoreApplication::translate("MainWindow", "Melodic Tom", nullptr));
        instrument_select->setItemText(118, QCoreApplication::translate("MainWindow", "Synth Drum", nullptr));
        instrument_select->setItemText(119, QCoreApplication::translate("MainWindow", "Reverse Cymbal", nullptr));
        instrument_select->setItemText(120, QCoreApplication::translate("MainWindow", "Guitar Fret Noise", nullptr));
        instrument_select->setItemText(121, QCoreApplication::translate("MainWindow", "Breath Noise", nullptr));
        instrument_select->setItemText(122, QCoreApplication::translate("MainWindow", "Seashore", nullptr));
        instrument_select->setItemText(123, QCoreApplication::translate("MainWindow", "Bird Tweet", nullptr));
        instrument_select->setItemText(124, QCoreApplication::translate("MainWindow", "Telephone Ring", nullptr));
        instrument_select->setItemText(125, QCoreApplication::translate("MainWindow", "Helicopter", nullptr));
        instrument_select->setItemText(126, QCoreApplication::translate("MainWindow", "Applause", nullptr));
        instrument_select->setItemText(127, QCoreApplication::translate("MainWindow", "Gunshot", nullptr));

        instrument_select->setCurrentText(QCoreApplication::translate("MainWindow", "Acoustic Grand Piano", nullptr));
        instrument_label->setText(QCoreApplication::translate("MainWindow", "Instrument Select", nullptr));
        octave_label->setText(QCoreApplication::translate("MainWindow", "Octave Select", nullptr));
        stop_button->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        arp_type_select->setItemText(0, QCoreApplication::translate("MainWindow", "UP", nullptr));
        arp_type_select->setItemText(1, QCoreApplication::translate("MainWindow", "DOWN", nullptr));
        arp_type_select->setItemText(2, QCoreApplication::translate("MainWindow", "UP -> DOWN", nullptr));
        arp_type_select->setItemText(3, QCoreApplication::translate("MainWindow", "RANDOM", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "Arpeggio Type", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
