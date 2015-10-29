#include <iostream>
#include <stdio.h>
#include "Space.h"
#include "Tower.h"
#include <QDebug>
#include <QTextEdit>
#include "mainwindow.h"
using namespace std;


Spotify::Spotify( int brand, std::string name, int value, int costOf ) : Ownable( brand, name, value, costOf ){

}


std::string Spotify::print() {
    return "LAND ON Spotify\n" + message;
}


void Spotify::landOn(Player& 	curPlayer , MainWindow* main) {
    qDebug() << "LAND ON Spotify"<< endl;
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
BillBoard* Spotify::getBillBoard() {
    return bboard;
}


std::string Spotify::buyProperty(Player &curPlayer) {
    qDebug() << "INSIDE BUY PROPERTY OF Spotify";
    std::string forward = buyYes(curPlayer);
    qDebug() << "ENDED BUY PROPERTY OF Spotify";
    return forward;
}

