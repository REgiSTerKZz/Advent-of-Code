// GIVEN the Day 03 [Explanation](https://adventofcode.com/2022/day/3) this is the implementation by REgiSTerKZz


#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>												// I / O with Files



void ReadFile(std::string _file) {
	std::string mStr;
	std::ifstream mFile;

	mFile.open(_file);

	while (getline(mFile, mStr))
	{
		// Call process function here
	}

	mFile.close();
}

int main()
{
	ReadFile("Test_Input.txt");
}
