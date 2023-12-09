/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:49:42 by fcardina          #+#    #+#             */
/*   Updated: 2023/12/09 17:02:13 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"
# include <iostream>

class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		void		attack(void);
		
	private:
		std::string	_name;
		Weapon		_weapon;
};

#endif