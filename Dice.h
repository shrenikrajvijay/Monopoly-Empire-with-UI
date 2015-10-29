/*
 * Dice.h
 *
 *  Created on: Feb 21, 2014
 *      Author: Anh
 */

#ifndef DICE_H_
#define DICE_H_
#include <string>
#include "Player.h"

// class Player;

class Dice {
	bool is_double;
	bool sneaky_swapping;
public:
	Dice();
	int Roll( Player* );
	void Roll();
	bool isDouble();
	bool isSneaky();
};

#endif /* DICE_H_ */
