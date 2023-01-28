#ifndef ZYH_H
#define ZYH_H
#include <QString>
#include <QVector>
#include <QMap>

//创建路径结构体
typedef struct Arccell
{
    int path;
} Matrix[25][25];

//创建图矩阵
typedef struct
{
    QString places[25];
    Matrix arcs;
    //顶点数 边数
    int vexnum, arcnum;
}Graph;

class zyh
{
public:
    zyh();
    Graph G;
    QVector<QPair<int,QPair<int,int> > > List;
    //创建Qmap实例 键值对为 QString - int
    QMap<QString,int> mp;
    //起点地点
    QString starcity;
    //终点地点
    QString overcity;
    //起点与终点
    int st;
    int ed;
};

#endif // ZYH_H
