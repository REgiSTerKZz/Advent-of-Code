// GIVEN the Day 03 [Explanation](https://adventofcode.com/2022/day/3) this is the implementation by REgiSTerKZz

/*
*	Given a String
*	Divide the string in half	(the string is always even in length)
*	Check now the char in both half-strings that is the same
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
	auto subs = 0;

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

void ReadFile(std::string _file) {
	std::string mStr;
	std::ifstream mFile;

	mFile.open(_file);

	while (getline(mFile, mStr))
	{
		PartOne(mStr);
	}

	mFile.close();
}

int main()
{
	totalScore = 0;
	ReadFile("Input.txt");

	std::cout << "Total Score: " << totalScore << "\n";
}
