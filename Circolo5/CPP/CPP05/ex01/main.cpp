/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:16:42 by fcardina          #+#    #+#             */
/*   Updated: 2024/10/10 15:16:44 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    std::cout << "FORM CREATION TESTS" << std::endl;
    {
        Form contract("Contract", 42, 42);
        Form copy_of_contract(contract); // Copy Constructor
        Form another_form = copy_of_contract; // Copy Assignment

        // Testing output
        std::cout << "Form contract:\n" << contract << std::endl;
        std::cout << "Form copy_of_contract:\n" << copy_of_contract << std::endl;
        std::cout << "Form another_form:\n" << another_form << std::endl;
    }

    std::cout << std::endl;

    {
        std::cout << "TEST CASE: LOW GRADE FOR SIGNING" << std::endl;
        try
        {
            Form low_grade_form("LowGradeForm", LOWEST_GRADE + 1, LOWEST_GRADE - 1);
            std::cout << low_grade_form << std::endl;
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }

        std::cout << std::endl;

        std::cout << "TEST CASE: HIGH GRADE FOR SIGNING" << std::endl;
        try
        {
            Form high_grade_form("HighGradeForm", HIGHEST_GRADE - 1, 42);
            std::cout << high_grade_form << std::endl;
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }

        std::cout << std::endl;

        std::cout << "TEST CASE: BUREAUCRAT CAN SIGN FORMS" << std::endl;
        try
        {
            Bureaucrat top_bureaucrat("Top Bureaucrat", HIGHEST_GRADE);
            std::cout << top_bureaucrat << std::endl;

            Form top_form1("TopForm1", HIGHEST_GRADE, 2);
            Form top_form2("TopForm2", 90, LOWEST_GRADE);
            std::cout << top_form1 << std::endl;
            std::cout << top_form2 << std::endl;

            top_bureaucrat.signForm(top_form1);
            top_bureaucrat.signForm(top_form2);
            top_bureaucrat.signForm(top_form1);  // Form already signed

            std::cout << top_form1 << std::endl;
            std::cout << top_form2 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }

        std::cout << std::endl;

        std::cout << "TEST CASE: BUREAUCRAT CANNOT SIGN FORMS" << std::endl;
        try
        {
            Bureaucrat low_bureaucrat("Low Bureaucrat", LOWEST_GRADE);
            std::cout << low_bureaucrat << std::endl;

            Form challenging_form("ChallengingForm", HIGHEST_GRADE, 2);
            std::cout << challenging_form << std::endl;

            // Attempt to sign - exception will be thrown
            low_bureaucrat.signForm(challenging_form);
            std::cout << challenging_form << std::endl;
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    return EXIT_SUCCESS;
}
