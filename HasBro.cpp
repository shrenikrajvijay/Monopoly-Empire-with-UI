#include <iostream>
#include <stdio.h>
#include "Space.h"
#include "Tower.h"
#include <QDebug>
#include <QTextEdit>
#include "mainwindow.h"
using namespace std;


HasBro::HasBro( int brand, std::string name, int value, int costOf ) : Ownable( brand, name, value, costOf ){

}


std::string HasBro::print() {
    return "LAND ON HasBro\n" + message;
}


void HasBro::landOn(Player& 	curPlayer , MainWindow* main) {
    qDebug() << "LAND ON HasBro"<< endl;
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
BillBoard* HasBro::getBillBoard() {
    return bboard;
}


std::string HasBro::buyProperty(Player &curPlayer) {
    qDebug() << "INSIDE BUY PROPERTY OF HasBro";
    std::string forward = buyYes(curPlayer);
    qDebug() << "ENDED BUY PROPERTY OF HasBro";
    return forward;
}

