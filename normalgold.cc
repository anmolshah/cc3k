#include <iostream>
#include "normalgold.h"

using namespace std;

NormalGold::NormalGold(string kind, bool status): Gold{kind, status}{}

void NormalGold::useItem(Player *p){
	p->changeGold(2);
}
