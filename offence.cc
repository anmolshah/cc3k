#include <iostream>
#include "offence.h"

using namespace std;

Offence::Offence(string kind, bool status): Potion{kind, status}{}

void Offence::useItem(Player *p){
        //if potion is negative
        if(this->neg){
                p->changeAtt(-5);
		if (p->getRace() == "drow"){
			p->changeAtt(-3);
		}
        } else {
                p->changeAtt(5);
		if (p->getRace() == "drow"){
			p->changeAtt(3);
		}
        }
}
