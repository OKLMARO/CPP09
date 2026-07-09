/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 12:06:19 by oamairi           #+#    #+#             */
/*   Updated: 2026/07/10 00:49:50 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <cstdlib>
#include <fstream>
#include <iostream>

class BitcoinExchange
{
private:
	std::map<std::string, double> _data;
	bool	dateChecker(std::string date);
public:
	BitcoinExchange();
	BitcoinExchange(std::string cvsFile);
	BitcoinExchange(const BitcoinExchange &obj);

	void	run(std::string input);

	BitcoinExchange	&operator=(const BitcoinExchange &obj);

	~BitcoinExchange();

	class BitcoinExchangeFileErrorException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};
