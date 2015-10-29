#include <iostream>
#include <stdio.h>
#include "Space.h"
#include "Tower.h"
#include <QDebug>
#include <QTextEdit>
#include "mainwindow.h"
using namespace std;


Transformers::Transformers( int brand, std::string name, int value, int costOf ) : Ownable( brand, name, value, costOf ){

}


std::string Transformers::print() {
    return "LAND ON Transformers\n" + message;
}


void Transformers::landOn(Player& 	curPlayer , MainWindow* main) {
    qDebug() << "LAND ON Transformers"<< endl;
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
BillBoard* Transformers::getBillBoard() {
    return bboard;
}


std::string Transformers::buyProperty(Player &curPlayer) {
    qDebug() << "INSIDE BUY PROPERTY OF Transformers";
    std::string forward = buyYes(curPlayer);
    qDebug() << "ENDED BUY PROPERTY OF Transformers";
    return forward;
}

