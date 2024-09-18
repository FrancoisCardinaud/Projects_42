/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:26:57 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/18 16:30:06 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Base.hpp"

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main() {
    Base *instance = generate();

    std::cout << std::endl;
    identify(instance);
    identify(*instance);

    delete instance;
    return EXIT_SUCCESS;
}
