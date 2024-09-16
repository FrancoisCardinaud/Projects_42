/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:24:35 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/16 21:04:13 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : name("Default"), grade(LOWEST_GRADE) {
    std::cout << "[Bureaucrat] default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {
    std::cout << "[Bureaucrat] copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
    if (grade < HIGHEST_GRADE)
        throw(GradeTooHighException());
    if (grade > LOWEST_GRADE)
        throw(GradeTooLowException());
    this->grade = grade;
    std::cout << "[Bureaucrat] constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        const_cast<std::string&>(this->name) = other.name;
        this->grade = other.grade;
    }
    std::cout << "[Bureaucrat] copy assignment operator called" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat(void) {
    std::cout << "[Bureaucrat] destructor called" << std::endl;
}

const std::string& Bureaucrat::getName(void) const {
    return this->name;
}

int Bureaucrat::getGrade(void) const {
    return this->grade;
}

void Bureaucrat::setGrade(int grade) {
    if (grade < HIGHEST_GRADE)
        throw(GradeTooHighException());
    if (grade > LOWEST_GRADE)
        throw(GradeTooLowException());
    this->grade = grade;
}

void Bureaucrat::incrementGrade(void) {
    if (this->grade - 1 < HIGHEST_GRADE)
        throw(GradeTooHighException());
    this->grade--;
}

void Bureaucrat::decrementGrade(void) {
    if (this->grade + 1 > LOWEST_GRADE)
        throw(GradeTooLowException());
    this->grade++;
}

void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat exception: grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat exception: grade too low!";
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat &bureaucrat) {
    stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return stream;
}
