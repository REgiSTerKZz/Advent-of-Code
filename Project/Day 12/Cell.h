#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <list>

class Cell
{
public:
	int height;
	char c;
	bool visited = false;
	Cell* cameFrom;

	std::pair<int, int> mPos;
	std::map<char, Cell*> mNeighbours;	// key is either 'U' -> Up , 'D' -> Down ...


	Cell();
	Cell(char c, std::pair<int, int> _pos);
	void AddNeighbour(char dir, Cell* compareTo);
	bool operator== (const Cell& B) const;
	bool operator!= (const Cell& B) const;

private:
	void UpdateHeight(char c);
};
