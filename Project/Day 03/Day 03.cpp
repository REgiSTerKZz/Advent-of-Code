// GIVEN the Day 03 [Explanation](https://adventofcode.com/2022/day/3) this is the implementation by REgiSTerKZz

/*
* PART 1
*	Given a String
*	Divide the string in half	(the string is always even in length)
*	Check now the char in both half-strings that is the same
*	Once found, check it's value depending on the conditions -> (lowercase 1 - 26, uppercase 27 - 52)
*	Add them all
* 
* PART 2
*	GIVEN group of 3 Strings
*	Check what char have all 3 in common
*	Once found, check it's value depending on the conditions -> (lowercase 1 - 26, uppercase 27 - 52)
*	Add them all
*/


#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>												// I / O with Files

int totalScore;
int count = 0;

int CalculateScore(char _c) {
	int s = 0;

	// Calculate ASCII Value
	int v = int(_c);

	// Lowercase
	if (v >= 97) {
		s = v - 96;
	}
	// Uppercase
	else if (v >= 65) {
		s = v - 65 + 27;
	}

	std::cout << "Count: " << count << "	ASCII value: " << s << "\n";
	count++;
	if (count == 75) {
		return s;
	}
	return s;
}


void PartOne(std::string _input) {
	std::vector<std::string> halfs = {"",""};
	bool found = false;
	char c = NULL;
	int it = 0;

	// Split the input
	halfs[0] = _input.substr(0, (_input.size() / 2));
	halfs[1] = _input.substr(_input.size() / 2);

	// Find the char in common
	while (!found)
	{
		size_t pos = halfs[0].find(halfs[1][it]);

		if (pos!=std::string::npos) {
			c = halfs[0][pos];
			found = true;
		}
		if (it >= halfs[1].size()-1) {
			found = true;
		}
		it++;
	}

	// Calculate Score
	totalScore += CalculateScore(c);
}

void PartTwo(std::vector<std::string> _input) {
	bool found = false;
	char c = NULL;
	int it = 0;
	int i1, i2, i3;
	size_t sSize;

	// Get smallest string size
	sSize = std::min(std::min(_input[0].size(), _input[1].size()), _input[2].size());
	
	// Get smallest string
	if (_input[0].size() == sSize)		// If _input 0 is smallest
	{
		i1 = 0;
		i2 = 1;
		i3 = 2;
	}
	else if (_input[1].size() == sSize)	// If _input 1 is smallest
	{
		i1 = 1;
		i2 = 0;
		i3 = 2;
	}
	else								// If _input 2 is smallest
	{
		i1 = 2;
		i2 = 1;
		i3 = 0;
	}



	// Find the char in common
	while (!found)
	{
		size_t pos1 = _input[i2].find(_input[i1][it]);
		size_t pos2 = _input[i3].find(_input[i1][it]);

		if (pos1 != std::string::npos && pos2 != std::string::npos) {
			c = _input[i2][pos1];
			found = true;
		}

		if (it >= sSize-1)	{ found = true; }
		it++;
	}

	// Calculate Score
	totalScore += CalculateScore(c);
}

void ReadFile(std::string _file) {
	std::string mStr;
	std::ifstream mFile;

	std::vector<std::string> mGroup = {"","",""};

	mFile.open(_file);

	// PART ONE
	/*
	while (getline(mFile, mStr))
	{
		PartOne(mStr);
	}
	*/

	// PART TWO
	while (true)
	{
		getline(mFile, mGroup[0]);
		getline(mFile, mGroup[1]);
		getline(mFile, mGroup[2]);

		PartTwo(mGroup);

		if (mFile.eof()) { break; }
	}

	mFile.close();
}

int main()
{
	totalScore = 0;
	ReadFile("Input.txt");

	std::cout << "Total Score: " << totalScore << "\n";
}
