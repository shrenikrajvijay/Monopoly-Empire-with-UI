#include <iostream>
#include <stdio.h>
#include "Space.h"
#include "Tower.h"
#include <QDebug>
#include <QTextEdit>
#include "mainwindow.h"
using namespace std;


XGames::XGames( int brand, std::string name, int value, int costOf ) : Ownable( brand, name, value, costOf ){

}


std::string XGames::print() {
    return "LAND ON XGames\n" + message;
}


void XGames::landOn(Player& 	curPlayer , MainWindow* main) {
    qDebug() << "LAND ON XGames"<< endl;
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
BillBoard* XGames::getBillBoard() {
    return bboard;
}


std::string XGames::buyProperty(Player &curPlayer) {
    qDebug() << "INSIDE BUY PROPERTY OF XGames";
    std::string forward = buyYes(curPlayer);
    qDebug() << "ENDED BUY PROPERTY OF XGames";
    return forward;
}

