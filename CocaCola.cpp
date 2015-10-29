#include <iostream>
#include <stdio.h>
#include "Space.h"
#include "Tower.h"
#include <QDebug>
#include <QTextEdit>
#include "mainwindow.h"
using namespace std;


CocaCola::CocaCola( int brand, std::string name, int value, int costOf ) : Ownable( brand, name, value, costOf ){

}


std::string CocaCola::print() {
    return "LAND ON CocaCola\n" + message;
}


void CocaCola::landOn(Player& 	curPlayer , MainWindow* main) {
    qDebug() << "LAND ON CocaCola"<< endl;
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
BillBoard* CocaCola::getBillBoard() {
    return bboard;
}


std::string CocaCola::buyProperty(Player &curPlayer) {
    qDebug() << "INSIDE BUY PROPERTY OF CocaCola";
    std::string forward = buyYes(curPlayer);
    qDebug() << "ENDED BUY PROPERTY OF CocaCola";
    return forward;
}

