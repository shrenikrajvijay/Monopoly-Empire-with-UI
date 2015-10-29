#include <iostream>
#include <stdio.h>
#include "Space.h"
#include "Tower.h"
#include <QDebug>
#include <QTextEdit>
#include "mainwindow.h"
using namespace std;


Macdonalds::Macdonalds( int brand, std::string name, int value, int costOf ) : Ownable( brand, name, value, costOf ){

}


std::string Macdonalds::print() {
    return "LAND ON Macdonalds\n" + message;
}


void Macdonalds::landOn(Player& 	curPlayer , MainWindow* main) {
    qDebug() << "LAND ON Macdonalds"<< endl;
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
BillBoard* Macdonalds::getBillBoard() {
    return bboard;
}


std::string Macdonalds::buyProperty(Player &curPlayer) {
    qDebug() << "INSIDE BUY PROPERTY OF Macdonalds";
    std::string forward = buyYes(curPlayer);
    qDebug() << "ENDED BUY PROPERTY OF Macdonalds";
    return forward;
}

