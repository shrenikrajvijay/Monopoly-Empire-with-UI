

#include "Tower.h"
#include <iostream>
Tower::Tower() : current_height(0) {

	TowerHeight[0] = 50;
	TowerHeight[1] = 50;
	TowerHeight[2] = 100;
	TowerHeight[3] = 150;
	TowerHeight[4] = 200;
	TowerHeight[5] = 250;
	TowerHeight[6] = 300;
	TowerHeight[7] = 350;
	TowerHeight[8] = 400;
	TowerHeight[9] = 450;
	TowerHeight[10] = 500;
	TowerHeight[11] = 550;
	TowerHeight[12] = 600;
	TowerHeight[13] = 650;
	TowerHeight[14] = 700;
	TowerHeight[15] = 750;
	TowerHeight[16] = 800;

    deque<BillBoard*> Top_BillBoard;



}

int Tower:: getHeight() {
	return current_height;
}

void Tower:: setHeight( int change ) {
	current_height += change;
}
int	 Tower:: getValue() {
	return TowerHeight[current_height];

}

void Tower:: setBillBoard( BillBoard *bboard ) {
	cout << "SETBILLBOARD";
    Top_BillBoard.push_back( bboard );
 	std::cout << "size: " << Top_BillBoard.size() << '\n';
}


BillBoard* Tower:: getTopBillBoard() {
    return Top_BillBoard.back();
}

deque<BillBoard*>* Tower::getStack(){
    return &Top_BillBoard;
}

vector<BillBoard*>* Tower::getInOrder() {
    for( int i=0; i<Top_BillBoard.size();i++) {
        tmp->push_back( Top_BillBoard.back() );
        Top_BillBoard.pop_back();
    }
    for ( int x=tmp->size(); x>0; x-- ) {
        Top_BillBoard.push_back( tmp->at(x) );
    }
    return tmp;
}

Tower::~Tower() {
	// TODO Auto-generated destructor stub
}

