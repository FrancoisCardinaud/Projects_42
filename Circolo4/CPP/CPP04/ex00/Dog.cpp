/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:11:54 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 17:57:58 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog(void) : Animal() //inheritance
{
	std::cout << "DOG default constructor has been called" << std::endl;
	this->setType("Dog");
}

Dog::Dog(const Dog &other) : Animal(other)
{
	*this = other;
	std::cout << "DOG copy constructor has been called " << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
    this->type = other.type;
	std::cout << "DOG assignment operator has been called " << std::endl;
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
