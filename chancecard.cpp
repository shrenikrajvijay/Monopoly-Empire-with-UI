#include "chancecard.h"
#include "Player.h"
#include "Space.h"
//class Space;

ChanceCard::ChanceCard() {
//    if ( place == 0 ) {
//       title = "Speed ahead!";
//    } else if ( place == 1 ) {
//        title = "Water bonus!";
//    } else if ( place == 2 ) {
//        title = "Profit soar!";
//    } else if ( place == 3 ) {
//        title = "Go To Jail!";
//    } else if ( place == 4 ) {
//        title = "It's your empire's first birthday!";
//    } else if ( place == 5 ) {
//        title = "Insider trading fine!";
//    } else if ( place == 6 ) {
//        title = "Casino Night!";
//    } else if ( place == 7 ) {
//        title = "Successful advertising compaign!";
//    } else if ( place == 8 ) {
//        title = "Win 'Business of the Year' award!";
//    } else if ( place == 9 ) {
//        title = "Casino night!";
//    } else if ( place == 10 ) {
//        title = "Get out of jail free!";
//    } else if ( place == 11 ) {
//        title = "Launch your website!";
//    } else if ( place == 12 ) {
//        title = "Go to Jail for fraud!";
//    } else if ( place == 13 ) {
//        title = "Solar power bonus!";
//    }
};

//void ChanceCard::use(Player& curPlayer){

//}

//void ChanceCard::print() {
//    qDebug() << QString::fromStdString(title);
//}

std::string ChanceCard::getTitle() {
    return title;
}

SpeedAhead::SpeedAhead() : ChanceCard(){
    title = "Speed ahead!";
};

WaterBonus::WaterBonus() : ChanceCard(){
    title = "Water bonus!";
};

ProfitSoars::ProfitSoars() : ChanceCard(){
    title = "Profit soar!";
};


GoToJailCard::GoToJailCard() : ChanceCard(){
    title = "Go To Jail!";
};

FirstBirthday::FirstBirthday() : ChanceCard(){
    title = "It's your empire's first birthday!";
};

InsideTrading::InsideTrading() : ChanceCard(){
    title = "Insider trading fine!";
};

CasinoNight::CasinoNight() : ChanceCard(){
    title = "Casino Night!";
};

Campaign::Campaign() : ChanceCard(){
    title = "Successful advertising campaign!";
};

Award::Award() : ChanceCard(){
    title = "Win 'Business of the Year' award!";
};


JailFree::JailFree() : ChanceCard(){
    title = "Get out of jail free!";
};

Website::Website() : ChanceCard(){
    title = "Launch your website!";
};

JailFraud::JailFraud() : ChanceCard(){
        title = "Go to Jail for fraud!";
};

SolarPower::SolarPower() : ChanceCard(){
    title = "Solar power bonus!";
};


void SpeedAhead::play(Player* curPlayer, string& msg) {
    msg+= "\n    Speed Ahead!\n    Move Forward up to five spaces in your private limo.\n";
};


void WaterBonus::play(Player* curPlayer, string& msg) {
    msg+= "\n    Water bonus!\n    Take a free Water Works billboard and add it to your tower.\n    If none are available, do nothing.";
    Ownable* electric = dynamic_cast<Ownable*>(curPlayer->getSpaces().at(30));

    if ( electric->owned < 4 ) {
    curPlayer->getTower()->setBillBoard( electric->bboard );
    curPlayer->getTower()->setHeight( electric->bboard->getValue() );

    electric->owned += 1;
    electric->owner = curPlayer->getId();
    msg += "\n    You added Water Works to your tower.";
    } else {
        msg += "\n    Out of Water Works BillBoards.";
    }


};

void ProfitSoars::play(Player* curPlayer, string& msg) {
    msg += "\n    Profit Soars!\n    Advance to Go to collect your tower value.\n";
    curPlayer->setGlobal(0);
};

void GoToJailCard::play(Player* curPlayer, string& msg) {
    msg += "\n    Go to Jail!\n    Do not collect cash for passing GO.";
    curPlayer->setJail( 1 );
};

void FirstBirthday::play(Player* curPlayer, string& msg) {
    msg += "\n    It's your empire's first birthday!\n    All players play you 50.\n";
    curPlayer->changeMoney( (curPlayer->getPlayers().size()-1) * 50);
    for ( int x = 0 ; x<curPlayer->getPlayers().size(); x++) {
        if ( curPlayer->getPlayers().at(x)->getId() != curPlayer->getId() ) {
            curPlayer->getPlayers().at(x)->changeMoney(-50);
        }
    }
};

void InsideTrading::play(Player* curPlayer, string& msg) {
    msg += "\n    Insider trading fine!\n    Pay the Bank 200.\n";
    curPlayer->changeMoney(-200);
};

void CasinoNight::play(Player* curPlayer, string& msg) {
    msg += "\n    Casino Night!\n    Pick an opponent.Both roll. Highest-roller collects 200 from the Bank.\n";
};

//void CasinoNight::play(Player* curPlayer, string& msg, MainWindow* main) {
//};

void Campaign::play(Player* curPlayer, string& msg) {
    msg += "\n    Successful advertising campaign!\n    Collect 100 from the Bank.\n";
    curPlayer->changeMoney(100);
};

void Award::play(Player* curPlayer, string& msg) {
    msg += "\n    Win 'Business of the Year' award!\n    Collect 400 from the Bank.\n";
    curPlayer->changeMoney(400);
};

void JailFree::play(Player* curPlayer, string& msg) {

};

void Website::play(Player* curPlayer, string& msg) {
    msg += "\n    Sales Skyrocket!\n    Collect 300 from the Bank.\n";
    curPlayer->changeMoney(300);
};

void JailFraud::play(Player* curPlayer, string& msg) {
    msg += "\n    Go to Jail for fraud!\n    Do not collect cash for passing GO.";
    curPlayer->setJail( 1 );
};

void SolarPower::play(Player* curPlayer, string& msg) {
    msg+= "\n    Solar Power !\n    Take a free Electric Company billboard.\n    Add it to your tower.\n    If none are available, do nothing.";
    Ownable* electric = dynamic_cast<Ownable*>(curPlayer->getSpaces().at(12));

    if ( electric->owned < 4 ) {
    curPlayer->getTower()->setBillBoard( electric->bboard );
    curPlayer->getTower()->setHeight( electric->bboard->getValue() );

    electric->owned += 1;
    electric->owner = curPlayer->getId();
    msg += "\n    You added Electric Company to your tower.";
    } else {
        msg += "\n    Out of Electric Company BillBoards.";
    }
};


