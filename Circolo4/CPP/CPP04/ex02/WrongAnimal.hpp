/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:12:40 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 17:57:58 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{	
	protected:
		std::string type;
		
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &original);
		WrongAnimal &operator=(const WrongAnimal &other);
		virtual ~WrongAnimal(void);

		std::string getType(void) const;
		void setType(std::string type);

		void makeSound(void) const;
};

#endif
