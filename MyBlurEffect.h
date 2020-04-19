#ifndef MYBLUREFFECT_H
#define MYBLUREFFECT_H

#include <QGraphicsEffect>
#include <QGraphicsItem>

class MyBlurEffect : public QGraphicsBlurEffect{
public:
    MyBlurEffect(QGraphicsItem* item);
    void adjustForItem();
    void draw(QPainter *painter) override;

private:
    QGraphicsItem* m_item;
};

#endif // MYBLUREFFECT_H
