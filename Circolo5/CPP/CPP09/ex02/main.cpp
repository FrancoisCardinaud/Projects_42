/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:31:04 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 16:29:46 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "PmergeMe.hpp"


using std::cerr;


unsigned int ft_stou(const std::string& str)
{
	unsigned int num;
	std::stringstream ss(str);

	ss >> num;
	return num;
}

int main(int argc, char **argv)
{
	if (argc == 1)
	    return EXIT_SUCCESS;
    PmergeMe pmm;

    try {
        for (int i = 1; i < argc; i += 1)
            if (std::string(argv[i]).find_first_not_of("0123456789 ") != std::string::npos)
			    throw PmergeMe::InvalidElementException();

        std::vector<unsigned int>temp;
        for (int i = 1; i < argc; i += 1)
            temp.push_back(ft_stou(argv[i]));

        std::vector<unsigned int>::iterator itr;
        std::vector<unsigned int>::iterator itr2;
        for (itr = temp.begin(); itr != temp.end(); itr++)
        {
            for (itr2 = itr + 1; itr2 != temp.end(); itr2++)
                if (*itr2 == *itr)
			        throw PmergeMe::InvalidElementException();
        }
    }
    catch (std::exception& e) {
        cerr << e.what() << '\n';
        return EXIT_FAIL;
    }

    pmm.sortVec(argc, argv);
    cout << std::endl;
    pmm.sortList(argc, argv);

	return EXIT_SUCCESS;
}
