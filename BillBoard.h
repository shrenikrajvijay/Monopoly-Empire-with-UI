#ifndef BILLBOARD_H_
#define BILLBOARD_H_
#include <string>

// class Space;

using namespace std;
class BillBoard {
	int value;
	string name;
	int * reset;
	int * payto;
public:
	BillBoard(int, string, int&, int&);
	virtual ~ BillBoard();
	int getValue();
    string getName();
	void setStatus( int );
	void setOwner( int );
	int getOwner();
};

#endif /* BOARD_H_ */
