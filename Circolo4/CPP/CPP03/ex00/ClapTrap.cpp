/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:53:07 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 18:53:09 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

using std::cout;
using std::endl;

ClapTrap::ClapTrap(std::string name)
: name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
	cout << "Default constructor " << name << " has been called!" << endl;
}

ClapTrap::ClapTrap(const ClapTrap &to_copy)
{
	this->name = to_copy.name;
	this->_hit_points = to_copy._hit_points;
	this->_energy_points = to_copy._energy_points;
	this->_attack_damage = to_copy._attack_damage;
	cout << "Copy constructor has been called!" << endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &original)
{
	if (this != &original)
	{
		this->name = original.name;
		this->_hit_points = original._hit_points;
		this->_energy_points = original._energy_points;
		this->_attack_damage = original._attack_damage;
	}
	cout << "Copy assignment constructor has been called!" << endl;
	return *this;
}

ClapTrap::~ClapTrap(void) {
	cout << "Destructor has been called" << endl;
};

void ClapTrap::attack(const std::string& target)
{
	if (this->_energy_points == 0)
	{
		cout << "ClapTrap is out of Energy Points!" << endl;
		return;
	}
	cout << "ClapTrap " << this->name  << " attacks " << target << " causing " << this->_attack_damage << " points of damage!" << endl;
	this->_energy_points -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->_hit_points || this->_hit_points == 0)
	{
		cout << "ClapTrap " << this->name << " died" << endl;
		this->_hit_points = 0;
		return;
	}
	this->_hit_points -= amount;
	cout << "ClapTrap " << this->name
		 << " took " << amount << " points of damage" << endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points == 0)
	{
		cout << "ClapTrap is out of Energy Points!" << endl;
		return ;
	}
	this->_hit_points += amount;
	this->_energy_points -= 1;
	cout << "ClapTrap " << this->name
		 << " has been healed and gained "
		 << amount << " hit points" << endl;
}