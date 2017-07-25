#include <iostream>
#include "defense.h"
#include <string>

using namespace std;

Defense::Defense(string kind, bool status): Potion{kind, status}{}

void Defense::useItem(Player *p){
	//if potion is negative
	if(this->neg){
		p->changeDef(-5);
		if (p->getRace() == "drow"){
			p->changeDef(-3);
		} 
	} else {
		p->changeDef(5);
		if (p->getRace() == "drow"){
			p->changeDef(3);
		}
	}
}
