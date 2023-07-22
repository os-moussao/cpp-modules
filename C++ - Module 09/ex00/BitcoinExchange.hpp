#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>

#define OPEN_ERR "Error: could not open file.\n"

const int MN_YR = 2009; // birth of bitcoin
const int MX_YR = 2023;
const int DATE_SZ = 10;

extern std::map<std::string, double> btcPrices;

void loadDatabase(void);

std::string head(std::ifstream &file);
std::string handle(std::stringstream &query, std::string &squery);