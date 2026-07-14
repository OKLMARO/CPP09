/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 22:21:07 by oamairi           #+#    #+#             */
/*   Updated: 2026/07/14 13:37:00 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <list>
#include <ctime>
#include <vector>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <algorithm>

class PmergeMe
{
private:
	std::list<int>		_dataList;
	std::vector<int>	_dataVector;

	int					suiteJacobsthal(int n);
	std::vector<int>	buildJacobOrder(size_t size);

	std::vector<std::pair<int, int> >	makePair(std::vector<int> &grands);
	std::vector<int>					lowPair(std::vector<std::pair<int, int> > &vecPair);
	std::vector<int>					highPair(std::vector<std::pair<int, int> > &vecPair);
	void								doGreatPair(std::vector<std::pair<int, int> > &vecPair);

	std::vector<int>	fordJohnsonVec(std::vector<int> grands);
	void				dichotomieVec(std::vector<int> &vec, int n, size_t bound);
public:
	PmergeMe();
	PmergeMe(const PmergeMe &obj);

	bool	run(char **av);

	PmergeMe	&operator=(const PmergeMe &obj);

	~PmergeMe();
};
