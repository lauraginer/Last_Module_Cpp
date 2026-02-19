/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:47:53 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/19 14:08:37 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default"), grade(150){
	std::cout << "Default constructor of Bureaucrat called\n";
}
Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade){
	std::cout << "Copy constructor of Bureaucrat called\n";
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Copy assignment operator of Bureaucrat called\n";
	if(this != &other)
		grade = other.grade; // Recuerda que la variable name es const
	return(*this);
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor of Bureaucrat called\n";
}
std::string Bureaucrat::getName() const
{
	return(name);
}
int Bureaucrat::getGrade() const
{
	return(grade);
}

void Bureaucrat::setGrade(int number)
{
	grade = number;
}

void Bureaucrat::incrementGrade()
{
	if(grade >= 1 && grade <= 150)
		grade--;
	return;
}
void Bureaucrat::decrementGrade()
{
	if(grade >= 1 && grade <= 150)
		grade++;
	return;
}

std::ostream &operator<<(std::ostream& out, Bureaucrat const& obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return(out);
}


