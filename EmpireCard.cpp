#include "EmpireCard.h"
#include "Player.h"
#include "Space.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include "mainwindow.h"
#include "ui_mainwindow.h"
//class Space;


EmpireCard::EmpireCard( int where_x, int where_y, int xs, int ys, int place_s,  MainWindow* mainW,QGraphicsItem* parent): QGraphicsItem(parent){
 x_loc = where_x;
 y_loc = where_y;
 width = xs;
 height =ys;
 main = mainW;
 setFlag(QGraphicsItem::ItemIsSelectable);

};

//void EmpireCard::use(Player& curPlayer){

//}

//void EmpireCard::print() {
//    qDebug() << QString::fromStdString(title);
//}

QRectF EmpireCard::boundingRect() const {
    return QRectF(x_loc,y_loc,width,height);
}

//void EmpireCard::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
//{
//    qDebug() << "ITEM IS CLICKED";
//    QPointF tmp = event->scenePos();
//    qDebug() << tmp.x();
//    qDebug() << tmp.y();
////    update();

//}


//void EmpireCard::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
//}


std::string EmpireCard::getTitle() {
    return title;
}

Move::Move( int where_x, int where_y, int xs, int ys, int place_s,  MainWindow* mainW,QGraphicsItem* parent) : EmpireCard(where_x,where_y,xs,ys,place_s,mainW, parent){
    title = "Move to any space on the board!";

};

void Move::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    QPixmap img = QPixmap("/Users/Anh/CSULB/SoftwareEng/GUIVersion/UsableCards/Move.png");
    painter->drawPixmap(x_loc,y_loc,width,height, img);
}

void Move::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "ITEM IS CLICKED";
    main->getUi()->console->append("Click on any space on the board to move there.");
    main->getRollButton()->setEnabled(false);
    main->getEDeck()->returnCard(this);
    main->getCardScene()->removeItem(this);

}



TallestTower::TallestTower( int where_x, int where_y, int xs, int ys, int place_s,  MainWindow* mainW,QGraphicsItem* parent) : EmpireCard(where_x,where_y,xs,ys,place_s,mainW, parent){
    title = "Tallest Tower Bonus!";
};

void TallestTower::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    QPixmap img = QPixmap("/Users/Anh/CSULB/SoftwareEng/GUIVersion/UsableCards/TallestTowerBonus.png");
    painter->drawPixmap(x_loc,y_loc,width,height, img);
}

void TallestTower::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "TallestTower is Clicked";
    vector<Player*>* tmp = main->getBoard()->getPlayer();
    int highest_tower=0;
    for (int x=0; x<tmp->size();x++ ) {
        if ( tmp->at(x)->getTower()->getValue() >= highest_tower ) {
            highest_tower = tmp->at(x)->getTower()->getValue();
        }
    }
    main->getPlayers()->at(main->round)->changeMoney(highest_tower);
    std::string msg;
    main->getUi()->console->append( "Used Empire Card: " + QString::fromStdString(title) + ": Acquired " + QString::number(highest_tower) + "." );
    main->redrawMoney();
    main->getEDeck()->returnCard(this);
    main->getCardScene()->removeItem(this);


}


MarketCrash::MarketCrash( int where_x, int where_y, int xs, int ys, int place_s,  MainWindow* mainW,QGraphicsItem* parent) : EmpireCard(where_x,where_y,xs,ys,place_s,mainW, parent){
    title = "Stock market crash!";
};

void MarketCrash::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    QPixmap img = QPixmap("/Users/Anh/CSULB/SoftwareEng/GUIVersion/UsableCards/StockMarketCrash.png");
    painter->drawPixmap(x_loc,y_loc,width,height, img);
}

void MarketCrash::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "MarketCrash is Clicked";
    for ( int x=0; x<main->peep;x++) {
        if ( main->getPlayers()->at(x)->getTower()->getHeight() > 0 ) {
            BillBoard * temp_bb = main->getPlayers()->at(x)->getTower()->Top_BillBoard.back();

            main->getPlayers()->at(x)->getTower()->Top_BillBoard.pop_back();

            main->getPlayers()->at(x)->getTower()->setHeight( -(temp_bb->getValue() ) );

            temp_bb->setOwner( -1 );
            temp_bb->setStatus( -1 );

        }
    }
    main->getUi()->console->append( "Used Empire Card: " + QString::fromStdString(title) + ": Everybody loses their top billboard"  );
    main->getTowerScene()->update();
    main->getEDeck()->returnCard(this);
    main->getCardScene()->removeItem(this);
}




SayNo::SayNo( int where_x, int where_y, int xs, int ys, int place_s,  MainWindow* mainW,QGraphicsItem* parent) : EmpireCard(where_x,where_y,xs,ys,place_s,mainW, parent){
    title = "Just Say No!";
};

void SayNo::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    QPixmap img = QPixmap("/Users/Anh/CSULB/SoftwareEng/GUIVersion/UsableCards/JustSayNo.png");
    painter->drawPixmap(x_loc,y_loc,width,height, img);
}


void SayNo::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "SayNo is Clicked";

}


JetTrip::JetTrip( int where_x, int where_y, int xs, int ys, int place_s,  MainWindow* mainW,QGraphicsItem* parent) : EmpireCard(where_x,where_y,xs,ys,place_s,mainW, parent){
    title = "Private Jet Trip!";
};


void JetTrip::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    QPixmap img = QPixmap("/Users/Anh/CSULB/SoftwareEng/GUIVersion/UsableCards/PrivateJetTrip.png");
    painter->drawPixmap(x_loc,y_loc,width,height, img);
}


void JetTrip::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "JetTrip is Clicked";
    main->getUi()->console->append("Click on a space up to five spaces ahead.");
    main->getRollButton()->setEnabled(false);
    main->getEDeck()->returnCard(this);
    main->getCardScene()->removeItem(this);
}

SwapTop::SwapTop( int where_x, int where_y, int xs, int ys, int place_s,  MainWindow* mainW,QGraphicsItem* parent) : EmpireCard(where_x,where_y,xs,ys,place_s,mainW, parent){
    title = "Swap the Top!";
};

void SwapTop::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    QPixmap img = QPixmap("/Users/Anh/CSULB/SoftwareEng/GUIVersion/UsableCards/SwapTheTop.png");
    painter->drawPixmap(x_loc,y_loc,width,height, img);
}


void SwapTop::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "SwapTop is Clicked";
    main->swap_w = new QWidget(main);
    QHBoxLayout* swap_v = new QHBoxLayout;
    main->swap1 = new QComboBox();
    QPushButton* swap_p = new QPushButton;
    swap_p->setText("Choose");
    swap_v->addWidget(main->swap1);
    swap_v->addWidget(swap_p);
    main->swap_w->setLayout(swap_v);
    main->getUi()->top_command->addWidget(main->swap_w);


    for( int x=0; x<main->peep; x++ ) {
        if ( main->getPlayers()->at(x)->getId() != main->round ) {
            main->swap1->addItem( QString::fromStdString( main->getPlayers()->at(x)->getName() ), QVariant(main->getPlayers()->at(x)->getId()) );
        }

    }
    main->swap1choose = main->round;
    main->getRollButton()->setEnabled(false);
    main->connect( swap_p, SIGNAL( clicked() ), main, SLOT( chooseSwap3() ) );
    main->swap1->show();

    main->getUi()->console->append( "Used Empire Card: " + QString::fromStdString(title) + ": Swapped Towers"  );
    main->getTowerScene()->update();
    main->getEDeck()->returnCard(this);
    main->getCardScene()->removeItem(this);


}
BillboardTax::BillboardTax( int where_x, int where_y, int xs, int ys, int place_s,  MainWindow* mainW,QGraphicsItem* parent) : EmpireCard(where_x,where_y,xs,ys,place_s,mainW, parent){
    title = "Billboard Tax!";
};

void BillboardTax::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    QPixmap img = QPixmap("/Users/Anh/CSULB/SoftwareEng/GUIVersion/UsableCards/BillboardTax.png");
    painter->drawPixmap(x_loc,y_loc,width,height, img);
}


void BillboardTax::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "BillboardTax is Clicked";
    qDebug() << "SwapTop is Clicked";
    main->swap_w = new QWidget(main);
    QHBoxLayout* swap_v = new QHBoxLayout;
    main->swap1 = new QComboBox();
    QPushButton* swap_p = new QPushButton;
    swap_p->setText("Choose");
    swap_v->addWidget(main->swap1);
    swap_v->addWidget(swap_p);
    main->swap_w->setLayout(swap_v);
    main->getUi()->top_command->addWidget(main->swap_w);


    for( int x=0; x<main->peep; x++ ) {
        if ( main->getPlayers()->at(x)->getId() != main->round && main->getPlayers()->at(x)->getTower()->getHeight() >= 4  ) {
            main->swap1->addItem( QString::fromStdString( main->getPlayers()->at(x)->getName() ), QVariant(main->getPlayers()->at(x)->getId()) );
        }

    }
    main->getRollButton()->setEnabled(false);
    main->connect( swap_p, SIGNAL( clicked() ), main, SLOT( exchangeCash() ) );
    main->swap1->show();

    main->getUi()->console->append( "Used Empire Card: " + QString::fromStdString(title) + ": Collect 400 from a player."  );
    main->getPlayers()->at(main->round)->changeMoney(400);
    main->redrawMoney();
    main->getEDeck()->returnCard(this);
    main->getCardScene()->removeItem(this);

}

ReverseRent::ReverseRent( int where_x, int where_y, int xs, int ys, int place_s,  MainWindow* mainW,QGraphicsItem* parent) : EmpireCard(where_x,where_y,xs,ys,place_s,mainW, parent){
    title = "ReverseRent!";
};

void ReverseRent::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    QPixmap img = QPixmap("/Users/Anh/CSULB/SoftwareEng/GUIVersion/UsableCards/ReverseRent.png");
    painter->drawPixmap(x_loc,y_loc,width,height, img);
}



void ReverseRent::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    main->getPlayers()->at(main->round)->playAction();
    main->redrawMoney();
    main->getEDeck()->returnCard(this);
    main->getCardScene()->removeItem(this);

}
BargainBusiness::BargainBusiness( int where_x, int where_y, int xs, int ys, int place_s,  MainWindow* mainW,QGraphicsItem* parent) : EmpireCard(where_x,where_y,xs,ys,place_s,mainW, parent){
    title = "Bargain business!";
};

void BargainBusiness::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    QPixmap img = QPixmap("/Users/Anh/CSULB/SoftwareEng/GUIVersion/UsableCards/BargainBusiness.png");
    painter->drawPixmap(x_loc,y_loc,width,height, img);
}


void BargainBusiness::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "BargainBusiness is Clicked";
    Ownable* space_on = dynamic_cast<Ownable*>(main->getBoard()->spaces.at(main->getPlayers()->at(main->round)->getPosition() ) );

    if ( space_on->owned < 1 ) {
    main->getPlayers()->at(main->round)->getTower()->setBillBoard( space_on->bboard );
    main->getPlayers()->at(main->round)->getTower()->setHeight( space_on->bboard->getValue() );

    space_on->owned += 1;
    space_on->owner = main->getPlayers()->at(main->round)->getId();
    main->getTowerScene()->update();
    main->getPlayers()->at(main->round)->changeMoney(-100);
    main->redrawMoney();
    main->getEDeck()->returnCard(this);
    main->getCardScene()->removeItem(this);
    main->yesButton->setEnabled(false);
    main->noButton->setEnabled(false);
    main->getRollButton()->setEnabled(true);
    }
}

DealBuster::DealBuster( int where_x, int where_y, int xs, int ys, int place_s,  MainWindow* mainW,QGraphicsItem* parent) : EmpireCard(where_x,where_y,xs,ys,place_s,mainW, parent){
    title = "Successful advertising campaign!";
};

void DealBuster::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    QPixmap img = QPixmap("/Users/Anh/CSULB/SoftwareEng/GUIVersion/UsableCards/DealBuster.png");
    painter->drawPixmap(x_loc,y_loc,width,height, img);
}


void DealBuster::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "DealBuster is Clicked";

}


JailFreeEmpire::JailFreeEmpire( int where_x, int where_y, int xs, int ys, int place_s,  MainWindow* mainW,QGraphicsItem* parent) : EmpireCard(where_x,where_y,xs,ys,place_s,mainW, parent){
    title = "Win 'Business of the Year' award!";
};

void JailFreeEmpire::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    QPixmap img = QPixmap("/Users/Anh/CSULB/SoftwareEng/GUIVersion/UsableCards/GetOutOfJailFree.png");
    painter->drawPixmap(x_loc,y_loc,width,height, img);
}


void JailFreeEmpire::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "JailFreeEmpire is Clicked";
    if ( main->getPlayers()->at(main->round)->isInJail()>0 ) {
        while ( main->getPlayers()->at(main->round)->isInJail() != 0 ) {
            main->getPlayers()->at(main->round)->setJail( -1 );
            main->getEDeck()->returnCard(this);
            main->getCardScene()->removeItem(this);
        }
    }

}

TakeOver::TakeOver( int where_x, int where_y, int xs, int ys, int place_s,  MainWindow* mainW,QGraphicsItem* parent) : EmpireCard(where_x,where_y,xs,ys,place_s,mainW, parent){
    title = "Get out of jail free!";
};

void TakeOver::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    QPixmap img = QPixmap("/Users/Anh/CSULB/SoftwareEng/GUIVersion/UsableCards/HostileTakeover.png");
    painter->drawPixmap(x_loc,y_loc,width,height, img);
}


void TakeOver::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "TakeOver is Clicked";

}


//void Move::play(Player* curPlayer, string& msg) {
//    msg+= "\n    Speed Ahead!\n    Move Forward up to five spaces in your private limo.\n";
//};


//void TallestTower::play(Player* curPlayer, string& msg) {
//    msg+= "\n    Water bonus!\n    Take a free Water Works billboard and add it to your tower.\n    If none are available, do nothing.";
//    Ownable* space_on = dynamic_cast<Ownable*>(curPlayer->getSpaces().at(30));

//    if ( space_on->owned < 4 ) {
//    curPlayer->getTower()->setBillBoard( space_on->bboard );
//    curPlayer->getTower()->setHeight( space_on->bboard->getValue() );

//    space_on->owned += 1;
//    space_on->owner = curPlayer->getId();
//    msg += "\n    You added Water Works to your tower.";
//    } else {
//        msg += "\n    Out of Water Works BillBoards.";
//    }


//};

//void MarketCrash::play(Player* curPlayer, string& msg) {
//    msg += "\n    Profit Soars!\n    Advance to Go to collect your tower value.\n";
//    curPlayer->setGlobal(0);
//};

//void SayNo::play(Player* curPlayer, string& msg) {
//    msg += "\n    Go to Jail!\n    Do not collect cash for passing GO.";
//    curPlayer->setJail( 1 );
//};

//void JetTrip::play(Player* curPlayer, string& msg) {
//    msg += "\n    It's your empire's first birthday!\n    All players play you 50.\n";
//    curPlayer->changeMoney( (curPlayer->getPlayers().size()-1) * 50);
//    for ( int x = 0 ; x<curPlayer->getPlayers().size(); x++) {
//        if ( curPlayer->getPlayers().at(x)->getId() != curPlayer->getId() ) {
//            curPlayer->getPlayers().at(x)->changeMoney(-50);
//        }
//    }
//};

//void SwapTop::play(Player* curPlayer, string& msg) {
//    msg += "\n    Insider trading fine!\n    Pay the Bank 200.\n";
//    curPlayer->changeMoney(-200);
//};

//void BillboardTax::play(Player* curPlayer, string& msg) {
//    msg += "\n    Casino Night!\n    Pick an opponent.Both roll. Highest-roller collects 200 from the Bank.\n";
//};

//void ReverseRent::play(Player* curPlayer, string& msg) {
//    msg += "\n    Successful advertising campaign!\n    Collect 100 from the Bank.\n";
//    curPlayer->changeMoney(100);
//};

//void BargainBusiness::play(Player* curPlayer, string& msg) {
//    msg += "\n    Successful advertising campaign!\n    Collect 100 from the Bank.\n";
//    curPlayer->changeMoney(100);
//};

//void DealBuster::play(Player* curPlayer, string& msg) {
//    msg += "\n    Successful advertising campaign!\n    Collect 100 from the Bank.\n";
//    curPlayer->changeMoney(100);
//};

//void JailFreeEmpire::play(Player* curPlayer, string& msg) {
//    msg += "\n    Win 'Business of the Year' award!\n    Collect 400 from the Bank.\n";
//    curPlayer->changeMoney(400);
//};

//void TakeOver::play(Player* curPlayer, string& msg) {

//};




