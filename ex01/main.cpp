/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 10:56:04 by oamairi           #+#    #+#             */
/*   Updated: 2026/07/11 22:08:33 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error\n";
		return 1;
	}
	RPN rpn;
	if (rpn.run(av[1]) == false)
	{
		std::cerr << "Error\n";
		return 1;
	}
	rpn.affichLastData();
	return 0;
}
