/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:06:32 by lauragm           #+#    #+#             */
/*   Updated: 2026/04/22 22:45:39 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//mejor separar en este archivo los costructores y toda la clase
#include "Array.hpp"

Array::Array(): size(0){
	std::cout << "Default constructor of Array called\n";
}