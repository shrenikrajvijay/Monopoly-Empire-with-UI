#include <iostream>
#include <stdio.h>
#include "Space.h"
#include "Tower.h"
#include <QDebug>
#include <QTextEdit>
#include "mainwindow.h"
using namespace std;


EA::EA( int brand, std::string name, int value, int costOf ) : Ownable( brand, name, value, costOf ){

}


std::string EA::print() {
    return "LAND ON EA\n" + message;
}


void EA::landOn(Player& 	curPlayer , MainWindow* main) {
    qDebug() << "LAND ON EA"<< endl;
    if ( owned == false ) {
        main->yesButton->setText("Buy");
        main->noButton->setText("Pass");
        main->turnSwitchOff();
        if ( curPlayer.getMoney() < ( cost ) ) {
            main->yesButton->setEnabled(false);
        }
    } else {
        rent(curPlayer);
    }
}
BillBoard* EA::getBillBoard() {
    return bboard;
}


std::string EA::buyProperty(Player &curPlayer) {
    qDebug() << "INSIDE BUY PROPERTY OF EA";
    std::string forward = buyYes(curPlayer);
    qDebug() << "ENDED BUY PROPERTY OF EA";
    return forward;
}

