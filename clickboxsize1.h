#ifndef ClickBoxSize1_H
#define ClickBoxSize1_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include "Board.h"
#include <QPoint>
#include <QVector>

class ClickBoxSize1 : public QGraphicsItem {
public:
    ClickBoxSize1( int, int, int, int, int, MainWindow*,QGraphicsItem* parent = NULL);
protected:
    int size_x;
    int size_y;
    int loc_x;
    int loc_y;
    int place;
    MainWindow* main;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    QRectF boundingRect() const;
//    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
//    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
};


#endif // ClickBoxSize1_H
