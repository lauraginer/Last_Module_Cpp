/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 18:35:37 by lauragm           #+#    #+#             */
/*   Updated: 2026/09/03 19:40:57 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	std::cout << "Default constructor of RPN called\n";
}
RPN::RPN(const RPN& other): data(other.data)
{
	std::cout << "Copy constructor of RPN called\n";
}
RPN& RPN::operator=(const RPN& other)
{
	std::cout << "Copy assignment operator of RPN called\n";
	if(this != &other)
	{
		data = other.data;
	}
	return(*this);
}
RPN::~RPN()
{
	std::cout << "Destructor of RPN called\n";
}