/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 20:03:31 by lauragm           #+#    #+#             */
/*   Updated: 2026/07/20 22:20:39 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
	std::cout << "Default constructor of MutantStack called\n";
}
template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other)
{
	std::cout << "Copy constructor of MutantStack called\n";
}
template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
	std::cout << "Copy assignment operator of MutantStack called\n";
	if(this != &other)
		std::stack<T>::operator=(other);
	return(*this);
}
template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "Destructor of MutantStack called\n";
}
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return this->c.begin();
}
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return this->c.end();
}
const char* MutantError::what() const throw()
{
	return("Error. Something was wrong on MutantStack!");
}