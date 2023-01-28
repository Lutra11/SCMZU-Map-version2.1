#include "widget.h"
#include "ui_widget.h"
#include "map.h"
#include <QWidget>
#include <QMouseEvent>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("民大地图导航");
//    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowFlags(Qt::X11BypassWindowManagerHint | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
}

Widget::~Widget()
{
    delete ui;
}


//退出按钮
void Widget::on_exitbtn_clicked()
{
    this->close();
}


//登录按钮
void Widget::on_loginbtn_clicked()
{
    QString admin = ui->adminLine->text();
    QString password = ui->passwordLine->text();
    map *son = new map();
    int flag = 0;
    if(admin == "101" && password == "123")
    {
        QMessageBox::information(this,"登录提示","登录成功");
        this->close();
        son->show();
        flag = 1;
    }
    if(admin == "" || password == "")
    {
        QMessageBox::information(this,"登录提示","账号或者密码不能为空");
    }
    else
    {
        if(flag = 0)
        {
           QMessageBox::information(this,"登录提示","登录失败");
        }

    }
}

