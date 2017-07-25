#include <iostream>
#include "hp.h"
#include <string>

using namespace std;

Hp::Hp(string kind, bool status): Potion{kind, status}{}

void Hp::useItem(Player *p){
	//if potion is negative
	if(this->neg){
		p->changeHP(-10);
		if (p->getRace() == "drow"){
			p->changeHP(-5);
		}
	if (p->getHP() < 0){ p->changeHP(p->getHP() * -1);}
	} else {
		p->changeHP(10);
		if (p->getRace() == "drow"){
			p->changeHP(5);
		}
		if(p->getHP() > p->getMaxHP()){ p->setHP(p->getMaxHP());}
	}
}
