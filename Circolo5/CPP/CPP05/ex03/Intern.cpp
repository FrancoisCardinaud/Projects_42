/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:25:35 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 16:29:46 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


using std::cerr;


Intern::Intern(void) {
    #ifdef LOGS
    	std::cout << "[Intern] Default Constructor called" << std::endl;
    #endif
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
    #ifdef LOGS
	    cout << "[Intern] Copy Constructor called" << std::endl;
    #endif
}

Intern::~Intern() {
    #ifdef LOGS
    	std::cout << "[Intern] Destructor called" << std::endl;
    #endif
}

Intern& Intern::operator=(const Intern &assign)
{
    #ifdef LOGS
	    cout << "[Intern] Copy Assignment Operator called" << std::endl;
    #endif
	if (this == &assign)
        return *this;
	return *this;
}

static AForm *newShrubbery(const std::string target) {
	return new ShrubberyCreationForm(target);
}

static AForm *newRobotomy(const std::string target) {
	return new RobotomyRequestForm(target);
}

static AForm *newPresidential(const std::string target) {
	return new PresidentialPardonForm(target);
}

typedef AForm *(*FormConstructorPtr)(const std::string);

AForm *Intern::makeForm(std::string name, std::string target)
{
    AForm *choosen_form = NULL;

    const std::string formnames[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };

    FormConstructorPtr form_constructors[3] = {&newShrubbery, &newRobotomy, &newPresidential};

    for (size_t i = 0; i < 3; i += 1)
    {
        if (name == formnames[i])
        {
            cout << "Intern creates " << name << std::endl;
            choosen_form = form_constructors[i](target);;
            break ;
        }
    }
    if (!choosen_form)
        cerr << "Intern couldn't create " << name << " form" << std::endl;
    return choosen_form;
}