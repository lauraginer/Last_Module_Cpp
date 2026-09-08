/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 21:36:31 by lauragm           #+#    #+#             */
/*   Updated: 2026/09/08 20:37:23 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << "Default constructor of PmergeMe called\n";
}
/*PmergeMe::PmergeMe(const PmergeMe& other): data(other.data)
{
	std::cout << "Copy constructor of PmergeMe called\n";
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	std::cout << "Copy assignment operator of PmergeMe called\n";
	if(this != &other)
	{
		data = other.data;
	}
	return(*this);
}*/
PmergeMe::~PmergeMe()
{
	std::cout << "Destructor of PmergeMe called\n";
}