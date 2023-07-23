#include "BitcoinExchange.hpp"

std::map<std::string, double> btcPrices;

std::string head(std::ifstream &file) {
    std::string hd;
    std::getline(file, hd);
    return hd;
}

bool isLeap(int year) {
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

bool validDate(std::string &date) {
    // valid date example: 2012-01-11
    
    if (date.size() != DATE_SZ)
        return false;

    for (int i = 0; i < DATE_SZ; i++) {
        if (i != 4 && i != 7) {
            if (!isdigit(date[i]))
                return false;
        } else if (date[i] != '-') {
            return false;
        }
    }

    int yr, mth, day;
    yr = std::stoi(date.substr(0, 4));
    mth = std::stoi(date.substr(5, 2));
    day = std::stoi(date.substr(8, 2));

    // this part bellow is inspired by https://www.geeksforgeeks.org/program-check-date-valid-not/
    if (yr < MN_YR || yr > MX_YR || mth < 1 || mth > 12 || day < 1 || day > 31)
        return false;

    if (mth == 2 && (day > 29 || (!isLeap(yr) && day > 28)))
        return false;
    
    if ((mth == 4 || mth == 6 || mth == 9 || mth == 11) && day > 30)
        return false;

    return true;
}

double convert(std::string &date, double amt) {
    std::map<std::string, double>::iterator it = btcPrices.lower_bound(date);
    
    // all dates in database are lower than the given date
    if (it == btcPrices.end())
        return amt * btcPrices.rbegin()->second;
    
    // date exists or all dates in database are higher than the given date
    if (it->first == date || it == btcPrices.begin())
        return amt * it->second;
    
    // a date lesser than the given one exists
    return amt * (--it)->second;
}

std::string handle(std::stringstream &query, std::string &squery) {
    std::string date, delim, amount, rest;
    
    if (!(query >> date) || !(query >> delim) || !(query >> amount) || (query >> rest)) {
        return "Error: bad query => " + squery;
    }

    if (!validDate(date)) {
        return "Error: invalid date => " + date;
    }

    if (delim != "|") {
        return "Error: bad query => " + squery;
    }

    size_t idx;
    double amt = std::stod(amount, &idx);

    if (idx != amount.size() || amt > 1000. || amt < 0.) {
        return "Error: invalid amount => " + amount;
    }

    return date + " => " + amount + " = " + std::to_string(convert(date, amt));
}

void loadDatabase(void) {
    std::ifstream database("data.csv");
    std::string keyVal;

    // ignore header
    std::getline(database, keyVal);

    // parse
    while (getline(database, keyVal)) {
        std::string key = keyVal.substr(0, DATE_SZ);
        std::string val = keyVal.substr(DATE_SZ + 1);
        btcPrices[key] = stod(val);
    }
}