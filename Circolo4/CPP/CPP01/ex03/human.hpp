/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:49:42 by fcardina          #+#    #+#             */
/*   Updated: 2023/12/03 12:53:52 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <iostream>

class HumanA
{
	private:
		std::string	_name;
		Weapon		_weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		void		attack(void);
};

class HumanB
{
	private:
		std::string	_name;
		Weapon		*_weapon;
	public:
		HumanB(std::string name);
		~HumanB(void);
		void		attack(void);
		void		setWeapon(Weapon &weapon);
};

class Weapon
{
	private:
		std::string	_type;

	public:
		Weapon(std::string weaponType);
		~Weapon();

		std::string const &getType();
		void		setType(std::string weaponType);
};

#endif