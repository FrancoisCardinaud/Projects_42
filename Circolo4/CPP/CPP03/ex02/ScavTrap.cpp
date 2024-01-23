/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:55:49 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 18:57:47 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

using std::cout;
using std::endl;

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	cout << "Sub Class (ScavTrap) constructor has been called" << endl;
}

ScavTrap::~ScavTrap(void) {
	cout << "Sub Class (ScavTrap) destructor has been called" << endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_energy_points == 0) {
		cout << "ScavTrap is out of energy points!" << endl;
		return;
	}
	cout << "ScavTrap " << this->name
	     << " attacks " << target 
		 << " causing <amount> " 
		 << "points of damage!" << endl;
	this->_energy_points -= 1;
}

void ScavTrap::guardGate(void) {
	cout << "ScavTrap " << this->name << " is now in gate keeper mode" << endl;
}
