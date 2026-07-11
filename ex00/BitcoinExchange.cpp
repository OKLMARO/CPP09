/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 12:06:26 by oamairi           #+#    #+#             */
/*   Updated: 2026/07/11 13:35:22 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	BitcoinExchange::dateChecker(std::string line)
{
	int	mois[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for (size_t i = 0; i < 4; i++)
	{
		if (!isdigit(line[i]))
			return false;
	}
	if (line[4] != '-')
		return false;
	if ((std::atoi(line.substr(0, 4).c_str()) % 4 == 0 && std::atoi(line.substr(0, 4).c_str()) % 100 != 0) || std::atoi(line.substr(0, 4).c_str()) % 400 == 0)
		mois[1] = 29;
	for (size_t i = 5; i < 7; i++)
	{
		if (!isdigit(line[i]))
			return false;
	}
	if (std::atoi(line.substr(5, 2).c_str()) > 12 || std::atoi(line.substr(5, 2).c_str()) < 1)
		return false;
	if (line[7] != '-')
		return false;
	for (size_t i = 8; i < 10; i++)
	{
		if (!isdigit(line[i]))
			return false;
	}
	if (std::atoi(line.substr(8, 2).c_str()) > mois[std::atoi(line.substr(5, 2).c_str()) - 1] || std::atoi(line.substr(8, 2).c_str()) < 1)
		return false;
	return true;
}

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
		else if (line.find('|') == std::string::npos || line.find('|') != 11 || !dateChecker(line))
		{
			std::cerr << "Error: bad input => " << line << "\n";
			continue;
		}
		else if (_data.find(line.substr(0, line.find('|') - 1)) == _data.end())
		{
			std::map<std::string, double>::iterator it = _data.upper_bound(line.substr(0, line.find('|') - 1));
			if (it != _data.begin())
			{
				bool isnombre = true;
				bool virgule = false;
				bool negatif = false;
				if (!line[line.find('|') + 2])
				{
					isnombre = false;
					std::cerr << "Error: bad input => " << line << "\n";
				}
				for (size_t i = line.find('|') + 2; i < line.size(); i++)
				{
					if (!virgule && line[i] == '.')
						virgule = true;
					else if (line[i] == '-' && !negatif && i == line.find('|') + 2)
						negatif = true;
					else if (!isdigit(line[i]))
					{
						isnombre = false;
						std::cerr << "Error: bad input => " << line << "\n";
						break;
					}
				}
				if (isnombre)
				{
					it--;
					if (std::atof(line.substr(line.find('|') + 2, line.size()).c_str()) < 0)
						std::cerr << "Error: not a positive number.\n";
					else if (std::atof(line.substr(line.find('|') + 2, line.size()).c_str()) > 1000)
						std::cerr << "Error: too large a number.\n";
					else
						std::cout << line.substr(0, line.find('|') - 1) << " => " << line.substr(line.find('|') + 2, line.size()) << " = " << it->second * std::atof(line.substr(line.find('|') + 2, line.size()).c_str()) << "\n";
				}
			}
			else
				std::cerr << "Error: bad input => " << line << "\n";
		}
		else
		{
			bool isnombre = true;
			bool virgule = false;
			bool negatif = false;
			if (!line[line.find('|') + 2])
			{
				isnombre = false;
				std::cerr << "Error: bad input => " << line << "\n";
			}
			for (size_t i = line.find('|') + 2; i < line.size(); i++)
			{
				if (!virgule && line[i] == '.')
					virgule = true;
				else if (line[i] == '-' && !negatif && i == line.find('|') + 2)
					negatif = true;
				else if (!isdigit(line[i]))
				{
					isnombre = false;
					std::cerr << "Error: bad input => " << line << "\n";
					break;
				}
			}
			if (isnombre )
			{
				if (std::atof(line.substr(line.find('|') + 2, line.size()).c_str()) < 0)
					std::cerr << "Error: not a positive number.\n";
				else if (std::atof(line.substr(line.find('|') + 2, line.size()).c_str()) > 1000)
					std::cerr << "Error: too large a number.\n";
				else
				{
					std::cout << line.substr(0, line.find('|') - 1) << " => " << line.substr(line.find('|') + 2, line.size()) << " = " << _data[line.substr(0, line.find('|') - 1)] * std::atof(line.substr(line.find('|') + 2, line.size()).c_str()) << "\n";
				}
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
	return "Error: could not open file.";
}
