// GIVEN the Day 06 [Explanation](https://adventofcode.com/2022/day/6) this is the implementation by REgiSTerKZz

#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>												// I / O with Files

int charsNeeded = 0;
int DISTINT_CHARS = 14;
std::vector<std::stack<char>> mStacks;

bool CheckMarker(std::string _input) {
	std::string temp = _input;

	for (int i = 0; i < DISTINT_CHARS; i++)
	{
		// TEMP
		temp = _input;
		temp.erase(i, 1);

		// FIND
		int n = temp.find(_input[i]);

		if (temp.find(_input[i]) != std::string::npos) {
			return false;
		}
	}
	return true;
}

// Result: 1198
int PartOne(std::string _input) {
	int it = DISTINT_CHARS-1;

	while (true)
	{
		std::string checkVec;
		for (int i = it; i > (it - DISTINT_CHARS); i--)
		{ 
			checkVec.push_back(_input[(it - i) + (it-(DISTINT_CHARS-1))]);
		}

		if (CheckMarker(checkVec)) {
			return it+1;
		}
		it++;
		if (it >= _input.size()) { return -1; }
	}
	return 0;
}

// Result: 3120
// Part 2 is simply change the DISTINT_CHARS from 4 to 14

void ReadFile(std::string _file) {
	std::string mString;
	std::ifstream mFile;

	mFile.open(_file);

	// Read the Movements
	getline(mFile, mString);

	charsNeeded = PartOne(mString);

	mFile.close();
}

int main()
{
	ReadFile("Input.txt");

	std::cout << "Chars needed: " << charsNeeded << "\n\n";
}