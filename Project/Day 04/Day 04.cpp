// GIVEN the Day 04 [Explanation](https://adventofcode.com/2022/day/4) this is the implementation by REgiSTerKZz

/*
* PART 1
*	GIVEN A String
*	Get the pairs of elves
*	Get the numbers between the 2 diits in each sector	-> (2-4,6-8) -> (2,3,4	&	6,7,8)
*	Check if any of the pair is inside one another (If min > min2 & max < max2)
*	Add the total of pairs that are completely inside one another
*/




#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>												// I / O with Files

void PartOne(std::string _input) {
	std::cout << _input << "\n"; // --------------------------------
	std::vector<std::string> pairs = { "","" };

	// Split by commas
	pairs[0] = _input.substr(0, _input.find(','));
	pairs[1] = _input.substr(_input.find(',')+1);		// +1 since we don't want the "comma"

	return;
}

void ReadFile(std::string _file) {
	std::string mStr;
	std::ifstream mFile;

	mFile.open(_file);

	// PART ONE
	while (true)
	{
		getline(mFile, mStr);

		PartOne(mStr);

		if (mFile.eof()) { break; }
	}

	mFile.close();
}

int main()
{
	ReadFile("Test_Input.txt");
}
