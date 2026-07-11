/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 22:21:05 by oamairi           #+#    #+#             */
/*   Updated: 2026/07/12 01:42:58 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	PmergeMe::suiteJacobsthal(int n)
{
	if (n == 0 || n == 1)
		return n;
	else
		return (suiteJacobsthal(n - 1) + 2 * suiteJacobsthal(n - 2));
}

void	PmergeMe::fordJohnsonVec(std::vector<int> &ctn)
{
	if (ctn.size() <= 1)
		return;
	int									i = 0;
	std::vector<std::pair<int, int>>	paire;
	int									impaire = INT_MIN;
	while (i + 1 < ctn.size())
	{
		if (ctn.at(i) > ctn.at(i + 1))
			paire.push_back(std::make_pair(ctn.at(i), ctn.at(i + 1)));
		else
			paire.push_back(std::make_pair(ctn.at(i + 1), ctn.at(i)));
		i = i + 2;
		if (i < ctn.size())
			impaire = ctn.at(i);
	}
	std::vector<int>	first;
	for (size_t i = 0; i < paire.size(); i++)
		first.push_back(paire.at(i).first);
	fordJohnsonVec(first);
}

PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	_dataList = obj._dataList;
	_dataVector = obj._dataVector;
}

bool	PmergeMe::run(char **av)
{
	int i = 0;
	while (av && av[i])
	{
		int j = 0;
		while (av[i][j])
		{
			if (!isdigit(av[i][j]))
				return false;
			j++;
		}
		if (std::atoll(av[i]) > INT_MAX)
			return false;
		_dataList.push_back(std::atoi(av[i]));
		_dataVector.push_back(std::atoi(av[i]));
		i++;
	}
	if (av[i] && !av[i][0])
		return false;
	std::cout << "Before:";
	for (size_t i = 0; i < _dataVector.size(); i++)
		std::cout << " " << _dataVector.at(i);
	return true;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &obj)
{
	if (this != &obj)
	{
		_dataList = obj._dataList;
		_dataVector = obj._dataVector;
	}
	return *this;
}

PmergeMe::~PmergeMe() {};
