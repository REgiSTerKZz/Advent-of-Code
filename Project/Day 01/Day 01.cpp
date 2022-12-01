// GIVEN the Day 01 [Explanation](https://adventofcode.com/2022/day/1) this is the implementation by REgiSTerKZz

#include <iostream>
#include <fstream>												// I / O with Files
#include <string>

const int TOP_SIZE = 3;

/// <summary>
/// Swapps the Top 3 Elves with most Calories
/// </summary>
/// <param name="_new">New higher value</param>
/// <param name="_index">Index from where the Top needs to be updated</param>
/// <param name="_list">Int array where the Top 3 is stored</param>
void UpdateTop(int _new, int _index, int(&_list)[TOP_SIZE]) {

	for (int i = TOP_SIZE - 1; i >= _index + 1; i--)
	{
		_list[i] = _list[i - 1];
	}

	// after loop
	_list[_index] = _new;
}

/// <summary>
/// Given a Elf Calories _value, it compares with the Top Elves
/// </summary>
/// <param name="_value">Number of calories for the current Elf</param>
/// <param name="_list">Current Top List for the most carrying calories Elves</param>
void CompareTop(int _value, int(&_list)[TOP_SIZE]) {
	int index = -1;
	for (int i = TOP_SIZE - 1; i >= 0; i--)						// Iterate backwards. If the "_value" is not bigger than the small of the TOP, no need ot keep iterating.
	{
		if (_value > _list[i])
		{ index = i; }
	}
	if (index >= 0) 
	{ UpdateTop(_value, index, _list); }
}


/// <summary>
/// Reads the Input from the ..\Resources and saves the data
/// </summary>
void ReadInput(int(&_list)[TOP_SIZE]) {
	std::string mFileString;
	std::ifstream mFile;
	int sum = 0;


	mFile.open("Input.txt");

	while (getline(mFile, mFileString)) {
		// Try to parse the String to int

		if (mFileString != "") {								// Add Calorioes to the Number
			sum += std::stoi(mFileString);
		}
		else													// Save the number if bigger
		{
			CompareTop(sum, _list);
			sum = 0;
		}
	}
	CompareTop(sum, _list);

	mFile.close();												// Closes the file in case we want to use it again.
}

int main()
{
	int top[TOP_SIZE] = { 0,0,0 };
	ReadInput(top);


	std::cout << "========= Top" << TOP_SIZE << " Elves: =========" << "\n";
	for (int i = 0; i < TOP_SIZE; i++)
	{
		std::cout << "  TOP " << i << ":	------	" << top[i] << "\n";
	}

	std::cout << "   ||		------	  ||" << "\n";
	std::cout << "  Calories:	------	" << top[0] + top[1] + top[2] << "\n";
	std::cout << "===============================" << "\n";
}