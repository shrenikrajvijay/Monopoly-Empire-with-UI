/*
 * Board.h
 *
 *  Created on: Feb 19, 2014
 *      Author: Anh
 */

#ifndef BOARD_H_
#define BOARD_H_
#include "Space.h"
#include "Player.h"
#include "ChanceDeck.h"
using namespace std;
class Board {
public:
	int peeps;
    Board( int player_num );
	virtual ~ Board();
	vector<Space*> spaces;
	vector<Player*> * players;
    void addNames(vector<string>);
    vector<Player*>* getPlayer();
    ChanceDeck* cDeck;
};

#endif /* BOARD_H_ */
