# Advent Of Code Utils:

## INDEX:
* [Custom Variables](#Custom-Variables)
* [Distances](#Distances)
* [Read Files](#Read-Files)
* [Dictionaries](#Dictionaries)
* [Iterate Arrays](#Iterate-Arrays)
* [Overload Operators](#Overload-Operators)
* [Console](#Console)

<details>
	<summary>Custom Variables</summary>

	## Custom Variables
	* **Vector 2**
	```C++
	// iPair ==> Integer Pair
	typedef pair<int, int> iPair;
	```
</details>
<details>
	<summary>Distances</summary>

## Distances

* **Euclidian:** with Pairs
```C++
// Euclidian Distance with Pairs
int Distance(std::pair<int, int> _pos1, std::pair<int, int> _pos2) {
	return sqrt(
		((_pos1.first - _pos2.first) * (_pos1.first - _pos2.first)) +
		((_pos1.second - _pos2.second) * (_pos1.second - _pos2.second))
	);
}
```
* **Manhattan:**
```C++
	// Manhattan Distance
	int Distance(int _x1, int _y1, int _x2, int _y2) {
		return abs(_x1 - _x2) + abs(_y1 - _y2);
	}
```
* **Manhattan:** with Pairs
```C++
	// Manhattan Distance with Pairs
	int Distance(std::pair<int, int> _pos1, std::pair<int, int> _pos2) {
		return abs(_pos1.first - _pos2.first) + abs(_pos1.second - _pos2.second);
	}
```

* **Create Vector from 2 Points:**
```C++
	// Vector from A to B = B - A
	std::pair<int, int> Vector(std::pair<int, int> A, std::pair<int, int> B) {
		return std::make_pair(B.first - A.first, B.second - A.second);
	}
```
* **Create Normalized Vector from 2 Points:**
```C++
// Vector from A to B = B - A normalized
std::pair <int, int> NormalizedVector(std::pair <int, int> A, std::pair <int, int> B) {
	auto vec = std::make_pair((B.first - A.first), (B.second - A.second));
	int l = sqrt(vec.first * vec.first + vec.second * vec.second);
	return { vec.first / l, vec.second / l };
}
```
</details>
<details>
	<summary>Read Files</summary>

## Read Files
* **Read File:** Single Line at a time
```C++
#include <fstream>		// File sys
#include <string>		// std::string

/// <summary>
/// Given FileName where input is, reads each line from the file.
/// </summary>
/// <param name="_file">FileName</param>
void ReadFile(std::string _file) {
	std::ifstream mFile;
	std::string mString;
	mFile.open(_file);

	while (true)
	{
		getline(mFile, mString);

		if (mFile.eof()) { break; }
	}

	mFile.close();
}
```

* **Split string:** With Splitted Strings
```C++
void ReadFile(std::string _file) {
	std::ifstream mFile;
	std::string mString;
// ===========================================================
	std::vector<std::string> mSplitedStrings;
	std::string tStr;
// ===========================================================
	mFile.open(_file);

	while (true)
	{
		getline(mFile, mString);
// ===========================================================
		while (getline(stream, tStr, ' '))
		{ mSplitedStrings.push_back(tStr); }
// ===========================================================
		if (mFile.eof()) { break; }
	}
	mFile.close();
}


```
</details>
<details>
	<summary>Dictionaries</summary>

## Dictionaries

```C++
std::map<char, std::pair<int, int>> mDirections = {
		{'R', { 1,  0}},
		{'L', {-1,  0}},
		{'U', { 0, -1}},
		{'D', { 0,  1}},
};

// mDirections['R'] => returns {1, 0} as std::pair
```
</details>
<details>
	<summary>Iterate Arrays</summary>

## Iterate Arrays

* **Create 1D Index from 2D Array (X, Y):**
```C++
int Index(int _x, int _xLength, int _y)
{
	return (_x * _xLength) + _y;
}
```

* **Create 2D Index from 1D (X, xLenght):**
```C++
std::pair < int, int> Index_1Dto2D(int i, int _xLenght) {
	return { i / _xLenght , i%_xLenght};
}
```

* **Splits the inputed String into diferent strings:**
```C++
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
```
* **Splits the inputed String into diferent types:**
```C++
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
```
</details>
<details>
	<summary>Overload Operators</summary>

## Overload Operators

* **Pair<int, int> addition (+):**

```C++
template <typename T, typename U>
std::pair<T, U> operator+(const std::pair<T, U>& l, const std::pair<T, U>& r) {
	return { l.first + r.first,l.second + r.second };
}
```
</details>
<details>
	<summary>Console</summary>

## Console

* **Init Windonws.h:**
```C++
#include <Windows.h>

HANDLE hConsole;

int main(){
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}
```

* **Set Console Color:**
```C++
enum COLOR
{
	BLUE = 1,
	GREEN = 2,
	RED = 4,
	WHITE = 7
};

// c = COLOR
void SetColor(int _c) {
	SetConsoleTextAttribute(hConsole, _c);
}
```

* **Clear Console:**
```C++
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

int main(){
	cls(hConsole);
}
```

* **Draw Array:**
```C++
void Draw2Darray(std::vector<std::vector<Cell>> _arr) {
	for (int i = 0; i < _arr.size(); i++) {
		for (int j = 0; j < _arr[0].size(); j++) {
			std::cout << _arr[i][j].height;
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}
```
</details>