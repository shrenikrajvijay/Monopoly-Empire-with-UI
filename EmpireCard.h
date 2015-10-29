#ifndef EMPIRECARD_H
#define EMPIRECARD_H

#include <QGraphicsItem>
#include <string>
#include "Player.h"
#include <QRectF>
#include <QPainter>
#include <QPoint>
#include <QVector>

class MainWindow;

class EmpireCard: public QGraphicsItem {
protected:
    std::string title;
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) = 0;
    QRectF boundingRect() const;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) = 0;

public:
    EmpireCard(int, int, int, int, int, MainWindow*,QGraphicsItem* parent = NULL);
    int x_loc;
    int y_loc;
    int height;
    int width;
    MainWindow* main;
    // void use(Player&);
//     void print();
//    virtual void play(Player*, std::string&){};
    std::string getTitle();

};

class Move: public EmpireCard {

public:
    Move(int, int, int, int, int, MainWindow*,QGraphicsItem* parent = NULL);
//    void play(Player*, std::string&);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

class TallestTower: public EmpireCard {

public:
    TallestTower(int, int, int, int, int, MainWindow*,QGraphicsItem* parent = NULL);
//    void play(Player*, std::string&);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

class MarketCrash: public EmpireCard {

public:
    MarketCrash(int, int, int, int, int, MainWindow*,QGraphicsItem* parent = NULL);
//    void play(Player*, std::string&);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

class SayNo: public EmpireCard {

public:
    SayNo(int, int, int, int, int, MainWindow*,QGraphicsItem* parent = NULL);
//    void play(Player*, std::string&);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

class JetTrip: public EmpireCard {

public:
    JetTrip(int, int, int, int, int, MainWindow*,QGraphicsItem* parent = NULL);
//    void play(Player*, std::string&);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

class SwapTop: public EmpireCard {

public:
    SwapTop(int, int, int, int, int, MainWindow*,QGraphicsItem* parent = NULL);
//    void play(Player*, std::string&);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

class BillboardTax: public EmpireCard {

public:
    BillboardTax(int, int, int, int, int, MainWindow*,QGraphicsItem* parent = NULL);
//    void play(Player*, std::string& );
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

class ReverseRent: public EmpireCard {

public:
    ReverseRent(int, int, int, int, int, MainWindow*,QGraphicsItem* parent = NULL);
//    void play(Player*, std::string&);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

class BargainBusiness: public EmpireCard {

public:
    BargainBusiness(int, int, int, int, int, MainWindow*,QGraphicsItem* parent = NULL);
//    void play(Player*, std::string&);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

class DealBuster: public EmpireCard {

public:
    DealBuster(int, int, int, int, int, MainWindow*,QGraphicsItem* parent = NULL);
//    void play(Player*, std::string&);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);


};

class JailFreeEmpire: public EmpireCard {

public:
    JailFreeEmpire(int, int, int, int, int, MainWindow*,QGraphicsItem* parent = NULL);
//    void play(Player*, std::string&);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);


};

class TakeOver: public EmpireCard {

public:
    TakeOver(int, int, int, int, int, MainWindow*,QGraphicsItem* parent = NULL);
//    void play(Player*, std::string&);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);


};





#endif // EMPIRECARD_H
