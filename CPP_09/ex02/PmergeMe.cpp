/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 21:36:31 by lauragm           #+#    #+#             */
/*   Updated: 2026/09/10 20:39:16 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cerrno>
#include <climits>
#include <cstdlib>

PmergeMe::PmergeMe()
{
	//std::cout << "Default constructor of PmergeMe called\n";
}
PmergeMe::PmergeMe(const PmergeMe& other): base(other.base), base2(other.base2)
{
	std::cout << "Copy constructor of PmergeMe called\n";
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	std::cout << "Copy assignment operator of PmergeMe called\n";
	if(this != &other)
	{
		base = other.base;
		base2 = other.base2;
	}
	return(*this);
}
PmergeMe::~PmergeMe()
{
	//std::cout << "Destructor of PmergeMe called\n";
}
const char* error::what() const throw()
{
	return("Error");
}

void PmergeMe::parsingInput(char** argv, int argc)
{
	int i = 1;
	while(i < argc)
	{
		std::string token(argv[i]);
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
		base.push_back(static_cast<int>(num)); //rellenamos los vectores
		base2.push_back(static_cast<int>(num));
		
		i++;
	}
}
void PmergeMe::printFirstLine()
{
	size_t i = 0;
	std::cout << "Before: ";
	while(i < base.size())
	{
		std::cout << base[i] << " ";
		i++;
	}
	std::cout << std::endl;
	/*for (std::list<int>::iterator it = data.base2.begin(); it != data.base2.end(); ++it)
	{
		std::cout << *it << " ";
	}*/
}	