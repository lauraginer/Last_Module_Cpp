/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 21:00:19 by lauragm           #+#    #+#             */
/*   Updated: 2026/07/26 22:55:31 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <set>

int main()
{
	try{
		std::cout << "--TEST 1: TESTING WITH VECTORS--\n";
		std::vector<int> numbers = {20, 4, 8, 15};
		std::vector<int>::iterator it = easyfind(numbers, 15); //guardamos el result en otro iterador
		std::cout << "Found it: " << *it << std::endl;
		std::cout << std::endl;
		
		std::cout << "--TEST 2: TESTING WITH LIST AND DEQUE TYPES--\n";
		std::list<int> nums; //funciona como una lista doblemente enlazada
		std::deque<int> numsD; //funciona como un vector segmentado
		nums.push_back(10);
		nums.push_back(-2);
		nums.push_back(5);
		numsD.push_back(20);
		numsD.push_back(100);
		numsD.push_back(90);
		std::list<int>::iterator itList = easyfind(nums, -2);
		std::deque<int>::iterator itDeque = easyfind(numsD, 20);
		std::cout << "Found it (list type): " << *itList << std::endl;
		std::cout << "Found it (deque type): " << *itDeque << std::endl;
		std::cout << std::endl;
		//no puedo probar con map, porque el iterador de este no apunta a un int, sino a un par clave/valor
		//ademas, tanto set como map, son contenedores asociativos
		
		std::cout << "--TEST 3: WRONG CASES--\n";
		std::vector<int> empty;
		std::vector<int>::iterator emt = easyfind(empty, 0);
		std::cout << "Found it: " << *emt << std::endl;
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
}