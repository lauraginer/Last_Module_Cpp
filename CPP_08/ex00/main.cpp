/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 21:00:19 by lauragm           #+#    #+#             */
/*   Updated: 2026/06/21 21:57:31 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main()
{
	try{
		std::cout << "--TEST 1: TESTING WITH VECTORS--\n";
		std::vector<int> numbers;
		std::vector<int> empty;
		numbers.push_back(20);
		numbers.push_back(4);
		numbers.push_back(8);
		numbers.push_back(15);
		std::vector<int>::iterator it = easyfind(numbers, 8); //guardamos el result en otro iterador
		std::cout << "Found it: " << *it << std::endl;
		
		std::vector<int>::iterator emt = easyfind(empty, 0);
		std::cout << "Found it: " << *emt << std::endl;
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
}