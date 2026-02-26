/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:40:34 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/26 17:47:54 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): target("Default"), grade_sign(25), grade_execute(5)
{
	std::cout << "Default constructor of PresidentialPardonForm called\n";
}
PresidentialPardonForm::PresidentialPardonForm(std::string &subject) : target(subject), grade_sign(25), grade_execute(5)
{
	std::cout << "Parametrized constructor of PresidentialPardonForm called\n";
	if (grade_sign < 1 || grade_execute < 1)
	{
		std::cout << "Invalid grade. Can't be too hight";
		return ;
	}
    	return ;
	if (grade_sign > 150 || grade_execute > 150)
	{
		std::cout << "Invalid grade. Can't be too low";
		return ;
	}
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): target(other.target), grade_sign(other.grade_sign), grade_execute(other.grade_execute) {
	std::cout << "Copy constructor of PresidentialPardonForm called\n";
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << "Copy assignment operator of PresidentialPardonForm called\n";
	if(this != &other)
		target = other.target;
	return(*this);
}
PresidentialPardonForm:: ~PresidentialPardonForm()
{
	std::cout << "Destructor of PresidentialPardonForm called\n";
}

//Informa de que <target> ha sido indultado por Zaphod Beeblebrox.