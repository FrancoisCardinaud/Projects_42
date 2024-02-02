/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:11:54 by fcardina          #+#    #+#             */
/*   Updated: 2024/02/02 18:43:06 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->setType("Dog");
    this->brain = new Brain();
    std::cout << "DOG default constructor has been called" << std::endl;
}

Dog::Dog(const Dog &to_copy) : Animal(to_copy)
{
    this->brain = new Brain();
    *this = to_copy;
    std::cout << "DOG copy constructor has been called " << std::endl;
}

Dog& Dog::operator=(const Dog &to_copy)
{
    this->type = to_copy.type;
    *(this->brain) = *(to_copy.brain);
    std::cout << "DOG copy assignment constructor has been called " << std::endl;
    return *this;
}

Dog::~Dog(void)
{
    delete brain;
	std::cout << "DOG default destructor has been called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "\"Arf!\"" << std::endl;
}

Brain* Dog::getBrain(void) const
{
    return brain;
}
