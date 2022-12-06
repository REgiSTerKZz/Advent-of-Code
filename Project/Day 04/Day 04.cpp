// GIVEN the Day 04 [Explanation](https://adventofcode.com/2022/day/4) this is the implementation by REgiSTerKZz

/*
* PART 1
*	GIVEN A String
*	Get the pairs of elves
*	Get the numbers between the 2 diits in each sector	-> (2-4,6-8) -> (2,3,4	&	6,7,8)
*	Check if any of the pair is inside one another (If min > min2 & max < max2)
*	Add the total of pairs that are completely inside one another
* 
* PART 2
*	Same as PART 1
*	But only calculate the Overlapping ones
*/




#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>												// I / O with Files

int totalSum = 0;

/// Result: 464
void PartOne(std::string _input) {
	std::vector<std::string> pairs = { "","" };
	std::vector<int> intPairs(4);

	// Split by commas
	pairs[0] = _input.substr(0, _input.find(','));
	pairs[1] = _input.substr(_input.find(',')+1);		// +1 since we don't want the "comma"

	// Split by dash
	intPairs[0] = std::stoi(pairs[0].substr(0, pairs[0].find('-')));
	intPairs[1] = std::stoi(pairs[0].substr(pairs[0].find('-') + 1));

	intPairs[2] = std::stoi(pairs[1].substr(0, pairs[1].find('-')));
	intPairs[3] = std::stoi(pairs[1].substr(pairs[1].find('-') + 1));


	// Get rid of the one that don't even collide
	if (intPairs[1] < intPairs[2] || intPairs[3] < intPairs[0])
	{ return; }

	// Check the ones with same number
	if (intPairs[0] == intPairs[1] || intPairs[2] == intPairs[3]) {
		if		(intPairs[0] >= intPairs[2] && intPairs[0] <= intPairs[3])	{ totalSum++; std::cout << _input <<"	Inside! \n"; return; }
		else if (intPairs[2] >= intPairs[0] && intPairs[2] <= intPairs[1])	{ totalSum++; std::cout << _input << "	Inside! \n"; return; }
	}

	// Check the rest
		// If 1 is inside 2 || 2 is inside 1
	if ((intPairs[0] >= intPairs[2] && intPairs[1] <= intPairs[3]) || (intPairs[2] >= intPairs[0] && intPairs[3] <= intPairs[1]))
	{
		totalSum++; 
		std::cout << _input << "	Inside! \n";
		return;
	}
}

/// Result: 770
void PartTwo(std::string _input) {
	std::vector<std::string> pairs = { "","" };
	std::vector<int> intPairs(4);

	// Split by commas
	pairs[0] = _input.substr(0, _input.find(','));
	pairs[1] = _input.substr(_input.find(',') + 1);		// +1 since we don't want the "comma"

	// Split by dash
	intPairs[0] = std::stoi(pairs[0].substr(0, pairs[0].find('-')));
	intPairs[1] = std::stoi(pairs[0].substr(pairs[0].find('-') + 1));

	intPairs[2] = std::stoi(pairs[1].substr(0, pairs[1].find('-')));
	intPairs[3] = std::stoi(pairs[1].substr(pairs[1].find('-') + 1));


	// Get rid of the one that don't even collide
	if (intPairs[1] < intPairs[2] || intPairs[3] < intPairs[0]) { return; }

	totalSum++;
	std::cout << _input << "Overlap! \n";
}

void ReadFile(std::string _file) {
	std::string mStr;
	std::ifstream mFile;

	mFile.open(_file);

	// PART ONE
	while (true)
	{
		getline(mFile, mStr);

		PartTwo(mStr);

		if (mFile.eof()) { break; }
	}

	mFile.close();
}

int main()
{
	ReadFile("Input.txt");
	std::cout << "Total Sum: " << totalSum << "\n";

}
