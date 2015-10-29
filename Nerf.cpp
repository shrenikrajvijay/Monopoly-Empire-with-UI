#include <iostream>
#include <stdio.h>
#include "Space.h"
#include "Tower.h"
#include <QDebug>
#include <QTextEdit>
#include "mainwindow.h"
using namespace std;


Nerf::Nerf( int brand, std::string name, int value, int costOf ) : Ownable( brand, name, value, costOf ){

}


std::string Nerf::print() {
    return "LAND ON Nerf\n" + message;
}


void Nerf::landOn(Player& 	curPlayer , MainWindow* main) {
    qDebug() << "LAND ON Nerf"<< endl;
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
BillBoard* Nerf::getBillBoard() {
    return bboard;
}


std::string Nerf::buyProperty(Player &curPlayer) {
    qDebug() << "INSIDE BUY PROPERTY OF Nerf";
    std::string forward = buyYes(curPlayer);
    qDebug() << "ENDED BUY PROPERTY OF Nerf";
    return forward;
}

