#include <iostream>
#include <stdio.h>
#include "Space.h"
#include "Tower.h"
#include <QDebug>
#include <QTextEdit>
#include "mainwindow.h"
using namespace std;


Chevrolet::Chevrolet( int brand, std::string name, int value, int costOf ) : Ownable( brand, name, value, costOf ){

}


std::string Chevrolet::print() {
    return "LAND ON Chevrolet\n" + message;
}


void Chevrolet::landOn(Player& 	curPlayer , MainWindow* main) {
    qDebug() << "LAND ON Chevrolet"<< endl;
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
BillBoard* Chevrolet::getBillBoard() {
    return bboard;
}


std::string Chevrolet::buyProperty(Player &curPlayer) {
    qDebug() << "INSIDE BUY PROPERTY OF Chevrolet";
    std::string forward = buyYes(curPlayer);
    qDebug() << "ENDED BUY PROPERTY OF Chevrolet";
    return forward;
}

