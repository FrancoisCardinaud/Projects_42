/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:25:40 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/18 15:37:54 by fcardina         ###   ########.fr       */
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
    Bureaucrat hermano("Hermano", LOWEST_GRADE);
    Bureaucrat ebil("Ebil", HIGHEST_GRADE);
    Intern someRandomIntern;
    
    std::cout << std::endl;
    
    // Create forms using the Intern
    AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Ebil");
    AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Ebil");
    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Ebil");

    std::cout << std::endl;

    // Execute ShrubberyCreationForm
    try {
        ebil.executeForm(*scf);
    } catch (const std::exception &e) {
        std::cerr << scf->getName() << " couldn't be executed by " << ebil.getName() << " because " << e.what() << std::endl;
    }

    scf->beSigned(ebil);
    try {
        ebil.executeForm(*scf);
        std::cout << ebil.getName() << " executed " << scf->getName() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << scf->getName() << " couldn't be executed by " << ebil.getName() << " because " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Execute PresidentialPardonForm
    try {
        ebil.executeForm(*ppf);
    } catch (const std::exception &e) {
        std::cerr << ppf->getName() << " couldn't be executed by " << ebil.getName() << " because " << e.what() << std::endl;
    }

    ppf->beSigned(ebil);
    try {
        ebil.executeForm(*ppf);
        std::cout << ebil.getName() << " executed " << ppf->getName() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << ppf->getName() << " couldn't be executed by " << ebil.getName() << " because " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Execute RobotomyRequestForm
    try {
        ebil.executeForm(*rrf);
    } catch (const std::exception &e) {
        std::cerr << rrf->getName() << " couldn't be executed by " << ebil.getName() << " because " << e.what() << std::endl;
    }

    rrf->beSigned(ebil);
    try {
        ebil.executeForm(*rrf);
        std::cout << ebil.getName() << " executed " << rrf->getName() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << rrf->getName() << " couldn't be executed by " << ebil.getName() << " because " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Hermano trying to execute a form
    try {
        hermano.executeForm(*scf);
        std::cout << hermano.getName() << " executed " << scf->getName() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << hermano.getName() << " couldn't execute " << scf->getName() << " because " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Clean up dynamically allocated memory
    delete scf;
    delete ppf;
    delete rrf;

    return EXIT_SUCCESS;
}
