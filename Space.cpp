

#include "Space.h"
#include "Player.h"
#include <string>
#include <iostream>
#include <QDebug>
#include <sstream>
#include "mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QComboBox>
#include "ui_mainwindow.h"

using namespace std;

Space::Space( int place, std::string name ) : spot(place), title(name) {};
Ownable::Ownable( int place, std::string name, int value, int costOf ) : Space(place,name){
	bboard = new BillBoard( value, name, owned, owner );
	owned = false;
	cost = costOf;

	owner = -1;
    message = "";
};

void Ownable::buy (Player& curPlayer ) {
//    int ans = 2; // IMPORTANT auto setted to 2

//    qDebug() << "You have " << curPlayer.getMoney() << endl;
//    qDebug() << "Do you want to buy " << QString::fromStdString( title ) << " for " << cost <<"?" << endl ;

//    qDebug() << "1. Yes 2. No" << endl;
////	cin >> ans;

//    if ( ans == 1 && curPlayer.getMoney()>=50 ) {
//        qDebug() << "You bought " << QString::fromStdString(title) << "." << endl;
//        curPlayer.changeMoney( -50 );
//            curPlayer.getTower()->setBillBoard( ( bboard) );
//        curPlayer.getTower()->setHeight( (*bboard).getValue() );
//        qDebug() << QString::number( (*bboard).getValue() )<< "VALUE" << endl ;
//        qDebug() << QString::number( curPlayer.getTower()->getHeight() ) << "HEIGHT" << endl;
//        owned =true;

//        owner = curPlayer.getId();


//    } else {
//        qDebug() << QString::fromStdString( curPlayer.getName() ) << " did not buy " << QString::fromStdString( title ) << "." << endl;
//    }


}

std::string Ownable::buyYes (Player& curPlayer ) {
    qDebug() << "You bought " << QString::fromStdString(title) << "." << endl;
    curPlayer.changeMoney( -cost );
        curPlayer.getTower()->setBillBoard( ( bboard) );
    curPlayer.getTower()->setHeight( (*bboard).getValue() );
    qDebug() << QString::number( (*bboard).getValue() )<< "VALUE" << endl ;
    qDebug() << QString::number( curPlayer.getTower()->getHeight() ) << "HEIGHT" << endl;
    owned += 1;

    owner = curPlayer.getId();
    return "TEST BUYING";
}

std::string Ownable::buyNo (Player& curPlayer ) {
    qDebug() << QString::fromStdString( curPlayer.getName() ) << " did not buy " << QString::fromStdString( title ) << "." << endl;
    return curPlayer.getName() + " did not buy " + title + ".";
}

void Ownable::rent(Player& curPlayer) {


    if ( owner != curPlayer.getId() && owner!= -1 && (*(curPlayer.getPlayers().at(owner))).isInJail() == 0 ) {
        if (curPlayer.getMoney() >= (*(curPlayer.getPlayers().at(owner))).getTower()->getValue() )   {
            curPlayer.setAction( new ReverseRentAct((*(curPlayer.getPlayers().at(owner))).getTower()->getValue(), curPlayer.getPlayers().at(owner)) ); //IMPORTANT

            qDebug() << "USE getPlayer() and it WORKKKKKS WTF" << endl;
            qDebug() << QString::fromStdString( curPlayer.getName() ) << " pays " << QString::fromStdString( (*(curPlayer.getPlayers().at(owner))).getName() ) << " " <<  QString::number( (*(curPlayer.getPlayers().at(owner))).getTower()->getValue() ) << endl ;
            curPlayer.changeMoney( -( (*(curPlayer.getPlayers().at(owner))).getTower()->getValue() ) );
            (*(curPlayer.getPlayers().at(owner))).changeMoney( (*(curPlayer.getPlayers().at(owner))).getTower()->getValue() );
            int tmp = (*(curPlayer.getPlayers().at(owner))).getTower()->getValue() ;
            std::ostringstream oss;
            oss << tmp;
            message = ( curPlayer.getName() + " pays " + (*(curPlayer.getPlayers().at(owner))).getName() + " " + ( oss.str() ) + "." );

        } else if ( curPlayer.getTower()->getHeight() > 0 ) {
            qDebug() << "CALLED RENT B" << endl;
            BillBoard * temp_bb = curPlayer.getTower()->Top_BillBoard.back();
            cout << curPlayer.getName() << " loses his BillBoard: " << temp_bb->getName()<< "." << endl;

            curPlayer.getTower()->Top_BillBoard.pop_back();
            cout << curPlayer.getTower()->getHeight() << "HEIGHT_ before";

            curPlayer.getTower()->setHeight( -(temp_bb->getValue() ) );
            cout << curPlayer.getTower()->getHeight() << "HEIGHT_ after";

            temp_bb->setOwner( -1 );
            temp_bb->setStatus( -1 );
            int tmp = (*(curPlayer.getPlayers().at(owner))).getTower()->getValue() ;
            std::ostringstream oss;
            oss << tmp;
            message = curPlayer.getName() + " could not pay " + (*(curPlayer.getPlayers().at(owner))).getName() + " " + oss.str() + ".\n" + curPlayer.getName() + " loses his BillBoard: " + temp_bb->getName() + ".";

        } else {
            qDebug() << "Player does not have anything to give";
            message = "Player has not have anything to Give.";
        }
	}


}

Space::~Space() {
}
Ownable::~Ownable() {
}

void Go::landOn(Player &curPlayer, MainWindow* main) {
    qDebug() << "LAND ON GO" << endl;
}







void EmpireSpace::landOn(Player &curPlayer, MainWindow* main) {
    message = "";
    main->getCardScene()->addItem( main->getECard() );
    message = curPlayer.getName() + " acquired an Empire Card.";

    int place_card=0;
    for ( int x=0; x<main->getCardScene()->items().size(); x++ ) {
        main->getCardScene()->items().at(x)->setPos(0,place_card);
        place_card+=190;
    }

    main->getCardScene()->update();

}



void Chance::landOn(Player &curPlayer, MainWindow* main) {
    message = "";
    ChanceCard* draw_card = deck->getCard();
//    message = draw_card->getTitle();
    draw_card->play(&curPlayer, message);

    if (draw_card->getTitle() == "Casino Night!") {
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
            if ( curPlayer.getId() != main->getPlayers()->at(x)->getId()  ) {
                main->swap1->addItem( QString::fromStdString( main->getPlayers()->at(x)->getName() ), QVariant(main->getPlayers()->at(x)->getId()) );
            }

        }
        main->getRollButton()->setEnabled(false);
        main->connect( swap_p, SIGNAL( clicked() ), main, SLOT( casinoNight() ) );
        main->swap1->show();
    }
    qDebug() << "LAND ON CHANCE" << endl;
    main->getTowerScene()->update();
}





void JustVisiting::landOn(Player &curPlayer, MainWindow * main) {
    qDebug() << "LAND ON JUST VISITING" << endl;
}











std::string Go::print() {
    qDebug() << "LAND ON GO";
    return "LAND ON GO";
}





std::string EmpireSpace::print() {
    qDebug() << "LAND ON EMPIRE SPACE" ;
    return "LAND ON EMPIRE SPACE\n" + message;
}



std::string Chance::print() {
    qDebug() << "LAND ON CHANCE";
    return "LAND ON CHANCE\n" + message;
}




std::string JustVisiting::print() {
    qDebug() << "LAND ON JUST VISITING";
    return "LAND ON JUST VISITING";
}












std::string Go::buyProperty(Player &curPlayer) {
    qDebug() << "LAND ON GO";
    return "LAND ON GO";
}





std::string EmpireSpace::buyProperty(Player &curPlayer) {
    qDebug() << "LAND ON EMPIRE SPACE";
    return "LAND ON EMPIRE SPACE";
}



std::string Chance::buyProperty(Player &curPlayer) {
    qDebug() << "LAND ON CHANCE";
    return "LAND ON CHANCE";
}




std::string JustVisiting::buyProperty(Player &curPlayer) {
    qDebug() << "LAND ON JUST VISITING";
    return "LAND ON JUST VISITING";
}






