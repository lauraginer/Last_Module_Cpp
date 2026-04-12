/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:58:25 by lginer-m          #+#    #+#             */
/*   Updated: 2026/04/12 21:18:53 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Default constructor of Serializer called\n";
}
Serializer::Serializer(const Serializer& other)
{
	std::cout << "Copy constructor of Serializer called\n";
	(void)other;
}
Serializer& Serializer::operator=(const Serializer& other)
{
	std::cout << "Copy assignment operator of Serializer called\n";
	if(this != &other)
		(void)other;
	return(*this);
}
Serializer::~Serializer()
{
	std::cout << "Destructor of Serializer called\n";
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data *>(raw)); 
}
uintptr_t Serializer::serialize(Data *ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr)); 
	//Reinterpreta un tipo como si fuera otro, funciona bien entre punteros porque tienen el mismo formato físico
}

