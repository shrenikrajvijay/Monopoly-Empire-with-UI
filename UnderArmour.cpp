#include <iostream>
#include <stdio.h>
#include "Space.h"
#include "Tower.h"
#include <QDebug>
#include <QTextEdit>
#include "mainwindow.h"
using namespace std;


UnderArmour::UnderArmour( int brand, std::string name, int value, int costOf ) : Ownable( brand, name, value, costOf ){

}


std::string UnderArmour::print() {
    return "LAND ON UnderArmour\n" + message;
}


void UnderArmour::landOn(Player& 	curPlayer , MainWindow* main) {
    qDebug() << "LAND ON UnderArmour"<< endl;
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
BillBoard* UnderArmour::getBillBoard() {
    return bboard;
}


std::string UnderArmour::buyProperty(Player &curPlayer) {
    qDebug() << "INSIDE BUY PROPERTY OF UnderArmour";
    std::string forward = buyYes(curPlayer);
    qDebug() << "ENDED BUY PROPERTY OF UnderArmour";
    return forward;
}

