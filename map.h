#ifndef MAP_H
#define MAP_H
#include"zyh.h"
#include <QWidget>
#include <QRadioButton>
#include <QMainWindow>
#include <QVector>
#include <QMap>
#include <QMediaPlayer>





namespace Ui {
class map;
}

class map : public QWidget
{
    Q_OBJECT

public:
    explicit map(QWidget *parent = nullptr);
    int c=4;
    int distance[25];
    int distance1[25][25];
    QString display;
    QString colors[25][25];
    QRadioButton *mpb[10];
    void place_onclick(QRadioButton *btn);
    void init();
    void floyd_print(int dis[25][25],int i,int j);
    ~map();

private slots:
    //按钮点击事件 start
    void on_minzu_clicked();
    void on_sanshitang_clicked();
    void on_qingzhen_clicked();
    void on_nanqu_clicked();
    void on_nanhu_clicked();
    void on_nanhuyuan_clicked();
    void on_shuangzita_clicked();
    void on_zhengmen_clicked();
    void on_zhongxinshitang_clicked();
    void on_beiqu_clicked();
    //end

    void on_calculatebtn_clicked();

    void on_clearbtn_clicked();

    void on_playmusic_clicked();

    void on_stopmusic_clicked();

    void on_jieshao1_clicked();

    void on_jieshao2_clicked();

    void on_showmap_clicked();

private:
    Ui::map *ui;
    zyh *shortes;
    QMediaPlayer *player = new QMediaPlayer(this);//设置背景音乐

    //控制人物移动
    void keyPressEvent(QKeyEvent *);
//    void mousePressEvent(QMouseEvent *);

//protected:
//   void paintEvent(QPaintEvent *);
};

#endif // MAP_H
