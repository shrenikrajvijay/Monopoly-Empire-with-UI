#include <iostream>
#include <stdio.h>
#include "Space.h"
#include "Tower.h"
#include <QDebug>
#include <QTextEdit>
#include "mainwindow.h"
using namespace std;


Paramount::Paramount( int brand, std::string name, int value, int costOf ) : Ownable( brand, name, value, costOf ){

}


std::string Paramount::print() {
    return "LAND ON Paramount\n" + message;
}


void Paramount::landOn(Player& 	curPlayer , MainWindow* main) {
    qDebug() << "LAND ON Paramount"<< endl;
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
BillBoard* Paramount::getBillBoard() {
    return bboard;
}


std::string Paramount::buyProperty(Player &curPlayer) {
    qDebug() << "INSIDE BUY PROPERTY OF Paramount";
    std::string forward = buyYes(curPlayer);
    qDebug() << "ENDED BUY PROPERTY OF Paramount";
    return forward;
}

