/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:11:46 by fcardina          #+#    #+#             */
/*   Updated: 2024/02/02 18:43:05 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal //Derived class
{
	private:
		Brain* brain;
		
	public:
		Cat(void);
		Cat(const Cat &original);
		Cat &operator=(const Cat &to_copy);
		~Cat(void);

		void makeSound(void) const; //Polymorphic behavior
		Brain* getBrain(void) const;
};

#endif
