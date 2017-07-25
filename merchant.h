#ifndef MERCHANT_H
#define MERCHANT_H

#include "enemy.h"
#include "merchantgold.h"
class Grid;
class Merchant: public Enemy{
	public:
	Merchant(Grid *g):Enemy(g,30,5,70, 'M', "merchant"){}
	void kill(Player *p) override;
	~Merchant();
};
#endif
