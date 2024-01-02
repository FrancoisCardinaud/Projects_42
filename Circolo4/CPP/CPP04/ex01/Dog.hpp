/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:13:08 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 19:13:09 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog(void);
		Dog(const Dog &to_copy);
		Dog &operator=(const Dog &to_copy);
		~Dog(void);

		void makeSound(void) const;

	private:
		Brain* brain;
};

#endif // DOG_HPP