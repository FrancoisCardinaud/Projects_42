/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:40:36 by fcardina          #+#    #+#             */
/*   Updated: 2023/12/11 04:39:51 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//C++ Module 02 - ex00

Fixed::Fixed() : _RawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed	&Fixed::operator=(const Fixed &f2)
{
	std::cout << "Assignation operator called" << std::endl;
	this->setRawBits(f2.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (_RawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->_RawBits = raw;
}

//C++ Module 02 - ex01

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	this->_RawBits = (integer << Fixed::_bits);
}

Fixed::Fixed(const float floating_point)
{
	std::cout << "Float constructor called" << std::endl;
	this->_RawBits = std::roundf(floating_point * (1 << Fixed::_bits));
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_RawBits / (float)(1 << Fixed::_bits));
}

int		Fixed::toInt(void) const
{
	return (this->_RawBits >> Fixed::_bits);
}

std::ostream	&operator<<(std::ostream &stream, Fixed const &f)
{
	stream << f.toFloat();
	return (stream);
}