/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:23:49 by lauragm           #+#    #+#             */
/*   Updated: 2026/03/11 18:17:16 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): name("Default"), isSigned(false), gradeSign(140), gradeExecute(140){
	std::cout << "Default constructor of AForm called\n";
}
AForm::AForm(const std::string &nick, const int sign, const int exe) : name(nick), isSigned(false), gradeSign(sign), gradeExecute(exe){
	if (gradeSign < 1 || gradeExecute < 1)
    	throw AForm::GradeTooHighException();
	if (gradeSign > 150 || gradeExecute > 150)
    	throw AForm::GradeTooLowException();
	std::cout << "Parametrized constructor of AForm called\n";
}
AForm::AForm(const AForm& other): name(other.name), isSigned(other.isSigned), gradeSign(other.gradeSign), gradeExecute(other.gradeExecute) {
	std::cout << "Copy constructor of AForm called\n";
}
AForm& AForm::operator=(const AForm& other)
{
	std::cout << "Copy assignment operator of AForm called\n";
	if(this != &other)
		isSigned = other.isSigned;
	return(*this);
}
AForm:: ~AForm()
{
	std::cout << "Destructor of AForm called\n";
}
std::string AForm::getName() const
{
	return(name);
}
bool AForm::getSigned() const
{
	return(isSigned);
}
int AForm::getGradeSign() const
{
	return(gradeSign);
}
int AForm::getGradeExecute() const
{
	return(gradeExecute);
}
void AForm::beSigned(const Bureaucrat &obj)
{
	if(isSigned == true)
		throw GradeIsAlreadySigned();
	if(obj.getGrade() <= gradeSign)
		isSigned = true;
	else
		throw GradeTooLowException();
}
std::ostream &operator<<(std::ostream& out, AForm const& obj)
{
	out << obj.getName();
	if(obj.getSigned() == true)
		out << " signed!" << std::endl;
	else
		out << " not signed!" << std::endl;
	
	out << "Sign Grade " << obj.getGradeSign() << std::endl;
	out << "Execute Grade " << obj.getGradeExecute() << std::endl;
    return(out);
}

void AForm::execute(Bureaucrat const &executor) const
{
	if(getSigned() == true)
	{
		std::cout << getName() << " has signed!\n";
		if(executor.getGrade() <= getGradeExecute())
			std::cout << executor.getName() << " has the great grade for execute" << std::endl;
		else
			throw GradeNotExecute();
	}
	else
		throw GradeNotSigned(); 
	executeAction();
	// Las excepciones se controlan en Bureaucrat
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Oops. Grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return("Oops. Grade isn't enought!");
}

const char* AForm::GradeIsAlreadySigned::what() const throw()
{
	return("has already signed!");
}

const char* AForm::GradeNotSigned::what() const throw()
{
	return("can't be signed");
}

const char* AForm::GradeNotExecute::what() const throw()
{
	return("doesn't have enought grade for execute");
}

