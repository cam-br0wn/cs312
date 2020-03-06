#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_play_clicked();

    void on_actionOpen_triggered();

    void on_actionSave_as_triggered();

    void on_horizontalScrollBar_zoom_valueChanged(int value);

private:
    Ui::MainWindow *ui;

    QString qOpenFileName;
    QString qSaveAsFileName;
    void doMessageBox( const QString& qs );
    void plot();

};
#endif // MAINWINDOW_H
