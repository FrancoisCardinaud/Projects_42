/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:53:07 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/25 00:31:53 by fcardina         ###   ########.fr       */
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
	cout << "Destructor was called for " << name << endl;
};

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_points--;
	}
	else if (this->_energy_points == 0)
		std::cout << "\033[31mClapTrap " << this->name << " is not able to attack " << target << ", because he has no energy points left.\033[0m" << std::endl;
	else
		std::cout << "\033[31mClapTrap " << this->name << " is not able to attack " << target << ", because he has not enough hit points.\033[0m" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points > amount)
	{
		this->_hit_points -= amount;
	}
	else if (this->_hit_points <= amount)
	{
		cout << "ClapTrap " << this->name << " has died..." << endl;
		this->_hit_points = 0;
	}
	std::cout << "ClapTrap " << this->name << " was attacked and lost " << amount << " hit points, he now has " << this->_hit_points << " hit points." << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points > 0 && this->_hit_points > 0 && this->_hit_points + amount <= 10)
	{
		this->_hit_points += amount;
		std::cout << "ClapTrap " << this->name << " repaired himself and gained " << amount << " of hit points, he now has " << this->_hit_points << " hit points." << std::endl;
		this->_energy_points--;
	}
	else if (this->_energy_points == 0)
		std::cout << "ClapTrap " << this->name << " is not able to repair himself, because he doesn't have enough energy points." << std::endl;
	else if (this->_hit_points == 0)
		std::cout << "ClapTrap " << this->name << " is not able to repair himself, because he doesn't have enough hit points." << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " can't be repaired to have more than 10 hit points." << std::endl;
}