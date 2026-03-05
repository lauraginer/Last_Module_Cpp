/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:40:34 by lginer-m          #+#    #+#             */
/*   Updated: 2026/03/05 13:33:34 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon", 25, 5), target("Default")
{
	std::cout << "Default constructor of PresidentialPardonForm called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &subject): AForm("Presidential Pardon", 25, 5), target(subject)
{
	std::cout << "Parametrized constructor of PresidentialPardonForm called\n";
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other), target(other.target){
	std::cout << "Copy constructor of PresidentialPardonForm called\n";
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << "Copy assignment operator of PresidentialPardonForm called\n";
	if(this != &other)
		AForm::operator=(other);
	return(*this);
}
PresidentialPardonForm:: ~PresidentialPardonForm()
{
	std::cout << "Destructor of PresidentialPardonForm called\n";
}
void PresidentialPardonForm::executeAction() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox\n";
}
