#include <iostream>
#include <stdio.h>
#include "Space.h"
#include "Tower.h"
#include <QDebug>
#include <QTextEdit>
#include "mainwindow.h"
using namespace std;


EBay::EBay( int brand, std::string name, int value, int costOf ) : Ownable( brand, name, value, costOf ){

}


std::string EBay::print() {
    return "LAND ON EBay\n" + message;
}


void EBay::landOn(Player& 	curPlayer , MainWindow* main) {
    qDebug() << "LAND ON EBay"<< endl;
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
BillBoard* EBay::getBillBoard() {
    return bboard;
}


std::string EBay::buyProperty(Player &curPlayer) {
    qDebug() << "INSIDE BUY PROPERTY OF EBay";
    std::string forward = buyYes(curPlayer);
    qDebug() << "ENDED BUY PROPERTY OF EBay";
    return forward;
}

