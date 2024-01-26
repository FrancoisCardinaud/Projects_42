/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:53:25 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/24 22:30:43 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap 
{
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

		void attack(const std::string& target, const int points);
		void takeDamage(unsigned int points);
		void beRepaired(unsigned int points);


};

#endif
