#include <iostream>
#include <stdio.h>
#include "Space.h"
#include "Tower.h"
#include <QDebug>
#include <QTextEdit>
#include "mainwindow.h"
using namespace std;


XBox::XBox( int brand, std::string name, int value, int costOf ) : Ownable( brand, name, value, costOf ){

}


std::string XBox::print() {
    return "LAND ON XBox\n" + message;
}


void XBox::landOn(Player& 	curPlayer , MainWindow* main) {
    qDebug() << "LAND ON XBox"<< endl;
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
BillBoard* XBox::getBillBoard() {
    return bboard;
}


std::string XBox::buyProperty(Player &curPlayer) {
    qDebug() << "INSIDE BUY PROPERTY OF XBox";
    std::string forward = buyYes(curPlayer);
    qDebug() << "ENDED BUY PROPERTY OF XBox";
    return forward;
}

