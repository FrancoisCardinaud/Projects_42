/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:27:03 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/18 16:30:59 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base *generate(void) {
    srand(time(NULL));
    char c = "ABC"[rand() % 3];

    std::cout << "Type " << c << " created!" << std::endl;

    switch (c) {
        case 'A':
            return new A;
        case 'B':
            return new B;
        case 'C':
            return new C;
    }

    return nullptr;  // If none matched, though unreachable due to the rand constraint
}

void identify(Base *p) {
    std::cout << "Identify with Base *: ";

    if (dynamic_cast<A *>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B *>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C *>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Invalid type" << std::endl;
    }
}

void identify(Base &p) {
    std::cout << "Identify with Base &: ";

    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    } catch (const std::exception&) {
        try {
            (void)dynamic_cast<B &>(p);
            std::cout << "B" << std::endl;
        } catch (const std::exception&) {
            try {
                (void)dynamic_cast<C &>(p);
                std::cout << "C" << std::endl;
            } catch (const std::exception&) {
                std::cout << "Invalid type" << std::endl;
            }
        }
    }
}
