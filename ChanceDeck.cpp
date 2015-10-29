#include "ChanceDeck.h"
#include <iostream>
#include <QDebug>

using namespace std;
ChanceDeck::ChanceDeck() {


    std::vector<ChanceCard*> make_array;

    ChanceCard* card1 = new SpeedAhead();
    ChanceCard* card2 = new WaterBonus();
    ChanceCard* card3 = new ProfitSoars();
    ChanceCard* card4 = new GoToJailCard();
    ChanceCard* card5 = new FirstBirthday();
    ChanceCard* card6 = new InsideTrading();
    ChanceCard* card7 = new CasinoNight();
    ChanceCard* card8 = new Campaign();
    ChanceCard* card9 = new Award();
    ChanceCard* card10 = new CasinoNight();
    ChanceCard* card11 = new JailFree();
    ChanceCard* card12 = new Website();
    ChanceCard* card13 = new JailFraud();
    ChanceCard* card14 = new SolarPower();

    make_array.push_back(card1);
    make_array.push_back(card2);
    make_array.push_back(card3);
    make_array.push_back(card4);
    make_array.push_back(card5);
    make_array.push_back(card6);
    make_array.push_back(card7);
    make_array.push_back(card8);
    make_array.push_back(card9);
    make_array.push_back(card10);
    make_array.push_back(card11);
    make_array.push_back(card12);
    make_array.push_back(card13);
    make_array.push_back(card14);

    std::srand(std::time(0));  // needed once per program run


    std::vector<bool> checker;
    for ( int x=0; x<14; x++ ) {
        checker.push_back(false);
    }
    int count = 0;
    while ( count < 14 ) {
        // std::cout << "TRYING TO FIND A SPOT" << count;
        int rand = std::rand() % 14;
        // std::cout << "rand = " << rand;
        if ( checker.at(rand) == false ) {
            cDeck.push_back( make_array.at(rand) );
            count++;
            checker.at(rand) = true;
            // std::cout << deck.cDeck.back()->getTitle();
        }

    }


};



void ChanceDeck:: shuffle(){

};

ChanceCard* ChanceDeck:: getCard() {
    qDebug() << QString::fromStdString( cDeck.back()->getTitle() );
    ChanceCard* card = cDeck.back();
    cDeck.pop_back();
    return card;
};
