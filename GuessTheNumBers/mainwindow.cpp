#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QLineEdit>
#include <QtGlobal>





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("猜数字");
    this->setFixedSize(500,300);
    connect(ui->pushButton_Gameintr,&QPushButton::clicked,[=](){
        QMessageBox::information(this,"简介","玩法：输入数字(0~100)系统会提示过大或过小只到输入正确数字为止");

    });
    //创建label对象显示时间
    QVBoxLayout *labelout =new QVBoxLayout(this);
    labelout->addWidget(label);
    this->setLayout(layout());
    //初始化时间显示
    dateTime=QDateTime::currentDateTime();
    this->label->setText(dateTime.toString("hh:mm:ss ddd").toUtf8().data());
    //创建定时器更新时间
    timer=new QTimer(this);

    connect(timer,&QTimer::timeout,this,&MainWindow::timeUpdate);
    timer->start(1000);




    int num=qrand() % 100+1;  //生成随机数[1,100];
    ui->textBrowser->clear();

    connect(ui->lineEdit,&QLineEdit::returnPressed,[=](){
        InNumBer(num);
    });

    connect(ui->pushButton_dtm,&QPushButton::clicked,[=](){

        InNumBer(num);
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeUpdate()
{
    dateTime= QDateTime::currentDateTime();
    this->label->setText(dateTime.toString("hh:mm:ss ddd").toUtf8().data());
}

void MainWindow::InNumBer(int num)
{


    int i=ui->lineEdit->text().toInt();

    if(i>num)
    {ui->textBrowser->append("输入过大请重新输入.\n");
        ui->lineEdit->clear();


    }
    if(i<num)
    {ui->textBrowser->append("输入过小请重新输入.\n");
        ui->lineEdit->clear();

    }
   if(i==num)
    {    ui->textBrowser->append("恭喜你猜对了.\n");

    }
}

