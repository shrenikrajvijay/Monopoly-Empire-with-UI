#include "token.h"
#include <QtGui>
#include <QVector>
#include <QDebug>
#include <QHash>
//#include <QtWidgets>
//#include <QRectF>

Token::Token( Board* board , int num,QGraphicsItem* parent): QGraphicsItem(parent){
    main_board = board;
    Go = QPoint(570,475);

    Nerf = QPoint(490,475);
    Macdonalds = QPoint( 490, 50);

    RivalTowerTax = QPoint(440,475);
    Ducati =  QPoint(440,50);

    Transformers = QPoint( 390, 475);
    EmpireCard2 = QPoint( 390, 50);

    EmpireCard1 = QPoint( 335, 475);
    XGames = QPoint(335, 50);

    Spotify = QPoint(280, 475);
    Ebay = QPoint(280,50);

    Chance1 = QPoint(235, 475 );
    Chance3 = QPoint(235,50);

    Beats = QPoint(193, 475);
    Chevrolet = QPoint(193,50);

    Fender = QPoint(140, 475);
    Paramount = QPoint(140,50);

    Jail = QPoint(60, 475);
    GoToJail = QPoint(570,50);

    JetBlue = QPoint(60, 410);
    CocaCola = QPoint(570,410);

    EA = QPoint(60, 365);
    TowerTax = QPoint(570, 365);

    ElectricCompany = QPoint(60,325);
    Samsung = QPoint(570,325);

    HasBros = QPoint(60,283);
    Chance4 = QPoint(570, 283);

    UnderArmour = QPoint(60,240);
    Nestle = QPoint(570, 240);

    Chance2 = QPoint( 60, 200 );
    WaterWorks = QPoint( 570, 200 );

    Carnival = QPoint(60,160);
    XBox = QPoint( 570, 160);

    Yahoo = QPoint( 60,120);
    Intel = QPoint( 570,120);

    FreeParking = QPoint( 60, 50);

    int a = 8;
    int b = 3;
    int c = 4;
    int d = 5;
    int* a_address = &a;
    for ( int i = 0; i<board->peeps;i++ ) {
        qDebug() << "HIII THIS IS PRINTED" << endl;
        locations.push_back( (board->getPlayer()->at(i))->getPositionAdd() );
    }
}

QRectF Token::boundingRect() const {
    return QRectF(0,0,630,525);
}

void Token::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
//    painter->setBrush(Qt::yellow);
    painter->drawPixmap( 0 ,0, 630,525, QPixmap("/Users/Anh/Board.jpg"));
//    painter->dxrawEllipse(10,10,10,10);
    QHash<int,int> hash;
//    qDebug() << "SIZE IS: " << (locations.size())<< endl;
    for ( int x=0;x<locations.size(); x++ ) {
        if ( hash.value( *(locations.at(x)) ) == NULL ) {
            hash.insert( *(locations.at(x)), 1 );
        } else {
            hash.insert( *(locations.at(x)), hash.value(*(locations.at(x)) + 1) );
        }

        if ( x==0 ) {
            painter->setBrush(Qt::red);
        } else if ( x == 1 ) {
            painter->setBrush(Qt::blue);
        } else if ( x == 2) {
            painter->setBrush(Qt::green);
        } else {
            painter->setBrush(Qt::yellow);
        }

        if (*(locations.at(x)) == 0 ) {
            painter->drawEllipse(Go,10,10);
        } else if  (*(locations.at(x)) == 1 ) {
            painter->drawEllipse(Nerf,10,10);
        } else if  (*(locations.at(x)) == 2 ) {
            painter->drawEllipse(RivalTowerTax,10,10);
        } else if  (*(locations.at(x)) == 3 ) {
            painter->drawEllipse(Transformers,10,10);
        } else if  (*(locations.at(x)) == 4 ) {
            painter->drawEllipse(EmpireCard1,10,10);
        } else if  (*(locations.at(x)) == 5 ) {
            painter->drawEllipse(Spotify,10,10);
        } else if  (*(locations.at(x)) == 6 ) {
            painter->drawEllipse(Chance1,10,10);
        } else if  (*(locations.at(x)) == 7 ) {
            painter->drawEllipse(Beats,10,10);
        } else if  (*(locations.at(x)) == 8 ) {
            painter->drawEllipse(Fender,10,10);
        } else if  (*(locations.at(x)) == 9 ) {
            painter->drawEllipse(Jail,10,10);
        } else if  (*(locations.at(x)) == 10 ) {
            painter->drawEllipse(JetBlue,10,10);
        } else if  (*(locations.at(x)) == 11 ) {
            painter->drawEllipse(EA,10,10);
        } else if  (*(locations.at(x)) == 12 ) {
            painter->drawEllipse(ElectricCompany,10,10);
        } else if  (*(locations.at(x)) == 13 ) {
            painter->drawEllipse(HasBros,10,10);
        } else if  (*(locations.at(x)) == 14 ) {
            painter->drawEllipse(UnderArmour,10,10);
        } else if  (*(locations.at(x)) == 15 ) {
            painter->drawEllipse(Chance2,10,10);
        } else if  (*(locations.at(x)) == 16 ) {
            painter->drawEllipse(Carnival,10,10);
        } else if  (*(locations.at(x)) == 17 ) {
            painter->drawEllipse(Yahoo,10,10);
        } else if  (*(locations.at(x)) == 18 ) {
            painter->drawEllipse(FreeParking,10,10);
        } else if  (*(locations.at(x)) == 19 ) {
            painter->drawEllipse(Paramount,10,10);
        } else if  (*(locations.at(x)) == 20 ) {
            painter->drawEllipse(Chevrolet,10,10);
        } else if  (*(locations.at(x)) == 21 ) {
            painter->drawEllipse(Chance3,10,10);
        } else if  (*(locations.at(x)) == 22 ) {
            painter->drawEllipse(Ebay,10,10);
        } else if  (*(locations.at(x)) == 23 ) {
            painter->drawEllipse(XGames,10,10);
        } else if  (*(locations.at(x)) == 24 ) {
            painter->drawEllipse(EmpireCard2,10,10);
        } else if  (*(locations.at(x)) == 25 ) {
            painter->drawEllipse(Ducati,10,10);
        } else if  (*(locations.at(x)) == 26 ) {
            painter->drawEllipse(Macdonalds,10,10);
        } else if  (*(locations.at(x)) == 27 ) {
            painter->drawEllipse(GoToJail,10,10);
        } else if  (*(locations.at(x)) == 28 ) {
            painter->drawEllipse(Intel,10,10);
        } else if  (*(locations.at(x)) == 29 ) {
            painter->drawEllipse(XBox,10,10);
        } else if  (*(locations.at(x)) == 30 ) {
            painter->drawEllipse(WaterWorks,10,10);
        } else if  (*(locations.at(x)) == 31 ) {
            painter->drawEllipse(Nestle,10,10);
        } else if  (*(locations.at(x)) == 32 ) {
            painter->drawEllipse(Chance4,10,10);
        } else if  (*(locations.at(x)) == 33 ) {
            painter->drawEllipse(Samsung,10,10);
        } else if  (*(locations.at(x)) == 34 ) {
            painter->drawEllipse(TowerTax,10,10);
        } else {
            painter->drawEllipse(CocaCola,10,10);
        }

    }
//    painter->drawEllipse(Nerf,10,10);
//    painter->drawEllipse(RivalTowerTax,10,10);

//    painter->drawEllipse(EA,10,10);
//    painter->drawEllipse(ElectricCompany,10,10);
//    painter->drawEllipse(Jail,10,10);
//    painter->drawEllipse(HasBros,10,10);
//    painter->drawEllipse(JetBlue,10,10);
//    painter->drawEllipse(UnderArmour,10,10);
//    painter->drawEllipse(Carnival,10,10);
//    painter->drawEllipse(Yahoo,10,10);
//    painter->drawEllipse(FreeParking,10,10);
//    painter->drawEllipse(Macdonalds,10,10);
//    painter->drawEllipse(Ducati,10,10);
//    painter->drawEllipse(EmpireCard2,10,10);
//    painter->drawEllipse(XGames,10,10);
//    painter->drawEllipse(Chance3,10,10);
//    painter->drawEllipse(Chevrolet,10,10);
//    painter->drawEllipse(Paramount,10,10);
//    painter->drawEllipse(Ebay,10,10);
//    painter->drawEllipse(Transformers,10,10);
//    painter->drawEllipse(EmpireCard1,10,10);
//    painter->drawEllipse(Spotify,10,10);
//    painter->drawEllipse(Chance1,10,10);
//    painter->drawEllipse(Beats,10,10);
//    painter->drawEllipse(Fender,10,10);
//    painter->drawEllipse(Chance2,10,10);
//    painter->drawEllipse(GoToJail,10,10);
//    painter->drawEllipse(Intel,10,10);





}
