#ifndef ACTION_H
#define ACTION_H

#include <string>
//#include "Player.h"

class Player;

using namespace std;
class Action {

public:
    Action();
    virtual ~ Action();
    virtual void execute(Player*)=0;

};

class ReverseRentAct: public Action{
    int money;
    Player* pred;
public:
    ReverseRentAct(int,Player*);
    void execute(Player*);
};



#endif // ACTION_H
