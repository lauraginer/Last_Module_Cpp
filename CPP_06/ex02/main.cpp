/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 14:26:10 by lginer-m          #+#    #+#             */
/*   Updated: 2026/04/10 21:01:57 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
 
int main()
{
	Base *normal = NULL;
	
	Base *copy = generate();
	identify(copy);
	identify(normal);
	delete (copy);
}
