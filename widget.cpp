#include "widget.h"

#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      counter(0)
{
    setGeometry(500,200,700,500);
    timer = new QTimer();
    connect(timer,&QTimer::timeout,this,[&]() {
        counter++;
        repaint();
    });
    timer->start(100);
}

Widget::~Widget()
{

}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter p(this);
    p.setBrush(QBrush(Qt::black));
    p.setPen(QPen(Qt::white));

    p.drawRect(0,0,this->width(),this->height());

    gt.drawText(10,10,GameTextSize::font_size_micro,QString("Micro text %1").arg(counter),&p);
    gt.drawText(10,30,GameTextSize::font_size_small,QString("Small text %1").arg(counter),&p);
    gt.drawText(10,60,GameTextSize::font_size_meduim,QString("Medium text %1").arg(counter),&p);
    gt.drawText(10,120,GameTextSize::font_size_large,QString("Large text %1").arg(counter),&p);
}

