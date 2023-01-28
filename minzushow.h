#ifndef MINZUSHOW_H
#define MINZUSHOW_H
#include <QWidget>

namespace Ui {
class MinzuShow;
}

class MinzuShow : public QWidget
{
    Q_OBJECT

public:
    explicit MinzuShow(QWidget *parent = nullptr);
    ~MinzuShow();


        // 设置图片列表;
        void setImageList(QStringList imageFileNameList);
        // 添加图片;
        void addImage(QString imageFileName);
        // 开始播放;
        void startPlay();



private:
    Ui::MinzuShow *ui;
};

#endif // MINZUSHOW_H
