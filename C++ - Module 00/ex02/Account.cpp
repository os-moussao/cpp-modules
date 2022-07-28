#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

std::string two_digit_nbr(int x) {
	std::string ret;
	ret.resize(2);
	ret[0] = (x/10) + '0';
	ret[1] = (x%10) + '0';
	return ret;
}

void Account::_displayTimestamp() {
    time_t     linux_time = time(0);
    struct tm  *tm = localtime(&linux_time);
    std::cout << "[" << tm->tm_year + 1900 << two_digit_nbr(tm->tm_mon) << \
	two_digit_nbr(tm->tm_mday) << "_" << two_digit_nbr(tm->tm_hour) << \
	two_digit_nbr(tm->tm_min) << two_digit_nbr(tm->tm_sec) << "] ";
}

Account::Account(void) {
	_accountIndex = Account::_nbAccounts++;
	_amount = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << "created\n";
}

Account::Account(int init) {
	_accountIndex = Account::_nbAccounts++;
	_amount = init;
	Account::_totalAmount += init;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account() {
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

void Account::displayAccountsInfos() {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:" \
	<< Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << '\n';
}

int	Account::getNbAccounts( void ) {
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void ) {
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return Account::_totalNbWithdrawals;
}

void Account::makeDeposit( int deposit ) {
	_amount += deposit;
	Account::_totalAmount += deposit;
	_nbDeposits++;
	Account::_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << \
	_amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << \
	";nb_deposits:" << _nbDeposits << '\n';
}

bool Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (withdrawal > _amount) {
		std::cout << "refused\n";
		return false;
	}
	_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << '\n';
	return true;
}

int Account::checkAmount( void ) const {
	return _amount;
}

void Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	// index:0;amount:42;deposits:0;withdrawals:0
	std::cout << "index:" << _accountIndex << ";amount:" << \
	_amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << '\n';
}
