/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 22:21:05 by oamairi           #+#    #+#             */
/*   Updated: 2026/07/14 13:39:21 by oamairi          ###   ########.fr       */
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

std::vector<int> PmergeMe::buildJacobOrder(size_t size)
{
	std::vector<int> order;
	size_t n = 2;
	while ((size_t)suiteJacobsthal(n) < size)
	{
		int curr = suiteJacobsthal(n);
		int prev = suiteJacobsthal(n - 1);
		for (int j = curr - 1; j >= prev; j--)
		{
			if (j < (int)size)
				order.push_back(j);
		}
		n++;
	}
	size_t j = suiteJacobsthal(n - 1);
	while (j < size)
	{
		order.push_back(j);
		j++;
	}
	return order;
}

std::vector<std::pair<int, int> > PmergeMe::makePair(std::vector<int> &grands)
{
	size_t i = 0;
	std::vector<std::pair<int, int> > vecPair;

	while (i + 1 < grands.size())
	{
		vecPair.push_back(std::make_pair(grands[i], grands[i + 1]));
		i += 2;
	}
	if (grands.size() % 2 == 1)
		vecPair.push_back(std::make_pair(grands[grands.size() - 1], -1));

	return vecPair;
}

void PmergeMe::doGreatPair(std::vector<std::pair<int, int> > &vecPair)
{
	for (size_t i = 0; i < vecPair.size(); i++)
	{
		if (vecPair[i].second != -1 && vecPair[i].first > vecPair[i].second)
			std::swap(vecPair[i].first, vecPair[i].second);
	}
}

std::vector<int> PmergeMe::lowPair(std::vector<std::pair<int, int> > &vecPair)
{
	std::vector<int> small;
	for (size_t i = 0; i < vecPair.size(); i++)
		small.push_back(vecPair[i].first);
	return small;
}

std::vector<int> PmergeMe::highPair(std::vector<std::pair<int, int> > &vecPair)
{
	std::vector<int> pair;
	for (size_t i = 0; i < vecPair.size(); i++)
		pair.push_back(vecPair[i].second);
	return pair;
}

void PmergeMe::dichotomieVec(std::vector<int> &vec, int n, size_t bound)
{
	int low = 0;
	int high = static_cast<int>(bound);

	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (vec.at(mid) < n)
			low = mid + 1;
		else
			high = mid;
	}
	vec.insert(vec.begin() + low, n);
}

std::vector<int> PmergeMe::fordJohnsonVec(std::vector<int> grands)
{
	if (grands.size() <= 1)
		return grands;

	std::vector<std::pair<int, int> > vecPair = makePair(grands);
	doGreatPair(vecPair);

	std::vector<int> small = lowPair(vecPair);
	std::vector<int> higherPair = highPair(vecPair);

	bool hasOdd = (higherPair.back() == -1 && grands.size() % 2 == 1);
	if (hasOdd)
		higherPair.pop_back();

	std::vector<int> originalHigherPair = higherPair;
	higherPair = fordJohnsonVec(higherPair);

	std::vector<int> newSmall;
	for (size_t i = 0; i < higherPair.size(); i++)
	{
		for (size_t j = 0; j < originalHigherPair.size(); j++)
		{
			if (originalHigherPair[j] == higherPair[i])
			{
				newSmall.push_back(small[j]);
				break;
			}
		}
	}
	small = newSmall;

	if (!small.empty())
		higherPair.insert(higherPair.begin(), small[0]);

	std::vector<int> sortedHigherPair(higherPair.begin() + (small.empty() ? 0 : 1), higherPair.end());
	std::vector<int> order = buildJacobOrder(small.size());

	for (size_t i = 0; i < order.size(); i++)
	{
		if ((size_t)order[i] >= small.size() || order[i] == 0)
			continue;
		size_t position = std::find(higherPair.begin(), higherPair.end(),
										sortedHigherPair[order[i] - 1]) - higherPair.begin();
		dichotomieVec(higherPair, small[order[i]], position + 1);
	}

	if (hasOdd)
		dichotomieVec(higherPair, grands.back(), higherPair.size());

	return higherPair;
}

PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	_dataList = obj._dataList;
	_dataVector = obj._dataVector;
}

bool	PmergeMe::run(char **av)
{
	int i = 1;
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
	std::cout << "\n";
	std::vector<std::pair<int, int> >	vec;
	for (size_t i = 0; i + 1 < _dataVector.size(); i = i + 2)
	{
		if (_dataVector.at(i) > _dataVector.at(i + 1))
			vec.push_back(std::make_pair(_dataVector.at(i), _dataVector.at(i + 1)));
		else
			vec.push_back(std::make_pair(_dataVector.at(i + 1), _dataVector.at(i)));
	}
	clock_t startvec = clock();
	_dataVector = fordJohnsonVec(_dataVector);
	clock_t endvec = clock();
	std::cout << "After:";
	for (size_t i = 0; i < _dataVector.size(); i++)
		std::cout << " " << _dataVector.at(i);
	std::cout << "\n";
	std::cout << "Time to process a range of " << _dataVector.size() << " elements with std::vector : " << endvec - startvec << "\n";
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
