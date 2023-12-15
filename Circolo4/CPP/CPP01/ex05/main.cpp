/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:55:21 by fcardina          #+#    #+#             */
/*   Updated: 2023/12/03 12:56:42 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;

    harl.complain("INFO");
    std::cout << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;
    std::cout << "Now you have 5 opportunities to make Harl say something (INFO, DEBUG, WARNING, ERROR) for testing:" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::string input;
		getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			std::cerr << "^D" << std::endl;
			exit(1);
		}
		harl.complain(input);
		std::cout << std::endl;
	}

    return 0;
}