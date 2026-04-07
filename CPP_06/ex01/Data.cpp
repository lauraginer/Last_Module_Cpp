/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:57:15 by lginer-m          #+#    #+#             */
/*   Updated: 2026/04/07 19:00:50 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{
	std::cout << "Default constructor of Data called\n";
}
Data::Data(const Data& other)
{
	std::cout << "Copy constructor of Data called\n";
	(void)other;
}
Data& Data::operator=(const Data& other)
{
	std::cout << "Copy assignment operator of Data called\n";
	if(this != &other)
		(void)other;
	return(*this);
}
Data::~Data()
{
	std::cout << "Destructor of Data called\n";
}