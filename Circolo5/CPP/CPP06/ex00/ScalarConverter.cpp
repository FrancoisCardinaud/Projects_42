/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:26:19 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/18 16:12:08 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>
#include "ScalarConverter.hpp"

// Utility functions for string to number conversion
static int stringToInt(const std::string& str)
{
    int num;
    std::stringstream ss(str);
    ss >> num;
    return num;
}

static float stringToFloat(const std::string& str)
{
    float num;
    std::stringstream ss(str);
    ss >> num;
    return num;
}

static double stringToDouble(const std::string& str)
{
    double num;
    std::stringstream ss(str);
    ss >> num;
    return num;
}

// Enum for scalar literal types
enum LiteralType {
    InvalidType,
    PseudoLiteral,
    CharType,
    IntType,
    FloatType,
    DoubleType
};

// Helper function to identify char literals
static bool isChar(const std::string& literal)
{
    return literal.length() == 1 && !isdigit(literal[0]);
}

// Helper function to identify integer literals
static bool isInt(const std::string& literal)
{
    size_t i = (literal[0] == '-') ? 1 : 0;
    for (; i < literal.length(); i++) {
        if (!isdigit(literal[i])) return false;
    }
    return true;
}

// Helper function to identify float literals
static bool isFloat(const std::string& literal)
{
    if (literal == "-inff" || literal == "+inff" || literal == "nanf") return true;
    if (literal.back() != 'f') return false;

    bool foundPoint = false;
    for (size_t i = 0; i < literal.length() - 1; i++) {
        if (literal[i] == '.') {
            if (foundPoint) return false;
            foundPoint = true;
        } else if (!isdigit(literal[i])) {
            return false;
        }
    }
    return true;
}

// Helper function to identify double literals
static bool isDouble(const std::string& literal)
{
    if (literal == "-inf" || literal == "+inf" || literal == "nan") return true;

    bool foundPoint = false;
    for (size_t i = 0; i < literal.length(); i++) {
        if (literal[i] == '.') {
            if (foundPoint) return false;
            foundPoint = true;
        } else if (!isdigit(literal[i])) {
            return false;
        }
    }
    return true;
}

// Function to get the type of literal
static LiteralType getLiteralType(const std::string& literal)
{
    if (isChar(literal)) return CharType;
    if (isInt(literal)) return IntType;
    if (isFloat(literal)) return FloatType;
    if (isDouble(literal)) return DoubleType;
    return InvalidType;
}

// Display conversions for char literals
static void displayChar(char ch)
{
    std::cout << "char: '" << ch << "'\n";
    std::cout << "int: " << static_cast<int>(ch) << "\n";
    std::cout << "float: " << static_cast<float>(ch) << ".0f\n";
    std::cout << "double: " << static_cast<double>(ch) << ".0\n";
}

// Display conversions for integer literals
static void displayInt(int nbr)
{
    if (isprint(nbr))
        std::cout << "char: '" << static_cast<char>(nbr) << "'\n";
    else
        std::cout << "char: Non displayable\n";
    std::cout << "int: " << nbr << "\n";
    std::cout << "float: " << static_cast<float>(nbr) << ".0f\n";
    std::cout << "double: " << static_cast<double>(nbr) << ".0\n";
}

// Display conversions for float literals
static void displayFloat(float nbr)
{
    if (isprint(nbr))
        std::cout << "char: '" << static_cast<char>(nbr) << "'\n";
    else
        std::cout << "char: Non displayable\n";
    std::cout << "int: " << static_cast<int>(nbr) << "\n";
    std::cout << "float: " << nbr << "f\n";
    std::cout << "double: " << static_cast<double>(nbr) << "\n";
}

// Display conversions for double literals
static void displayDouble(double nbr)
{
    if (isprint(nbr))
        std::cout << "char: '" << static_cast<char>(nbr) << "'\n";
    else
        std::cout << "char: Non displayable\n";
    std::cout << "int: " << static_cast<int>(nbr) << "\n";
    std::cout << "float: " << static_cast<float>(nbr) << "f\n";
    std::cout << "double: " << nbr << "\n";
}

// Display conversions for pseudo-literals (like NaN, inf)
static void displayPseudoLiteral(const std::string& pseudo_literal)
{
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: " << pseudo_literal << "\n";
    std::cout << "double: " << pseudo_literal.substr(0, pseudo_literal.size() - 1) << "\n";
}

// Convert the literal based on its type
void ScalarConverter::convert(const std::string& literal)
{
    LiteralType type = getLiteralType(literal);

    switch (type) {
        case CharType:
            displayChar(literal[0]);
            break;
        case IntType:
            displayInt(stringToInt(literal));
            break;
        case FloatType:
            if (literal == "-inff" || literal == "+inff" || literal == "nanf")
                displayPseudoLiteral(literal);
            else
                displayFloat(stringToFloat(literal));
            break;
        case DoubleType:
            if (literal == "-inf" || literal == "+inf" || literal == "nan")
                displayPseudoLiteral(literal);
            else
                displayDouble(stringToDouble(literal));
            break;
        default:
            std::cout << "Invalid input.\n";
            break;
    }
}
