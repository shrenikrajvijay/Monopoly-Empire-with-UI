

#ifndef TOWER_H_
#define TOWER_H_
#include <deque>
#include <vector>
#include "BillBoard.h"
class Tower {
	int current_height;
public:
	Tower();
	virtual ~Tower();
	int TowerHeight[17];
	int getHeight();
	void setHeight( int change );
	int getValue();
	void setBillBoard( BillBoard * bboard);
	BillBoard* getTopBillBoard();
    deque<BillBoard*> * getStack();
    deque<BillBoard*> Top_BillBoard;
    vector<BillBoard*>* tmp ;
    vector<BillBoard*>* getInOrder();

};

#endif /* TOWER_H_ */
