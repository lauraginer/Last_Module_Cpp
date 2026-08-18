/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 20:02:19 by lauragm           #+#    #+#             */
/*   Updated: 2026/08/18 21:04:27 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "Default constructor of BitcoinExchange called\n";
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): maxSize(other.maxSize), numbers(other.numbers)
{
	std::cout << "Copy constructor of BitcoinExchange called\n";
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	std::cout << "Copy assignment operator of BitcoinExchange called\n";
	/*if(this != &other)
	{
		-
	}
	return(*this);*/
}
BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Destructor of BitcoinExchange called\n";
}

const char* errorArgument::what() const throw()
{
	return("Error: could not open file");
};

const char* errorToDate::what() const throw()
{
	return("Error: not a valid date");
};