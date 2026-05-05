/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:36:49 by lauragm           #+#    #+#             */
/*   Updated: 2026/05/05 18:25:34 by lginer-m         ###   ########.fr       */
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
		delete cb;
		std::cout << std::endl;
		std::cout << "--TEST 3: Testing subject test and arrays forms on stack and heap--" << std::endl;
		int *d = new int();
		Array <char> w(5);
		const Array<int> e(8);
		Array<int> cpye(e);
		Array<float> *ptnum = new Array<float>(16);
		e[0] = 10;
		e[5] = 100;
		w[0] = 'T';
		w[1] = 'U';
		(*ptnum)[9] = 1909; //Desreferenciar, porque si no intentas acceder al 9 objeto
		std::cout << "Value of d: " << *d << '\n';
		std::cout << "Value of e[0]: " << e[0] << '\n';
		std::cout << "Value of e[5]: " << e[5] << '\n';
		std::cout << "Value of e[2]: " << e[2] << '\n';
		std::cout << "Value of w[0]: " << w[0] << '\n';
		std::cout << "Value of w[1]: " << w[1] << '\n';
		std::cout << "Value of ptnum[9] to check pointer: " << (*ptnum)[9] << '\n';		
		delete ptnum;
		delete d;
		std::cout << std::endl;
		std::cout << "--TEST 4: Testing wrong cases--" << std::endl;
		Array<int> f(8);
		Array<int> empt; //Para intentar acceder al array
		f[0] = -10;
		std::cout << "Value of f[-2] out of range: " << f[-2] << '\n';
		//std::cout << "Value of f[10] out of range: " << f[10] << '\n';
		//std::cout << empt[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caption: " << e.what() << '\n';
	}
	
	
}