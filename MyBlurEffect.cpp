#include "MyBlurEffect.h"

#include <QDebug>


MyBlurEffect::MyBlurEffect(QGraphicsItem* item)
    :QGraphicsBlurEffect(), m_item(item)
{
    ;
}


void MyBlurEffect::adjustForItem()
{
    if (m_item->y()>30.0)
        setBlurRadius(0);
    else
        setBlurRadius(15.0);
    qDebug()<<"item y = "<<m_item->y();
}



void MyBlurEffect::draw(QPainter *painter)
{
    adjustForItem();
    QGraphicsBlurEffect::draw(painter);
}
