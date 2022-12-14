// GIVEN the Day 12 [Explanation](https://adventofcode.com/2022/day/12) this is the implementation by REgiSTerKZz


#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

#include "Field.h"

HANDLE hConsole;
enum COLOR
{
	BLUE = 1,
	GREEN = 2,
	RED = 4,
	WHITE = 7,
	START = 237,
	END = 170
};

// c = COLOR
void SetColor(int _c) {
	SetConsoleTextAttribute(hConsole, _c);
}

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

void Draw2DarrayAsChar(Field &mField) {
	//SetColor(WHITE);
	for (int i = 0; i < mField.mField.size(); i++) {
		for (int j = 0; j < mField.mField[0].size(); j++) {

			std::vector<Cell*>::iterator it;
			it = std::find(mField.mPath.begin(), mField.mPath.end(), mField.mField[i][j]);

			if (it != mField.mPath.end())
			{ SetColor(GREEN); }
			else
			{ SetColor(WHITE); }

			if (mField.mField[i][j]->c == 'S')
			{
				SetColor(START);
			}
			else if (mField.mField[i][j]->c == 'E')
			{
				SetColor(END);
			}
			char d = (mField.mField[i][j]->visited) ? mField.mField[i][j]->c : '~';
			std::cout << d;
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}


int Part2(Field &mField) {
	int minPath = 100000000;

	for (int i = 0; i < mField.mField.size(); i++)
	{
		minPath = min(minPath, mField.BFS(mField.mField[i][0]));
	}
	return minPath;
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

	// std::cout << "\nTotal Steps: " << mField.BFS(mField.startCell) << std::endl;
	std::cout << "\nTotal Steps: " << Part2(mField) << std::endl;

	

	Draw2DarrayAsChar(mField);

	mFile.close();
}

// Response: 412
// Response: 402 Resposne 401 + 1 since the first A cell is not beeing added
int main()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Field mField = Field();
	ReadFile("Input.txt", mField);
}