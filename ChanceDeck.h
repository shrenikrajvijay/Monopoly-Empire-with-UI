#ifndef CHANCEDECK_H
#define CHANCEDECK_H

#include <string>
#include <deque>
#include "ChanceCard.h"
#include <vector>

class ChanceDeck{

    protected:


    public:
        ChanceDeck();
        std::deque<ChanceCard*> cDeck;



//        virtual void use(Player&) = 0;

//        void use(Player&);
//        virtual ~ChanceDeck();
        void shuffle();
        ChanceCard* getCard();
};




#endif //CHANCEDECK_H

