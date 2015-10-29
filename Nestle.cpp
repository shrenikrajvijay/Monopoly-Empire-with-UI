#include <iostream>
#include <stdio.h>
#include "Space.h"
#include "Tower.h"
#include <QDebug>
#include <QTextEdit>
#include "mainwindow.h"
using namespace std;


Nestle::Nestle( int brand, std::string name, int value, int costOf ) : Ownable( brand, name, value, costOf ){

}


std::string Nestle::print() {
    return "LAND ON Nestle\n" + message;
}


void Nestle::landOn(Player& 	curPlayer , MainWindow* main) {
    qDebug() << "LAND ON Nestle"<< endl;
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
BillBoard* Nestle::getBillBoard() {
    return bboard;
}


std::string Nestle::buyProperty(Player &curPlayer) {
    qDebug() << "INSIDE BUY PROPERTY OF Nestle";
    std::string forward = buyYes(curPlayer);
    qDebug() << "ENDED BUY PROPERTY OF Nestle";
    return forward;
}

