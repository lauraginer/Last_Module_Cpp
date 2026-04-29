/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:36:49 by lauragm           #+#    #+#             */
/*   Updated: 2026/04/29 22:11:18 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	Array<int> *emptyArray = NULL;
	
	emptyArray->sizeArray = emptyArray->size(); //chica no puedo mas me quiero pegar un puto tiro
	delete emptyArray;
	
	//probar con int * a = new int();` y luego muestre *a. Ejemplo de main.
	//probar con char y double o float a ver si soporta
	//probar con constructor de copia y asignacion
	//probar con casos que esten mal (al estilo un indice fuera de rango) blablabla

	//NO OLVIDES QUE TODO DEBE DE IR DENTRO DE UNA EXCEPCIÓN
}