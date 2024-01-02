/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:12:51 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 19:12:52 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include "Brain.hpp"


class Animal {
	public:
		Animal(void);
		Animal(const Animal &to_copy);
		Animal &operator=(const Animal &to_copy);
		virtual ~Animal(void);

		std::string getType(void) const;
		void setType(std::string type);

		virtual void makeSound(void) const;

	protected:
		std::string type;
};

#endif // ANIMAL_HPP