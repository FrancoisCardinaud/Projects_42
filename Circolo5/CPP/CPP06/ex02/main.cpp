/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:26:57 by fcardina          #+#    #+#             */
/*   Updated: 2024/10/17 18:27:43 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Base.hpp"

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main() {
    srand(static_cast<unsigned int>(time(NULL)));  // Initialize random seed once

    std::cout << "TEST: Single Identification" << std::endl;
    Base *instance = generate();

    std::cout << std::endl;
    identify(instance);
    identify(*instance);

    delete instance;

    std::cout << "------------------------------" << std::endl;
    std::cout << "TEST: Identification of nullptr" << std::endl;
    Base *nullInstance = NULL;
    identify(nullInstance);
    
    try {
        identify(*nullInstance);  // This should throw an exception
    } catch (const std::exception &e) {
        std::cout << "Exception caught: nullptr reference" << std::endl;
    }

    std::cout << "------------------------------" << std::endl;
    std::cout << "TEST: Multiple Identifications" << std::endl;
    for (int i = 0; i < 5; ++i) {
        Base *multiInstance = generate();
        identify(multiInstance);
        identify(*multiInstance);
        delete multiInstance;
        std::cout << "------------------------------" << std::endl;
    }

    return EXIT_SUCCESS;
}