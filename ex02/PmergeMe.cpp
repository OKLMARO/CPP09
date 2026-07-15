/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 22:21:05 by oamairi           #+#    #+#             */
/*   Updated: 2026/07/15 12:26:07 by oamairi          ###   ########.fr       */
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

std::vector<int>	PmergeMe::buildJacobOrderVec(size_t size)
{
	size_t				n = 2;
	std::vector<int>	ordre;

	while ((size_t) suiteJacobsthal(n) < size)
	{
		int curr = suiteJacobsthal(n);
		int prev = suiteJacobsthal(n - 1);
		for (int j = curr - 1; j >= prev; j--)
		{
			if (j < (int)size)
				ordre.push_back(j);
		}
		n++;
	}

	size_t j = suiteJacobsthal(n - 1);

	while (j < size)
	{
		ordre.push_back(j);
		j++;
	}

	return ordre;
}

void	PmergeMe::dichotomieVec(std::vector<int> &vec, int n)
{
	int min = 0;
	int max = vec.size();

	while (min < max)
	{
		int mid = min + (max - min) / 2;
		if (vec.at(mid) < n)
			min = mid + 1;
		else
			max = mid;
	}
	vec.insert(vec.begin() + min, n);
}

std::vector<int> PmergeMe::fordJohnsonVec(std::vector<int> ctn)
{
	if (ctn.size() <= 1)
		return ctn;

	size_t								i = 0;
	std::vector<std::pair<int, int> >	paire;
	int									impaire = INT_MIN;

	while (i + 1 < ctn.size())
	{
		paire.push_back(std::make_pair(ctn.at(i), ctn.at(i + 1)));
		i += 2;
	}

	if (ctn.size() % 2 == 1)
		impaire = ctn.at(ctn.size() - 1);

	for (size_t i = 0; i < paire.size(); i++)
	{
		if (paire.at(i).first < paire.at(i).second)
			std::swap(paire.at(i).first, paire.at(i).second);
	}

	std::vector<int> grand;
	for (size_t i = 0; i < paire.size(); i++)
		grand.push_back(paire.at(i).first);
	std::vector<int> petit;
	for (size_t i = 0; i < paire.size(); i++)
		petit.push_back(paire.at(i).second);

	std::vector<int> grandCopie = grand;
	grand = fordJohnsonVec(grand);

	std::vector<int> petitCopie;
	for (size_t i = 0; i < grand.size(); i++)
	{
		for (size_t j = 0; j < grandCopie.size(); j++)
		{
			if (grandCopie.at(j) == grand.at(i))
			{
				petitCopie.push_back(petit.at(j));
				break;
			}
		}
	}

	petit = petitCopie;

	if (!petit.empty())
		grand.insert(grand.begin(), petit.at(0));

	std::vector<int> ordre = buildJacobOrderVec(petit.size());

	for (size_t i = 0; i < ordre.size(); i++)
	{
		if ((size_t) ordre.at(i) >= petit.size() || ordre.at(i) == 0)
			continue;
		dichotomieVec(grand, petit.at(ordre.at(i)));
	}

	if (impaire != INT_MIN)
		dichotomieVec(grand, impaire);

	return grand;
}

std::deque<int> PmergeMe::buildJacobOrderDeque(size_t size)
{
	size_t			n = 2;
	std::deque<int>	ordre;

	while ((size_t)suiteJacobsthal(n) < size)
	{
		int curr = suiteJacobsthal(n);
		int prev = suiteJacobsthal(n - 1);
		for (int j = curr - 1; j >= prev; j--)
		{
			if (j < (int)size)
				ordre.push_back(j);
		}
		n++;
	}

	size_t j = suiteJacobsthal(n - 1);

	while (j < size)
	{
		ordre.push_back(j);
		j++;
	}

	return ordre;
}

void PmergeMe::dichotomieDeque(std::deque<int> &deque, int n)
{
	int	min = 0;
	int	max = deque.size();

	while (min < max)
	{
		int mid = min + (max - min) / 2;
		if (deque.at(mid) < n)
			min = mid + 1;
		else
			max = mid;
	}
	deque.insert(deque.begin() + min, n);
}

std::deque<int> PmergeMe::fordJohnsonDeque(std::deque<int> ctn)
{
	if (ctn.size() <= 1)
		return ctn;

	size_t								i = 0;
	std::deque<std::pair<int, int> >	paire;
	int									impaire = INT_MIN;

	while (i + 1 < ctn.size())
	{
		paire.push_back(std::make_pair(ctn.at(i), ctn.at(i + 1)));
		i += 2;
	}

	if (ctn.size() % 2 == 1)
		impaire = ctn.at(ctn.size() - 1);

	for (size_t i = 0; i < paire.size(); i++)
	{
		if (paire.at(i).first < paire.at(i).second)
			std::swap(paire.at(i).first, paire.at(i).second);
	}

	std::deque<int> grand;
	for (size_t i = 0; i < paire.size(); i++)
		grand.push_back(paire.at(i).first);
	std::deque<int> petit;
	for (size_t i = 0; i < paire.size(); i++)
		petit.push_back(paire.at(i).second);

	std::deque<int> grandCopie = grand;
	grand = fordJohnsonDeque(grand);

	std::deque<int> petitCopie;
	for (size_t i = 0; i < grand.size(); i++)
	{
		for (size_t j = 0; j < grandCopie.size(); j++)
		{
			if (grandCopie.at(j) == grand.at(i))
			{
				petitCopie.push_back(petit.at(j));
				break;
			}
		}
	}

	petit = petitCopie;

	if (!petit.empty())
		grand.insert(grand.begin(), petit.at(0));

	std::deque<int> ordre = buildJacobOrderDeque(petit.size());

	for (size_t i = 0; i < ordre.size(); i++)
	{
		if ((size_t) ordre.at(i) >= petit.size() || ordre.at(i) == 0)
			continue;
		dichotomieDeque(grand, petit.at(ordre.at(i)));
	}

	if (impaire != INT_MIN)
		dichotomieDeque(grand, impaire);

	return grand;
}

PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	_dataDeque = obj._dataDeque;
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
		_dataDeque.push_back(std::atoi(av[i]));
		_dataVector.push_back(std::atoi(av[i]));
		i++;
	}
	if (av[i] && !av[i][0])
		return false;
	std::cout << "Before:";
	for (size_t i = 0; i < _dataVector.size(); i++)
		std::cout << " " << _dataVector.at(i);
	std::cout << "\n";
	struct timeval startvec, endvec;
	gettimeofday(&startvec, NULL);
	_dataVector = fordJohnsonVec(_dataVector);
	gettimeofday(&endvec, NULL);
	long microseconds = (endvec.tv_sec - startvec.tv_sec) * 1000000L + (endvec.tv_usec - startvec.tv_usec);
	std::cout << "After:";
	for (size_t i = 0; i < _dataVector.size(); i++)
		std::cout << " " << _dataVector.at(i);
	std::cout << "\n";
	std::cout << "Time to process a range of " << _dataVector.size() << " elements with std::vector : " << microseconds << " us\n";
	struct timeval startdeque, endeque;
	gettimeofday(&startdeque, NULL);
	_dataDeque = fordJohnsonDeque(_dataDeque);
	gettimeofday(&endeque, NULL);
	microseconds = (endeque.tv_sec - startdeque.tv_sec) * 1000000L + (endeque.tv_usec - startdeque.tv_usec);
	/*std::cout << "After:";
	for (size_t i = 0; i < _dataDeque.size(); i++)
		std::cout << " " << _dataDeque.at(i);
	std::cout << "\n";*/
	std::cout << "Time to process a range of " << _dataDeque.size() << " elements with std::deque : " << microseconds << " us\n";
	return true;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &obj)
{
	if (this != &obj)
	{
		_dataDeque = obj._dataDeque;
		_dataVector = obj._dataVector;
	}
	return *this;
}

PmergeMe::~PmergeMe() {};
