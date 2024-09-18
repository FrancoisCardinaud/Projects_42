/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:29:03 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/18 17:04:44 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

#define ARRAY_LEN 3

int main(void)
{
	int int_array[ARRAY_LEN] = {0, 1, 2};

	std::cout << "BEFORE increment()" << std::endl;
	::iter(int_array, ARRAY_LEN, &::print_element);

	::iter(int_array, ARRAY_LEN, &::increment);

	std::cout << "AFTER increment()" << std::endl;
	::iter(int_array, ARRAY_LEN, &::print_element);

	// Test with a string array
	std::string str_array[ARRAY_LEN] = {"hello", "world", "!"};

	std::cout << "String array:" << std::endl;
	::iter(str_array, ARRAY_LEN, &::print_element);

	return EXIT_SUCCESS;
}
