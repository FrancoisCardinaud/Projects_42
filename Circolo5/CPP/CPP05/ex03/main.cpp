/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:25:40 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/27 16:20:34 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    Bureaucrat joe("Joe", LOWEST_GRADE);
    Bureaucrat jack("Jack", HIGHEST_GRADE);
    Intern someRandomIntern;
    
    std::cout << std::endl;
    
    // Create forms using the Intern
    AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Jack");
    AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Jack");
    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Jack");

    std::cout << std::endl;

    // Execute ShrubberyCreationForm
    try {
        jack.executeForm(*scf);
    } catch (const std::exception &e) {
        std::cerr << scf->getName() << " couldn't be executed by " << jack.getName() << " because " << e.what() << std::endl;
    }

    scf->beSigned(jack);
    try {
        jack.executeForm(*scf);
        std::cout << jack.getName() << " executed " << scf->getName() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << scf->getName() << " couldn't be executed by " << jack.getName() << " because " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Execute PresidentialPardonForm
    try {
        jack.executeForm(*ppf);
    } catch (const std::exception &e) {
        std::cerr << ppf->getName() << " couldn't be executed by " << jack.getName() << " because " << e.what() << std::endl;
    }

    ppf->beSigned(jack);
    try {
        jack.executeForm(*ppf);
        std::cout << jack.getName() << " executed " << ppf->getName() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << ppf->getName() << " couldn't be executed by " << jack.getName() << " because " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Execute RobotomyRequestForm
    try {
        jack.executeForm(*rrf);
    } catch (const std::exception &e) {
        std::cerr << rrf->getName() << " couldn't be executed by " << jack.getName() << " because " << e.what() << std::endl;
    }

    rrf->beSigned(jack);
    try {
        jack.executeForm(*rrf);
        std::cout << jack.getName() << " executed " << rrf->getName() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << rrf->getName() << " couldn't be executed by " << jack.getName() << " because " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Joe trying to execute a form
    try {
        joe.executeForm(*scf);
        std::cout << joe.getName() << " executed " << scf->getName() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << joe.getName() << " couldn't execute " << scf->getName() << " because " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Clean up dynamically allocated memory
    delete scf;
    delete ppf;
    delete rrf;

    return EXIT_SUCCESS;
}
