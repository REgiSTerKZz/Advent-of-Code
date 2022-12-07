// GIVEN the Day 05 [Explanation](https://adventofcode.com/2022/day/5) this is the implementation by REgiSTerKZz

/*
* PART 1
*/


#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>												// I / O with Files

int totalSum = 0;
std::vector<std::stack<char>> mStacks;



std::vector<std::stack<char>> MySetup(std::vector<std::string> _input) {
	// We need to start creating the Stacks from the bottom (Second to last) -> _setup.size() - 2 
	int numOfStacks = _input[_input.size() - 1][_input[_input.size() - 1].find(_input[_input.size() - 1][_input[_input.size() - 1].size() - 2])] - '0';

	std::vector<std::stack<char>> _mStacks(numOfStacks);

	// Init Stacks
	for (int i = 0; i < numOfStacks; i++)
	{
		// Iterate the stacks
		for (int j = _input.size()-2; j >= 0; j--)
		{	// it = (i * 4) + 1
			if (_input[j][(i * 4) + 1] == 32)
			{ break; }
			_mStacks[i].push(_input[j][(i * 4) + 1]);
		}
	}
	return _mStacks;
}

// Result: TLFGBZHCN
void PartOne(std::istringstream _input) {
	// Separate the first move
	std::vector<std::string> mSplitedString;
	std::string t;

	while (getline(_input, t, ' '))
	{ mSplitedString.push_back(t); }

	// MOVE mSplitedString[1]		FROM mSplitedString[3		TO	mSplitedString[5]

	// elemToSwap = mStacks[std::stoi(mSplitedString[3]) - 1].top();

	for (int i = 0; i < std::stoi(mSplitedString[1]); i++)
	{
		// Swap
		mStacks[std::stoi(mSplitedString[5]) - 1].push(mStacks[std::stoi(mSplitedString[3]) - 1].top());
		mStacks[std::stoi(mSplitedString[3]) - 1].pop();
	}
}

void ReadFile(std::string _file) {
	std::vector<std::string> mStringVector;
	std::string mString;
	std::ifstream mFile;
	auto setup = false;
	auto i = 0;

	mFile.open(_file);

	// Get Stacks
	// PART ONE
	while (true)
	{
		mStringVector.push_back("");
		getline(mFile, mStringVector[i]);

		if (mStringVector[i] == "") 
		{ 
			mStringVector.pop_back();
			break; 
		}
		i++;
	}
	mStacks = MySetup(mStringVector);

	// Read the Movements
	while (true)
	{
		getline(mFile, mString);

		PartOne(std::istringstream(mString));

		if (mFile.eof()) { break; }
	}


	mFile.close();
}

int main()
{
	ReadFile("Input.txt");

	std::cout << "Final Crates on Top: ";
	for (int i = 0; i < mStacks.size(); i++)
	{
		std::cout << mStacks[i].top();
	}
	std::cout << "\n\n";

}