/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:30:55 by fcardina          #+#    #+#             */
/*   Updated: 2024/11/12 17:31:33 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using std::cerr;

// Utility to convert string to integer
static int ft_stoi(const std::string& str)
{
    int num;
    std::stringstream ss(str);
    ss >> num;
    return num;
}

// Constructor, Copy Constructor, Destructor
RPN::RPN(void) {};
RPN::RPN(const RPN &other) { *this = other; }
RPN& RPN::operator=(const RPN &other) { (void)other; return *this; }
RPN::~RPN(void) {}

// Validate expression: only allow digits, operators, and spaces
bool RPN::valid_expression(const std::string& expr)
{
    return expr.find_first_not_of("0123456789+-/* ") == std::string::npos;
}

// Calculate the result of an RPN expression
long long RPN::calculate(const std::string& expr)
{
    std::stringstream postfix(expr);
    //Stack container
    std::stack<int> temp;
    std::string s;

    while (postfix >> s)
    {
        if (s == "+" || s == "-" || s == "/" || s == "*")
        {
            if (temp.size() < 2)
                throw NoResultException();

            // Operands
            int right = temp.top(); temp.pop();
            int left = temp.top(); temp.pop();

            // Perform operation
            if (s == "+") temp.push(left + right);
            if (s == "-") temp.push(left - right);
            if (s == "*") temp.push(left * right);
            if (s == "/")
            {
                if (right == 0) throw DivisionByZeroException();
                temp.push(left / right);
            }
        }
        else
            temp.push(ft_stoi(s)); // Add numbers to stack
    }

    // Return the final result
    return temp.top();
}

// Exception messages
const char* RPN::NoResultException::what() const throw() {
    return "RPN exception: No result. Wrongly formatted expression";
}

const char* RPN::DivisionByZeroException::what() const throw() {
    return "RPN exception: division by zero";
}
