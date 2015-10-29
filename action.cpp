#include "action.h"
#include <iostream>
#include "Player.h"
#include <QDebug>
Action::Action(){
}


ReverseRentAct::ReverseRentAct(int stmt_money,Player* predator) : Action(){
    money = stmt_money;
    pred = predator;
}


void ReverseRentAct::execute(Player* prey)
{
    prey->changeMoney(2*money);
    qDebug() << QString::fromStdString( prey->getName() ) + " gains " + QString::number( 2*money );
    qDebug() << QString::fromStdString( pred->getName() ) + " loses " + QString::number( 2*money );
    pred->changeMoney(-2*money);
}

Action::~Action() {
}

