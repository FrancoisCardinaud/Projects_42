/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:11:46 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 17:57:58 by fcardina         ###   ########.fr       */
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
		std::string type;
		
	public:
		Cat(void);
		Cat(const Cat &original);
		Cat &operator=(const Cat &other);
		~Cat(void);

		void makeSound(void) const; //Polymorphic behavior
		void getIdea(void)const;
		Brain* getBrain(void) const;
};

#endif
