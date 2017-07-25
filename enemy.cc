#include "enemy.h"
#include <iostream>
#include <cmath>
using namespace std;

Enemy::Enemy(Grid *g, int hp, int def, int atk, char symb, string race):Character(g,hp, def, atk, symb, race){}

Enemy::~Enemy(){}
void Enemy::attackPlayer(Player *p){
	if(p && (rand() % 2)){
		int damage = ceil((100.0/(100+ p->getDef())) * this->getAtt());
		p->changeHP(damage);
		cout << this->getSymb() << " attacked " << p->getRace() << " leaving it with " << p->getHP() << " HP" << endl;
	}
	else{
		cout<< this->getSymb() << " missed their attack" << endl;
	}
}

void Enemy::kill(Player *p){
	getGrid()->emptyCell(this->getPosition());
	if(rand() % 2){
		p->changeGold(1);
	}
	else{
		p->changeGold(2);
	}
}

void Enemy::move(){
	Cell *curr = this->getPosition();
	Cell *destCell = curr;
		while(destCell->getSymb() != '.'){
			destCell = curr;
			int xOffset = (rand() % 3) - 1;
			int yOffset = (rand() % 3) - 1;
			destCell->setX(xOffset);
			destCell->setY(yOffset);
		}
		getGrid()->move(destCell);
		getGrid()->emptyCell(curr);
}

string Enemy::getRace(){
	return Character::getRace();
}

void Enemy::move(string dir){}


