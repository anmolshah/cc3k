#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <sstream>
#include <utility>
#include <string>
#include "cell.h"

class Player;

class Item{
	std::string whatKind;
	Cell *curCell;
	public:
	bool neg;
	void setCell(Cell *destCell);
	Cell * getCell();
	virtual char getSymb() = 0;
	virtual void useItem(Player *p) = 0;
	Item(std::string kind, bool status);
	std::string getType();
	virtual bool getStatus();
	~Item();
};

#endif
