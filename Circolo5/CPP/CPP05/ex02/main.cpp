/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:58:43 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/27 16:20:34 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    // Creating Bureaucrats
    Bureaucrat joe("Joe", LOWEST_GRADE);
    Bureaucrat jack("Jack", HIGHEST_GRADE);

    std::cout << std::endl;

    // Creating Forms
    ShrubberyCreationForm scf("Jack");
    PresidentialPardonForm ppf("Jack");
    RobotomyRequestForm rrf("Jack");

    std::cout << std::endl;

    // Executing and signing the ShrubberyCreationForm
    try {
        jack.executeForm(scf); // Trying to execute before signing
    } catch (std::exception& e) {
        std::cerr << jack.getName() << " couldn't execute " << scf.getName() << " because: " << e.what() << std::endl;
    }

    try {
        scf.beSigned(jack);
        jack.executeForm(scf);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Executing and signing the PresidentialPardonForm
    try {
        jack.executeForm(ppf); // Trying to execute before signing
    } catch (std::exception& e) {
        std::cerr << jack.getName() << " couldn't execute " << ppf.getName() << " because: " << e.what() << std::endl;
    }

    try {
        ppf.beSigned(jack);
        jack.executeForm(ppf);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Executing and signing the RobotomyRequestForm
    try {
        jack.executeForm(rrf); // Trying to execute before signing
    } catch (std::exception& e) {
        std::cerr << jack.getName() << " couldn't execute " << rrf.getName() << " because: " << e.what() << std::endl;
    }

    try {
        rrf.beSigned(jack);
        jack.executeForm(rrf);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Joe trying to execute a form without sufficient grade
    try {
        joe.executeForm(scf);
   	} catch (std::exception& e) {
        std::cerr << joe.getName() << " couldn't execute " << scf.getName() << " because: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    return EXIT_SUCCESS;
}
