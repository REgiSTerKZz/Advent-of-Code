// GIVEN the Day 09 [Explanation](https://adventofcode.com/2022/day/9) this is the implementation by REgiSTerKZz

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>

#include <Windows.h>

int totalVisited;

std::map<int, std::pair<int, int>> tailVisitedPlaces;

int FIELD_WIDTH = 100;
int FIELD_HEIGHT = 100;

/// <summary>
/// Create 1D Index from 2D Array (X, Y)
/// </summary>
/// <param name="_x">Rows</param>
/// <param name="_xLength">Rows Length</param>
/// <param name="_y">Columns</param>
/// <returns></returns>
int Index(int _x, int _xLength, int _y)
{ return (_x * _xLength) + _y; }

std::map<char, std::pair<int, int>> mDirections = {
		{'R', { 1,  0}},
		{'L', {-1,  0}},
		{'U', { 0, -1}},
		{'D', { 0,  1}},
};

// Manhattan Distance with Pairs
int Distance(std::pair<int, int> _pos1, std::pair<int, int> _pos2) {
	return abs(_pos1.first - _pos2.first) + abs(_pos1.second - _pos2.second);
}

template <typename T, typename U>
std::pair<T, U> operator+(const std::pair<T, U>& l, const std::pair<T, U>& r) {
	return { l.first + r.first,l.second + r.second };
}

class Knot
{
public:
	std::pair<int, int> mPos;
	char mPart;

	Knot(int _x, int _y, char _mPart) {
		mPos.first = _x;
		mPos.second = _y;
		mPart= _mPart;
	}
	void Move(std::pair<int, int> _dir) {
		this->mPos = mPos + _dir;
	}

	std::pair<int, int> DirToHead(Knot* _head) {
		auto a = std::make_pair((_head->mPos.first - this->mPos.first), (_head->mPos.second - this->mPos.second));
		int l = sqrt(a.first * a.first + a.second * a.second);
		return { a.first / l, a.second / l };
	}
};

class Rope
{
	std::vector<Knot*> mRope;
	Knot* Head;
	Knot* Tail;

public:
	Rope(int _size) {
		char c;
		for (int i = 0; i < _size; i++)
		{
			if (i == 0)
				c = 'H';
			else if (i == _size - 1)
				c = 'T';
			else
				c = '0';

			mRope.push_back(new Knot(FIELD_WIDTH * 0.5, FIELD_HEIGHT * 0.5, c));
		}

		Head = mRope[0];
		Tail = mRope[_size - 1];
	}


	void Move(std::pair<int, int> _dir, int _times) {
		for (int i = 0; i < _times; i++)
		{
			// Move Head
			Head->Move(_dir);
			// Check if Tail needs to move
			if (Distance(Head->mPos, Tail->mPos) >= 2) {
				// Tail Follows
				Tail->Move(Tail->DirToHead(Head));
			}
			// Insert Movement to the map
			tailVisitedPlaces.insert(
				std::make_pair(
					Index(Tail->mPos.first, FIELD_WIDTH, Tail->mPos.second), 
					std::make_pair(
						Tail->mPos.first, 
						Tail->mPos.second)
				)
			);
		}
	}
};


std::pair<char, int> Split(const std::string& s, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	// Update the Types
	return { tokens[0][0], std::stoi(tokens[1]) };
}

void ReadFile(std::string _file) {
	std::string mString;
	std::pair<char, int> mInstruction;
	std::ifstream mFile;
	mFile.open(_file);

	while (true)
	{
		getline(mFile, mString);

		mInstruction = Split(mString, ' ');
		std::cout << "Instrucction: " << mInstruction.first << " -> " << mInstruction.second << "\n";

		if (mFile.eof()) { break; }
	}

	mFile.close();
}

int main()
{
	// Create the Rope
	Rope mRope = Rope(2);

	mRope.Move(mDirections['R'], 4);		// This should be called inside the ReadFile using the mInstruction.first and .second

	ReadFile("Test_Input.txt");


	std::cout << "myrecipe contains:" << std::endl;
	for (auto& x : tailVisitedPlaces)
	{
		std::cout << x.first << "\n";
	}
	std::cout << "";
};
