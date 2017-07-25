#include "grid.h"
#include "enemy.h"
#include "character.h"
#include "shade.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "troll.h"
#include "vampire.h"
#include "goblin.h"
#include "drow.h"
#include "generate.h"
#include "item.h"
#include "cell.h"
#include <string>

using namespace std;
int main(int argc, char *argv[]){
	start:
	Grid *g;
	Generate *gen;
	Player *player;
	if(argc ==2){
		ifstream filename {argv[1]};
		g = new Grid();
		g->gridInit(filename);
		cout<<*g;
	 } 
	
	string chosenRace;
	cout << "Please choose one of the following races:"<< endl;
	cout << "(S)hade" <<endl << "(D)row" << endl << "(V)ampire" << endl << "(G)oblin" << endl << "(T)roll" << endl;
	cout << "Press q to quit" <<endl;
 	while(cin >> chosenRace){
		if(chosenRace == "q"){
			return 0;
		}
		else if(chosenRace == "s"){
			player = new Shade(g);
			break;
		}
		else if(chosenRace == "d"){
			player = new Drow(g);
			break;
		}
		else if(chosenRace == "v"){
			player = new Vampire(g);
			break;
		}
		else if(chosenRace == "g"){
			player = new Goblin(g);
			break;
		}
		else if(chosenRace == "t"){
			player = new Troll(g);
			break;
		}
		else{
			player = new Shade(g);
			cout << "Invalid input, please try again!"<<endl;
		}
	}
	cout << "Instructions" << endl;
	cout << "Move North = no" << endl;
	cout << "Move South = so" << endl;
	cout << "Move East = ea" << endl;
	cout << "Move West = we" << endl;
	cout << "Move North East = ne" << endl;
	cout << "Move North West = nw" << endl;
	cout << "Move South East = se" << endl;
	cout << "Move South West = sw" << endl;
	cout << "Attack = a" << endl;
	cout << "Use = u" << endl;
	cout << "Reset = r" << endl;
	cout << "Quit = q" << endl;
	gen->generatePlayer(g,player);
	cout << *g;
	cout << "Race: " << player->getRace() << " Gold: " << player->getGold()
	 << "            					        " << "floor "<< g->getLevel() << endl;
	cout<< "HP: " <<player->getHP() << endl;
	cout << "Atk:" << player->getAtt() << endl;
	cout << "Def:" << player->getDef() << endl;
	cout << "Action: Player character has spawned." << endl;

	bool use = false;
	bool attack = false;
	bool frozen = false;
	string command;
	while(cin >> command && player->isAlive){
		if(command == "f"){
			frozen = !frozen;
			continue;
		}
		else if(command == "q"){
			player->kill(player);
			cout<< "Quit! Your final score was: " << player->getGold() << endl;
			delete g;
			delete gen;
			return 0;
		}
		else if(command == "r"){
			goto start;
		}
		else if(command == "u"){
			use = true;
			continue;
		}
		else if(command == "a"){
			attack = true;
			continue;
		}
		else if(command == "no" || command == "so" || command == "ea" || command == "we" || command == "ne" || command == "nw" || command == "se" || command == "sw"){
			if(attack){
				Cell * temp = player->getPosition();
				Cell *dest = temp;
				if(command ==" no"){
                                        dest->setY(1);
                                }
                                else if(command == "so"){
                                        dest->setY(-1);
                                }
                                else if(command == "ea"){
                                        dest->setX(1);
                                }
                                else if(command == "we"){
                                        dest->setX(-1);
                                }
                                else if(command == "ne"){
                                        dest->setX(1);
                                        dest->setY(1);
                                }
                                else if(command == "nw"){
                                        dest->setX(-1);
                                        dest->setY(1);
                                }
                                else if(command == "se"){
                                        dest->setX(1);
                                        dest->setY(-1);
                                }
                                else if(command == "sw"){
                                        dest->setX(-1);
                                        dest->setY(-1);
                                }
                                player->attack(dest->getChar());
                               	attack  = false;
                                delete temp;
                                delete dest;
			}
			if(use){
				Cell *curr = player->getPosition();
				Cell *dest = curr;
				if(command ==" no"){
					dest->setY(1);
				}
				else if(command == "so"){
					dest->setY(-1);
				}
				else if(command == "ea"){
					dest->setX(1);
				}
				else if(command == "we"){
					dest->setX(-1);
				}
				else if(command == "ne"){
					dest->setX(1);
					dest->setY(1);
				}
				else if(command == "nw"){
					dest->setX(-1);
					dest->setY(1);
				}
				else if(command == "se"){
					dest->setX(1);
					dest->setY(-1);
				}
				else if(command == "sw"){
					dest->setX(-1);
					dest->setY(-1);
				}
				Item *pickup = dest->getItem();
				player->pickUpPotion(pickup,dest);
				use = false;
				delete curr;
				delete dest;
			} else{
				player->move(command);
			}
		cout<<*g;
		}
		else if(!frozen){
			g->resetGrid();
		}
		else{
			cout << "Invalid input try again!" << endl;
			continue;
		}

	}
	cout << "Game over! Final Score: " << player->getGold() << endl;
	player->kill(player);
	delete gen;
	delete g;
	string restart;
	cout << "Press p to play again or q to quit";
	while(cin >> restart){
		if(restart == "p"){
			goto start;
		}
		else if(restart == "q"){
			return 0;
		}
		else{
			cout << "Invalid input, try again!";
		}
	}
}
