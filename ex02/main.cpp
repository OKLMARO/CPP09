/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 22:21:01 by oamairi           #+#    #+#             */
/*   Updated: 2026/07/14 13:45:34 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	PmergeMe test;

	if (ac < 2)
	{
		std::cerr << "Error\n";
		return 1;
	}
	for (size_t i = 1; i + 1 < (size_t) ac; i++)
	{
		std::string temp = av[i];
		std::string tempbis = av[i + 1];
		if (temp == tempbis)
		{
			std::cerr << "Error\n";
			return 1;
		}
	}
	if (!test.run(av))
	{
		std::cerr << "Error\n";
		return 1;
	}
	return 0;
}
