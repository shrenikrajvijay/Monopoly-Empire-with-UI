#include <iostream>
#include <stdio.h>
#include "Space.h"
#include "Tower.h"
//#include <QDebug>
#include "mainwindow.h"
using namespace std;




WaterWorks::WaterWorks( int brand, std::string name, int value, int costOf ) : Ownable( brand, name, value, costOf ){
        owned = 0;
    }
void WaterWorks::buy(Player& curPlayer) {
//	int ans;
//	cout << "You have " << curPlayer.getMoney() << endl;
//	std::cout << "Do you want to buy " <<title << " for 150?" << endl ;

//	cout << "1. Yes \n2. No \n3. Another player will buy it" << endl;
//	cin >> ans;

//	if ( ans == 1 ) {
//		cout << "You bought " << title << "." << endl;
//		curPlayer.changeMoney( -150 );
//			curPlayer.getTower()->setBillBoard( ( bboard) );
//		curPlayer.getTower()->setHeight( (*bboard).getValue() );
//		cout << (*bboard).getValue() << "VALUE" << endl ;
//		cout << curPlayer.getTower()->getHeight() << "HEIGHT" << endl;
//		owned+=true;
//	} else if ( ans == 3) {
//		cout << "Which Player will buy it?" << endl;
//		for ( int x = 0; x<curPlayer.getNum(); x++ ) {
//			if ( x  !=  curPlayer.getId() ) {
//			cout << x << "." << (*(curPlayer.getPlayers()).at(x)).getName() << endl;
//			}
//		}
//		cin >> ans;
//		(*(*(curPlayer.getPlayers().at(ans))).getSpaces()[12]).landOn(*(curPlayer.getPlayers().at(ans)));
//	} else {
//				cout << curPlayer.getName() << " did not buy " << title << "." << endl;

//	}



}


void WaterWorks::rent() {
    cout<< "OVERRRRRRRRRRRRRIDEEEEEEEE" << endl;
}



std::string WaterWorks::print() {
    std::cout << "LAND ON WaterWorks";
    return "LAND ON WaterWorks";
}

void WaterWorks::landOn(Player& curPlayer , MainWindow* main) {
    //    qDebug() << "LAND ON WaterWorks"<< endl;
    if ( owned < 4 ) {
        main->yesButton->setText("Buy");
        main->noButton->setText("Pass");
        main->turnSwitchOff();
        if ( curPlayer.getMoney() < ( cost ) ) {
            main->yesButton->setEnabled(false);
        }
    }
    main->getScene()->update();
}

BillBoard* WaterWorks::getBillBoard() {
    return bboard;
}


std::string WaterWorks::buyProperty(Player &curPlayer) {
//    qDebug() << "INSIDE BUY PROPERTY OF WATER WORKS";
    if ( owned < 4 ) {
    std::string forward = buyYes(curPlayer);
//    qDebug() << "ENDED BUY PROPERTY OF WATER WORKS";
    return forward;
    }
    return "DID NOT BUY";
}
