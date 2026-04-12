/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 14:26:16 by lginer-m          #+#    #+#             */
/*   Updated: 2026/04/12 21:16:03 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	std::cout << "Destructor of Base called\n";
}

Base *generate(void)
{
	srand(time(NULL));
	int num = rand() % 3;
	if(!num)
	{
		std::cout << "Object of class A has been created!\n";
		return(new A);
	}
	else if(num == 1)
	{
		std::cout << "Object of class B has been created!\n";
		return(new B);

	}
	else
	{
		std::cout << "Object of class C has been created!\n";
		return(new C);
	}
}

void identify(Base *p)
{
	if(dynamic_cast<A*>(p))
		std::cout << "Real type of pointer Base is A!\n";
	else if(dynamic_cast<B*>(p))
		std::cout << "Real type of pointer Base is B!\n";
	else if(dynamic_cast<C*>(p))
		std::cout << "Real type of pointer Base is C!\n";
	else
		std::cout << "Pointer Base does not have a real type!\n";
}
void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Real type of reference Base is A!\n";
		return;
	}
	catch(const std::exception& e){}
	
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Real type of reference Base is B!\n";
		return;
	}
	catch(const std::exception& e){}
	
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Real type of reference Base is C!\n";
		return;
	}
	catch(const std::exception& e){}
	
	std::cerr << "Something failed!" << std::endl;
	//El cast lanza una excepción std::bad_cast en lugar de devolver algo falso si falla, por eso el uso de la excepcion 
}