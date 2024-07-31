/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:25:25 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 17:57:58 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"




AForm::AForm(std::string name, std::string target, int grade_to_sign, int grade_to_execute)
: name(name), target(target), is_signed(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	#ifdef LOGS
		std::cout << "[AForm] Parameterized constructor called" << std::endl;
	#endif
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw AForm::GradeTooLowException();
	else if (grade_to_sign < 1 || grade_to_execute < 1)
		throw AForm::GradeTooHighException();
}

AForm::~AForm() {
    #ifdef LOGS
		std::cout << "[AForm] Destructor called" << std::endl;
	#endif
}

AForm::AForm(AForm& other)
: name(other.getName()), target(other.getTarget()), is_signed(other.getSignState()), grade_to_sign(other.getGradeToSign()), grade_to_execute(other.getGradeToExecute()) {
	#ifdef LOGS
		std::cout << "[AForm] Copy Constructor called" << std::endl;
	#endif
}

AForm& AForm::operator=(AForm& original) {
	#ifdef LOGS
		std::cout << "[AForm] Copy Assignment Operator called" << std::endl;
	#endif
	this->is_signed = original.getSignState();
	return *this;
}

const std::string& AForm::getName(void) const {
	return this->name;
}

const std::string& AForm::getTarget(void) const {
	return this->target;
}

int AForm::getGradeToSign(void) const {
	return this->grade_to_sign;
}

int AForm::getGradeToExecute(void) const {
	return this->grade_to_execute;
}

bool AForm::getSignState(void) const {
	return this->is_signed;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
	{
		this->is_signed = true;
		bureaucrat.signForm(this->getName(), this->is_signed);
	}
	else
	{
		bureaucrat.signForm(this->getName(), this->is_signed);
		throw AForm::GradeTooLowException();
	}
}

void AForm::execute(Bureaucrat const& executor) const {
	this->executeSuperClassForm(executor);
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return "AForm exception: grade too high!";
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return "AForm exception: grade too low!";
}

std::ostream &operator<<(std::ostream& stream, AForm& form)
{
	stream << "AForm: " << form.getName() 
		   << "Grade to sign: " << form.getGradeToSign()
		   << "Grade to execute: " << form.getGradeToExecute()
		   << "Signed state:" << form.getSignState();
	return stream;
}
