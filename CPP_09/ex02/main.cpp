/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 21:36:25 by lauragm           #+#    #+#             */
/*   Updated: 2026/09/20 21:42:37 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>

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

void secondPart(std::vector<int> &minors, std::vector<int> &largestOrdered) //la idea es que entren los menores
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
	secondPart(minors, largestOrdered); //tambien hace la insercion binaria aqui directamente
	if(odd)
		calculeBinary(largestOrdered, alone);
	return(largestOrdered);
}

int main(int argc, char **argv)
{
	try{
		if(argc < 2)
			throw error();
		PmergeMe data;
		data.parsingInput(argv, argc);
		data.printResultLine(false);
		data.result = firstStep(data.base);
		data.printResultLine(true);

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