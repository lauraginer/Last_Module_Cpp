/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 20:03:31 by lauragm           #+#    #+#             */
/*   Updated: 2026/07/14 21:28:55 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

MutantStack::MutantStack(): size(0)
{
	std::cout << "Default constructor of MutantStack called\n";
}
MutantStack::MutantStack(unsigned int max): size(max)
{
	std::cout << "Parametrized constructor of MutantStack called\n";
}
MutantStack::MutantStack(const MutantStack& other): size(other.size)
{
	std::cout << "Copy constructor of MutantStack called\n";
}
MutantStack& MutantStack::operator=(const MutantStack& other)
{
	std::cout << "Copy assignment operator of MutantStack called\n";
	if(this != &other)
	{
		size = other.size;
	}
	return(*this);
}
MutantStack::~MutantStack()
{
	std::cout << "Destructor of MutantStack called\n";
}
const char* MutantError::what() const throw()
{
	return("Error. Something was wrong on MutantStack!");
}