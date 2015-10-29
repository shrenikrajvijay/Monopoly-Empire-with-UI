#ifndef EmpireDeck_H
#define EmpireDeck_H

#include <string>
#include <deque>
#include "ChanceCard.h"
#include <vector>
#include "EmpireCard.h"


class EmpireDeck{

    protected:


    public:
        EmpireDeck(MainWindow* main);
        std::deque<EmpireCard*> eDeck;



//        virtual void use(Player&) = 0;

//        void use(Player&);
//        virtual ~EmpireDeck();
        void shuffle();
        EmpireCard* getCard();
        EmpireCard* returnCard(EmpireCard*);
};




#endif //EmpireDeck_H

