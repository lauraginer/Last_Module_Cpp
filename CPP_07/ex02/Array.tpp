/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:06:32 by lauragm           #+#    #+#             */
/*   Updated: 2026/04/29 22:08:55 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//mejor separar en este archivo los costructores y toda la clase
#include "Array.hpp"
#include <string>

template <typename T>
Array<T>::Array(): sizeArray(0), array(NULL){
	array = new T[sizeArray];
	std::cout << "Default constructor of Array called\n";
};

template <typename T>
Array<T>::Array(unsigned int n): sizeArray(n), array(NULL){
	array = new T[n];
	std::cout << "Parameter constructor of Array called\n";
}

template <typename T>
Array<T>::Array(const Array &other): sizeArray(other.sizeArray), array(NULL)
{
	size_t i = 0;
	array = new T[sizeArray];
	while(i < sizeArray)
	{
		array[i] = other.array[i];
		i++;
	}
	std::cout << "Copy constructor of Array called\n";
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	size_t i = 0;
	std::cout << "Copy assignment operator of Array called\n";
	if(this != &other)
	{
		delete[] array; //borramos el objeto que ya existe para evitar leaks
		sizeArray = other.sizeArray;
		array = new T[sizeArray];
		while(i < sizeArray)
		{
			array[i] = other.array[i];
			i++;
		}
	}
	return(*this);
}

template <typename T>
const char* Array<T>::IndexException::what() const throw()
{
    return "Error. Index is out of range!";
}
template <typename T>
T& Array<T>::operator[](const unsigned int i)
{
	std::cout << "Subscript operator operator of Array called\n";
	if((i >= sizeArray) || i < 0) 
		throw IndexException();
	return(array[i]);
}
template <typename T>
Array<T>::~Array()
{
	delete[] array;
	std::cout << "Destructor of Array called\n";
}
template <typename T>
size_t Array<T>::size() const
{
	int i = 0;
	while(i)
	{
		array[i++];
	}
	std::cout << "Total elements of array: " << i << std:endl;
} //ESTO ESTA MAL DIRIA YO, porque no deberia de recorrer el array como tal, sino imprimir el sizeArray no?
//recuerda la deep copy!!