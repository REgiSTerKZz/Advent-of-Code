#pragma once
#include "Cell.h"

class Field
{
public:
	int FIELD_WIDTH, FIELD_HEIGHT;

	Cell* startCell;
	Cell* goalCell;

	std::vector<std::vector<Cell*>> mField;
	std::vector<Cell* > mPath;

	Field();
	void GenerateNeighbours();
	int BFS();

private:
	int GetPathLength();
	bool isBorder(int _pos, char c);
	std::map<int, char> mDirections = {
	{0, 'R'},
	{1, 'L'},
	{2, 'U'},
	{3, 'D'},
	};
};