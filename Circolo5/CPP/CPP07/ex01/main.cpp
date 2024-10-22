/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:29:03 by fcardina          #+#    #+#             */
/*   Updated: 2024/10/22 04:44:30 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

#define ARRAY_LEN 3

int main(void)
{
    // Test with an integer array
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

    // Additional test with a float array
    float float_array[ARRAY_LEN] = {1.1f, 2.2f, 3.3f};
    
    std::cout << "Float array before increment:" << std::endl;
    ::iter(float_array, ARRAY_LEN, &::print_element);
    
    ::iter(float_array, ARRAY_LEN, &::increment);

    std::cout << "Float array after increment:" << std::endl;
    ::iter(float_array, ARRAY_LEN, &::print_element);

    // Additional test with a double array
    double double_array[ARRAY_LEN] = {10.5, 20.75, 30.125};

    std::cout << "Double array:" << std::endl;
    ::iter(double_array, ARRAY_LEN, &::print_element);

    // Test with a char array
    char char_array[ARRAY_LEN] = {'A', 'B', 'C'};

    std::cout << "Char array before increment:" << std::endl;
    ::iter(char_array, ARRAY_LEN, &::print_element);
    
    ::iter(char_array, ARRAY_LEN, &::increment);

    std::cout << "Char array after increment:" << std::endl;
    ::iter(char_array, ARRAY_LEN, &::print_element);

    // Edge case: Empty array
    int empty_array[0];

    std::cout << "Empty array test:" << std::endl;
    ::iter(empty_array, 0, &::print_element);

    return EXIT_SUCCESS;
}