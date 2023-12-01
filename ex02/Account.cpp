// ************************************************************************** //
//                                                                            //
//                Account.cpp for GlobalBanksters United                      //
//                Created on  : Thu Nov 30 15:57:31 2023                      //
//                Last update : Fri Dec 01 10:08:10 2023                      //
//                Made by : larmenou <la@gbu.com>                             //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <string>
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = getNbAccounts();
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout 	<< "index:" << this->_accountIndex
				<< ";amount:" << this->_amount 
				<< ";created" << std::endl;
	return ;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout 	<< "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";closed" << std::endl;
	return ;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::makeDeposit( int deposit )
{
	int tmp;

	tmp = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;

	_totalNbDeposits++;
	_totalAmount += deposit;

	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";p_amount:" << tmp
				<< ";deposit:" << deposit
				<< ";amount:" << this->_amount
				<< ";nb_deposits:" << this->_nbDeposits
				<< std::endl;
}

int		Account::checkAmount( void ) const
{
	if (this->_amount > 0)
		return (1);
	return (0);
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int	tmp;

	tmp = this->_amount;
	this->_amount -= withdrawal;
	_displayTimestamp();
	if (checkAmount())
	{
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout	<< "index:" << this->_accountIndex
					<< ";p_amount:" << tmp
					<< ";withdrawal:" << withdrawal
					<< ";amount:" << this->_amount
					<< ";nb_withdrawals:" << this->_nbWithdrawals
					<< std::endl;
		return (true);
	}
	this->_amount = tmp;
	std::cout	<< "index:" << this->_accountIndex
				<< ";p_amount:" << tmp
				<< ";withdrawal:refused"
				<< std::endl;
	return (false);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout 	<< "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals()
				<< std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout 	<< "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals
				<< std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t timestamp;
	std::tm *timeinfo;

	timestamp = std::time(nullptr);
	timeinfo = std::localtime(&timestamp);
	std::cout	<< "[" 
				<< timeinfo->tm_year + 1900
				<< timeinfo->tm_mon + 1
				<< timeinfo->tm_mday
				<< "_"
				<< timeinfo->tm_hour
				<< timeinfo->tm_min
				<< timeinfo->tm_sec
				<< "] ";
}
