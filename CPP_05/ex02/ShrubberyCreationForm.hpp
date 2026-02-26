/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:06:02 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/26 14:01:10 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRUBBERYCREATIONFORM_HPP
#define SRUBBERYCREATIONFORM_HPP

#include "iostream"
#include <exception>

class Bureaucrat;

class ShrubberyCreationForm {
	private:
		std::string target;
		const int grade_sign; // Grado mínimo requerido para FIRMAR
		const int grade_execute; // Grado mínimo requerido para EJECUTAR 
		
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string &subject);
  		ShrubberyCreationForm(const ShrubberyCreationForm& other);
    	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
};

#endif