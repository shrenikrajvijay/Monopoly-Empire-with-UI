#ifndef TowerView_H
#define TowerView_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include "Board.h"
#include <QPoint>
#include <QVector>

class TowerView : public QGraphicsItem {
public:
    TowerView( Board* board,QGraphicsItem* parent = NULL);
protected:
    Board* main_board;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    QRectF boundingRect() const;
    QVector<deque<BillBoard*>*> towers;

    QPixmap Nerf;
    QPixmap Transformers;
    QPixmap Spotify;
    QPixmap Beats;
    QPixmap Fender;
    QPixmap JetBlue;
    QPixmap EA;
    QPixmap ElectricCompany;
    QPixmap HasBros;
    QPixmap UnderArmour;
    QPixmap Carnival;
    QPixmap Yahoo;
    QPixmap Paramount;
    QPixmap Chevrolet;
    QPixmap Ebay;
    QPixmap XGames;
    QPixmap Ducati;
    QPixmap Macdonalds;
    QPixmap Intel;
    QPixmap XBox;
    QPixmap Nestle;
    QPixmap WaterWorks;
    QPixmap Samsung;
    QPixmap CocaCola;



};


#endif // TowerView_H
