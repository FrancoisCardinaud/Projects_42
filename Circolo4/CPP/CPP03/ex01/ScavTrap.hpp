/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:55:40 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/25 00:27:01 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{
	private:
		ScavTrap(void);

	public:
		ScavTrap(std::string name);
		~ScavTrap(void);

		void attack(const std::string& target, const int points);
		void guardGate(void);
};

#endif