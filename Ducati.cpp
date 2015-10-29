#include <iostream>
#include <stdio.h>
#include "Space.h"
#include "Tower.h"
#include <QDebug>
#include <QTextEdit>
#include "mainwindow.h"
using namespace std;


Ducati::Ducati( int brand, std::string name, int value, int costOf ) : Ownable( brand, name, value, costOf ){

}


std::string Ducati::print() {
    return "LAND ON Ducati\n" + message;
}


void Ducati::landOn(Player& 	curPlayer , MainWindow* main) {
    qDebug() << "LAND ON Ducati"<< endl;
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
BillBoard* Ducati::getBillBoard() {
    return bboard;
}


std::string Ducati::buyProperty(Player &curPlayer) {
    qDebug() << "INSIDE BUY PROPERTY OF Ducati";
    std::string forward = buyYes(curPlayer);
    qDebug() << "ENDED BUY PROPERTY OF Ducati";
    return forward;
}

