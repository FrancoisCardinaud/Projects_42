/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:26:19 by fcardina          #+#    #+#             */
/*   Updated: 2024/10/17 18:19:26 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>
#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>

// Trim leading and trailing spaces from a string
static std::string trim(const std::string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

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
    std::string withoutF = str;
    if (!withoutF.empty() && withoutF[withoutF.length() - 1] == 'f') {
        withoutF = withoutF.substr(0, withoutF.length() - 1);
    }

    std::istringstream iss(withoutF);
    float num;

    iss >> num;

    if (iss.fail() || !iss.eof()) {
        throw std::invalid_argument("Invalid input for conversion to float.");
    }

    if (num > std::numeric_limits<float>::max() || num < -std::numeric_limits<float>::max()) {
        throw std::out_of_range("Float value out of range.");
    }

    return num;
}

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cmath>

// ... (keep other existing code)

static double stringToDouble(const std::string& literal) {
    std::cout << "Debug: Attempting to convert '" << literal << "' to double" << std::endl;
    
    if (literal == "nan" || literal == "+inf" || literal == "-inf") {
        if (literal == "nan") return std::numeric_limits<double>::quiet_NaN();
        if (literal == "+inf") return std::numeric_limits<double>::infinity();
        if (literal == "-inf") return -std::numeric_limits<double>::infinity();
    }

    std::istringstream iss(literal);
    double num;
    
    iss >> num;

    if (iss.fail() || !iss.eof()) {
        std::cout << "Debug: Failed to convert '" << literal << "' to double" << std::endl;
        throw std::invalid_argument("Invalid input for conversion to double.");
    }

    if (std::isinf(num) || std::isnan(num)) {
        std::cout << "Debug: Converted to inf or nan" << std::endl;
        return num;
    }

    if (num > std::numeric_limits<double>::max() || num < -std::numeric_limits<double>::max()) {
        std::cout << "Debug: Value out of range for double" << std::endl;
        throw std::overflow_error("Value out of range for double.");
    }

    std::cout << "Debug: Successfully converted to " << num << std::endl;
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
    return literal.length() == 1 && !isdigit(static_cast<unsigned char>(literal[0]));
}

// Helper function to identify integer literals
static bool isInt(const std::string& literal)
{
    size_t i = (literal[0] == '-') ? 1 : 0;
    for (; i < literal.length(); i++) {
        if (!isdigit(static_cast<unsigned char>(literal[i])))
            return false;
    }
    return true;
}

// Helper function to identify float literals
static bool isFloat(const std::string& literal)
{
    if (literal == "-inff" || literal == "+inff" || literal == "nanf" || literal == "inff") 
        return true;
    
    if (literal.empty() || literal[literal.length() - 1] != 'f') 
        return false;

    std::string withoutF = literal.substr(0, literal.length() - 1);
    std::istringstream iss(withoutF);
    float f;
    iss >> std::noskipws >> f;
    return iss.eof() && !iss.fail();
}

// Helper function to identify double literals
static bool isDouble(const std::string& literal)
{
    if (literal == "-inf" || literal == "+inf" || literal == "nan") return true;

    std::istringstream iss(literal);
    double d;
    iss >> std::noskipws >> d;
    return iss.eof() && !iss.fail();
}

// Function to get the type of literal
static LiteralType getLiteralType(const std::string& literal) {
    if (literal.empty()) return InvalidType;
    if (isChar(literal)) return CharType;
    if (isInt(literal)) return IntType;
    if (isFloat(literal)) return FloatType;
    if (isDouble(literal)) return DoubleType;
    if (literal == "-inf" || literal == "+inf" || literal == "nan" ||
        literal == "-inff" || literal == "+inff" || literal == "nanf" || literal == "inff") 
        return PseudoLiteral;
    return InvalidType;
}

// Display conversions for char literals
static void displayChar(char c)
{
    if (std::isprint(c))
        std::cout << "char: '" << c << "'\n";
    else
        std::cout << "char: Non displayable\n";
    std::cout << "int: " << static_cast<int>(c) << "\n";
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(c) << "f\n";
    std::cout << "double: " << static_cast<double>(c) << "\n";
}

// Display conversions for integer literals
static void displayInt(int nbr)
{
    if (nbr < 0 || nbr > 127)
        std::cout << "char: impossible\n";
    else if (std::isprint(nbr))
        std::cout << "char: '" << static_cast<char>(nbr) << "'\n";
    else
        std::cout << "char: Non displayable\n";

    std::cout << "int: " << nbr << "\n";
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(nbr) << "f\n";
    std::cout << "double: " << static_cast<double>(nbr) << "\n";
}

// Display conversions for float literals
static void displayFloat(float nbr)
{
    if (std::isnan(nbr) || std::isinf(nbr)) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << (std::isnan(nbr) ? "nanf" : (nbr > 0 ? "+inff" : "-inff")) << "\n";
        std::cout << "double: " << (std::isnan(nbr) ? "nan" : (nbr > 0 ? "+inf" : "-inf")) << "\n";
    } else {
        if (nbr < 0 || nbr > 127 || std::floor(nbr) != nbr)
            std::cout << "char: impossible\n";
        else if (std::isprint(static_cast<int>(nbr)))
            std::cout << "char: '" << static_cast<char>(nbr) << "'\n";
        else
            std::cout << "char: Non displayable\n";

        if (nbr > static_cast<float>(std::numeric_limits<int>::max()) || 
            nbr < static_cast<float>(std::numeric_limits<int>::min()) || 
            std::floor(nbr) != nbr)
            std::cout << "int: impossible\n";
        else
            std::cout << "int: " << static_cast<int>(nbr) << "\n";

        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << nbr << "f\n";
        std::cout << "double: " << static_cast<double>(nbr) << "\n";
    }
}

// Display conversions for double literals
static void displayDouble(double nbr)
{
    if (std::isnan(nbr) || std::isinf(nbr)) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << (std::isnan(nbr) ? "nanf" : (nbr > 0 ? "+inff" : "-inff")) << "\n";
        std::cout << "double: " << (std::isnan(nbr) ? "nan" : (nbr > 0 ? "+inf" : "-inf")) << "\n";
    } else {
        if (nbr < 0 || nbr > 127 || std::floor(nbr) != nbr)
            std::cout << "char: impossible\n";
        else if (std::isprint(static_cast<int>(nbr)))
            std::cout << "char: '" << static_cast<char>(nbr) << "'\n";
        else
            std::cout << "char: Non displayable\n";

        if (nbr > static_cast<double>(std::numeric_limits<int>::max()) || 
            nbr < static_cast<double>(std::numeric_limits<int>::min()) || 
            std::floor(nbr) != nbr)
            std::cout << "int: impossible\n";
        else
            std::cout << "int: " << static_cast<int>(nbr) << "\n";

        std::cout << std::fixed << std::setprecision(1);
        if (nbr != 0 && (std::abs(nbr) < 1e-5 || std::abs(nbr) >= 1e6))
            std::cout << "float: " << std::scientific << std::setprecision(1) << static_cast<float>(nbr) << "f\n";
        else
            std::cout << "float: " << static_cast<float>(nbr) << "f\n";
        
        if (nbr != 0 && (std::abs(nbr) < 1e-5 || std::abs(nbr) >= 1e6))
            std::cout << "double: " << std::scientific << std::setprecision(1) << nbr << "\n";
        else
            std::cout << "double: " << nbr << "\n";
    }
}

// Convert the literal based on its type
void ScalarConverter::convert(const std::string& literal)
{
    std::string trimmed_literal = trim(literal);
    LiteralType type = getLiteralType(trimmed_literal);

    try {
        switch (type) {
            case CharType:
                displayChar(trimmed_literal[0]);
                break;
            case IntType:
                displayInt(stringToInt(trimmed_literal));
                break;
            case FloatType:
                if (trimmed_literal == "-inff" || trimmed_literal == "+inff" || trimmed_literal == "nanf" || trimmed_literal == "inff")
                    displayFloat(trimmed_literal == "nanf" ? std::numeric_limits<float>::quiet_NaN() :
                                 trimmed_literal == "+inff" || trimmed_literal == "inff" ? std::numeric_limits<float>::infinity() :
                                 -std::numeric_limits<float>::infinity());
                else
                    displayFloat(stringToFloat(trimmed_literal));
                break;
            case DoubleType:
                if (trimmed_literal == "-inf" || trimmed_literal == "+inf" || trimmed_literal == "nan")
                    displayDouble(trimmed_literal == "nan" ? std::numeric_limits<double>::quiet_NaN() :
                                  trimmed_literal == "+inf" ? std::numeric_limits<double>::infinity() :
                                  -std::numeric_limits<double>::infinity());
                else
                    displayDouble(stringToDouble(trimmed_literal));
                break;
            default:
                std::cout << "Invalid input.\n";
                break;
        }
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
