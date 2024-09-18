/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:30:51 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/18 19:12:35 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "RPN.hpp"

using std::cerr;
using std::cout;

# define ERROR_MSG_PREFFIX "RPN: error: "
# define ARGC_ERR "invalid number of arguments"
# define INVALID_EXPR_ERR "invalid expression"

// Function to print error and return EXIT_FAILURE
static int panic(const std::string& error_msg)
{
    cerr << ERROR_MSG_PREFFIX << error_msg << '\n';
    return EXIT_FAILURE; // Changed from EXIT_FAIL to EXIT_FAILURE
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return panic(ARGC_ERR);

    if (!RPN::valid_expression(argv[1]))
        return panic(INVALID_EXPR_ERR);

    try {
        cout << RPN::calculate(argv[1]) << std::endl;
    }
    catch (std::exception& e) {
        cerr << e.what() << "\n";
    }
    
    return EXIT_SUCCESS;
}
