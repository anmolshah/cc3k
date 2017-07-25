#ifndef GENERATE_H
#define GENERATE_H
#include "potion.h"
#include "character.h"
#include "defense.h"
#include "offence.h"
#include "hp.h"
#include "chamber.h"
#include <vector>
#include "enemy.h"
class Generate{
	public:
	Generate();
	void generatePot(Grid *g);
	void generateEnemy(Grid *g);
	void generatePlayer(Grid *g, Player *p);
	void generateStair(Grid *g);
	int randChamber(); // return num from 1 to 5
	int getDot(Chamber *c, int &x, int &y);
	int randPos(int size); // takes size of a chamber and randomly pick a pos
};	
#endif
