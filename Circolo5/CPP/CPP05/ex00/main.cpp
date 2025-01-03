/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:26:32 by fcardina          #+#    #+#             */
/*   Updated: 2024/10/09 15:26:40 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>

int	main(void)
{
	//shows how a Bureaucrat object is created, copied, and printed. 
	//At the end of the block, the destructors for those objects are 
	//automatically called.
	std::cout << "GENERAL TEST" << std::endl;
	{
		// Constructor
		Bureaucrat a("Jack", 87);
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
		/*Various scenarios where the Bureaucrat class is tested 
		with invalid grades (too high or too low). The exceptions 
		are caught, and error messages are printed, demonstrating 
		how exception handling works.*/
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
			Bureaucrat jack("Jack", 10);

			jack.decrementGrade();
			std::cout << jack << std::endl;
			jack.incrementGrade();
			std::cout << jack << std::endl;
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
