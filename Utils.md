# Advent Of Code Utils:

## INDEX:
1. [Read Files](#Read-Files)
2. [Distances](#Distances)
3. [Dictionaries](#Dictionaries)
4. [Other](#Other)


## Read Files
* **Read File:** Single Line at a time
```C++
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

## Other

* **Create 1D Index from 2D Array (X, Y):**
```C++
/// <summary>
/// Create 1D Index from 2D Array (X, Y)
/// </summary>
/// <param name="_x">Rows</param>
/// <param name="_xLength">Rows Length</param>
/// <param name="_y">Columns</param>
/// <returns></returns>
int Index(int _x, int _xLength, int _y)
{
	return (_x * _xLength) + _y;
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

## Distances

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

## Overload Operators

* **Pair<int, int> addition (+):**

```C++
template <typename T, typename U>
std::pair<T, U> operator+(const std::pair<T, U>& l, const std::pair<T, U>& r) {
	return { l.first + r.first,l.second + r.second };
}
```