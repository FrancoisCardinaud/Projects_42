/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:47:34 by fcardina          #+#    #+#             */
/*   Updated: 2023/12/09 17:03:01 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	public:
		Weapon(const std::string &weapon);
		~Weapon();
		std::string getType() const;
		void setType(const std::string &weapon);

    private:
		std::string	_type;

};

#endif