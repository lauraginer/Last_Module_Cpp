/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:58:30 by lginer-m          #+#    #+#             */
/*   Updated: 2026/04/08 13:53:41 by lginer-m         ###   ########.fr       */
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
	
	std::cout << "Puntero original " << ptr << std::endl;
	std::cout << "Puntero final: " << nptr << std::endl;
	std::cout << "Resultado de serialize: " << result << std::endl;

}