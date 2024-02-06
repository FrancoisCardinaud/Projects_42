/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:11:54 by fcardina          #+#    #+#             */
/*   Updated: 2024/02/02 20:20:07 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->setType("Dog");
	this->brain = new Brain();
    brain->setIdea(0, "Original Dog Idea");
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
    std::cout << "DOG assignment operator has been called " << std::endl;
    return *this;
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "DOG default destructor has been called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "\"Woof woof!\"" << std::endl;
}

Brain* Dog::getBrain(void) const
{
    return (this->brain);
}
