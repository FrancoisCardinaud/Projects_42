/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:26:43 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/18 16:25:24 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Serialization.hpp"

int main() {
    Data foo;
    uintptr_t reinterpreted;

    foo.dummy_str = "test";
    reinterpreted = Serialization::serialize(&foo);

    std::cout << "Original foo (Data) Address = " << &foo << std::endl;
    std::cout << "dummy_str value = " << foo.dummy_str << std::endl;

    std::cout << std::endl;

    std::cout << "Serialized foo value = " << reinterpreted << std::endl;

    std::cout << std::endl;

    Data *deserialized = Serialization::deserialize(reinterpreted);

    std::cout << "Deserialized Address = " << deserialized << std::endl;
    std::cout << "dummy_str value = " << deserialized->dummy_str << std::endl;

    return EXIT_SUCCESS;
}
