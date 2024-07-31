/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:53:07 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 17:57:58 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"




ClapTrap::ClapTrap(std::string name) : name(name), _hit_points(10), _energy_points(10), _attack_damage(0) 
{
	std::cout << "Default constructor " << name << " was called!" << std::endl;
}//Default constructor

ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->name = other.name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
	std::cout << "Copy constructor was called!" << std::endl;
}//Copy constructor

ClapTrap& ClapTrap::operator=(const ClapTrap &original)
{
	if (this != &original)
	{
		this->name = original.name;
		this->_hit_points = original._hit_points;
		this->_energy_points = original._energy_points;
		this->_attack_damage = original._attack_damage;
	}
	std::cout << "assignment operator was called!" << std::endl;
	return *this;
}//Copy assignment operator

ClapTrap::~ClapTrap(void) 
{
	std::cout << "Destructor was called for " << name << std::endl;
};//Destructor

void	ClapTrap::attack(const std::string &target, const int points)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << points << " points of damage!" << std::endl;
		this->_energy_points--;
	}
	else if (this->_energy_points == 0)
		std::cout << "ClapTrap " << this->name << " cannot attack " << target << ", because he has no energy points left." << std::endl;
	else if (this->_hit_points == 0)
		std::cout << "ClapTrap " << this->name << " cannot attack " << target << ", because he does not have enough hit points." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int points)
{
	if (this->_hit_points > points)
	{
		this->_hit_points -= points;
		std::cout << "ClapTrap " << this->name << " was attacked, he now has " << this->_hit_points << " hit points." << std::endl;
	}
	else if (this->_hit_points <= points)
	{
		this->_hit_points = 0;
		std::cout << "ClapTrap " << this->name << " was attacked, he now has " << this->_hit_points << " hit points." << std::endl;
		std::cout << "ClapTrap " << this->name << " has died :(" << std::endl;
	}
}
void	ClapTrap::beRepaired(unsigned int points)
{
	if (this->_energy_points > 0 && this->_hit_points > 0 && this->_hit_points + points <= 10)
	{
		this->_hit_points += points;
		std::cout << "ClapTrap " << this->name << " repaired himself and gained " << points << " of hit points, he now has " << this->_hit_points << " hit points." << std::endl;
		this->_energy_points--;
	}
	else if (this->_energy_points == 0)
		std::cout << "ClapTrap " << this->name << " cannot repair himself, because he does not have enough energy points." << std::endl;
	else if (this->_hit_points == 0)
		std::cout << "ClapTrap " << this->name << " cannot repair himself, because he does not have enough hit points." << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " cannot be repaired to have more than 10 hit points." << std::endl;
}
