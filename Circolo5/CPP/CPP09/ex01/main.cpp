/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:30:51 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 16:29:46 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "RPN.hpp"


using std::cerr;


# define ERROR_MSG_PREFFIX "RPN: error: "
# define ARGC_ERR "invalid number of arguments"
# define INVALID_EXPR_ERR "invalid expression"

static int panic(const std::string& error_msg)
{
    cerr << ERROR_MSG_PREFFIX << error_msg << '\n';
    return EXIT_FAIL;
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
