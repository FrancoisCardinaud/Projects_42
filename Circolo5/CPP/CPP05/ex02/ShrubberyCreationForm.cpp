/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:47:47 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/16 20:57:57 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", target, 145, 137) 
{
    #ifdef LOGS
        std::cout << "[ShrubberyCreationForm] Parameterized Constructor called" << std::endl;
    #endif
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
    : AForm(copy) 
{
    #ifdef LOGS
        std::cout << "[ShrubberyCreationForm] Copy Constructor called" << std::endl;
    #endif
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    #ifdef LOGS
        std::cout << "[ShrubberyCreationForm] Destructor called" << std::endl;
    #endif
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign) {
    if (this != &assign) {
        AForm::operator=(assign);
    }
    #ifdef LOGS
        std::cout << "[ShrubberyCreationForm] Copy Assignment Operator called" << std::endl;
    #endif
    return *this;
}

void ShrubberyCreationForm::executeSuperClassForm(Bureaucrat const& executor) const
{
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw Bureaucrat::GradeTooLowException();
    }
    
    std::ofstream file;
    file.open((this->getTarget() + "_shrubbery").c_str(), std::ofstream::out | std::ofstream::trunc);
    
    if (!file) {
        throw std::ios_base::failure("Failed to open shrubbery file");
    }

    file << "        .\n"
         << "       .;;.   \n"
         << "      ;%;;;'  \n"
         << "      ;%%%;;  \n"
         << "     ;%%%%;;\n"
         << "      ;%;;;\n"
         << "       ;;;\n";

    file.close();
    std::cout << "Shrubbery created." << std::endl;
}
