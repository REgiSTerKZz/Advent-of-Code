#include "Cell.h"

Cell::Cell()
{
}

Cell::Cell(char c, std::pair<int, int> _pos)
{
	UpdateHeight(c);
	mPos = _pos;
}

void Cell::UpdateHeight(char c)
{
	if (c == 'S')		{ c = 'a'; }
	else if (c == 'E')	{ c = 'z'; }
	
	this->height = int(c) - 97;
}

void Cell::AddNeighbour(char dir, Cell compareTo)
{
	if (abs(this->height - compareTo.height) <= 1)
	{ mNeighbours.insert(std::make_pair(dir, compareTo)); }
}
