

#ifndef PLAYER_H_
#define PLAYER_H_
#include <string>
#include "Tower.h"
#include <vector>
#include "action.h"
//#include "Space.h"
using namespace std;

class Space;

class Player {
private:
	string name;
	int money;
	int position;
	int at_jail;
	Tower * tower;
	vector<Player*> * players;
	int num_player;
	int my_id;
	vector<Space*> spaces;
    std::string message;
    Action* act;

public:
	Player( string input, vector<Player*>* , int, int, vector<Space*> );
	virtual ~Player();
	string getName();
	int getPosition();
	void setPostion( int );
	int getTowerValue();
    void changeMoney( int );
	int getMoney();
    void setGlobal(int);
	Tower * getTower();
    void sneakySwap(Player&, Player&);
    vector<Player*> getPlayers();
	int getNum();
	int getId();
	void testPlayers();
	int isInJail();
	void setJail( int );
	vector<Space*> getSpaces();
    int* getPositionAdd();
    std::string getMessage();
    void setMessage(std::string);
    void setAction(Action*);
    void playAction();
    Action* getAction();
};

#endif /* PLAYER_H_ */
