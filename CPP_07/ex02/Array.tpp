/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:06:32 by lauragm           #+#    #+#             */
/*   Updated: 2026/04/24 21:44:42 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//mejor separar en este archivo los costructores y toda la clase
#include "Array.hpp"
#include <string>

template <typename T>
Array<T>::Array(): size(0), array(NULL){
	array = new T[size];
	std::cout << "Default constructor of Array called\n";
};

template <typename T>
Array<T>::Array(unsigned int n): size(n), array(NULL){
	array = new T[n];
	std::cout << "Parameter constructor of Array called\n";
}

template <typename T>
Array<T>::Array(const Array &other)
{
	std::cout << "Copy assignment operator of Array called\n";
	if(this != &other)
	{
		size = other.size;
		array = other.array; //Sospecho de manera muy fuerte que esta mal
	}
	return(*this);
}

//recuerda la deep copy!!