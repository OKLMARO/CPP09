/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 10:56:12 by oamairi           #+#    #+#             */
/*   Updated: 2026/07/14 14:53:39 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <cstdlib>
#include <iostream>

class RPN
{
private:
	std::stack<double>	_data;
public:
	RPN();
	RPN(const RPN &obj);

	bool	run(std::string str);
	void	affichLastData();

	RPN	&operator=(const RPN &obj);

	~RPN();
};
