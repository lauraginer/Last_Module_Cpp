/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:00:34 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/26 15:35:23 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "iostream"
#include <exception>

class Bureaucrat;

class RobotomyRequestForm {
	private:
		std::string target;
		const int grade_sign; // Grado mínimo requerido para FIRMAR
		const int grade_execute; // Grado mínimo requerido para EJECUTAR 
		
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string &subject);
  		RobotomyRequestForm(const RobotomyRequestForm& other);
    	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();
};

#endif