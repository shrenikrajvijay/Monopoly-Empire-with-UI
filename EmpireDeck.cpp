#include "EmpireDeck.h"
#include <iostream>
#include <QDebug>

using namespace std;
EmpireDeck::EmpireDeck(MainWindow* main) {


    std::vector<EmpireCard*> make_array;

    EmpireCard* card1 = new Move(0,0,290,160,0,main);
    EmpireCard* card2 = new TallestTower(0,0,290,160,1,main);
    EmpireCard* card3 = new MarketCrash(0,0,290,160,2,main);
//    EmpireCard* card4 = new SayNo(0,0,290,160,3,main);
    EmpireCard* card5 = new JetTrip(0,0,290,160,3,main);
    EmpireCard* card6 = new SwapTop(0,0,290,160,3,main);
    EmpireCard* card7 = new SayNo(0,0,290,160,3,main);
    EmpireCard* card8 = new BillboardTax(0,0,290,160,3,main);
    EmpireCard* card9 = new ReverseRent(0,0,290,160,3,main);
    EmpireCard* card10 = new BargainBusiness(0,0,290,160,3,main);
//    EmpireCard* card11 = new DealBuster(0,0,290,160,3,main);
    EmpireCard* card12 = new JailFreeEmpire(0,0,290,160,3,main);
//    EmpireCard* card13 = new SayNo(0,0,290,160,3,main);
//    EmpireCard* card14 = new TakeOver(0,0,290,160,3,main);

    make_array.push_back(card1);
    make_array.push_back(card2);
    make_array.push_back(card3);
//    make_array.push_back(card4);
    make_array.push_back(card5);
    make_array.push_back(card6);
    make_array.push_back(card7);
    make_array.push_back(card8);
    make_array.push_back(card9);
    make_array.push_back(card10);
//    make_array.push_back(card11);
    make_array.push_back(card12);
//    make_array.push_back(card13);
//    make_array.push_back(card14);

    std::srand(std::time(0));  // needed once per program run


    std::vector<bool> checker;
    for ( int x=0; x<make_array.size(); x++ ) {
        checker.push_back(false);
    }
    int count = 0;
    while ( count < 10 ) {
        // std::cout << "TRYING TO FIND A SPOT" << count;
        int rand = std::rand() % 10;
        // std::cout << "rand = " << rand;
        if ( checker.at(rand) == false ) {
            eDeck.push_back( make_array.at(rand) );
            count++;
            checker.at(rand) = true;
            // std::cout << deck.eDeck.back()->getTitle();
        }

    }


};



void EmpireDeck:: shuffle(){

};

EmpireCard* EmpireDeck:: getCard() {
    qDebug() << QString::fromStdString( eDeck.back()->getTitle() );
    EmpireCard* card = eDeck.back();
    eDeck.pop_back();
    return card;
}

EmpireCard *EmpireDeck::returnCard(EmpireCard * e)
{
    eDeck.push_front(e);
};
