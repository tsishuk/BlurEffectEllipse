#ifndef BLURWIDGET_H
#define BLURWIDGET_H
#include <QtWidgets>

class BlurWidget : public QGraphicsView
{
    Q_OBJECT
    Q_PROPERTY(qreal index READ index WRITE setIndex);
public:
    BlurWidget(QWidget *parent = 0);
    qreal index() const;
    void setIndex(qreal new_index);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    void setupScene();

private:
    int m_counter;
    qreal m_index;
    QList<QGraphicsItem*> m_icons;
    QPropertyAnimation m_animation;
};

#endif // BLURWIDGET_H
