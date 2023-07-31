#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

#include "qgametext.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    gametextQ gt;

    void paintEvent(QPaintEvent *event)override;

private:
    int counter;
    QTimer *timer;
};
#endif // WIDGET_H
