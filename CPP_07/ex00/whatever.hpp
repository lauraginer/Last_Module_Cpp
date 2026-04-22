/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 21:12:24 by lginer-m          #+#    #+#             */
/*   Updated: 2026/04/22 11:19:51 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T &n, T &m)
{
	if(n < m)
		return(n);
	return(m);
}

template <typename T>
T max(T &o, T &l)
{
	if(o > l)
		return(o);
	return(l);
}
#endif