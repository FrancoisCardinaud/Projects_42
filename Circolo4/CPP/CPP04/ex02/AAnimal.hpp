/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:14:54 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 17:57:58 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>
# include "Brain.hpp"

class AAnimal
{
	protected:
		std::string type;
		
	public:
		AAnimal(void);
		AAnimal(const AAnimal &other);
		AAnimal &operator=(const AAnimal &other);
		virtual ~AAnimal(void);

		std::string getType(void) const;
		void setType(std::string type);

		virtual void makeSound(void) const = 0;
		//Pure virtual function: Any class deriving from AAnimal 
		// must provide its own implementation of makeSound()
};

#endif