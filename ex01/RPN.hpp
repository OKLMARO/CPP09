/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 10:56:12 by oamairi           #+#    #+#             */
/*   Updated: 2026/07/11 22:09:24 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <cstdlib>
#include <iostream>

class RPN
{
private:
	std::deque<double>	_data;
public:
	RPN();
	RPN(const RPN &obj);

	bool	run(std::string str);
	void	affichLastData();

	RPN	&operator=(const RPN &obj);

	~RPN();
};
