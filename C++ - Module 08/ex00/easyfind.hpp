#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template <class T>
int easyfind(const T &cont, int n) {
	int pos = std::find(cont.begin(), cont.end(), n) - cont.begin();
	return pos==(int)cont.size()? -1: pos;
}