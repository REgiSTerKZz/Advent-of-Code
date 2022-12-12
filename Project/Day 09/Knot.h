#include <iostream>			// std::pair<>
#include <algorithm>		// std::clamp()
#include <vector>
#include <map>

#pragma once

// Pair Addition
template <typename T, typename U>
std::pair<T, U> operator+(const std::pair<T, U>& l, const std::pair<T, U>& r) {
	return { l.first + r.first,l.second + r.second };
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
