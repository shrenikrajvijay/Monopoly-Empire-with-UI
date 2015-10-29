#include <iostream>
#include <stdio.h>
#include "Space.h"
#include "Tower.h"
#include <QDebug>
#include <QTextEdit>
#include "mainwindow.h"
using namespace std;


Fender::Fender( int brand, std::string name, int value, int costOf ) : Ownable( brand, name, value, costOf ){

}


std::string Fender::print() {
    return "LAND ON Fender\n" + message;
}


void Fender::landOn(Player& 	curPlayer , MainWindow* main) {
    qDebug() << "LAND ON Fender"<< endl;
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
BillBoard* Fender::getBillBoard() {
    return bboard;
}


std::string Fender::buyProperty(Player &curPlayer) {
    qDebug() << "INSIDE BUY PROPERTY OF Fender";
    std::string forward = buyYes(curPlayer);
    qDebug() << "ENDED BUY PROPERTY OF Fender";
    return forward;
}

