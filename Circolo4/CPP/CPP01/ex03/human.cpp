/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:48:28 by fcardina          #+#    #+#             */
/*   Updated: 2023/12/03 12:53:00 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "human.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	return ;
}

HumanA::~HumanA()
{
	return ;
}

void	HumanA::attack(void)
{
	std::cout	<< this->_name
				<< " attacks with his "
				<< this->_weapon.getType()
				<< std::endl ;
}


HumanB::HumanB(std::string name) : _name(name)
{
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

void	HumanB::attack(void)
{
	std::cout	<< this->_name
				<< " attacks with his "
				<< (*this->_weapon).getType()
				<< std::endl ;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

Weapon::Weapon(std::string weaponType)
{
	this->setType(weaponType);
	return ;
}

Weapon::~Weapon()
{
	return ;
}

std::string const &Weapon::getType()
{
	return (this->_type);
}

void		Weapon::setType(std::string weaponType)
{
	this->_type = weaponType;
}