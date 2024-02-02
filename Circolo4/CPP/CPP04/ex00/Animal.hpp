/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:11:39 by fcardina          #+#    #+#             */
/*   Updated: 2024/02/02 16:01:30 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal  //Base class
{
	protected:
		std::string type;
		
	public:
		Animal(void);
		Animal(const Animal &to_copy);
		Animal &operator=(const Animal &to_copy);
		virtual ~Animal(void); //Polymorphism

		std::string getType(void) const;
		void setType(std::string type);

		virtual void makeSound(void) const;
};

#endif
