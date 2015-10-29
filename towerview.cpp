#include "TowerView.h"
#include <QtGui>
#include <QVector>
#include <QDebug>
#include <QHash>
//#include <QtWidgets>
//#include <QRectF>

TowerView::TowerView( Board* board,QGraphicsItem* parent): QGraphicsItem(parent){

    Nerf = QPixmap("/Users/Anh/MonopolyBrand/Nerf.jpg");
    Transformers = QPixmap("/Users/Anh/MonopolyBrand/Transformers.jpg");
    Spotify = QPixmap("/Users/Anh/MonopolyBrand/Spotify.jpg");
    Beats = QPixmap("/Users/Anh/MonopolyBrand/Beats.jpg");
    Fender = QPixmap("/Users/Anh/MonopolyBrand/Fender.jpg");
    JetBlue = QPixmap("/Users/Anh/MonopolyBrand/JetBlue.jpg");
    EA = QPixmap("/Users/Anh/MonopolyBrand/EA.jpg");
    ElectricCompany = QPixmap("/Users/Anh/MonopolyBrand/ElectricCompany.jpg");
    HasBros= QPixmap("/Users/Anh/MonopolyBrand/HasBros.jpg");
    UnderArmour= QPixmap("/Users/Anh/MonopolyBrand/UnderArmour.jpg");
    Carnival= QPixmap("/Users/Anh/MonopolyBrand/Carnival.jpg");
    Yahoo= QPixmap("/Users/Anh/MonopolyBrand/Yahoo.jpg");
    Paramount= QPixmap("/Users/Anh/MonopolyBrand/Paramount.jpg");
    Chevrolet= QPixmap("/Users/Anh/MonopolyBrand/Chevrolet.jpg");
    Ebay= QPixmap("/Users/Anh/MonopolyBrand/Ebay.jpg");
    XGames= QPixmap("/Users/Anh/MonopolyBrand/XGames.jpg");
    Ducati= QPixmap("/Users/Anh/MonopolyBrand/Ducati.jpg");
    Macdonalds= QPixmap("/Users/Anh/MonopolyBrand/Macdonalds.jpg");
    Intel= QPixmap("/Users/Anh/MonopolyBrand/Intel.jpg");
    XBox= QPixmap("/Users/Anh/MonopolyBrand/XBox.jpg");
    WaterWorks= QPixmap("/Users/Anh/MonopolyBrand/WaterWorks.jpg");
    Nestle= QPixmap("/Users/Anh/MonopolyBrand/Nestle.jpg");
    Samsung= QPixmap("/Users/Anh/MonopolyBrand/Samsung.jpg");
    CocaCola= QPixmap("/Users/Anh/MonopolyBrand/CocaCola.jpg");


    for ( int x=0; x<board->peeps;x++) {
        towers.push_back( (board->getPlayer()->at(x))->getTower()->getStack() );
    }
    main_board = board;
}

QRectF TowerView::boundingRect() const {
    return QRectF(0,0,630,525);
}

void TowerView::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->setBrush(Qt::yellow);
    painter->drawEllipse( 50,50, 20,20 );

    int x = 10;
    int y = 540;
//    qDebug() << "TOWER SIZE IS: " << (towers.size())<< endl;
//    QVector<BillBoard*> tmp;

    for ( int i=0; i<towers.size();i++) {
//        qDebug() << "Tower at i: " << i << " Size is "<< towers.at(i)->size() << endl ;
        for( int i2=0; i2<towers.at(i)->size();i2++) {
            if ( (towers.at(i)->at(i2))->getName() == "NERF" ) {
                painter->drawPixmap(x,y,50,50,Nerf);
                y-=55;
            }

            else if ( (towers.at(i)->at(i2))->getName() == "TRANSFORMERS" ) {
                painter->drawPixmap(x,y,50,50,Transformers);
                y-=55;
            }

            else if ( (towers.at(i)->at(i2))->getName() == "SPOTIFY" ) {
                painter->drawPixmap(x,y,50,50,Spotify);
                y-=55;
            }

            else if ( (towers.at(i)->at(i2))->getName() == "ELECTRIC COMPANY" ) {
                painter->drawPixmap(x,y,50,50,ElectricCompany);
                y-=55;
            }

            else if ( (towers.at(i)->at(i2))->getName() == "BEATS" ) {
                painter->drawPixmap(x,y,50,50,Beats);
                y-=55;
            }

            else if ( (towers.at(i)->at(i2))->getName() == "FENDER" ) {
                painter->drawPixmap(x,y,50,50,Fender);
                y-=55;
            }

            else if ( (towers.at(i)->at(i2))->getName() == "JET BLUE" ) {
                painter->drawPixmap(x,y,50,50,JetBlue);
                y-=55;
            }

            else if ( (towers.at(i)->at(i2))->getName() == "EA SPORTS" ) {
                painter->drawPixmap(x,y,50,50,EA);
                y-=55;
            }

            else if ( (towers.at(i)->at(i2))->getName() == "HASBROS" ) {
                painter->drawPixmap(x,y,50,50,HasBros);
                y-=55;
            }

            else if ( (towers.at(i)->at(i2))->getName() == "UNDER ARMOUR" ) {
                painter->drawPixmap(x,y,50,50,UnderArmour);
                y-=55;
            }

            else if ( (towers.at(i)->at(i2))->getName() == "CARNIVAL" ) {
                painter->drawPixmap(x,y,50,50,Carnival);
                y-=55;
            }

            else if ( (towers.at(i)->at(i2))->getName() == "YAHOO!" ) {
                painter->drawPixmap(x,y,50,50,Yahoo);
                y-=55;
            }

            else if ( (towers.at(i)->at(i2))->getName() == "PARAMOUNT" ) {
                painter->drawPixmap(x,y,50,50,Paramount);
                y-=55;
            }

            else if ( (towers.at(i)->at(i2))->getName() == "CHEVROLET" ) {
                painter->drawPixmap(x,y,50,50,Chevrolet);
                y-=55;
            }

            else if ( (towers.at(i)->at(i2))->getName() == "EBAY" ) {
                painter->drawPixmap(x,y,50,50,Ebay);
                y-=55;
            }

            else if ( (towers.at(i)->at(i2))->getName() == "X GAMES" ) {
                painter->drawPixmap(x,y,50,50,XGames);
                y-=55;
            }

            else if ( (towers.at(i)->at(i2))->getName() == "DUCATI" ) {
                painter->drawPixmap(x,y,50,50,Ducati);
                y-=55;
            }

            else if ( (towers.at(i)->at(i2))->getName() == "MACDONALDS" ) {
                painter->drawPixmap(x,y,50,50,Macdonalds);
                y-=55;
            }

            else if ( (towers.at(i)->at(i2))->getName() == "INTEL" ) {
                painter->drawPixmap(x,y,50,50,Intel);
                y-=55;
            }

            else if ( (towers.at(i)->at(i2))->getName() == "XBOX" ) {
                painter->drawPixmap(x,y,50,50,XBox);
                y-=55;
            }

            else if ( (towers.at(i)->at(i2))->getName() == "WATER WORKS" ) {
                painter->drawPixmap(x,y,50,50,WaterWorks);
                y-=55;
            }

            else if ( (towers.at(i)->at(i2))->getName() == "NESTLE" ) {
                painter->drawPixmap(x,y,50,50,Nestle);
                y-=55;
            }

            else if ( (towers.at(i)->at(i2))->getName() == "SAMSUNG" ) {
                painter->drawPixmap(x,y,50,50,Samsung);
                y-=55;
            }

            else {
                painter->drawPixmap(x,y,50,50,CocaCola);
                y-=55;
            }







        }
        y = 540;
        x += 60;
    }

    //    QVector<BillBoard*> tmp;
    //    qDebug() << "TOWER SIZE IS: " << (towers.size())<< endl;
    //    for ( int i=0; i<towers.size();i++) {
    //        qDebug() << "Tower at i: " << i << " Size is "<< towers.at(i)->size() << endl ;
    //        for( int i2=0; i2<towers.at(i)->size();i2++) {
    //            tmp.push_back( towers.at(i)->top() );
    //            towers.at(i)->pop();
    //        }
    //        for ( int i3=towers.at(i)->size(); i3>0; i3--) {
    //            if ( tmp.at(i3)->getName() == "NERF") {
    //                painter->drawPixmap(x,y,Nerf);
    //            }
    //            if ( tmp.at(i3)->getName() == "TRANSFORMERS" ) {
    //                painter->drawPixmap(x,y,Transformers);
    //            }
    //            if ( tmp.at(i3)->getName() == "SPOTIFY" ) {
    //                painter->drawPixmap(x,y,Transformers);
    //            }
    //            if ( tmp.at(i3)->getName() == "ELECTRIC COMPANY" ) {
    //                painter->drawPixmap(x,y,ElectricCompany);
    //            }

    //        }

    //        for ( int i4=0; i4<tmp.size();i4++ ) {
    //            towers.at(i)->push( tmp.at(i4) );
    //        }
    //        y = 70;
    //        x += 20;
    //    }

}
