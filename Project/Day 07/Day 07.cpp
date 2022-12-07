// GIVEN the Day 07[Explanation](https://adventofcode.com/2022/day/7) this is the implementation by REgiSTerKZz

#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>												// I / O with Files

void PartOne(std::string _input) {

}

void ReadFile(std::string _file) {
	std::string mString;
	std::ifstream mFile;

	mFile.open(_file);

	while (true)
	{
		//Read the Movements
		getline(mFile, mString);

		PartOne(mString);

		if (mFile.eof()) { break; }
	}

	mFile.close();
}

int main()
{
	std::cout << "Hello World!\n";
}