// GIVEN the Day 02 [Explanation](https://adventofcode.com/2022/day/2) this is the implementation by REgiSTerKZz


#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>												// I / O with Files

#include <Windows.h>	// Add color to console (Fun)


enum COLOR
{
	BLUE = 1,
	GREEN = 2,
	RED = 4,
	WHITE = 7
};


int totalScore = 0;
HANDLE hConsole;

void SetColor(int _c) {
	SetConsoleTextAttribute(hConsole, _c);
}

/// <summary>
/// Given a Delimiter, splits the string input into different strings
/// </summary>


/// <summary>
/// Given a Delimiter, Splits the inputed String into diferent strings
/// </summary>
/// <param name="s">Input String</param>
/// <param name="delimiter">Delimiter</param>
/// <returns>Vector of Strings</returns>
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


int CalculateScore(std::string _e, std::string _m, std::string &_result, COLOR &_c) {
	int score = 0;

	if		(_m == "ROCK") score = 1;
	else if (_m == "PAPER") score = 2;
	else if (_m == "SCISSOR") score = 3;

	// Check DRAW
	if (_e == _m) {
		score += 3;
		_result = "DRAW";
		_c = BLUE;
		return score;
	}

	// Check WIN/LOSE
	if (_e == "ROCK") {
		if (_m == "SCISSOR") {			// LOSE
			_result = "LOSE";
			_c = RED;
			return score;
		}
		else if (_m == "PAPER") {		// WIN
			_result = "WIN";
			_c = GREEN;
			score += 6;
			return score;
		}
	}
	else if (_e == "PAPER") {
		if (_m == "ROCK") {				// LOSE
			_result = "LOSE";
			_c = RED;
			return score;
		}
		else if (_m == "SCISSOR") {		// WIN
			_result = "WIN";
			_c = GREEN;
			score += 6;
			return score;
		}
	}
	else if (_e == "SCISSOR") {
		if (_m == "PAPER") {			// LOSE
			_result = "LOSE";
			_c = RED;
			return score;
		}
		else if (_m == "ROCK") {		// WIN
			_result = "WIN";
			_c = GREEN;
			score += 6;
			return score;
		}
	}
}

int CalculateScoreTwo(std::string _m, std::string _res) {
	int score = 0;
	
	// YOU
	if		(_m == "ROCK")		score = 1;
	else if (_m == "PAPER")		score = 2;
	else if (_m == "SCISSOR")	score = 3;

	// RESULT
	if		(_res == "Y")		score += 3;			// Draw -> +3
	else if (_res == "Z")		score += 6;			// WIN  -> +6

	return score;
}


void PartOne(std::string _input)
{
	if (_input == "")	return;

	COLOR mColor = WHITE;
	SetColor(mColor);

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
	int score = CalculateScore(e, m, res, mColor);

	std::cout << "Enemy ->	" << e << "	---vs---   " << m << "   <- You";
	std::cout << "	Score: " << score << "	Result: ";
	SetColor(mColor);
	std::cout << res << "\n";
	totalScore += score;
}

void PartTwo(std::string _input) {
	std::string e = "";			// Enemy play
	std::string m = "";			// My expected play
	int expRes;					// Expected result

	// Split the input between the Enemy and yours
	std::vector<std::string> cleanInput = Split(_input, ' ');

	// Get the enemy's play
	if (cleanInput[0] == "A") e = "ROCK";
	else if (cleanInput[0] == "B") e = "PAPER";
	else if (cleanInput[0] == "C") e = "SCISSOR";

	// Get winning play depending on the enemy & expected Result


	// DRAW -> Return the same play as the enemy
	if (cleanInput[1] == "Y")
	{
		m = e;
	}

	if (e == "ROCK") {
		if		(cleanInput[1] == "X") { m = "SCISSOR"; }		// LOSE -> SCISSOR
		else if (cleanInput[1] == "Z") { m = "PAPER"; }			// WIN  -> PAPER
	}
	else if (e == "PAPER") {
		if		(cleanInput[1] == "X") { m = "ROCK"; }			// LOSE -> ROCK
		else if (cleanInput[1] == "Z") { m = "SCISSOR"; }		// WIN  -> SCISSOR
	}
	else if (e == "SCISSOR") {
		if		(cleanInput[1] == "X") { m = "PAPER"; }			// LOSE -> PAPER
		else if (cleanInput[1] == "Z") { m = "ROCK"; }			// WIN  -> ROCK
	}

	totalScore += CalculateScoreTwo(m, cleanInput[1]);
}



void ReadFile() {
	std::string mStr;
	std::ifstream mFile;

	mFile.open("Input.txt");

	while (getline(mFile, mStr))
	{
		PartTwo(mStr);
	}

	mFile.close();
}


int main()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ReadFile();

	std::cout << "Total Score: " << totalScore << "\n\n";
}