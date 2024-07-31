/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:24:35 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 17:57:58 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


using std::cerr;


Bureaucrat::Bureaucrat(void) {
	std::cout << "[Bureaucrat] default constructor has been called" << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	if (this != &other)
		*this = other;
	std::cout << "[Bureaucrat] <" << this->getName() << "> copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < HIGHEST_GRADE)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > LOWEST_GRADE)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->grade = grade;
	std::cout << "[Bureaucrat] <" << this->getName() << "> constructor called" << std::endl;
};

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &original)
{
	const_cast<std::string&>(this->name) = original.name;
	this->grade = original.grade;
	std::cout << "[Bureaucrat] <" << this->getName() << "> copy assignment operator called" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "[Bureaucrat] <" << this->getName() << "> default destructor has been called" << std::endl;
};

const std::string& Bureaucrat::getName(void) const {
	return this->name;
}

int Bureaucrat::getGrade(void) const {
	return this->grade;
}

void Bureaucrat::setGrade(int grade) {
	if (grade > LOWEST_GRADE)
		throw(Bureaucrat::GradeTooLowException());
	else if (grade < HIGHEST_GRADE)
		throw(Bureaucrat::GradeTooHighException());
	else
		this->grade = grade;
}

void Bureaucrat::incrementGrade(void)
{
	if (grade - 1 < HIGHEST_GRADE)
		throw(Bureaucrat::GradeTooHighException());
	else
		this->grade -= 1;
}

void Bureaucrat::decrementGrade(void)
{
	if (grade + 1 > LOWEST_GRADE)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->grade += 1;
}

void Bureaucrat::signForm(std::string formname, bool is_signed)
{
	if (is_signed)
		std::cout << this->getName() << " signed " << formname << std::endl;
	else
		std::cout << this->getName() << " couldn't sign " << formname
			 << " because the grade was too low and was nervoxhinhu 🥺" << std::endl;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat exception: grade too high!";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat exception: grade too low!";
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat &Bureaucrat)
{
	stream << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
	return stream;
}
