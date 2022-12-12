#pragma once
#include "Cell.h"

class Field
{
public:
	int FIELD_WIDTH, FIELD_HEIGHT;

	Cell currentCell;
	Cell goalCell;

	std::vector<std::vector<Cell>> mField;

	Field();
	std::map<char, Cell> GetNeighbours(Cell _c);
	void GenerateNeighbours();

private:
	bool isBorder(int _pos, char c);
};