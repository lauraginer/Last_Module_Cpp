/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 21:36:31 by lauragm           #+#    #+#             */
/*   Updated: 2026/09/20 21:49:02 by lauragm          ###   ########.fr       */
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
void PmergeMe::printResultLine(bool flag)
{
	size_t i = 0;
	if(flag == false)
	{
		std::cout << "Before:";
		while(i < base.size())
		{
			std::cout << " " << base[i] ;
			i++;
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "After:";
		while(i < result.size())
		{
			std::cout << " " << result[i] ;
			i++;
		}
		std::cout << std::endl;
	}
}
std::vector<size_t> generateJacobstall(size_t index)
{
	std::vector<size_t> jacob;
	jacob.push_back(0);
	jacob.push_back(1);

	size_t i = 2;
	while(jacob.size() < 3 || jacob[i - 1] < index)
	{
		size_t next = jacob[i - 1] + 2 * jacob[i - 2]; //formula traducida a código: J(n) = J(n-1) + 2*J(n-2)
		jacob.push_back(next);
		i++;
	}
	return(jacob);
}
std::vector<size_t> buildOrder(size_t n)
{
	std::vector<size_t> jacob = generateJacobstall(n);
	std::vector<size_t> order;

	size_t j = 2;
	size_t prev = 0; //tope inferior
	while(prev < n)
	{
		size_t begin = jacob[j]; //tope superior
		if(begin > n)
			begin = n;
		
		size_t k = begin;
		while(k > prev)
		{
			order.push_back(k);
			k--;
		}
		prev = begin;
		if(j < jacob.size())
			j++;
	}
	return(order);
}
void calculeBinary(std::vector<int> &largest, int value) //inserta uno por uno de minors en largestOrdered
{
	size_t left = 0; //limite izq. aqui van los mayores (o si es igual tamb)
	size_t right = largest.size(); //limite der. aqui van los menores 
	
	while(left < right) //salimos cuando los valores son iguales, ya no queda nada que reducir
	{
		size_t mid = (left + right) / 2;
		if(value < largest[mid]) //comparas con el INDICE
			right = mid;
		else
			left = mid + 1; //añadimos el +1 porque sabemos que mid no es la pos correcta
		//std::cout << "La mitad es: " << mid << std::endl;
		//std::cout << "valor minors: " << value <<std::endl;
	}
	largest.insert(largest.begin() + left, value);
	/*esto es una movida, si le sumas a un iterador x numeros, estas desplazando esa cantidad de posiciones, 
	entonces con insert, lo que ocurre es que insertas el valor en esa misma pos y lo demas lo desplaza a la derecha*/
}
void secondStep(std::vector<int> &minors, std::vector<int> &largestOrdered) //la idea es que entren los menores
{
	std::vector<size_t> vec = buildOrder(minors.size()); //la secuencia de imdices ya correcta y ordenada tras jacobstall
	size_t x = 0;
	std::vector<int> finalOrdered;
	while(x < vec.size())
	{
		size_t j = vec[x]; //el valor ya ordenado de builOrder
		finalOrdered.push_back(minors[j - 1]);
		calculeBinary(largestOrdered, minors[j - 1]);
		x++;
	}
}
std::vector<int> firstStep(std::vector<int> vec)
{
	std::vector<int> minors;
	std::vector<int> largers;
	size_t i = 0;
	
	if (vec.size() <= 1) //CASO BASE: si el vector tiene 0 o 1 elementos, ya está "ordenado" 
		return(vec);
	
	while(i + 1 < vec.size())
	{
		if(vec[i] < vec[i + 1])
		{
			minors.push_back(vec[i]);
			largers.push_back(vec[i + 1]);
		}
		else
		{
			minors.push_back(vec[i + 1]);
			largers.push_back(vec[i]);
		}
		i += 2; //recorremos por pares
	}
	int alone = 0; //numero inpar
	bool odd = false;
	if(i < vec.size())
	{
		alone = vec[i];
		odd = true;
	}
	std::vector<int> largestOrdered = firstStep(largers);
	secondStep(minors, largestOrdered); //tambien hace la insercion binaria aqui directamente
	if(odd)
		calculeBinary(largestOrdered, alone);
	return(largestOrdered);
}