#include "player.h"
#include <iostream>
using namespace std;

Player::Player(Grid *g,int hp, int def, int attack, std::string race): Character(g,hp, def, attack, '@', race){
	this->race = race;
	this->gold = 0;
	baseAtk = attack;
	baseDef = def;
}

Player::~Player() {};

int Player::getGold(){
	return this->gold;
}

void Player::changeGold(int change){
	this->gold += change;
}

void Player::kill(Player *p){
	p->isAlive = false;
	cout << "Game over" << endl;
}

void Player::setBaseAtk(int baseAtk){
	this->baseAtk = baseAtk;
}

void Player::reset(){
	setBaseAtk(this->baseAtk);
	setBaseDef(this->baseDef);
}

int Player::getBaseAtk(){
	return this->baseAtk;
}

void Player::setBaseDef(int baseDef){
	this->baseDef = baseDef;
}

int Player::getBaseDef(){
	return this->baseDef;
}

string Player::getRace(){
	return this->race;
}

void Player::attack(Character* c){
	if(c == nullptr){
		throw("Invalid move. No enemy exists to attack in specified direction");
	}
	else if(c->getSymb() == 'L' && (rand() % 2)){
		cout << "Player misses attack on Halfling" << endl;
		return;
	}
	else{
		if(c->getSymb() == 'M'){
			if(!c->hostile()){
				c->setHostile();
				cout << "Player attacked merchant. Merchant is now hostile" << endl;
			}
		}
		int damage = ceil((100.0/(100+ c->getDef())) * this->getAtt());
		c->changeHP(damage * -1);
		if(c->getHP() == 0 ){
			c->kill(this);
			cout << this->getRace() << " killed " << c->getRace() << endl;
			if(this->getRace() == "Goblin"){
				this->changeGold(5);
			}
		getGrid()->emptyCell(c->getPosition());
		}
		cout << this->getRace() << " attacked " << c->getRace() << " leaving it with " << c->getHP() << " HP" << endl;
	}
}


void Player::move(std::string dir){
/*	Cell *dest = this->getPosition();
	if(dir == "no"){
		if(!(getGrid()->getCell(x, y)->isEmpty())){
			getGrid()->emptyCell(destCell);
			getGrid()->move(destCell);
			getGrid()->getCell(x, y)->setObj(this);
			getGrid()->emptyCell(curr);
			delete curr;
		}
	 else if (dir == "we"){
		dest->setY(-1);
		if(getGrid()->getCell(dest)->getSymb() == '.'){
			getGrid()->move(dest);
                        swap(*this->getPosition(), *dest);
                }
	}*/
}

string Player::pickUpPotion(Item *it, Cell * pos){
	if (it && ((it->getType() == "BA")) || (it->getType() == "WA") ||
		(it->getType() == "BD") || (it->getType() == "WD") ||
		(it->getType() == "RH") || (it->getType() == "PH")){
		it->useItem(this);
		getGrid()->emptyCell(pos);
	}
}
