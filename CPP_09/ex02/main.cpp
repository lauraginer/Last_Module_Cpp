/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 21:36:25 by lauragm           #+#    #+#             */
/*   Updated: 2026/09/09 21:51:16 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <cerrno>
#include <climits>

void parsingInput(std::string input, PmergeMe &data )
{
	std::string token(input);
	if(token.empty())
		throw error();
	size_t j = 0;
	if(token[0] == '+')
		j = 1;
	if(j == token.size()) //para evitar un + solo
		throw error();
	while(j < token.size()) 
	{
		if(!isdigit(token[j]))
			throw error();
		j++;
	}
	errno = 0;
	char *endptr; //se detiene cuando no es numero
	long num = strtol(token.c_str(), &endptr, 10);
	if(errno == ERANGE || num > INT_MAX || num < 0)
		throw error();
	data.base.push_back(static_cast<int>(num)); //rellenamos los vectores
	data.base2.push_back(static_cast<int>(num));
}
void printFirstLine(PmergeMe &data)
{
	size_t i = 0;
	std::cout << "Before: ";
	while(i < data.base.size())
	{
		std::cout << data.base[i] << " ";
		i++;
	}
	std::cout << std::endl;
	/*for (std::list<int>::iterator it = data.base2.begin(); it != data.base2.end(); ++it)
	{
		std::cout << *it << " ";
	}*/
}	
int main(int argc, char **argv)
{
	try{
		if(argc < 2)
			throw error();
		
		PmergeMe data;
		int i = 1;
		while(i < argc)
		{
			parsingInput(argv[i], data);
			i++;
		}
		printFirstLine(data);
	
		return(0);
	}
	catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	
}

//En la primera línea debes mostrar un texto explícito seguido de la secuencia de enteros positivos sin ordenar.
//En la segunda línea debes mostrar un texto explícito seguido de la secuencia de enteros positivos ordenada.

/*En la tercera línea, debes mostrar un mensaje explícito indicando el tiempo empleado por tu algoritmo, 
especificando el primer contenedor usado para ordenar la secuencia de enteros positivos.*/

/*En la última línea debes mostrar un texto explícito indicando el tiempo empleado por tu algoritmo, 
especificando el segundo contenedor usado para ordenar la secuencia de enteros positivos.*/

//que ruina dios