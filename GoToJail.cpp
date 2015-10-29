#include <iostream>
#include <stdio.h>
#include "Space.h"
#include <QDebug>
#include "mainwindow.h"
using namespace std;

void GoToJail::landOn(Player &curPlayer, MainWindow* main) {
	print();
    qDebug() << "YOU ARE NOW IN JAIL" << endl;

    curPlayer.setJail( 1 );
//    curPlayer.setGlobal(9);
    message = "You are now in Jail.";
}

std::string GoToJail::print() {
    return "LAND ON GO TO JAIL\n" + message;

}


std::string GoToJail::buyProperty(Player &curPlayer) {
    qDebug() << "LAND ON COCA COLA";
    return "LAND ON COCA COLA";
}
