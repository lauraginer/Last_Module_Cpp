/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:23:49 by lauragm           #+#    #+#             */
/*   Updated: 2026/02/26 18:53:05 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): name("Default"), is_signed(false), grade_sign(140), grade_execute(140){
	std::cout << "Default constructor of AForm called\n";
}
AForm::AForm(const std::string &nick, const int sign, const int exe) : name(nick), is_signed(false), grade_sign(sign), grade_execute(exe){
	if (grade_sign < 1 || grade_execute < 1)
    	throw AForm::GradeTooHighException();
	if (grade_sign > 150 || grade_execute > 150)
    	throw AForm::GradeTooLowException();
	std::cout << "Parametrized constructor of AForm called\n";
}
AForm::AForm(const AForm& other): name(other.name), is_signed(other.is_signed), grade_sign(other.grade_sign), grade_execute(other.grade_execute) {
	std::cout << "Copy constructor of AForm called\n";
}
AForm& AForm::operator=(const AForm& other)
{
	std::cout << "Copy assignment operator of AForm called\n";
	if(this != &other)
		is_signed = other.is_signed;
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
	return(is_signed);
}
int AForm::getGradeSign() const
{
	return(grade_sign);
}
int AForm::getGradeExecute() const
{
	return(grade_execute);
}
void AForm::beSigned(const Bureaucrat &obj)
{
	if(is_signed == true)
		throw GradeIsAlreadySigned();
	if(obj.getGrade() <= grade_sign)
		is_signed = true;
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
			throw GradeNotExecute(); //hay que controlar la excepcion (el bloque este de cach con un mensaje personalizao)
	}
	else
		throw GradeNotSigned(); //hay que controlar la excepcion de mierda de los cojones junto a la anterior
	
	//executeAction(); hay que implementar esta funcion en las demas clases para que hagan su accion especifica
}

