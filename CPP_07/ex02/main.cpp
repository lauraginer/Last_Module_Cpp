/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:36:49 by lauragm           #+#    #+#             */
/*   Updated: 2026/05/04 14:52:22 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	try
	{
		std::cout << std::endl;
		std::cout << "--TEST 1: Testing simple forms on stack--" << std::endl;
		Array<int> emptyArray;
		Array<char> cArr(6);
		Array<char> copy(cArr);
		Array<int> cpyArr;
		cpyArr = emptyArray; //esto es el operador =, recuerda que este operador se crea cuando ya hay un objeto creadooooooo
		std::cout << "Tamaño de emptyArray: " << emptyArray.size() << std::endl;
		std::cout << "Tamaño de cArr: " << cArr.size() << std::endl;
		std::cout << "Tamaño de copy: " << copy.size() << std::endl;
		std::cout << "Tamaño de cpyArr: " << cpyArr.size() << std::endl;
		std::cout << std::endl;

		std::cout << "--TEST 2: Testing many forms on heap--" << std::endl;
		Array<int> *a = new Array<int>(4);
		Array<std::string> *b = new Array<std::string>(100);
		Array<float> *c = new Array<float>(12);
		Array<std::string> *cb = new Array<std::string>(*b); //para forzar el constructor de copia
		std::cout << "Tamaño de a: " << a->size() << std::endl;
		std::cout << "Tamaño de b: " << b->size() << std::endl;
		std::cout << "Tamaño de c: " << c->size() << std::endl;
		std::cout << "Tamaño de cb: " << cb->size() << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
		std::cout << "--TEST 3: Testing subject test and arrays forms on stack and heap--" << std::endl;
		int *d = new int();
		Array<int> e(8);
		e[-1] = 10;
		std::cout << "Value of d: " << *d << '\n';
		std::cout << "Value of e: " << e[0] << '\n';
		delete d;
		std::cout << std::endl;
		std::cout << "--TEST 4: Testing wrong cases--" << std::endl;
		std::cout << "Value of d: " << e[5] << '\n';

		//probar con int * a = new int();` y luego muestre *a. Ejemplo de main.
		//probar con char y double o float a ver si soporta
		//probar con constructor de copia y asignacion
		//probar con casos que esten mal (al estilo un indice fuera de rango) blablabla

		//aprende de nuevo punteros en c++ que estoy loca
	}
	catch(const std::exception& e)
	{
		std::cerr << "exception: " << e.what() << '\n';
	}
	
	
}