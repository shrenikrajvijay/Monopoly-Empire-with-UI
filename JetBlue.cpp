#include <iostream>
#include <stdio.h>
#include "Space.h"
#include "Tower.h"
#include <QDebug>
#include <QTextEdit>
#include "mainwindow.h"
using namespace std;


JetBlue::JetBlue( int brand, std::string name, int value, int costOf ) : Ownable( brand, name, value, costOf ){

}


std::string JetBlue::print() {
    return "LAND ON JetBlue\n" + message;
}


void JetBlue::landOn(Player& 	curPlayer , MainWindow* main) {
    qDebug() << "LAND ON JetBlue"<< endl;
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
BillBoard* JetBlue::getBillBoard() {
    return bboard;
}


std::string JetBlue::buyProperty(Player &curPlayer) {
    qDebug() << "INSIDE BUY PROPERTY OF JetBlue";
    std::string forward = buyYes(curPlayer);
    qDebug() << "ENDED BUY PROPERTY OF JetBlue";
    return forward;
}

