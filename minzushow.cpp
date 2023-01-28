#include "minzushow.h"
#include "ui_minzushow.h"

#include <QApplication>
#include  <QDesktopServices>
#include <QUrl>

MinzuShow::MinzuShow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MinzuShow)
{
    ui->setupUi(this);
    this->setWindowTitle("民族学博物馆");
    QDesktopServices::openUrl(QUrl("https://www.baidu.com", QUrl::TolerantMode));
}

MinzuShow::~MinzuShow()
{
    delete ui;
}


