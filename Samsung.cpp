#include <iostream>
#include <stdio.h>
#include "Space.h"
#include "Tower.h"
#include <QDebug>
#include <QTextEdit>
#include "mainwindow.h"
using namespace std;


Samsung::Samsung( int brand, std::string name, int value, int costOf ) : Ownable( brand, name, value, costOf ){

}


std::string Samsung::print() {
    return "LAND ON Samsung\n" + message;
}


void Samsung::landOn(Player& 	curPlayer , MainWindow* main) {
    qDebug() << "LAND ON Samsung"<< endl;
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
BillBoard* Samsung::getBillBoard() {
    return bboard;
}


std::string Samsung::buyProperty(Player &curPlayer) {
    qDebug() << "INSIDE BUY PROPERTY OF Samsung";
    std::string forward = buyYes(curPlayer);
    qDebug() << "ENDED BUY PROPERTY OF Samsung";
    return forward;
}

