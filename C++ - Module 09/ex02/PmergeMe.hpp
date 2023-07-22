#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
#include <sys/time.h>
#include <queue>

#define SZ(x) ((int)(x.size()))

std::pair<std::vector<int>, std::string> parse(char **av);

void PmergeMe(std::vector<int> &vec, bool use_multiset);

unsigned long long gettimeUS(void);