#include <iostream>
#include <stdio.h>
#include "Space.h"
#include <QDebug>
using namespace std;

std::string TowerTax::print() {
    return "LAND ON TOWER TAX\n" + message;
}



void TowerTax::landOn(Player &curPlayer, MainWindow* main) {
    std::cout << "LAND ON TOWER TAX"<< endl;
    if ( curPlayer.getTower()->getHeight() > 0 ) {
        qDebug() << "IN HERE NOT IN ELSE FOR TOWER TAX";
        BillBoard * temp_bb = curPlayer.getTower()->Top_BillBoard.back();
        cout << curPlayer.getName() << " loses his BillBoard: " << temp_bb->getName()<< "." << endl;
        message = curPlayer.getName() + " loses his BillBoard: " + temp_bb->getName() +  ".";

        curPlayer.getTower()->Top_BillBoard.pop_back();
        cout << curPlayer.getTower()->getHeight() << "HEIGHT_ before";

        curPlayer.getTower()->setHeight( -(temp_bb->getValue() ) );
        cout << curPlayer.getTower()->getHeight() << "HEIGHT_ after";

        temp_bb->setOwner( -1 );
        temp_bb->setStatus( -1 );

    } else {
        cout << curPlayer.getName() <<" can not be be taxed anymore." << endl;
        message = curPlayer.getName() + " can not be be taxed anymore.";

    }


}


std::string TowerTax::buyProperty(Player &curPlayers) {
    return "LAND ON COCA COLA";
}
