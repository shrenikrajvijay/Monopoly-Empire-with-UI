#ifndef TOKEN_H
#define TOKEN_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include "Board.h"
#include <QPoint>
#include <QVector>

class Token : public QGraphicsItem {
public:
    Token( Board* board , int,QGraphicsItem* parent = NULL);
protected:
    Board* main_board;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    QRectF boundingRect() const;
    QVector<int*> locations;
    QPoint Go;
    QPoint Nerf;
    QPoint RivalTowerTax;
    QPoint Transformers;
    QPoint EmpireCard1;
    QPoint Spotify;
    QPoint Chance1;
    QPoint Beats;
    QPoint Fender;
    QPoint Jail;
    QPoint JetBlue;
    QPoint EA;
    QPoint ElectricCompany;
    QPoint HasBros;
    QPoint UnderArmour;
    QPoint Chance2;
    QPoint Carnival;
    QPoint Yahoo;
    QPoint FreeParking;
    QPoint Paramount;
    QPoint Chevrolet;
    QPoint Chance3;
    QPoint Ebay;
    QPoint XGames;
    QPoint EmpireCard2;
    QPoint Ducati;
    QPoint Macdonalds;
    QPoint GoToJail;
    QPoint Intel;
    QPoint XBox;
    QPoint WaterWorks;
    QPoint Nestle;
    QPoint Chance4;
    QPoint Samsung;
    QPoint TowerTax;
    QPoint CocaCola;

};


#endif // TOKEN_H
