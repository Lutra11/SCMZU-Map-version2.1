#include "zyh.h"
#include "cstring"
zyh::zyh()
{
    starcity="";
    overcity="";
    G.arcnum = 20;
    G.vexnum = 22;

    //绑定各点地名
    G.places[0]="minzu";mp["minzu"]=0;
    G.places[1]="sanshitang";mp["sanshitang"]=1;
    G.places[2]="qingzhen";mp["qingzhen"]=2;
    G.places[3]="nanqu";mp["nanqu"]=3;
    G.places[4]="nanhu";mp["nanhu"]=4;
    G.places[5]="nanhuyuan";mp["nanhuyuan"]=5;
    G.places[6]="shuangzita";mp["shuangzita"]=6;
    G.places[7]="zhengmen";mp["zhengmen"]=7;
    G.places[8]="beiqu";mp["beiqu"]=8;
    G.places[9]="zhongxinshitang";mp["zhongxinshitang"]=9;


    //设置各地之间的距离
    List.push_back({0,{1,80}});
    List.push_back({1,{2,90}});
    List.push_back({2,{3,90}});
    List.push_back({1,{4,120}});
    List.push_back({2,{4,100}});
    List.push_back({4,{5,80}});
    List.push_back({5,{6,100}});
    List.push_back({5,{7,120}});
    List.push_back({6,{7,200}});
    List.push_back({6,{9,120}});
    List.push_back({7,{9,240}});
    List.push_back({8,{9,120}});
    List.push_back({8,{6,220}});
    List.push_back({8,{7,220}});



    for(int i=0;i<=21;i++)
    {
        for(int j=0;j<=21;j++)
        {
            G.arcs[i][j].path=999999;
        }
    }
    for(auto x:List)
    {
        int nw=x.first,nx=x.second.first,dis=x.second.second;
        G.arcs[nw][nx].path=G.arcs[nx][nw].path=dis;
    }
}


