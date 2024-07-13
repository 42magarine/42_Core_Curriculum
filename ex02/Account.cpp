/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:52:33 by mott              #+#    #+#             */
/*   Updated: 2024/07/13 14:20:16 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit) {
	_accountIndex = Account::getNbAccounts();
	_nbAccounts++;
	_totalAmount += _amount;
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "created" << std::endl;
}

Account::~Account() {
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "closed" << std::endl;
}

int	Account::getNbAccounts() {
	return _nbAccounts;
}

int	Account::getTotalAmount() {
	return _totalAmount;
}

int	Account::getNbDeposits() {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos() {

}

void	Account::makeDeposit(int deposit) {
	_amount += deposit;
	_nbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_amount -= withdrawal;
	_nbWithdrawals++;
	return true;
}

int	Account::checkAmount() const {
	return 0;
}

void	Account::displayStatus() const {

}
