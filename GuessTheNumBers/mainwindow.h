#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QBoxLayout>
#include <QDateTime>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void timeUpdate(void);

    void InNumBer(int num);


    QLabel * label=new QLabel(this);

    QDateTime dateTime;
    QTimer *timer;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
