#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include "cell.h"
#include "generate.h"
#include "chamber.h"
#include "door.h"
#include "passageway.h"
#include "stairway.h"
#include "tile.h"
#include "wall.h"

class Generate;
class Cell;
class Chamber;
class Grid{
	int level = 0;
	Generate *gen;

	public:
	Player *p; // This is the user
	Grid();
	int gridHeight = 25;
        int gridWidth = 79;
	void generateGrid();
	void move(Cell *moveTo);
	Cell * getCell(Cell *dest);
	std::vector<std::vector< Cell *>> theGrid;
	std::vector<Chamber *> chamber;
	void gridInit(std::ifstream &file);
	void resetGrid();
	void regenerateGrid();
	void emptyCell(Cell *pos);
	int getLevel();
	~Grid();

};
std::ostream &operator<<(std::ostream &out, Grid &g);

#endif
