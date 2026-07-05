/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 20:03:28 by lauragm           #+#    #+#             */
/*   Updated: 2026/07/05 21:04:01 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): maxSize(0){
	std::cout << "Default constructor of Span called\n";
}
Span::Span(unsiged int max): maxSize(max){
	std::cout << "Parametrized constructor of Span called\n";
}