#include "BlurWidget.h"
#include <QtWidgets>
#include <QtCore/qmath.h>
#include <qmath.h>
#include "MyBlurEffect.h"

BlurWidget::BlurWidget(QWidget* parent)
    : QGraphicsView(parent), m_counter(0), m_index(0),  m_animation(this, "index")
{
    setBackgroundBrush(QPixmap(":/Png_icons/background.jpg"));
    setScene(new QGraphicsScene(this));

    m_animation.setDuration(250);
    m_animation.setEasingCurve(QEasingCurve::InOutSine);

    setupScene();
    setIndex(0);

    setRenderHint(QPainter::Antialiasing, true);
    setFrameStyle(QFrame::NoFrame);
}


void BlurWidget::setupScene()
{
    (this->scene())->setSceneRect(-200, -120, 400, 240);

    QStringList names;
    names << ":/Png_Icons/drive (1).png";
    names << ":/Png_Icons/dropbox (1).png";
    names << ":/Png_Icons/evernote (1).png";
    names << ":/Png_Icons/home (1).png";
    names << ":/Png_Icons/gallery (1).png";
    names << ":/Png_Icons/train (1).png";
    names << ":/Png_Icons/voice (1).png";
    names << ":/Png_Icons/chrome (1).png";

    for (int i=0; i<names.count(); i++){
        QPixmap pixmap(names[i]);
        QGraphicsPixmapItem* icon = scene()->addPixmap(pixmap);
        icon->setZValue(1);
        icon->setGraphicsEffect(new MyBlurEffect(icon));
        m_icons << icon;
    }

    QGraphicsPixmapItem *bg = scene()->addPixmap(QPixmap(":/Png_Icons/background.jpg"));
    bg->setZValue(0);
    bg->setPos(-200, -150);
}



qreal BlurWidget::index() const
{
    return m_index;
}




void BlurWidget::setIndex(qreal new_index)
{
    m_index = new_index;
    qDebug()<<"index = "<<m_index<<" counter = "<<++m_counter;

    const qreal iconAngle = 2 * M_PI / m_icons.count();
    for (int i=0; i < m_icons.count(); ++i){
        QGraphicsItem* icon = m_icons[i];
        qreal a = (i + m_index)*iconAngle;
        qreal xs = 170 * qSin(a);
        qreal ys = 100 * qCos(a);
        QPointF pos(xs, ys);
        pos = QTransform().rotate(-20).map(pos);
        pos -= QPointF(40,40);
        icon->setPos(pos);
    }

    scene()->update();
}



void BlurWidget::mousePressEvent(QMouseEvent *event)
{
    int value = 0;
    if (event->x() > (this->width()/2))
        value = 1;
    else
        value = -1;
    if ((m_animation.state() == QAbstractAnimation::Stopped) && value){
        m_animation.setEndValue(m_index + value);
        m_animation.start();
        event->accept();
        m_counter = 0;
    }
}



void BlurWidget::resizeEvent(QResizeEvent *event)
{
    ;
}



void BlurWidget::keyPressEvent(QKeyEvent *event)
{
    int delta = 0;
    if (event->key() == Qt::Key_Left)
        delta = 1;
    else if (event->key() == Qt::Key_Right)
        delta = -1;

    if ((m_animation.state() == QAbstractAnimation::Stopped) && delta){
        m_animation.setEndValue(index() + delta);
        m_animation.start();
        event->accept();
        m_counter = 0;
    }
}
