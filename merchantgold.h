#ifndef MERCHANTGOLD_H
#define MERCHANTGOLD_H
#include "player.h"
#include "gold.h"
#include <utility>

class MerchantGold: public Gold{
	public:
	MerchantGold(std::string kind, bool status);
	void useItem(Player *p);
};
#endif

