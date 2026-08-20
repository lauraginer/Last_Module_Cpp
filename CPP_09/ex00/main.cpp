/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 20:02:19 by lauragm           #+#    #+#             */
/*   Updated: 2026/08/20 22:07:05 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream> //leer archivos
int main(int argc, char **argv)
{
	try{
		if(argc != 2)
			throw errorArgument();
		std::ifstream file(argv[1]); //aqui se abre el archivo
		if(!file.is_open())
			throw errorArgument();
		
		std::string line;
		while(std::getline(file, line)) //lee los caracteres de file y los guarda todo en line
		{
			//aqui hacemos todo el parser
			//parseamos la línea (separar fecha y valor, convertirla en float y blabla)
			//paseamos la fecha, formato valido
			//parseamos el valor, si es un valor negativo y despues si es demasiado grande
		}
		
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}
}
