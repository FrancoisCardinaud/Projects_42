/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:58:43 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/16 21:02:22 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    // Creating Bureaucrats
    Bureaucrat hermano("Hermano", LOWEST_GRADE);
    Bureaucrat ebil("Ebil", HIGHEST_GRADE);

    std::cout << std::endl;

    // Creating Forms
    ShrubberyCreationForm scf("Ebil");
    PresidentialPardonForm ppf("Ebil");
    RobotomyRequestForm rrf("Ebil");

    std::cout << std::endl;

    // Executing and signing the ShrubberyCreationForm
    try {
        ebil.executeForm(scf); // Trying to execute before signing
    } catch (std::exception& e) {
        std::cerr << ebil.getName() << " couldn't execute " << scf.getName() << " because: " << e.what() << std::endl;
    }

    try {
        scf.beSigned(ebil);
        std::cout << ebil.getName() << " signed " << scf.getName() << std::endl;
        ebil.executeForm(scf);
        std::cout << ebil.getName() << " executed " << scf.getName() << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Executing and signing the PresidentialPardonForm
    try {
        ebil.executeForm(ppf); // Trying to execute before signing
    } catch (std::exception& e) {
        std::cerr << ebil.getName() << " couldn't execute " << ppf.getName() << " because: " << e.what() << std::endl;
    }

    try {
        ppf.beSigned(ebil);
        std::cout << ebil.getName() << " signed " << ppf.getName() << std::endl;
        ebil.executeForm(ppf);
        std::cout << ebil.getName() << " executed " << ppf.getName() << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Executing and signing the RobotomyRequestForm
    try {
        ebil.executeForm(rrf); // Trying to execute before signing
    } catch (std::exception& e) {
        std::cerr << ebil.getName() << " couldn't execute " << rrf.getName() << " because: " << e.what() << std::endl;
    }

    try {
        rrf.beSigned(ebil);
        std::cout << ebil.getName() << " signed " << rrf.getName() << std::endl;
        ebil.executeForm(rrf);
        std::cout << ebil.getName() << " executed " << rrf.getName() << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Hermano trying to execute a form without sufficient grade
    try {
        hermano.executeForm(scf);
        std::cout << hermano.getName() << " executed " << scf.getName() << std::endl;
   	} catch (std::exception& e) {
        std::cerr << hermano.getName() << " couldn't execute " << scf.getName() << " because: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    return EXIT_SUCCESS;
}