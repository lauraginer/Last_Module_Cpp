/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:34:18 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/26 15:39:40 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): target("Default"), grade_sign(72), grade_execute(45){
	std::cout << "Default constructor of RobotomyRequestForm called\n";
}
RobotomyRequestForm::RobotomyRequestForm(std::string &subject) : target(subject), grade_sign(72), grade_execute(45)
{
	std::cout << "Parametrized constructor of RobotomyRequestForm called\n";
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
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): target(other.target), grade_sign(other.grade_sign), grade_execute(other.grade_execute) {
	std::cout << "Copy constructor of RobotomyRequestForm called\n";
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "Copy assignment operator of RobotomyRequestForm called\n";
	if(this != &other)
		target = other.target;
	return(*this);
}
RobotomyRequestForm:: ~RobotomyRequestForm()
{
	std::cout << "Destructor of RobotomyRequestForm called\n";
}

//Hace unos ruidos de taladro y luego informa de que <target> ha sido robotomizado con éxito el 50% de las veces.
//En el resto de casos, informa de que la robotomía ha fallado.