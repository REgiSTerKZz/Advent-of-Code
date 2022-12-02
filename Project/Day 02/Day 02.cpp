// GIVEN the Day 02 [Explanation](https://adventofcode.com/2022/day/2) this is the implementation by REgiSTerKZz


#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>												// I / O with Files

#include <Windows.h>	// Add color to console (Fun)


/*
* 
* TOTAL SCORE
* 
* ROCK 
*	Enemy	= A
*	You		= X
*	Points	= 1
* 
* PAPER 
*	Enemy	= B
*	You		= Y
*	Points	= 2
* 
* SCISSORS 
*	Enemy	= C
*	You		= Z
*	Points	= 3
* 
* LOST		= 0
* DRAW		= 3
* WIN		= 6
* 
*/


int totalScore = 0;

/// <summary>
/// Given a Delimiter, splits the string input into different strings
/// </summary>
std::vector<std::string> Split(const std::string& s, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}


int CalculateScore(std::string _e, std::string _m, std::string &_result) {
	int score = 0;

	if		(_m == "ROCK") score = 1;
	else if (_m == "PAPER") score = 2;
	else if (_m == "SCISSOR") score = 3;

	// Check DRAW
	if (_e == _m) {
		score += 3;
		_result = "DRAW";
		return score;
	}

	// Check WIN/LOSE
	if (_e == "ROCK") {
		if (_m == "SCISSOR") {			// LOSE
			_result = "LOSE";
			return score;
		}
		else if (_m == "PAPER") {		// WIN
			_result = "WIN";
			score += 6;
			return score;
		}
	}
	else if (_e == "PAPER") {
		if (_m == "ROCK") {				// LOSE
			_result = "LOSE";
			return score;
		}
		else if (_m == "SCISSOR") {		// WIN
			_result = "WIN";
			score += 6;
			return score;
		}
	}
	else if (_e == "SCISSOR") {
		if (_m == "PAPER") {			// LOSE
			_result = "LOSE";
			return score;
		}
		else if (_m == "ROCK") {		// WIN
			_result = "WIN";
			score += 6;
			return score;
		}
	}
}

void ConvertResult(std::string _input)
{
	if (_input == "")	return;


	std::string e = "";			// Enemy play
	std::string m = "";			// My play


	// Split the input between the Enemy and yours
	std::vector<std::string> cleanInput = Split(_input, ' ');

	if		(cleanInput[0] == "A") e = "ROCK";
	else if (cleanInput[0] == "B") e = "PAPER";
	else if (cleanInput[0] == "C") e = "SCISSOR";

	if		(cleanInput[1] == "X") m = "ROCK";
	else if (cleanInput[1] == "Y") m = "PAPER";
	else if (cleanInput[1] == "Z") m = "SCISSOR";

	std::string res;
	int score = CalculateScore(e, m, res);

	std::cout << "Enemy ->	" << e << "	---vs---   " << m << "   <- You";
	std::cout << "	Score: " << score << "	Result: " << res << "\n";
	totalScore += score;
}





void ReadFile() {
	std::string mStr;
	std::ifstream mFile;

	mFile.open("Input.txt");

	while (getline(mFile, mStr))
	{
		ConvertResult(mStr);
	}

	mFile.close();
}


int main()
{
	ReadFile();

	std::cout << "Total Score: " << totalScore << "\n\n";
}