/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 20:03:28 by lauragm           #+#    #+#             */
/*   Updated: 2026/07/07 21:21:29 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): maxSize(0)
{
	std::cout << "Default constructor of Span called\n";
}
Span::Span(unsigned int max): maxSize(max)
{
	std::cout << "Parametrized constructor of Span called\n";
}
Span::Span(const Span& other): maxSize(other.maxSize)
{
	std::cout << "Copy constructor of Span called\n";
}
Span::Span& operator=(const Span& other)
{
	std::cout << "Copy assignment operator of Span called\n";
	if(this != &other)
		maxSize = other.maxSize;
	return(*this);
}
Span::~Span()
{
	std::cout << "Destructor of Span called\n";
}
void Span::addNumber(unsigned int number)
{
	if(numbers.size() >= maxSize)
		throw SpanError();
	numbers.push_back(number);
}
unsigned int Span::longestSpan()
{
	if(!numbers.size() || numbers.size() == 1)
		throw SpanError();
//falta implemetar la difrencia de rango
}
const char* SpanError::what() const throw()
{
	return("Error. Something failed on Span");
}