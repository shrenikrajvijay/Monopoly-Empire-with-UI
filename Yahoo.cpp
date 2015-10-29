#include <iostream>
#include <stdio.h>
#include "Space.h"
#include "Tower.h"
#include <QDebug>
#include <QTextEdit>
#include "mainwindow.h"
using namespace std;


Yahoo::Yahoo( int brand, std::string name, int value, int costOf ) : Ownable( brand, name, value, costOf ){

}


std::string Yahoo::print() {
    return "LAND ON Yahoo\n" + message;
}


void Yahoo::landOn(Player& 	curPlayer , MainWindow* main) {
    qDebug() << "LAND ON Yahoo"<< endl;
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
BillBoard* Yahoo::getBillBoard() {
    return bboard;
}


std::string Yahoo::buyProperty(Player &curPlayer) {
    qDebug() << "INSIDE BUY PROPERTY OF Yahoo";
    std::string forward = buyYes(curPlayer);
    qDebug() << "ENDED BUY PROPERTY OF Yahoo";
    return forward;
}

