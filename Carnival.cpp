#include <iostream>
#include <stdio.h>
#include "Space.h"
#include "Tower.h"
#include <QDebug>
#include <QTextEdit>
#include "mainwindow.h"
using namespace std;


Carnival::Carnival( int brand, std::string name, int value, int costOf ) : Ownable( brand, name, value, costOf ){

}


std::string Carnival::print() {
    return "LAND ON Carnival\n" + message;
}


void Carnival::landOn(Player& 	curPlayer , MainWindow* main) {
    qDebug() << "LAND ON Carnival"<< endl;
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
BillBoard* Carnival::getBillBoard() {
    return bboard;
}


std::string Carnival::buyProperty(Player &curPlayer) {
    qDebug() << "INSIDE BUY PROPERTY OF Carnival";
    std::string forward = buyYes(curPlayer);
    qDebug() << "ENDED BUY PROPERTY OF Carnival";
    return forward;
}

