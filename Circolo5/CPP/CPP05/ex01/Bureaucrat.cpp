/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:26:20 by fcardina          #+#    #+#             */
/*   Updated: 2024/10/09 15:26:21 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150) {
    std::cout << "Bureaucrat default constructor called " << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
    std::cout << "Bureaucrat copy constructor called for " << _name << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    validateGrade(grade);
    _grade = grade;
    std::cout << "Bureaucrat " << _name << " created with grade " << _grade << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        this->_grade = other._grade;
    }
    std::cout << "Copy assignment operator called for Bureaucrat " << _name << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat(void) {
    std::cout << "Bureaucrat destructor called " << std::endl;
}

const std::string &Bureaucrat::getName(void) const {
    return (_name);
}

int Bureaucrat::getGrade(void) const {
    return (_grade);
}

void Bureaucrat::incrementGrade(void) {
    validateGrade(_grade - 1);
    _grade--;
}

void Bureaucrat::decrementGrade(void) {
    validateGrade(_grade + 1);
    _grade++;
}

void Bureaucrat::validateGrade(int grade) const {
    if (grade < HIGHEST_GRADE)
        throw GradeTooHighException();
    if (grade > LOWEST_GRADE)
        throw GradeTooLowException();
}

void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << _name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
    return "Bureaucrat exception: Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
    return "Bureaucrat exception: Grade too low!";
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &bureaucrat) {
    stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return stream;
}
