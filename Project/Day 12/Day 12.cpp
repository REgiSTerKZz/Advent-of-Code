// GIVEN the Day 12 [Explanation](https://adventofcode.com/2022/day/12) this is the implementation by REgiSTerKZz


#include <iostream>
#include <fstream>
#include <string>

#include "Field.h"


void CreateField(int row, std::string _s, Field &_f) {
	// Add Row
	_f.mField.push_back(std::vector<Cell>());
	for (int i = 0; i < _s.size(); i++)
	{
		Cell c = Cell(_s[i], std::make_pair(row, i));
		_f.mField[row].push_back(c);
		// Set Starting & Goal
		if (_s[i] == 'S')		{ _f.currentCell = c; }
		else if (_s[i] == 'E')	{ _f.goalCell = c; }
	}
}

void Draw2Darray(std::vector<std::vector<Cell>> _arr) {
	for (int i = 0; i < _arr.size(); i++) {
		for (int j = 0; j < _arr[0].size(); j++) {
			std::cout << _arr[i][j].height;
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void Draw2DarrayAsChar(std::vector<std::vector<Cell>> _arr) {
	for (int i = 0; i < _arr.size(); i++) {
		for (int j = 0; j < _arr[0].size(); j++) {
			std::cout << char(_arr[i][j].height + 97);
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
	Draw2Darray(mField.mField);
	std::cout << "----------------------\n";
	Draw2DarrayAsChar(mField.mField);

	mFile.close();
}



int main()
{
	Field mField = Field();
	ReadFile("Test_Input.txt", mField);
}