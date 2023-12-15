/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:38:00 by fcardina          #+#    #+#             */
/*   Updated: 2023/12/09 16:46:00 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie 
{
	public:

	Zombie();
	~Zombie();
	void	announce(void);
	void	setname(std::string name);

	private:

	std::string name;
};

Zombie* zombieHorde(int N, std::string name);

# endif