/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:29:47 by fcardina          #+#    #+#             */
/*   Updated: 2024/10/23 20:41:01 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main(void)
{
	try {
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.printStorage();

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		// Test exceeding storage capacity
		try {
			sp.addNumber(42);
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}

		// Test span calculation with insufficient elements
		Span sp1 = Span(1);
		sp1.addNumber(1);
		try {
			std::cout << sp1.shortestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}

		// Test adding random numbers
		Span sp2 = Span(100);
		sp2.addRandomNumbers(100);
		sp2.printStorage();
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

		// Test with duplicates
		Span sp3 = Span(5);
		sp3.addNumber(10);
		sp3.addNumber(10);
		sp3.addNumber(10);
		sp3.addNumber(10);
		sp3.addNumber(10);
		sp3.printStorage();
		std::cout << "Shortest span with duplicates: " << sp3.shortestSpan() << std::endl;
		std::cout << "Longest span with duplicates: " << sp3.longestSpan() << std::endl;

		// Test with edge values
		Span sp4 = Span(2);
		sp4.addNumber(INT_MIN);
		sp4.addNumber(INT_MAX);
		sp4.printStorage();
		std::cout << "Shortest span with edge values: " << sp4.shortestSpan() << std::endl;
		std::cout << "Longest span with edge values: " << sp4.longestSpan() << std::endl;

	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
