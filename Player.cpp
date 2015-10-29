

#include "Player.h"
#include <string>
#include <iostream>
#include <vector>
#include <QDebug>
#include <sstream>
using namespace std;

Player::Player( string input, vector<Player*>* array_player, int player_num, int id, vector<Space*> array_space ) {
    // cout << array_player << endl;
    // cout << &array_player << " : Match 1" << endl;
    at_jail = 0;
	tower = new Tower();
	money = 1000;
	name = (input);
	position = 0;
	players = *&array_player; //**
    // cout << &players << " : Match 2" << endl;
	spaces = *&array_space;
	num_player = player_num;
	my_id = id;
    message="";
    act = NULL;
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

string Player::getName() {
	return name;
}

void Player::setPostion( int rolled_a ) {
    message = "";
    if ( position + rolled_a >= 36 ) {
		changeMoney( getTowerValue() );
        qDebug() << " Receives " <<QString::number( getTowerValue() ) << " for passing GO. :";
        int tmp = getTowerValue();
        std::ostringstream oss;
        oss << tmp;
        message = "Receives " + oss.str()  + " for passing GO.";
	}
    position = (position + rolled_a) % 36;

//	cout << "POSTION AFTER ROLL " << position
}

int Player::getPosition() {
	return position;
}

int Player::getTowerValue() {
	return tower->getValue();
}

void Player::changeMoney( int amount ) {
	money += amount;
}

int Player::getMoney() {
	return money;
}

int* Player::getPositionAdd(){
    return &position;
}

Tower* Player::getTower() {
	return tower;
}

void Player::sneakySwap(Player& choosen1, Player& choosen2 ) {

//        cout << "CURRENT: First Choosen Player has " << choosen1.getTower()->getHeight() << "/17 points." << endl;
        choosen1.getTower()->setHeight( -( choosen1.getTower()->Top_BillBoard.back()->getValue() ) );
        choosen2.getTower()->setHeight( -( choosen2.getTower()->Top_BillBoard.back()->getValue() ) );
        (*(choosen1.getTower()->Top_BillBoard.back())).setOwner( choosen2.getId() );
        (*(choosen2.getTower()->Top_BillBoard.back())).setOwner( choosen1.getId() );
        BillBoard * choosen1_tmp = (choosen1.getTower()->Top_BillBoard.back());
        BillBoard * choosen2_tmp = (choosen2.getTower()->Top_BillBoard.back());

        choosen1.getTower()->Top_BillBoard.pop_back();
        choosen2.getTower()->Top_BillBoard.pop_back();

        choosen1.getTower()->setBillBoard( choosen2_tmp );
        choosen1.getTower()->setHeight( ( choosen1.getTower()->Top_BillBoard.back()->getValue() ) );

        choosen2.getTower()->setBillBoard( choosen1_tmp );
        choosen2.getTower()->setHeight( ( choosen1.getTower()->Top_BillBoard.back()->getValue() ) );

//        cout << "AFTER SWAP: First Choosen Player has " << choosen1.getTower()->getHeight() << "/17 points." << endl;


}


void Player::testPlayers() {
    // cout << (*players[0]).getName() << "WORKSSSSSS" <<endl ;
    // cout << (*players[1]).getName() << "WORKSSSSSS" <<endl ;
    // cout << (*players[2]).getName() << "WORKSSSSSS" <<endl ;
    // cout << (*players[3]).getName() << "WORKSSSSSS" <<endl ;

}



int Player::getNum() {
	return num_player;
}

int Player::getId() {
	return my_id;
}

vector<Player*> Player::getPlayers(){
	return *players;
}

vector<Space*> Player::getSpaces() {
	return spaces;
}

int Player::isInJail() {
	return at_jail;
}

void Player::setJail( int jail_status ) {
	at_jail += jail_status;
    this->position = 9;
}

void Player::setGlobal(int newPosition)
{
    qDebug() << "CALLED COLLECTED";
    if ( position > newPosition ) {
        qDebug() << "OLD POSITION IS HIGHER THAN NEW POSITION";
        qDebug() << "POSITION is : " + QString::number(position);
        qDebug() << "NEW POSITION is : " + QString::number(newPosition);
        // cal = position + (35 - ( position - newPosition ) );
        // if ( cal > 35 ) {
        if ( this->at_jail == 0 ) {
            changeMoney( getTowerValue() );
            cout << "Receives " << getTowerValue() << " for passing GO. :";
            int tmp = getTowerValue();
            std::ostringstream oss;
            oss << tmp;
            message = "Receives " + oss.str()  + " for passing GO.";
        }
    }
    position = newPosition;

}

std::string Player::getMessage() {
    return message;
}

void Player::setMessage(std::string msg) {
    message = msg;
}

void Player::setAction(Action* save ) {
    act = save;
}

void Player::playAction() {
    qDebug("ACTION IS PLAYED");
    act->execute(this);
}

Action* Player::getAction() {
    return act;
}
