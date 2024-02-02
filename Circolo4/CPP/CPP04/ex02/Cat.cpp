/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:11:41 by fcardina          #+#    #+#             */
/*   Updated: 2024/02/02 18:43:03 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->setType("Cat");
	this->brain = new Brain();
	std::cout << "CAT default constructor has been called" << std::endl;
}

Cat::Cat(const Cat &to_copy) : Animal(to_copy)
{
    this->brain = new Brain();
	*this = to_copy;
    std::cout << "CAT copy constructor has been called " << std::endl;
}

Cat& Cat::operator=(const Cat &to_copy)
{
	this->type = to_copy.type;
	*(this->brain) = *(to_copy.brain);
    std::cout << "CAT copy assignment constructor has been called " << std::endl;
    return *this;
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "CAT default destructor has been called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "\"Meow...\"" << std::endl;
}

Brain* Cat::getBrain(void) const
{
    return (this->brain);
}
