// GIVEN the Day 07 [Explanation](https://adventofcode.com/2022/day/7) this is the implementation by REgiSTerKZz

/*
*	Create a Tree (Root is called /)
*/

#include <sstream>
#include <fstream>												// I / O with Files

#include "FileSystem.h"

void PartOne(std::vector<std::string> _input) {
	FileSystem mFS = FileSystem();
	
	if (_input[0] == "$")
	{	// Command to execute
	}

	mFS.LS();
}


void ReadFile(std::string _file) {
	std::string mString;
	std::ifstream mFile;

	std::vector<std::string> mSplitedStrings;
	std::string tStr;

	mFile.open(_file);

	while (true)
	{
		//Read the Movements
		getline(mFile, mString);
		std::istringstream stream = std::istringstream(mString);

		while (getline(stream, tStr, ' '))
		{ mSplitedStrings.push_back(tStr); }


		PartOne(mSplitedStrings);

		if (mFile.eof()) { break; }
	}

	mFile.close();
}

int main()
{
	ReadFile("Test_Input.txt");
}