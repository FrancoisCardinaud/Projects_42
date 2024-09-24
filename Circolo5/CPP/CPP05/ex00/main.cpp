/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+      */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*   Created: 2024/01/02 19:24:28 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/16 20:32:56 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>

int	main(void)
{
	std::cout << "GENERAL" << std::endl;
	{
		// Constructor
		Bureaucrat a("Ana", 87);
		// Copy Constructor
		Bureaucrat b(a);
		// Copy assignment
		Bureaucrat c = b;

		// ostream overload
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "TEST 1" << std::endl;
		try
		{
			// grade too low
			Bureaucrat a("A", LOWEST_GRADE + 1);
			std::cout << a << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "TEST 2" << std::endl;
		try
		{
			// grade too high
			Bureaucrat b("B", HIGHEST_GRADE - 1);
			std::cout << b << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "TEST 3" << std::endl;
		try
		{
			// Increment to a grade higher than HIGHEST_GRADE
			Bureaucrat c("C", HIGHEST_GRADE);

			c.incrementGrade();
			std::cout << c << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "TEST 4" << std::endl;
		try
		{
			// Decrement to a grade lower than LOWEST_GRADE
			Bureaucrat d("D", LOWEST_GRADE);

			d.decrementGrade();
			std::cout << d << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "TEST 5" << std::endl;
		try
		{
			// Acceptable grade changes
			Bureaucrat ebil("EBIL", 10);

			ebil.decrementGrade();
			std::cout << ebil << std::endl;
			ebil.incrementGrade();
			std::cout << ebil << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		
		std::cout << std::endl;
		
		// Additional edge case: Consecutive increments and decrements from mid-range grade
		std::cout << "TEST 6 - Consecutive changes" << std::endl;
		try
		{
			Bureaucrat mid("Mid-Grade", 75);
			for (int i = 0; i < 5; i++) {
				mid.incrementGrade();
				std::cout << mid << std::endl;
			}
			for (int i = 0; i < 5; i++) {
				mid.decrementGrade();
				std::cout << mid << std::endl;
			 }
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (EXIT_SUCCESS);
}
