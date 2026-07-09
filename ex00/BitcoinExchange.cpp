/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 12:06:26 by oamairi           #+#    #+#             */
/*   Updated: 2026/07/09 16:32:06 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream file("data.csv");
	if (!file)
		throw BitcoinExchange::BitcoinExchangeFileErrorException();
	std::string line;
	while (std::getline(file, line))
	{
		if (line =="date,exchange_rate")
			continue;
		_data[line.substr(0, line.find(','))] = std::atof(line.substr(line.find(',') + 1, line.size()).c_str());
	}
}

BitcoinExchange::BitcoinExchange(std::string csvFile)
{
	std::ifstream file(csvFile.c_str());
	if (!file)
		throw BitcoinExchange::BitcoinExchangeFileErrorException();
	std::string line;
	while (std::getline(file, line))
	{
		if (line =="date,exchange_rate")
			continue;
		_data[line.substr(0, line.find(','))] = std::atof(line.substr(line.find(',') + 1, line.size()).c_str());
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) : _data(obj._data) {};

void	BitcoinExchange::run(std::string input)
{
	std::ifstream file(input.c_str());
	if (!file)
		throw BitcoinExchange::BitcoinExchangeFileErrorException();
	std::string line;
	while (std::getline(file, line))
	{
		if (line =="date | value")
			continue;
		else if (line.find('|') == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << "\n";
			continue;
		}
		else if (_data.find(line.substr(0, line.find('|') - 1)) == _data.end())
		{
			std::map<std::string, double>::iterator it = _data.upper_bound(line.substr(0, line.find('|') - 1));
			if (it != _data.begin())
			{
				it--;
				if (std::atof(line.substr(line.find('|') + 2, line.size()).c_str()) < 0)
					std::cerr << "Error: not a positive number.\n";
				else if (std::atof(line.substr(line.find('|') + 2, line.size()).c_str()) > 1000)
					std::cerr << "Error: too large a number.\n";
				else
					std::cout << it->first << " => " << it->second << " = " << it->second * std::atof(line.substr(line.find('|') + 2, line.size()).c_str()) << "\n";
			}
			else
			{
				std::cerr << "Error: bad input => " << line << "\n";
			}
		}
		else
		{
			if (std::atof(line.substr(line.find('|') + 2, line.size()).c_str()) < 0)
				std::cerr << "Error: not a positive number.\n";
			else if (std::atof(line.substr(line.find('|') + 2, line.size()).c_str()) > 1000)
				std::cerr << "Error: too large a number.\n";
			else
			{
				std::cout << line.substr(0, line.find('|') - 1) << " => " << _data[line.substr(0, line.find('|') - 1)] << " = " << _data[line.substr(0, line.find('|') - 1)] * std::atof(line.substr(line.find('|') + 2, line.size()).c_str()) << "\n";
			}
		}
	}
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this != &obj)
	{
		_data = obj._data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {};

const char	*BitcoinExchange::BitcoinExchangeFileErrorException::what() const throw()
{
	return "File not open";
}
