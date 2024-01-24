/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:53:25 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/25 00:26:56 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {

	protected:
		std::string name;
		unsigned int _hit_points;
		unsigned int _energy_points;
		unsigned int _attack_damage;

	public:
		ClapTrap(std::string name); //Default constructor
		ClapTrap(const ClapTrap &to_copy); //Copy constructor
		ClapTrap& operator=(const ClapTrap &original); //Copy assignment operator
		~ClapTrap(void); //Destructor

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);


};

#endif
