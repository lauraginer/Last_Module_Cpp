/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:49:43 by lauragm           #+#    #+#             */
/*   Updated: 2026/04/21 21:17:02 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
void printIter(const T& element)
{
	std::cout << element << std::endl;
}

int main()
{
	int arr1[] = {1, 2, 3, 4, 5};
	const char *arr2[] = {"hola", "jamón", "adios"};

	size_t len1 = sizeof(arr1) / sizeof(arr1[0]); //numero de elementos de array estatico
	size_t len2 = sizeof(arr2) / sizeof(arr2[0]);
 	std::cout << "TEST 1: trying with an int array with iter" << std::endl;
	::iter(arr1, len1, printIter<int>);
	std::cout << std::endl;
	std::cout << "TEST 2: trying with an const char array with iter" << std::endl;
	::iter(arr2, len2, printIter<const char*>);
	
	/*IMPORTANTE: Como la funcion printIter es un template también, tienes que usar especializacion explícita,
	ya que falla la deducción de Fuction por el compilador. Si la funcion fuese de tipo int o char (por ejemplo) no haria falta*/
	return 0;
}