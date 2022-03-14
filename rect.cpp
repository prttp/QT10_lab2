#include "rect.h"
#include <QDebug>
Rect::Rect(QWidget *parent)
    : QWidget(parent)
{
    isDrawing = 0;
    Qt::WindowFlags flags = this->windowFlags();
    qDebug()<<flags;
    flags=Qt::Widget;
    flags|=Qt::WindowStaysOnTopHint;
    flags|=Qt::CustomizeWindowHint;
    flags|=Qt::WindowTitleHint;
    flags|=Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);
    this->setWindowTitle(tr("Spider"));
}

Rect::~Rect()
{
}

QPaintEngine *Rect::paintEngine() const
{
}
void Rect::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton) {
        isDrawing = 1;
        QPoint gtopleft = QCursor::pos();
        topleft = mapFromGlobal(gtopleft);
    };

}
void Rect::mouseReleaseEvent(QMouseEvent *event) {isDrawing = 0; RList.append(QRect(topleft,botright)); }
void Rect::mouseMoveEvent(QMouseEvent *event) {
    this->repaint();
    QPoint gbotright = QCursor::pos();
    botright = mapFromGlobal(gbotright);
    qDebug()<<QString::number(botright.x())<<"  "<<QString::number(botright.y());
    }
void Rect::paintEvent(QPaintEvent *event)
{ if (isDrawing == 1) {

    QPainter paint(this);
    for (int i = 0; i < RList.size(); ++i) {
       paint.drawRect(RList[i]);
    }

    paint.drawRect(QRect(topleft,botright));
}
}

