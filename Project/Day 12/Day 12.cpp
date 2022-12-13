// GIVEN the Day 12 [Explanation](https://adventofcode.com/2022/day/12) this is the implementation by REgiSTerKZz


#include <iostream>
#include <fstream>
#include <string>

#include "Field.h"


void CreateField(int row, std::string _s, Field &_f) {
	// Add Row
	_f.mField.push_back(std::vector<Cell*>());
	for (int i = 0; i < _s.size(); i++)
	{
		Cell* c = new Cell(_s[i], std::make_pair(row, i));
		_f.mField[row].push_back(c);
		// Set Starting & Goal
		if (_s[i] == 'S')		{ _f.startCell = c; }
		else if (_s[i] == 'E')	{ _f.goalCell = c; }
	}
}

void Draw2Darray(std::vector<std::vector<Cell*>> _arr) {
	for (int i = 0; i < _arr.size(); i++) {
		for (int j = 0; j < _arr[0].size(); j++) {
			std::cout << _arr[i][j]->height;
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void Draw2DarrayAsChar(std::vector<std::vector<Cell*>> _arr) {
	for (int i = 0; i < _arr.size(); i++) {
		for (int j = 0; j < _arr[0].size(); j++) {
			if (_arr[i][j]->visited)
			{
				std::cout << char(_arr[i][j]->height + 97);
			}
			else
			{
				std::cout << "~";
			}
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}


void ReadFile(std::string _file, Field &mField) {
	std::ifstream mFile;
	std::string mString;
	mFile.open(_file);
	int it = 0;

	while (true)
	{
		getline(mFile, mString);

		CreateField(it, mString, mField);

		if (mFile.eof()) { break; }
		it++;
	}

	mField.GenerateNeighbours();
	//Draw2DarrayAsChar(mField.mField);

	std::cout << "Start: {" << mField.startCell->mPos.first << "}{" << mField.startCell->mPos.second << "}\n";
	std::cout << "Goal : {" << mField.goalCell->mPos.first << "}{" << mField.goalCell->mPos.second << "}\n";

	std::cout << "\nTotal Steps: " << mField.BFS() << std::endl;
	// Draw2DarrayAsChar(mField.mField);

	mFile.close();
}


// Response: 412
// Response: 
int main()
{
	Field mField = Field();
	ReadFile("Input.txt", mField);
}