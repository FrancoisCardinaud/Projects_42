/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:24:40 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/16 21:03:23 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : name("Default"), is_signed(false), grade_to_sign(LOWEST_GRADE), grade_to_execute(LOWEST_GRADE) {
    std::cout << "[Form] default constructor called" << std::endl;
}

Form::Form(const Form &other) : name(other.name), is_signed(other.is_signed), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute) {
    std::cout << "[Form] copy constructor called" << std::endl;
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute) {
    if (grade_to_sign < HIGHEST_GRADE || grade_to_execute < HIGHEST_GRADE)
        throw GradeTooHighException();
    if (grade_to_sign > LOWEST_GRADE || grade_to_execute > LOWEST_GRADE)
        throw GradeTooLowException();
    std::cout << "[Form] constructor called" << std::endl;
}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        const_cast<std::string&>(this->name) = other.name;
        this->is_signed = other.is_signed;
    }
    std::cout << "[Form] copy assignment operator called" << std::endl;
    return *this;
}

Form::~Form(void) {
    std::cout << "[Form] destructor called" << std::endl;
}

const std::string &Form::getName(void) const {
    return this->name;
}

bool Form::getSignState(void) const {
    return this->is_signed;
}

int Form::getGradeToSign(void) const {
    return this->grade_to_sign;
}

int Form::getGradeToExecute(void) const {
    return this->grade_to_execute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->grade_to_sign)
        throw GradeTooLowException();
    this->is_signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form exception: grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form exception: grade too low!";
}

std::ostream &operator<<(std::ostream &stream, Form &form) {
    stream << "Form " << form.getName() << ", signed: " << (form.getSignState() ? "yes" : "no") << ", grade required to sign: " << form.getGradeToSign() << ", grade required to execute: " << form.getGradeToExecute();
    return stream;
}
