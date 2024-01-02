/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:15:11 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 19:15:12 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"

class Dog : public AAnimal {
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