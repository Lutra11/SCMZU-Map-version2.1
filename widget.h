#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QMouseEvent>
#include "map.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

//    bool m_bPressed = true;
//    QPoint m_point;
//    void mouseReleaseEvent(QMouseEvent *event);
//    void mousePressEvent(QMouseEvent *event);
//    void mouseMoveEvent(QMouseEvent *event);


private slots:
    void on_exitbtn_clicked();

    void on_loginbtn_clicked();

private:
    Ui::Widget *ui;

};
#endif // WIDGET_H
