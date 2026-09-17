/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 21:36:25 by lauragm           #+#    #+#             */
/*   Updated: 2026/09/17 23:56:58 by lauragm          ###   ########.fr       */
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

std::vector<int> firstStep(std::vector<int> vec)
{
	std::vector<int> minors;
	std::vector<int> largers;
	size_t i = 0;
	//size_t z = 0;
	
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
	if(i < vec.size())
	{
		alone = vec[i];
		std::cout << alone << std::endl;
	}
	
	/*size_t d = 0;
	std::cout << "Minors: ";
	while(d < minors.size())
	{
		std::cout << minors[d] << " ";
		d++;
	}
	std::cout << "\n";
	std::cout << "Largers: ";
	while(z < largers.size())
	{
		std::cout << largers[z] << " ";
		z++;
	}*/
	std::vector<int> largestOrdered = firstStep(largers);
	//tenemos que meter, segun el algoritmo los menores y el suelto dentro de la lista de largers, de forma ordenada
	//necesitamosm la lista de Jacostall para indicar los indices correspondientes a los números menores, esta lista funciona como límites de bloque
	return(largestOrdered);
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

std::vector<int> secondPart(std::vector<int> minors) //la idea es que entren los menores
{
	std::vector<size_t> vec = buildOrder(minors.size());
	size_t i = 0;
	size_t x = 0;
	std::vector<int> final;
	while(i < minors.size())
	{
		if(x < vec.size())
		{
			size_t j = vec[x]; //el valor ordenado de vec
			//quiero meter el valor de minors dentro de final con el indice correcto
			final.push_back(minors[j]);
			x++;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	try{
		if(argc < 2)
			throw error();
		PmergeMe data;
		data.parsingInput(argv, argc);
		data.printFirstLine();
		std::vector<int> result = firstStep(data.base);
		secondPart(result);
		
		/*std::vector<size_t> order = buildOrder(8); //hardcodeado para comprobar que funcione
		size_t i = 0;
		while(i < order.size())
		{
			std::cout << order[i] << std::endl;
			i++;
		}
		return(0);*/
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