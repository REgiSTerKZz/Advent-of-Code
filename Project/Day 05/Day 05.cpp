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


void MySetup(std::vector<std::string> _s) {
	// We need to start creating the Stacks from the bottom (Second to last) -> _setup.size() - 2 
	int numOfStacks = _s[_s.size() - 1][_s[_s.size() - 1].find(_s[_s.size() - 1][_s[_s.size() - 1].size() - 2])] - '0';

	// Init Stacks
	for (size_t i = 0; i <= numOfStacks; i++)
	{
	}

	return;
}

void PartOne(std::string _input) {

}

void ReadFile(std::string _file) {
	std::vector<std::string> mStr;
	std::ifstream mFile;
	auto setup = false;

	mFile.open(_file);

	// Get Stacks
	


	int i = 0;
	// PART ONE
	while (true)
	{
		mStr.push_back("");
		getline(mFile, mStr[i]);

		if (mStr[i] == "") 
		{ 
			mStr.pop_back();
			break; 
		}
		i++;
	}

	MySetup(mStr);


	mFile.close();
}

int main()
{
	ReadFile("Test_Input.txt");
	std::cout << "Total Sum: " << totalSum << "\n";

}