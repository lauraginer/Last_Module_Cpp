/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 14:26:10 by lginer-m          #+#    #+#             */
/*   Updated: 2026/04/12 21:18:17 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
 
int main()
{
	Base *normal = NULL;
	std::cout << std::endl;
	std::cout << "--Using the fuction of generate...--\n";
	Base *copy = generate();
	std::cout << std::endl;
	std::cout << "--Using diferent forms of identify...--\n";
	Base &reference = *copy;
	identify(copy);
	identify(normal);
	identify(reference);
	std::cout << "--The end!--\n";
	std::cout << std::endl;
	delete (copy);
}
