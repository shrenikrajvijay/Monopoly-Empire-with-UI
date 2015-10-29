/*
 * Dice.cpp
 *
 *  Created on: Feb 21, 2014
 *      Author: Anh
 */

#include "Dice.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string>
#include <QString>
#include <QDebug>
using namespace std;


Dice::Dice() {
	srand (time(NULL));
	sneaky_swapping = false;
	is_double = false;

}

int Dice::Roll( Player* curPlayer ){
	int dice1 = rand() % 6 + 1;
	int dice2 = rand() % 6 + 1;
	sneaky_swapping = false;
	is_double = false;
	if ( dice1 == 1 ) {
        qDebug() << QString::fromStdString( curPlayer->getName() ) << " rolled a sneaky swap? 1.YES 2.NO:  ";
//		cin >> sneaky_swap;
        sneaky_swapping = true;
        return dice2;
	}
	if ( dice1 == dice2 ) {
		is_double = true;
	}
	return dice1+dice2;
}

void Dice::Roll() {
	int dice1 = rand() % 6 + 1;
	int dice2 = rand() % 6 + 1;
	is_double = false;
	if ( dice1 == dice2 ) {
		is_double = true;
	}
}
bool Dice::isSneaky() {
	return sneaky_swapping;
}

bool Dice::isDouble() {
	return is_double;
}


