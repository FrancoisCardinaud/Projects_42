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

Dog::Dog(void) : AAnimal()
{
	this->setType("Dog");
	this->brain = new Brain();
	std::cout << "DOG default constructor has been called" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
    this->brain = new Brain();
	*this = other;
    std::cout << "DOG copy constructor has been called " << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
	this->type = other.type;
	*(this->brain) = *(other.brain);
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
	std::cout << "\"Arf!\"" << std::endl;
}

void	Dog::getIdea(void)const
{
	for (int i = 0; i < 5; i++)
		std::cout << "\t""Dog's idea " << i << " is: \"" << this->brain->getIdea(i) << "\" at the address " << this->brain->getIdeaAddress(i) << std::endl;
}

Brain* Dog::getBrain(void) const
{
    return (this->brain);
}
