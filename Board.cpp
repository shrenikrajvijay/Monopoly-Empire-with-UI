/*
 * Board.cpp
 *
 *  Created on: Feb 19, 2014
 *      Author: Anh
 */

#include "Board.h"
#include <iostream>
#include <stdio.h>

using namespace std;

Board::Board( int player_num ) {

	peeps = player_num;
	
    cDeck = new ChanceDeck();
	players = new vector<Player*>[peeps];

	cout << "Address of Players: " << players;
	string str0 = "GO";
	string str1 = "NERF";
	string str2 = "RIVAL TOWER TAX";
	string str3 = "TRANSFORMERS";
	string str4 = "EMPIRE SPACE";
	string str5 = "SPOTIFY";
	string str6 = "CHANCE";
	string str7 = "BEATS";
	string str8 = "FENDER";
	string str9 = "JUST VISITING";
	string str10 = "JET BLUE";
	string str11 = "EA SPORTS";
    string str12 = "ELECTRIC COMPANY";
    string str13 = "HASBROS";
    string str14 = "UNDER ARMOUR";
	string str15 = "CHANCE";
	string str16 = "CARNIVAL";
	string str17 = "YAHOO!";
	string str18 = "FREE PARKING";
	string str19 = "PARAMOUNT";
	string str20 = "CHEVROLET";
	string str21 = "CHANCE";
	string str22 = "EBAY";
	string str23 = "X GAMES";
	string str24 = "EMPIRE SPACE";
	string str25 = "DUCATI";
	string str26 = "MACDONALDS";
	string str27 = "GO TO JAIL";
	string str28 = "INTEL";
	string str29 = "XBOX";
	string str30 = "WATER WORKS";
	string str31 = "NESTLE";
	string str32 = "CHANCE";
	string str33 = "SAMSUNG";
	string str34 = "TOWER TAX";
	string str35 = "COCA COLA";

    Space * space0 = new Go( 0, str0 );
    Space * space1 = new Nerf( 1, str1, 1, 50);
    Space * space2 = new RivalTowerTax( 3, str2 );
    Space * space3 = new Transformers( 3, str3, 1, 50 );
    Space * space4 = new EmpireSpace( 4, str4 );
    Space * space5 = new Spotify( 5, str5, 1, 50 );
    Space * space6 = new Chance( 6, str6, cDeck );
    Space * space7 = new Beats( 7, str7, 1 , 100 );
    Space * space8 = new Fender( 8, str8, 1, 100 );
    Space * space9 = new JustVisiting( 9, str9 );
    Space * space10 = new JetBlue( 10, str10, 2 , 150 );
    Space * space11 = new EA( 11, str11, 2, 150 );
    Space * space12 = new ElectricCompany( 12, str12, 1, 150 );
    Space * space13 = new HasBro( 13, str13, 2, 150 );
    Space * space14 = new UnderArmour( 14, str14 , 2, 200 );
    Space * space15 = new Chance( 15, str15, cDeck );
    Space * space16 = new Carnival( 16, str16, 2, 200 );
    Space * space17 = new Yahoo( 17, str17, 2, 200 );
    Space * space18 = new FreeParking( 18, str18 );
    Space * space19 = new Paramount( 19, str19, 3, 250 );
    Space * space20 = new Chevrolet( 20, str20, 3, 250 );
    Space * space21 = new Chance( 21, str21, cDeck );
    Space * space22 = new EBay( 22, str22, 3, 250 );
    Space * space23 = new XGames( 23, str23, 3, 300 );
    Space * space24 = new EmpireSpace( 24, str24 );
    Space * space25 = new Ducati( 25, str25, 3, 300 );
    Space * space26 = new Macdonalds( 26, str26 ,3, 300 );
    Space * space27 = new GoToJail( 27, str27 );
    Space * space28 = new Intel( 28, str28, 4, 350 );
    Space * space29 = new XBox( 29, str29, 4, 350 );
    Space * space30 = new WaterWorks( 30, str30, 1, 150 );
    Space * space31 = new Nestle( 31, str31, 4, 350 );
    Space * space32 = new Chance( 32, str32, cDeck );
    Space * space33 = new Samsung( 33, str33, 4, 400 );
    Space * space34 = new TowerTax( 34, str34 );
    Space * space35 = new CocaCola( 35, str35, 4, 400 );

	spaces.push_back(space0);
	spaces.push_back(space1);
	spaces.push_back(space2);
	spaces.push_back(space3);
	spaces.push_back(space4);
	spaces.push_back(space5);
	spaces.push_back(space6);
	spaces.push_back(space7);
	spaces.push_back(space8);
	spaces.push_back(space9);
	spaces.push_back(space10);
	spaces.push_back(space11);
	spaces.push_back(space12);
	spaces.push_back(space13);
	spaces.push_back(space14);
	spaces.push_back(space15);
	spaces.push_back(space16);
	spaces.push_back(space17);
	spaces.push_back(space18);
	spaces.push_back(space19);
	spaces.push_back(space20);
	spaces.push_back(space21);
	spaces.push_back(space22);
	spaces.push_back(space23);
	spaces.push_back(space24);
	spaces.push_back(space25);
	spaces.push_back(space26);
	spaces.push_back(space27);
	spaces.push_back(space28);
	spaces.push_back(space29);
	spaces.push_back(space30);
	spaces.push_back(space31);
	spaces.push_back(space32);
	spaces.push_back(space33);
	spaces.push_back(space34);
	spaces.push_back(space35);

}

void Board::addNames(vector<string> names) {


    for ( int x=0; x<peeps; x++ ) {
        players->push_back( new Player( names.at(x), players, peeps, x, (spaces) ) );
    }
    // cout << (players.at(0))->getName() << "NAME START" <<endl;
    // cout << "Players Addresss: "  << &players << endl ;



}



vector<Player*>* Board::getPlayer() {
	// cout << players->at(0)->getName();
	return players;
}


Board::~Board() {
	std::cout << "Test BOARD Deconstructor!";
}

