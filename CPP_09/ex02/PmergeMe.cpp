/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 21:36:31 by lauragm           #+#    #+#             */
/*   Updated: 2026/09/09 20:35:25 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	//std::cout << "Default constructor of PmergeMe called\n";
}
PmergeMe::PmergeMe(const PmergeMe& other): base(other.base), base2(other.base2)
{
	std::cout << "Copy constructor of PmergeMe called\n";
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	std::cout << "Copy assignment operator of PmergeMe called\n";
	if(this != &other)
	{
		base = other.base;
		base2 = other.base2;
	}
	return(*this);
}
PmergeMe::~PmergeMe()
{
	//std::cout << "Destructor of PmergeMe called\n";
}
const char* error::what() const throw()
{
	return("Error");
}