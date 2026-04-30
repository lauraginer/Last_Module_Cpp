/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:49:43 by lauragm           #+#    #+#             */
/*   Updated: 2026/04/30 21:08:31 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void printIter(const T& element)
{
	std::cout << element << std::endl;
}

template <typename T>
void incrementIter(T& element) //Funcion creada para modificar un no-const y comprobar que iter lo soporta
{
	element++;
}

int main()
{
	std::cout << "--TEST 1: trying with an int array with iter--" << std::endl;
	int arr1[] = {1, 2, 3, 4, 5};
	size_t len1 = sizeof(arr1) / sizeof(arr1[0]); //Numero de elementos de array estatico
	::iter(arr1, len1, printIter<int>);
	std::cout << std::endl;
	
	std::cout << "--TEST 2: trying with an const char array with iter--" << std::endl;
	const char *arr2[] = {"hola", "jamón", "adios"};
	size_t len2 = sizeof(arr2) / sizeof(arr2[0]);
	::iter(arr2, len2, printIter<const char*>);
	std::cout << std::endl;
	
	std::cout << "--TEST 3: trying with a reference no-const and const--" << std::endl;
	int (&ref1)[] = arr1;
	const char* (&ref2)[] = arr2; //Las referencias para arrays son asi de raras
	::iter(ref1, len1, incrementIter<int>);
	::iter(ref1, len1, printIter<int>);
	::iter(ref2, len2, printIter<const char *>);
	std::cout << std::endl;

	std::cout << "--TEST 4: trying with an const int array with iter--" << std::endl;
	const int arr3[] = {10, 20, 30, 40};
	size_t len3 = sizeof(arr3) / sizeof(arr3[0]);
	::iter(arr3, len3, printIter<int>);
	std::cout << std::endl;

	std::cout << "--TEST 5: trying with an std::string array with iter--" << std::endl;
	std::string arr4[] = {"one", "two", "three"};
	size_t len4 = sizeof(arr4) / sizeof(arr4[0]);
	::iter(arr4, len4, printIter<std::string>);
	std::cout << std::endl;
	
	/*IMPORTANTE: Como la funcion printIter es un template también, tienes que usar especializacion explícita,
	ya que falla la deducción de Fuction por el compilador. Si la funcion fuese de tipo int o char (por ejemplo) no haria falta*/
	return 0;
}