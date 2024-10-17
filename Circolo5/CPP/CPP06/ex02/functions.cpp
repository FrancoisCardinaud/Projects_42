/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:27:03 by fcardina          #+#    #+#             */
/*   Updated: 2024/10/17 18:29:35 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base *generate(void) {
    static bool seeded = false;
    if (!seeded) {
        // Seed with current time, but ensure it's done only once
        srand(time(NULL));
        seeded = true;
    }

    char c = "ABC"[rand() % 3];  // Still using random selection from A, B, C

    std::cout << "Type " << c << " created!" << std::endl;

    switch (c) {
        case 'A':
            return new A;
        case 'B':
            return new B;
        case 'C':
            return new C;
        default:
            return NULL;  // Fallback, though unreachable
    }
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
