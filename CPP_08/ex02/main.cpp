/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 20:03:31 by lauragm           #+#    #+#             */
/*   Updated: 2026/07/23 22:09:43 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <deque>

int main()
{
	try
	{
		std::cout << "--TEST 1: TEST FROM MAIN--\n";
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "The last element: " <<  mstack.top() << std::endl;
	
		mstack.pop();
		std::cout << "The size of mutant: " << mstack.size() << std::endl;
	
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
	
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it; //no entiendo muy bien para que esto
		--it;
		while (it != ite)
		{
			std::cout << "element: " << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		
		std::cout << "\n-- TEST 2: TESTING WITH LIST--\n";
        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(17);
        std::cout << "The last element: " << lst.back() << std::endl;
        lst.pop_back();
        std::cout << "The size of list: " << lst.size() << std::endl;
        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        lst.push_back(0);
		std::list<int>::iterator itl = lst.begin();
        while(itl != lst.end())
		{
			std::cout << "element: " << *itl << std::endl;
			++itl;
		}
		
		std::cout << "\n-- TEST 3: TESTING WITH DEQUE--\n";
        std::deque<int> dq;
        dq.push_back(5);
        dq.push_back(17);
        std::cout << "The last element: " << dq.back() << std::endl;
        dq.pop_back();
        std::cout << "The size of: " << dq.size() << std::endl;
        dq.push_back(3);
        dq.push_back(5);
        dq.push_back(737);
        dq.push_back(0);
		std::deque<int>::iterator itd = dq.begin();
        while( itd != dq.end())
		{
			std::cout << "element: " << *itd << std::endl;
			++itd;
		}
        return 0;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}