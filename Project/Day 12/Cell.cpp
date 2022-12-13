#include "Cell.h"

Cell::Cell()
{
}

Cell::Cell(char c, std::pair<int, int> _pos)
{
	UpdateHeight(c);
	this->c = c;
	mPos = _pos;
}

void Cell::UpdateHeight(char c)
{
	if (c == 'S')		{ c = 'a'; }
	else if (c == 'E')	{ c = 'z'; }
	
	this->height = int(c) - 97;
}

void Cell::AddNeighbour(char dir, Cell* compareTo)
{
	// If lower, no fall dmg
	if (this->height > compareTo->height)
	{ 
		mNeighbours.insert(std::make_pair(dir, compareTo));
		return;
	}
	if (abs(this->height - compareTo->height) < 2)
	{ mNeighbours.insert(std::make_pair(dir, compareTo)); }
}

bool Cell::operator==(const Cell& B) const
{
	return this->mPos == B.mPos;
}

bool Cell::operator!=(const Cell& B) const
{
	return this->mPos != B.mPos;
}
