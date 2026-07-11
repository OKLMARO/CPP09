/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 22:21:07 by oamairi           #+#    #+#             */
/*   Updated: 2026/07/12 01:15:52 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <list>
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
	void	fordJohnsonVec(std::vector<int> &ctn);
public:
	PmergeMe();
	PmergeMe(const PmergeMe &obj);

	bool	run(char **av);

	PmergeMe	&operator=(const PmergeMe &obj);

	~PmergeMe();
};
