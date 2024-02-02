/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:11:54 by fcardina          #+#    #+#             */
/*   Updated: 2024/02/02 16:06:43 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "DOG default constructor has been called" << std::endl;
	this->setType("Dog");
}

Dog::Dog(const Dog &to_copy) : Animal(to_copy)
{
	*this = to_copy;
	std::cout << "DOG copy constructor has been called " << std::endl;
}

Dog& Dog::operator=(const Dog &to_copy)
{
    if (this != &to_copy) // Check for self-assignment
    {
        *this = to_copy;
        std::cout << "DOG copy assignment constructor has been called " << std::endl;
    }
    return *this;
}

Dog::~Dog(void)
{
	std::cout << "DOG default destructor has been called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "\"Arf!\"" << std::endl;
}
