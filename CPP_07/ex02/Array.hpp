/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:38:01 by lauragm           #+#    #+#             */
/*   Updated: 2026/05/05 18:18:30 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <ostream>
#include <exception>


template<typename T>
class Array{
	private:
		size_t sizeArray;
		T *array;
		
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		T& operator[](const unsigned int i) const;
		~Array();
		size_t size() const;
		
	class IndexException : public std::exception{
			public:
				const char *what() const throw();
		};
};
#include "Array.tpp"
#endif