/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 22:21:05 by oamairi           #+#    #+#             */
/*   Updated: 2026/07/13 00:47:58 by oamairi          ###   ########.fr       */
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

void	PmergeMe::dichotomie(std::vector<int> &vec, int n)
{
	int	min = 0;
	int	max = vec.size();

	while (min < max)
	{
		int	mid = (max - min) / 2;
		if (vec.at(mid) < n)
			min = mid + 1;
		else
			max = mid;
	}
	vec.insert(vec.begin() + min, n);
}

void	PmergeMe::fordJohnsonVec(std::vector<std::pair<int, int>> &ctn)
{
	if (ctn.size() <= 1)
		return;
	int									i = 0;
	std::vector<std::pair<int, int>>	paire;
	int									impaire = INT_MIN;
	while (i + 1 < ctn.size())
	{
		if (ctn.at(i).first > ctn.at(i + 1).first)
			paire.push_back(ctn.at(i));
		else
			paire.push_back(ctn.at(i + 1));
		i = i + 2;
	}
	if (i < ctn.size())
		impaire = ctn.at(i).first;
	fordJohnsonVec(paire);
	std::vector<int> result;
	result.push_back(paire.at(0).second);
	result.push_back(paire.at(0).first);
	for (size_t i = 0; i < paire.size(); i++)
	{
		PmergeMe::dichotomie(result, paire.at(i).first);
		PmergeMe::dichotomie(result, paire.at(i).second);
	}
	if (impaire != INT_MIN)
		PmergeMe::dichotomie(result, impaire);
	ctn.clear();
	for (size_t i = 0; i < result.size(); i++)
		ctn.push_back(std::make_pair(result.at(i), 0));
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
	std::vector<std::pair<int, int>>	vec;
	for (size_t i = 2; i < _dataVector.at(i); i++)
		vec.push_back(std::make_pair(_dataVector))
	clock_t startvec = clock();
	
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
