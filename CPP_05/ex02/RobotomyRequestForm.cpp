/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:34:18 by lginer-m          #+#    #+#             */
/*   Updated: 2026/03/02 16:09:52 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy Request", 72, 45), target("Default")
{
	std::cout << "Default constructor of RobotomyRequestForm called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &subject): AForm("Robotomy Request", 72, 45), target(subject)
{
	std::cout << "Parametrized constructor of RobotomyRequestForm called\n";
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), target(other.target){
	std::cout << "Copy constructor of RobotomyRequestForm called\n";
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "Copy assignment operator of RobotomyRequestForm called\n";
	if(this != &other)
		AForm::operator=(other);
	return(*this);
}
RobotomyRequestForm:: ~RobotomyRequestForm()
{
	std::cout << "Destructor of RobotomyRequestForm called\n";
}
void RobotomyRequestForm::executeAction() const
{
	std::cout << "DRRRRRRRRRRRRRRRRRRR..\n";
	srand(time(NULL));
	int num = rand() % 2;
	if(!num)
		std::cout << target << " failed in the process of robotomy...\n";
	else
		std::cout << target << " has been robotomized successfully!\n";
}
