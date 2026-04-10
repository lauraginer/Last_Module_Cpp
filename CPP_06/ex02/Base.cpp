/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 14:26:16 by lginer-m          #+#    #+#             */
/*   Updated: 2026/04/10 21:49:05 by lginer-m         ###   ########.fr       */
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
		std::cout << "Pointer Base does not have a real type!";
}
void identify(Base &p)
{
	//Utilizamos una excepcion porque si falla, el cast lanza una excepción std::bad_cast, en lugar de devolver algo falso
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "Real type of reference Base is A!\n";
		dynamic_cast<B&>(p);
		std::cout << "Real type of reference Base is B!\n";
		dynamic_cast<C&>(p);
		std::cout << "Real type of reference Base is C!\n";
	}
	catch(std::bad_cast)
	{
		std::cout << "Something failed! Reference Base does not have a real type" << std::endl;
	}
	

}