#include "BillBoard.h"
#include <string>

BillBoard::BillBoard( int ValueOf, string NameOf, int& owned, int& owner ) : value(ValueOf), name(NameOf) {
	reset = &owned;
	payto = &owner;
};

int BillBoard::getValue() {
	return value;
}


string BillBoard::getName() {
    return name;
}

void BillBoard::setStatus( int set) {
	(*reset) += set;
} 

int BillBoard::getOwner() {
	return (*payto);
}

void BillBoard::setOwner( int owner) {
	(*payto) = owner;
}

BillBoard::~BillBoard() {}
