#include "map.h"
#include "ui_map.h"
#include<QString>
#include <QPainter>
#include<QTime>
#include <QMediaPlayer>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPixmap>
//打开外部链接
#include <QApplication>
#include  <QDesktopServices>
#include <QUrl>
#include <QMessageBox>


map::map(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::map)
{
    ui->setupUi(this);
    this->setWindowTitle("民大地图导航");
    this->shortes=new zyh;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            colors[i][j]="lightGray";
        }
    }
    mpb[0]= ui->minzu;
    mpb[1]= ui->sanshitang;
    mpb[2]=ui->qingzhen;
    mpb[3]=ui->nanqu;
    mpb[4]=ui->nanhu;
    mpb[5]=ui->nanhuyuan;
    mpb[6]=ui->shuangzita;
    mpb[7]=ui->zhengmen;
    mpb[8]=ui->zhongxinshitang;
    mpb[9]=ui->beiqu;
    ui->hero->setScaledContents(true);
    ui->caidan->setScaledContents(true);
}

map::~map()
{
    delete ui;
}

//初始化
void map::init()
{

    for(auto x:this->shortes->List)
    {
        int nw=x.first,nx=x.second.first,dis=x.second.second;
        QPen pen;
        QPainter painter(this);
        pen.setWidth(5);
        pen.setColor(colors[nw][nx]);
        painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
        painter.setPen(pen);
        painter.drawLine(QPointF(mpb[nw]->x()+7,mpb[nw]->y()+7), QPointF(mpb[nx]->x()+7, mpb[nx]->y()+7));// 绘制直线
        pen.setColor("Purple");
        painter.setPen(pen);
        painter.drawText(QPointF((mpb[nw]->x()+mpb[nx]->x())/2,(mpb[nw]->y()+mpb[nx]->y())/2),QString::number(dis));
    }
}

//绘制路线
//void map::paintEvent(QPaintEvent *)
//{
//    QPainter pbk(this);
//    pbk.drawPixmap(30,10,881,701,QPixmap(":/image/3.jpg"));
//    init();
//}

//按钮place事件函数
void map::place_onclick(QRadioButton *btn)
{
    int v;
    for(int i=0;i<=23;i++){
        if(mpb[i]==btn){
            v=i;
            break;
        }
    }
    //终点地点
    if(this->shortes->starcity=="")
    {
        update();
        this->ui->label_start->setText(btn->text());
        this->shortes->starcity=btn->text();
        this->ui->label_over->setText("");
        this->ui->label_display->setText("");
        this->shortes->st=v;
    }else if(this->shortes->starcity==btn->text()||this->shortes->overcity==btn->text()){
        this->ui->label_start->setText("");
        this->shortes->starcity="";

        this->ui->label_over->setText("");
        this->shortes->overcity="";

        this->ui->label_display->setText("");
    }else{
        update();
        this->ui->label_over->setText(btn->text());
        this->shortes->overcity=btn->text();
        this->ui->label_display->setText("");
        this->shortes->ed=v;
    }
    btn->setAutoExclusive(false);
    btn->setChecked(false);
}



//控制人物移动
void map::keyPressEvent(QKeyEvent *e)
{
   int x = ui->hero->x();
   int y = ui->hero->y();
   switch (e->key())
   {
       case Qt::Key_W : ui->hero->move(x, y-10); break;
       case Qt::Key_S : ui->hero->move(x, y+10); break;
       case Qt::Key_A : ui->hero->move(x-10, y); break;
       case Qt::Key_D : ui->hero->move(x+10, y); break;
       case Qt::Key_Z : ui->hero->move(x-10, y+10); break;
       case Qt::Key_C : ui->hero->move(x+10, y+10); break;
       case Qt::Key_Q : ui->hero->move(x-10, y-10); break;
       case Qt::Key_E : ui->hero->move(x+10, y-10); break;
    }
   //触发彩蛋
   if(x>680 && x < 710 && y>80 && y <120)
   {
      QMessageBox::information(this,"恭喜你触发了彩蛋！！","吹葫芦丝的是阿昌族小伙！");
      QDesktopServices::openUrl(QUrl("https://baike.baidu.com/item/%E9%98%BF%E6%98%8C%E6%97%8F/150510", QUrl::TolerantMode));

   }
}

//触发彩蛋
//void map::mousePressEvent(QMouseEvent *e)
//{
//   ui->pushButton->setText(tr("(%1,%2)").arg(e->x()).arg(e->y()));
//}

//地点按钮事件 start
void map::on_minzu_clicked()
{
    place_onclick(ui->minzu);
}


void map::on_sanshitang_clicked()
{
    place_onclick(ui->sanshitang);
}


void map::on_qingzhen_clicked()
{
    place_onclick(ui->qingzhen);
}


void map::on_nanqu_clicked()
{
    place_onclick(ui->nanqu);
}


void map::on_nanhu_clicked()
{
    place_onclick(ui->nanhu);
}


void map::on_nanhuyuan_clicked()
{
    place_onclick(ui->nanhuyuan);
}


void map::on_shuangzita_clicked()
{
    place_onclick(ui->shuangzita);
}


void map::on_zhengmen_clicked()
{
    place_onclick(ui->zhengmen);
}


void map::on_zhongxinshitang_clicked()
{
    place_onclick(ui->zhongxinshitang);
}


void map::on_beiqu_clicked()
{
    place_onclick(ui->beiqu);
}
//end####


//floyd算法计算最短路径
void map::on_calculatebtn_clicked()
{
    if(this->shortes->starcity == ""||this->shortes->overcity== "") return;
    this->c=1;
//    this->ui->calculatebtn->setStyleSheet("background-color: rgb(189, 240, 255);");
//    this->ui->btn_dijkstra->setStyleSheet("color: rgb(0, 0, 0);");
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<25;j++)
        {
            colors[i][j]="lightGray";
        }
    }
    update();

    int dis[25][25],pre[25][25];
    memset(pre,0,sizeof (pre));
    for(int i=0;i<=21;i++){
        for(int j=0;j<=21;j++){
            dis[i][j]=this->shortes->G.arcs[i][j].path;
        }
    }

    for(int k=0;k<=21;k++){
        for(int i=0;i<=21;i++){
            for(int j=0;j<=21;j++){
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                    pre[i][j]=k;
                }
            }
        }
    }
    floyd_print(pre,this->shortes->st,this->shortes->ed);
    this->ui->label_display->setText("最短距离是："+QString::number(dis[this->shortes->st][this->shortes->ed]));
}

//打印
void map::floyd_print(int pre[25][25],int i,int j){
    if(i==j) return;
    if(pre[i][j]==0){
        colors[i][j]=colors[j][i]="Blue";
    }else{
        floyd_print(pre,i,pre[i][j]);
        floyd_print(pre,pre[i][j],j);
    }
}

//clear清除重置函数
void map::on_clearbtn_clicked()
{
    this->c=-1;
//    this->ui->calculatebtn->setStyleSheet("color: rgb(0, 0, 0);");
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<25;j++)
        {
            colors[i][j]="lightGray";
        }
    }
    this->ui->label_start->setText("");
    this->ui->label_over->setText("");
    this->ui->label_display->setText("");
    this->shortes->starcity="";
    this->shortes->overcity="";
    update();
}


void map::on_playmusic_clicked()
{
    player->setMedia(QUrl::fromLocalFile("D:/QTProject/mapSCMZU/kuchazi.mp3"));
    player->setVolume(50);
    player->play();
}


void map::on_stopmusic_clicked()
{
    player->stop();
}


void map::on_jieshao1_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.scuec.edu.cn/bwg/wzsy.htm", QUrl::TolerantMode));
}


void map::on_jieshao2_clicked()
{
    QDesktopServices::openUrl(QUrl("https://baike.baidu.com/item/%E4%B8%AD%E5%8D%97%E6%B0%91%E6%97%8F%E5%A4%A7%E5%AD%A6%E5%9B%BE%E4%B9%A6%E9%A6%86/4133929", QUrl::TolerantMode));
}


void map::on_showmap_clicked()
{
    QDesktopServices::openUrl(QUrl("D:/QTProject/mapSCMZU/map/map.html", QUrl::TolerantMode));
}

