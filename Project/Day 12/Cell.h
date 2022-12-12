#pragma once
#include <iostream>
#include <vector>
#include <map>

class Cell
{
public:
	int height;
	std::pair<int, int> mPos;
	std::map<char, Cell> mNeighbours;	// key is either 'U' -> Up , 'D' -> Down ...

	Cell();
	Cell(char c, std::pair<int, int> _pos);
	void AddNeighbour(char dir, Cell compareTo);

private:
	void UpdateHeight(char c);
};
