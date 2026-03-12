/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:56:30 by lginer-m          #+#    #+#             */
/*   Updated: 2026/03/11 19:39:28 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Default constructor of Intern called\n";
}
Intern::Intern(const Intern& other){
	std::cout << "Copy constructor of Intern called\n";
	(void)other;
}
Intern& Intern::operator=(const Intern& other)
{
	std::cout << "Copy assignment operator of Intern called\n";
	if(this != &other)
	{
		(void)other;
	}
	return(*this);
}
Intern:: ~Intern()
{
	std::cout << "Destructor of Intern called\n";
}
AForm* Intern::makeForm(std::string form, std::string target)
{
	std::string valid_names[3] = { "presidential pardon", 
	"robotomy request", "shrubbery creation"};
	int i = 0;
	while(i < 3)
	{
		if(valid_names[i] == form)
			break;
		i++;
	}
	switch(i)
	{
		case 0:
			std::cout << "Intern creates " << form << std::endl;
			return (new PresidentialPardonForm(target));
		case 1:
			std::cout << "Intern creates " << form << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern creates " << form << std::endl;
			return(new ShrubberyCreationForm(target));
		default:
			throw Intern::FormDoesNotExist();
	}
}
const char* Intern::FormDoesNotExist::what() const throw()
{
	return("Unfortunately, Form doesn't exit in files");
}