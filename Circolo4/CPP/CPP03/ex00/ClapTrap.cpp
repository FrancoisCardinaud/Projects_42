/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:53:07 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/25 00:32:14 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

using std::cout;
using std::endl;

ClapTrap::ClapTrap(std::string name) : name(name), _hit_points(10), _energy_points(10), _attack_damage(0) 
{
	cout << "Default constructor " << name << " was called!" << endl;
}//Default constructor

ClapTrap::ClapTrap(const ClapTrap &to_copy)
{
	this->name = to_copy.name;
	this->_hit_points = to_copy._hit_points;
	this->_energy_points = to_copy._energy_points;
	this->_attack_damage = to_copy._attack_damage;
	cout << "Copy constructor was called!" << endl;
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
	cout << "Copy assignment constructor was called!" << endl;
	return *this;
}//Copy assignment operator

ClapTrap::~ClapTrap(void) 
{
	cout << "Destructor was called for " << name << endl;
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
		cout << "ClapTrap " << this->name << " has died :(" << endl;
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
