#include <iostream>
#include <stdio.h>
#include "Space.h"
#include "Tower.h"
#include <QDebug>
#include <QTextEdit>
#include "mainwindow.h"
using namespace std;


Intel::Intel( int brand, std::string name, int value, int costOf ) : Ownable( brand, name, value, costOf ){

}


std::string Intel::print() {
    return "LAND ON Intel\n" + message;
}


void Intel::landOn(Player& 	curPlayer , MainWindow* main) {
    qDebug() << "LAND ON Intel"<< endl;
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
BillBoard* Intel::getBillBoard() {
    return bboard;
}


std::string Intel::buyProperty(Player &curPlayer) {
    qDebug() << "INSIDE BUY PROPERTY OF Intel";
    std::string forward = buyYes(curPlayer);
    qDebug() << "ENDED BUY PROPERTY OF Intel";
    return forward;
}

