// GIVEN the Day 09 [Explanation](https://adventofcode.com/2022/day/9) this is the implementation by REgiSTerKZz

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>			// std::pair<>
#include <algorithm>		// std::clamp()
#include <vector>
#include <map>
#include <Windows.h>

int totalVisited;
HANDLE hConsole;

void cls(HANDLE hConsole)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	SMALL_RECT scrollRect;
	COORD scrollTarget;
	CHAR_INFO fill;

	// Get the number of character cells in the current buffer.
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
	{
		return;
	}

	// Scroll the rectangle of the entire buffer.
	scrollRect.Left = 0;
	scrollRect.Top = 0;
	scrollRect.Right = csbi.dwSize.X;
	scrollRect.Bottom = csbi.dwSize.Y;

	// Scroll it upwards off the top of the buffer with a magnitude of the entire height.
	scrollTarget.X = 0;
	scrollTarget.Y = (SHORT)(0 - csbi.dwSize.Y);

	// Fill with empty spaces with the buffer's default text attribute.
	fill.Char.UnicodeChar = TEXT(' ');
	fill.Attributes = csbi.wAttributes;

	// Do the scroll
	ScrollConsoleScreenBuffer(hConsole, &scrollRect, NULL, scrollTarget, &fill);

	// Move the cursor to the top left corner too.
	csbi.dwCursorPosition.X = 0;
	csbi.dwCursorPosition.Y = 0;

	SetConsoleCursorPosition(hConsole, csbi.dwCursorPosition);
}

std::map<int, std::pair<int, int>> tailVisitedPlaces;

int FIELD_WIDTH  = 50;
int FIELD_HEIGHT = 50;

// Pair Addition
template <typename T, typename U>
std::pair<T, U> operator+(const std::pair<T, U>& l, const std::pair<T, U>& r) {
	return { l.first + r.first,l.second + r.second };
}

/// <summary>
/// Create 1D Index from 2D Array (X, Y)
/// </summary>
/// <param name="_x">Rows</param>
/// <param name="_xLength">Rows Length</param>
/// <param name="_y">Columns</param>
/// <returns></returns>
int Index_2Dto1D(int _x, int _xLength, int _y)
{ return (_x * _xLength) + _y; }

std::pair < int, int> Index_1Dto2D(int i, int _xLenght) {
	return { i / _xLenght , i%_xLenght};
}

std::map<char, std::pair<int, int>> mDirections = {
	{'R', { 0, 1}},
	{'L', { 0,-1}},
	{'U', {-1, 0}},
	{'D', { 1, 0}},
};

// Manhattan Distance with Pairs
int DistanceManhattan(std::pair<int, int> _pos1, std::pair<int, int> _pos2) {
	return abs(_pos1.first - _pos2.first) + abs(_pos1.second - _pos2.second);
}

// Euclidian Distance with Pairs
int Distance(std::pair<int, int> _pos1, std::pair<int, int> _pos2) {
	return sqrt(
		((_pos1.first - _pos2.first) * (_pos1.first - _pos2.first)) +
		((_pos1.second - _pos2.second) * (_pos1.second - _pos2.second))
	);
}


/// <summary>
/// Class Knot
/// </summary>
class Knot
{
public:
	std::pair<int, int> mPos;
	char mPart;

	Knot(int _x, int _y, char _mPart) {
		mPos.first = _x;
		mPos.second = _y;
		mPart = _mPart;
	}
	void Move(std::pair<int, int> _dir) {
		this->mPos = mPos + _dir;
	}
	std::pair<int, int> DirToHead(Knot* _head) {
		auto a = std::make_pair((_head->mPos.first - this->mPos.first), (_head->mPos.second - this->mPos.second));
		int l = sqrt(a.first * a.first + a.second * a.second);
		return { std::clamp(a.first, -1, 1),std::clamp(a.second, -1, 1) };
	}
};

/// <summary>
/// Class Rope
/// </summary>
class Rope
{
	std::vector<Knot*> mRope;

public:
	Knot* Head;
	Knot* Tail;

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

			mRope.push_back(new Knot(FIELD_HEIGHT *0.5, FIELD_WIDTH *0.5, c));
		}

		Head = mRope[0];
		Tail = mRope[_size - 1];
	}


	void Move(std::pair<int, int> _dir, int _times, Rope& mRope) {
		for (int i = 0; i < _times; i++)
		{
			// Move Head
			Head->Move(_dir);
			// Check if Tail needs to move
			for (int k = 1; k < mRope.Length(); k++)
			{
				if (Distance(mRope[k-1]->mPos, mRope[k]->mPos) >= 2) {
					// Tail Follows
					mRope[k]->Move(mRope[k]->DirToHead(mRope[k-1]));
				}
			}

			// Move Tail
			

			// Insert Movement to the map
			tailVisitedPlaces.insert(
				std::make_pair(
					Index_2Dto1D(Tail->mPos.first, FIELD_WIDTH, Tail->mPos.second),
					std::make_pair(
						Tail->mPos.first,
						Tail->mPos.second)
				)
			);
		}
	}

	int Length() {
		return mRope.size();
	}

	Knot *&operator [](int i) {
		return mRope[i];
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


void DrawVisited(std::map<int, std::pair<int, int>> _map, std::pair<int, int> _hPos, std::pair<int, int> _tPos, Rope &mRope) {
	int it;
	for (int i = 0; i < FIELD_HEIGHT; i++) {
		for (int j = 0; j < FIELD_WIDTH; j++) {
			// Check if exists
			it = Index_2Dto1D(i, FIELD_WIDTH, j);

			char c = (_map.find(it) != _map.end()) ? '#' : '.';

			auto a = mRope[0];
			for (int k = 0; k < mRope.Length(); k++)
			{
				auto d1 = Distance(std::make_pair(i, j), mRope[k]->mPos);
				if (d1 == 0) {
					c = k + '0';
				}
			}
			std::cout << c;
		}
		std::cout << "\n";
	}
}

void ReadFile(std::string _file, Rope &mRope) {
	std::string mString;
	std::pair<char, int> mInstruction;
	std::ifstream mFile;
	mFile.open(_file);
	int it = 0;
	while (true)
	{
		getline(mFile, mString);

		mInstruction = Split(mString, ' ');

		mRope.Move(mDirections[mInstruction.first], mInstruction.second, mRope);
		//DrawVisited(tailVisitedPlaces, mRope.Head->mPos, mRope.Tail->mPos, mRope);
		//cls(hConsole);

		if (mFile.eof()) { break; }
		it++;
	}

	mFile.close();
}

// Response: 5902
// Response: 2445
int main()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// Create the Rope
	Rope mRope = Rope(10);
	//DrawVisited(tailVisitedPlaces, mRope.Head->mPos, mRope.Tail->mPos);

	ReadFile("Input.txt", mRope);
	

	DrawVisited(tailVisitedPlaces, mRope.Head->mPos, mRope.Tail->mPos, mRope);
	std::cout << "\n Total Visited: " << tailVisitedPlaces.size();
};

