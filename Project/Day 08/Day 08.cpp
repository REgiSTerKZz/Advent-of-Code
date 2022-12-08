// GIVEN the Day 08 [Explanation](https://adventofcode.com/2022/day/8) this is the implementation by REgiSTerKZz

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

std::vector<std::vector<int>> mForest;
int FOREST_HEIGHT, FOREST_WIDTH;

/*
* Forest
*	y +
*	^
*	|
*	|
*	|
*	# -----> x +
*/
int GetTree(int _x, int _y) {
	return mForest[_y][_x];
}

bool CheckIfVisible(int _x, int _y) {
	int currTree = GetTree(_x, _y);


	if (_x == 0 || _x == FOREST_WIDTH)  { return true; }
	if (_y == 0 || _x == FOREST_HEIGHT) { return true; }

	return CheckIfVisible(_x - 1, _y) || CheckIfVisible(_x + 1, _y) || CheckIfVisible(_x, _y - 1) || CheckIfVisible(_x, _y + 1);


	/*

	// CENTER SIDE 
	if (_x == FOREST_WIDTH / 2)
	{
		std::cout << "Center SIDE\n";
		return CheckIfVisible(_x - 1, _y) || CheckIfVisible(_x + 1, _y);


	}
	// LEFT
	else if (_x <= FOREST_WIDTH / 2) {
		std::cout << "LEFT: ";

		if (_x == 0) {					// If Left Tree is non-existen	->	return true
			std::cout << "	true\n";
			return true;
		}

		if (GetTree(_x - 1, _y) >= GetTree(_x, _y))		// If Left Tree is taller		->	return false
		{
			return false;
		}
		else											// If Left Tree is smaller		->	check Left Tree
		{
			return CheckIfVisible(_x - 1, _y);
		}
	}
	// RIGHT
	else
	{
		std::cout << "RIGHT: ";

		if (_x == 0) {					// If Left Tree is outmost tree	->	return true
			std::cout << "	true\n";
			return true;
		}

		if (GetTree(_x + 1, _y) >= GetTree(_x, _y))		// If Left Tree is taller		->	return false
		{
			return false;
		}
		else											// If Left Tree is smaller		->	check Left Tree
		{
			return CheckIfVisible(_x + 1, _y);
		}
	}


	// CENTER SIDE 
	if (_y == FOREST_HEIGHT / 2)
	{
		std::cout << "Center HEIGHT\n";
	}
	// TOP
	else if (_y <= FOREST_HEIGHT / 2)
	{
		std::cout << "TOP\n";
	}
	// BOTTOM
	else
	{
		std::cout << "BOTTOM\n";

	}

	return 1;

	*/
}

void CreateForest(int _col, std::string _row) {

	mForest.push_back(std::vector<int>());
	for (int i = 0; i < _row.size(); i++)
	{
		mForest[_col].push_back(_row[i] - '0');
	}
}

void ReadFile(std::string _file) {
	std::string mString;
	std::ifstream mFile;
	int it = 0;
	mFile.open(_file);

	while (true)
	{
		//Read the Movements
		getline(mFile, mString);

		CreateForest(it, mString);

		if (mFile.eof()) { break; }

		it++;
	}

	mFile.close();
}

int main()
{
	ReadFile("Test_Input.txt");
	FOREST_HEIGHT = mForest.size();
	FOREST_WIDTH = mForest[0].size();

	CheckIfVisible(3, 1);
}