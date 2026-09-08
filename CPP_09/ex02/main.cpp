/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 21:36:25 by lauragm           #+#    #+#             */
/*   Updated: 2026/09/08 21:46:47 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
	if(argc < 2)
	{
		std::cerr << "Error: bad input" << std::endl;
		return(1);
	}
	int i = 1;
	while(i < argc)
	{
		std::string token(argv[i]);
		if(token.empty())
		{
			std::cerr << "Error: bad input" << std::endl;
			return(1);
		}
		size_t j = 0;
		if(token[0] == '+')
			j = 1;
		if(j == token.size())//para evitar un + solo
		{
			std::cerr << "Error" << std::endl;
			return(1);
		}
		while(j < token.size())
		{
			if(!isdigit(token[j]))
			{
				std::cerr << "Error" << std::endl;
				return(1);
			}
			j++;
		}
		std::cout << token << std::endl; 
		i++;
	}
	
	return(0);
}

//En la primera línea debes mostrar un texto explícito seguido de la secuencia de enteros positivos sin ordenar.
//En la segunda línea debes mostrar un texto explícito seguido de la secuencia de enteros positivos ordenada.

/*En la tercera línea, debes mostrar un mensaje explícito indicando el tiempo empleado por tu algoritmo, 
especificando el primer contenedor usado para ordenar la secuencia de enteros positivos.*/

/*En la última línea debes mostrar un texto explícito indicando el tiempo empleado por tu algoritmo, 
especificando el segundo contenedor usado para ordenar la secuencia de enteros positivos.*/

//que ruina dios