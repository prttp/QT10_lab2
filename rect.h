#ifndef RECT_H
#define RECT_H

#include <QWidget>
#include<QMouseEvent>
#include<QPainter>
class Rect : public QWidget
{
    Q_OBJECT
    bool isDrawing;
    QPoint topleft;
    QPoint botright;
    QVector<QRect> RList;

public:
    Rect(QWidget *parent = nullptr);
    ~Rect();
    virtual QPaintEngine *paintEngine() const;

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent *event);
};
#endif // RECT_H
