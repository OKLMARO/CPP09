/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 22:21:07 by oamairi           #+#    #+#             */
/*   Updated: 2026/07/13 00:39:07 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <list>
#include <ctime>
#include <vector>
#include <climits>
#include <cstdlib>
#include <iostream>

class PmergeMe
{
private:
	std::list<int>		_dataList;
	std::vector<int>	_dataVector;

	int		suiteJacobsthal(int n);
	void	dichotomie(std::vector<int> &vec, int n);
	void	fordJohnsonVec(std::vector<std::pair<int, int>> &ctn);
public:
	PmergeMe();
	PmergeMe(const PmergeMe &obj);

	bool	run(char **av);

	PmergeMe	&operator=(const PmergeMe &obj);

	~PmergeMe();
};
