/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:09:27 by fcardina          #+#    #+#             */
/*   Updated: 2024/10/17 18:18:38 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>

using std::cerr;

int	main(int argc, char **argv)
{
    if (argc != 2 || !argv[1][0])
    {
        cerr << "Usage: ./convert <literal>" << "\n";
        return EXIT_FAILURE;
    }
    ScalarConverter::convert(argv[1]);
    return EXIT_SUCCESS;
}

/*
using std::cout;
using std::cerr;

void testLiteral(const std::string &literal)
{
    cout << "\nTesting literal: \"" << literal << "\"\n";
    ScalarConverter::convert(literal);
    cout << "------------------------------\n";
}

int	main(void)
{
    // Char Type Tests
    testLiteral("\n");    // Non-printable character
    testLiteral("a");     // Single printable char
    testLiteral("Z");     // Another char
    testLiteral("1");     // Invalid char input (digit)
    testLiteral("ab");    // Invalid multiple char input

    // Int Type Tests
    testLiteral("2147483647");    // Largest 32-bit int
    testLiteral("-2147483648");   // Smallest 32-bit int
    testLiteral("2147483648");    // Overflow
    testLiteral("-2147483649");   // Underflow

    // Float Type Tests
    testLiteral("42.42f");    // Valid float
    testLiteral("-42.42f");   // Negative float
    testLiteral(".42f");      // Edge case - missing integer part
    testLiteral("42.f");      // Edge case - missing decimal part
    testLiteral(".0f");       // Edge case float
    testLiteral("42.42ff");   // Invalid float
    testLiteral("inff");      // Invalid pseudo-literal

    // Double Type Tests
    testLiteral("42.42");     // Valid double
    testLiteral("-42.42");    // Negative double
    testLiteral(".42");       // Edge case - missing integer part
    testLiteral("42.");       // Edge case - missing decimal part
    testLiteral("42.42dd");   // Invalid double

    // Pseudo-literal Tests
    testLiteral("nan");       // Pseudo-literal nan (double)
    testLiteral("nanf");      // Pseudo-literal nanf (float)
    testLiteral("+inf");      // Positive infinity (double)
    testLiteral("+inff");     // Positive infinity (float)
    testLiteral("-inf");      // Negative infinity (double)
    testLiteral("-inff");     // Negative infinity (float)
    testLiteral("inff");      // Invalid pseudo-literal

    // Invalid Inputs
    testLiteral("hello");     // Completely non-numeric input
    testLiteral("42abc");     // Mixed input
    testLiteral("abc42");     // Mixed input
    testLiteral("42..0");     // Invalid format with multiple dots
    testLiteral("- 42");      // Invalid format
    testLiteral("+-42");      // Invalid format

    // Boundary and Special Cases
    testLiteral("3.402823e+38f");    // Max float value
    testLiteral("1.175494e-38f");    // Min float value
    testLiteral("1.7976931348623157e+308");   // Max double value
    testLiteral("2.2250738585072014e-308");   // Min double value
    testLiteral("1e400");            // Overflow for double
    testLiteral("-1e400");           // Underflow for double

    // Handling leading and trailing spaces (optional based on requirements)
    testLiteral("  42");
    testLiteral("42  ");
    testLiteral("  42  ");

    return EXIT_SUCCESS;
}*/

