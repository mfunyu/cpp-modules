// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   Account.cpp                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/10/14 01:41:56 by mfunyu            #+#    #+#             */
// /*   Updated: 2021/10/14 01:47:59 by mfunyu           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>

#include "Account.hpp"

// int		Account::getNbAccounts( void ) {
// 	return _nbAccounts;
// }

// int		Account::getTotalAmount( void ) {
// 	return _totalAmount;
// }

// int		Account::getNbDeposits( void ) {
// 	return _totalNbDeposits;
// }

// int		Account::getNbWithdrawals( void ) {
// 	return _totalNbWithdrawals;
// }

Account::Account(void) {
}

void	Account::_displayTimestamp( void ) {
	std::time_t	epoch = std::time(nullptr);
	std::cout << "[" << std::put_time(std::localtime(&epoch), "%Y%m%d-%H%M%S") << "] ";
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	// std::cout << "accounts:" << getNbAccounts() << ";";
	// std::cout << "total:" << getTotalAmount() << ";";
	// std::cout << "deposits:" << getNbDeposits() << ";";
	// std::cout << "withdrawals:" << getNbWithdrawals() << ";";
	std::cout << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	int	p_amount = _amount;
	_amount += deposit;
	_nbDeposits += 1;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << ";";
	std::cout << std::endl;
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
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawal:" << _nbWithdrawals << ";";
	std::cout << std::endl;
	return true;
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposit:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << ";";
	std::cout << std::endl;
}

Account::Account( int initial_deposit ) : _amount(initial_deposit){
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
