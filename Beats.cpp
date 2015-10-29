#include <iostream>
#include <stdio.h>
#include "Space.h"
#include "Tower.h"
#include <QDebug>
#include <QTextEdit>
#include "mainwindow.h"
using namespace std;


Beats::Beats( int brand, std::string name, int value, int costOf ) : Ownable( brand, name, value, costOf ){

}


std::string Beats::print() {
    return "LAND ON Beats\n" + message;
}


void Beats::landOn(Player& 	curPlayer , MainWindow* main) {
    qDebug() << "LAND ON Beats"<< endl;
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
BillBoard* Beats::getBillBoard() {
    return bboard;
}


std::string Beats::buyProperty(Player &curPlayer) {
    qDebug() << "INSIDE BUY PROPERTY OF Beats";
    std::string forward = buyYes(curPlayer);
    qDebug() << "ENDED BUY PROPERTY OF Beats";
    return forward;
}

