#include "merchant.h"

Merchant::~Merchant(){}
void Merchant::kill(Player *p){
	getGrid()->emptyCell(this->getPosition());
	getGrid()->getCell(this->getPosition())->setObj(new MerchantGold("gold", false));
}
