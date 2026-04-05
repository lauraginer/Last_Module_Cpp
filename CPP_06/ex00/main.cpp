/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:25:49 by lginer-m          #+#    #+#             */
/*   Updated: 2026/04/05 20:29:33 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "Wrong input. Please insert one argument!\n";
		return (1);
	}
	else
	{
		ScalarConverter::convert(argv[1]);
		std::string literal = argv[1];
	}
	return (0);
}