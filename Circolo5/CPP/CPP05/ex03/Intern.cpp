/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:25:35 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/24 19:15:48 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

// Constructor
Intern::Intern(void) {
    #ifdef LOGS
        std::cout << "[Intern] Default Constructor called" << std::endl;
    #endif
}

// Copy Constructor
Intern::Intern(const Intern &copy) {
    *this = copy;
    #ifdef LOGS
        std::cout << "[Intern] Copy Constructor called" << std::endl;
    #endif
}

// Destructor
Intern::~Intern() {
    #ifdef LOGS
        std::cout << "[Intern] Destructor called" << std::endl;
    #endif
}

// Copy Assignment Operator
Intern& Intern::operator=(const Intern &assign) {
    #ifdef LOGS
        std::cout << "[Intern] Copy Assignment Operator called" << std::endl;
    #endif
    (void)assign; // No member variables to assign, so just returning *this
    return *this;
}

// Helper Functions for Creating Specific Forms
static AForm *createShrubberyForm(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

static AForm *createRobotomyForm(const std::string &target) {
    return new RobotomyRequestForm(target);
}

static AForm *createPresidentialPardonForm(const std::string &target) {
    return new PresidentialPardonForm(target);
}

// Make Form Function
AForm *Intern::makeForm(const std::string &name, const std::string &target) {
    // Array of known form names
    const std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    // Array of function pointers to form creation functions
    typedef AForm *(*FormConstructorPtr)(const std::string &);
    FormConstructorPtr formConstructors[] = {
        createShrubberyForm,
        createRobotomyForm,
        createPresidentialPardonForm
    };

    // Loop through formNames to find a match and create the corresponding form
    for (size_t i = 0; i < 3; ++i) {
        if (name == formNames[i]) {
            std::cout << "Intern creates " << formNames[i] << std::endl;
            return formConstructors[i](target); // Return the newly created form
        }
    }

    // If no matching form name was found
    std::cerr << "Intern couldn't create the form: " << name << std::endl;
    return NULL;
}
