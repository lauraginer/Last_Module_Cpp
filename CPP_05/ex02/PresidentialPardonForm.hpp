/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:42:20 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/26 17:47:24 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "iostream"
#include <exception>

class Bureaucrat;

class PresidentialPardonForm {
	private:
		std::string target;
		const int grade_sign; // Grado mínimo requerido para FIRMAR
		const int grade_execute; // Grado mínimo requerido para EJECUTAR 
		
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string &subject);
  		PresidentialPardonForm(const PresidentialPardonForm& other);
    	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();
};

#endif