#ifndef CHANCECARD_H
#define CHANCECARD_H

#include <string>
#include "Player.h"

class MainWindow;

class ChanceCard {
protected:
    std::string title;
public:
    ChanceCard();
    // void use(Player&);
//     void print();
    virtual void play(Player*, std::string&){};
    std::string getTitle();
};

class SpeedAhead: public ChanceCard {

public:
    SpeedAhead();
    void play(Player*, std::string&);

};

class WaterBonus: public ChanceCard {

public:
    WaterBonus();
    void play(Player*, std::string&);

};

class ProfitSoars: public ChanceCard {

public:
    ProfitSoars();
    void play(Player*, std::string&);

};

class GoToJailCard: public ChanceCard {

public:
    GoToJailCard();
    void play(Player*, std::string&);

};

class FirstBirthday: public ChanceCard {

public:
    FirstBirthday();
    void play(Player*, std::string&);

};

class InsideTrading: public ChanceCard {

public:
    InsideTrading();
    void play(Player*, std::string&);

};

class CasinoNight: public ChanceCard {

public:
    CasinoNight();
    void play(Player*, std::string& );
//    void play(Player*, std::string&);
};

class Campaign: public ChanceCard {

public:
    Campaign();
    void play(Player*, std::string&);

};

class Award: public ChanceCard {

public:
    Award();
    void play(Player*, std::string&);

};

class JailFree: public ChanceCard {

public:
    JailFree();
    void play(Player*, std::string&);

};

class Website: public ChanceCard {

public:
    Website();
    void play(Player*, std::string&);

};

class JailFraud: public ChanceCard {

public:
    JailFraud();
    void play(Player*, std::string&);

};

class SolarPower: public ChanceCard {

public:
    SolarPower();
    void play(Player*, std::string&);

};



#endif // CHANCECARD_H
