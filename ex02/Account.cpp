/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 01:41:56 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/22 15:10:09 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>

#include "Account.hpp"

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

int		Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int		Account::getTotalAmount( void ) {
	return _totalAmount;
}

int		Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int		Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void	Account::_displayTimestamp( void ) {
	std::time_t	epoch = std::time(nullptr);
	std::cout << "[" << std::put_time(std::localtime(&epoch), "%Y%m%d-%H%M%S") << "] ";
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();

	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	int	p_amount = _amount;
	_amount += deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	_totalAmount += deposit;

	_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	int	p_amount = _amount;

	_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";

	if (_amount < withdrawal) {
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}

	_amount -= withdrawal;
	_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	_totalAmount -= withdrawal;

	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int		Account::checkAmount( void ) const {
	return _amount;
};

void	Account::displayStatus( void ) const {
	_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

Account::Account(void) {
	return ;
}

Account::Account( int initial_deposit ) : _accountIndex(getNbAccounts())
										, _amount(initial_deposit)
										, _nbDeposits(0)
										, _nbWithdrawals(0)
{
	_nbAccounts += 1;
	_totalAmount += initial_deposit;

	_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;

	return;
}

Account::~Account( void ) {
	_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;

	return;
}
