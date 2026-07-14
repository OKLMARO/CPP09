/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 10:56:09 by oamairi           #+#    #+#             */
/*   Updated: 2026/07/14 14:57:45 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {};

RPN::RPN(const RPN &obj)
{
	_data = obj._data;
}

bool	RPN::run(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]) && str[i] != '*' && str[i] != '/' && str[i] != '+' && str[i] != '-')
			return false;
		else if (isdigit(str[i]))
		{
			std::string temp(1, str[i]);
			_data.push(std::atof(temp.c_str()));
			i++;
		}
		else if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-')
		{
			if (_data.size() < 2)
				return false;
			double b = _data.top();
			_data.pop();
			double a = _data.top();
			_data.pop();
			if (str[i] == '*')
				a = a * b;
			else if (str[i] == '/')
			{
				if (b == 0)
					return false;
				a = a / b;
			}
			else if (str[i] == '+')
				a = a + b;
			else if (str[i] == '-')
				a = a - b;
			_data.push(a);
			i++;
		}
	}
	if (_data.size() == 1)
		return true;
	return false;
}

void	RPN::affichLastData()
{
	if (_data.size() >= 1)
		std::cout << _data.top() << "\n";
}

RPN	&RPN::operator=(const RPN &obj)
{
	if (this != &obj)
		_data = obj._data;
	return *this;
}

RPN::~RPN() {};
