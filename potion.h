#ifndef POTION_H
#define POTION_H
#include <iostream>
#include <sstream>
#include <utility>
#include "item.h"
#include <string>

class Potion: public Item {
	public:
	Potion(std::string kind, bool status);
	char getSymb() override;
	void useItem(Player *p) override;
};

#endif
