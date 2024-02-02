/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 01:20:26 by fcardina          #+#    #+#             */
/*   Updated: 2024/02/02 15:20:06 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal //Derived class
{
	public:
		Dog(void);
		Dog(const Dog &original);
		Dog &operator=(const Dog &to_copy);
		~Dog(void);

		void makeSound(void) const; //Polymorphic behavior
};

#endif
