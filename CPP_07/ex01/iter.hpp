/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:45:34 by lginer-m          #+#    #+#             */
/*   Updated: 2026/04/17 19:17:54 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename Function>
void iter(T *addres, T const length, Function f)
{
	
}
#endif

/*¿Cómo lo valida entonces?
Cuando instancias iter(...), el compilador deduce Function a partir del tercer argumento y 
luego intenta compilar esta línea dentro de iter.

En definitiva, basicamente segun como trates el tipo de dato, el compilador lo toma de
una forma o otra*/