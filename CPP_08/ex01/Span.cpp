/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 20:03:28 by lauragm           #+#    #+#             */
/*   Updated: 2026/07/26 22:48:56 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span(): maxSize(0)
{
	std::cout << "Default constructor of Span called\n";
}
Span::Span(unsigned int max): maxSize(max)
{
	std::cout << "Parametrized constructor of Span called\n";
}
Span::Span(const Span& other): maxSize(other.maxSize), numbers(other.numbers)
{
	std::cout << "Copy constructor of Span called\n";
}
Span& Span::operator=(const Span& other)
{
	std::cout << "Copy assignment operator of Span called\n";
	if(this != &other)
	{
		maxSize = other.maxSize;
		numbers = other.numbers;
	}
	return(*this);
}
Span::~Span()
{
	std::cout << "Destructor of Span called\n";
}
void Span::addNumber(int number)
{
	if(numbers.size() >= maxSize)
		throw SpanError();
	numbers.push_back(number);
}
unsigned int Span::shortestSpan() const
{
 	if(numbers.size() < 2)
		throw SpanError();
	std::vector<int> cpy(numbers);
	std::sort(cpy.begin(), cpy.end()); //ordenamos para que sea mas sencillo
	unsigned int shortest = cpy[1] - cpy[0];
	size_t i = 0;
	while(i + 1 < cpy.size()) //el +1 porque sino, se va fuera de rango
	{
		unsigned int result = cpy[i + 1] - cpy[i];
		if(result < shortest)
			shortest = result;
		++i;
	}
	return(shortest);
}
unsigned int Span::longestSpan() const
{
	if(numbers.size() < 2)
		throw SpanError();
	
	int max = numbers[0];
	int min = numbers[0];
	size_t i = 1;
	while(i < numbers.size())
	{
		if(numbers[i] < min)
			min = numbers[i];
		if(numbers[i] > max)
			max = numbers[i];
		++i;
	}
	return(max - min);
}
const char* SpanError::what() const throw()
{
	return("Error. Something failed on Span!");
}