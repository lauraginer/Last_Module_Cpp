/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:58:30 by lginer-m          #+#    #+#             */
/*   Updated: 2026/04/14 20:51:00 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data data;
	Data *ptr = &data;
	uintptr_t result = Serializer::serialize(ptr);
	Data *nptr = NULL;
	nptr = Serializer::deserialize(result);
	std::cout << "--Result of testing main forms...--\n";
	std::cout << "Puntero original " << ptr << std::endl;
	std::cout << "Puntero final: " << nptr << std::endl;
	std::cout << "Resultado de serialize: " << result << std::endl;
	std::cout << std::endl;

	std::cout << "--Result of testing with atributes...--\n";
	Data n;
	n.literal = "hello";
	n.number = 42;
	Data *p = &n;
	uintptr_t type = Serializer::serialize(p);
	Data *lastPtr = NULL;
	lastPtr = Serializer::deserialize(type);
	std::cout << "Puntero original " << p << std::endl;
	std::cout << "Puntero final: " << lastPtr << std::endl;
	std::cout << "Resultado de serialize: " << type << std::endl;
	
}