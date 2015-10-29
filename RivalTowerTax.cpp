#include <iostream>
#include <stdio.h>
#include "Space.h"
#include "mainwindow.h"
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include "ui_mainwindow.h"
#include <QDebug>
using namespace std;


std::string RivalTowerTax::print() {
    return "LAND ON RIVAL TOWER TAX\n" + message;

}

void RivalTowerTax::landOn(Player& curPlayer, MainWindow* main) {
    std::cout << "LAND ON RIVAL TOWER TAX" <<endl;
    int count = 0;

    main->yesButton->hide();
    main->noButton->hide();

    for( int x=0; x<main->peep; x++ ) {
        if ( !main->getPlayers()->at(x)->getTower()->Top_BillBoard.empty() && curPlayer.getId() !=  main->getPlayers()->at(x)->getId()  ) {
            count++;
        }
    }
    qDebug() << "COUNT IS " << QString::number( count );
    if ( count >= 1 ) {
        main->swap_w = new QWidget(main);
        QHBoxLayout* swap_v = new QHBoxLayout;
        main->swap1 = new QComboBox();
        QPushButton* swap_p = new QPushButton;
        swap_p->setText("Choose");
        swap_v->addWidget(main->swap1);
        swap_v->addWidget(swap_p);
        main->swap_w->setLayout(swap_v);
        main->getUi()->top_command->addWidget(main->swap_w);


        for( int x=0; x<main->peep; x++ ) {
            if ( !main->getPlayers()->at(x)->getTower()->Top_BillBoard.empty()  && curPlayer.getId() != main->getPlayers()->at(x)->getId()  ) {
                main->swap1->addItem( QString::fromStdString( main->getPlayers()->at(x)->getName() ), QVariant(main->getPlayers()->at(x)->getId()) );
            }

        }
        main->getRollButton()->setEnabled(false);
        main->connect( swap_p, SIGNAL( clicked() ), main, SLOT( rivalTax() ) );
        main->swap1->show();


    } else {
        main->getRollButton()->setEnabled(true);
        message = "No Rivals To Tax.";
    }

//    main->yesButton->setText("MainWindow");
//    main->noButton->setText("Pass");
//    main->turnSwitchOff();



//	int choose = 0;
//	int exist = 0;
//	cout << "Stage 1 " << endl;
//	for ( int x = 0; x<curPlayer.getNum(); x++ ) {
//		cout << "Stage 1a" << endl;
		
// 		if ( x  !=  curPlayer.getId() && ! (*(curPlayer.getPlayers()).at(x)).getTower()->Top_BillBoard.empty()  ) {
// 			cout << "Stage 2b" << endl;
//			cout << x << "." << (*(curPlayer.getPlayers()).at(x)).getName() << "  (" << (*(curPlayer.getPlayers().at(x))).getTower()->Top_BillBoard.top()->getName() << ")" << endl;
//			exist++;
//		}

//	}
//	cout << "Stage 2 " << endl;
//	if ( exist!= 0) {
//		cout << "Choose a player: " << endl ;
//		cin >> choose;
//		curPlayer.sneakySwap(*(curPlayer.getPlayers()).at(choose));
//	} else {
//		cout << "No Player to Swap." << endl;
//	}


}


std::string RivalTowerTax::buyProperty(Player &curPlayer) {
    return "LAND ON COCA COLA";
}
