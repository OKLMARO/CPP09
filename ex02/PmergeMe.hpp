/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 22:21:07 by oamairi           #+#    #+#             */
/*   Updated: 2026/07/14 16:25:04 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <ctime>
#include <vector>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <sys/time.h>

class PmergeMe
{
private:
	std::deque<int>		_dataDeque;
	std::vector<int>	_dataVector;

	int	suiteJacobsthal(int n);

	std::vector<int>					buildJacobOrderVec(size_t size);
	std::vector<int>					fordJohnsonVec(std::vector<int> grands);
	void								dichotomieVec(std::vector<int> &vec, int n);

	std::deque<int>						buildJacobOrderDeque(size_t size);
	std::deque<int>						fordJohnsonDeque(std::deque<int> grands);
	void								dichotomieDeque(std::deque<int> &deque, int n);
public:
	PmergeMe();
	PmergeMe(const PmergeMe &obj);

	bool	run(char **av);

	PmergeMe	&operator=(const PmergeMe &obj);

	~PmergeMe();
};
