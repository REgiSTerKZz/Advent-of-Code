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
*	y -
*	^
*	|
*	|
*	|
*	# -----> x +
*/
int GetTree(int _x, int _y) {
	return mForest[_y][_x];
}

// =========================================================
bool CheckLeft(int _tree, int _x, int _y) {
	if (_x <= 0)
	{ return _tree > GetTree(0, _y); }

	int currTree = GetTree(_x, _y);

	if (currTree < GetTree(_x - 1, _y) || currTree >= _tree) {
		return false;
	}
	return CheckLeft(_tree, _x - 1, _y);
}

bool CheckRight(int _tree, int _x, int _y) {
	if (_x >= FOREST_WIDTH - 1)
	{ return _tree > GetTree(FOREST_WIDTH-1, _y); }

	int currTree = GetTree(_x, _y);

	if (currTree < GetTree(_x + 1, _y) || currTree >= _tree) {
		return false;
	}
	return CheckRight(_tree, _x + 1, _y);
}

bool CheckTop(int _tree, int _x, int _y) {
	if (_y <= 0)
	{ return _tree > GetTree(_x, 0); }

	int currTree = GetTree(_x, _y);

	if (currTree < GetTree(_x, _y-1) || currTree >= _tree) {
		return false;
	}
	return CheckTop(_tree, _x, _y-1);
}

bool CheckBot(int _tree, int _x, int _y) {
	if (_y >= FOREST_HEIGHT - 1)
	{ return _tree > GetTree(_x, FOREST_HEIGHT-1); }

	int currTree = GetTree(_x, _y);

	if (currTree < GetTree(_x, _y + 1) || currTree >= _tree) {
		return false;
	}
	return CheckBot(_tree, _x, _y + 1);
}
// =========================================================
bool CheckIfVisible(int _x, int _y) {
	bool left, right, top, bot;
	std::cout << "\nChecking Tree{" << _x << "},{" << _y << "}: height("<< GetTree(_x, _y)<<"):	";

	int currTree = GetTree(_x, _y);
	if (_x == 0 || _x >= FOREST_WIDTH-1)
	{
		std::cout << "Visible (Edge)";
		return true;
	}
	if (_y == 0 || _y >= FOREST_HEIGHT-1)
	{ 
		std::cout << "Visible (Edge)";
		return true;
	}

	left = CheckLeft(currTree, _x - 1, _y);
	if (left)
	{
		std::cout << "LEFT Visible";
		return true;
	}
	std::cout << "!LEFT -> ";

	right = CheckRight(currTree, _x + 1, _y);
	if (right)
	{
		std::cout << "RIGHT Visible";
		return true;
	}
	std::cout << "!RIGHT -> ";

	top = CheckTop(currTree, _x, _y - 1);
	if (top)
	{
		std::cout << "TOP Visible";
		return true;
	}
	std::cout << "!TOP -> ";

	bot = CheckBot(currTree, _x, _y + 1);
	if (bot)
	{
		std::cout << "BOTTOM Visible";
		return true;
	}
	std::cout << "!BOTTOM";

	return false;
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
	int total = 0;
	ReadFile("Input.txt");
	FOREST_HEIGHT = mForest.size();
	FOREST_WIDTH = mForest[0].size();

	for (int x = 0; x < FOREST_WIDTH; x++)
	{
		for (int y = 0; y < FOREST_HEIGHT; y++)
		{
			total += CheckIfVisible(x, y);
		}
	}
	std::cout << "\n\nTotal Visible Trees: " << total << "\n";
}