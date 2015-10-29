#include "ClickBoxSize1.h"
#include <QtGui>
#include <QVector>
#include <QDebug>
#include <QHash>
//#include <QtWidgets>
//#include <QRectF>
#include <QGraphicsSceneMouseEvent>
#include "mainwindow.h"
#include "ui_mainwindow.h"

ClickBoxSize1::ClickBoxSize1( int where_x, int where_y, int xs, int ys, int place_s,  MainWindow* mainW,QGraphicsItem* parent): QGraphicsItem(parent){

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    this->setOpacity(0.01);
    main = mainW;
    size_x = xs;
    size_y = ys;
    loc_x = where_x;
    loc_y = where_y;
    place = place_s;
}

QRectF ClickBoxSize1::boundingRect() const {
    return QRectF(loc_x,loc_y,size_x,size_y);
}

void ClickBoxSize1::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "ITEM IS CLICKED";
    main->getPlayers()->at(main->round)->setGlobal(place);
    main->getBoard()->spaces.at( place )->landOn(*( main->getPlayers()->at(main->round) ), main);
    main->getUi()->console->append( QString::fromStdString( main->getBoard()->spaces.at( place )->print() ) );
    if (main->getPlayers()->at(main->round)->getMessage() != "" ) {
        main->getUi()->console->append( QString::fromStdString( main->getPlayers()->at(main->round)->getMessage() ) ) ;
        main->getPlayers()->at(main->round)->setMessage("");
    }
    main->redrawMoney();
    main->getScene()->update();
    QPointF tmp = event->scenePos();
    qDebug() << tmp.x();
    qDebug() << tmp.y();
//    update();

}


//void ClickBoxSize1::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
////    qDebug() << "ITEM IS CLICKED";
////    update();

//}

void ClickBoxSize1::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
//    painter->setBrush(Qt::OpaqueMode);
    QPen framepen(Qt::red);
    painter->setPen(framepen);
    painter->drawRect(loc_x,loc_y,size_x,size_y);



}

void ClickBoxSize1::keyPressEvent(QKeyEvent *event) {
    switch ( event->key() ) {
    case Qt::Key_Right: {
            moveBy(2,0);
            break;
        }
    case Qt::Key_Left: {
            moveBy(-2,0);
            break;
        }
    case Qt::Key_Up: {
            moveBy(0,-2);
            break;
        }
    case Qt::Key_Down: {
            moveBy(0,2);
            break;
        }
    }
    update();
}

//void ClickBoxSize1::mousePressEvent(QGraphicsSceneMouseEvent* event) {
//    QPointF tmp = event->scenePos();
//    qDebug() << tmp.x();
//    qDebug() << tmp.y();
//}


//void ClickBoxSize1::MousePressEvent(QMouseEvent *event) {
//    QWidget::mousePressEvent(event);
//    event->accept();
//}

