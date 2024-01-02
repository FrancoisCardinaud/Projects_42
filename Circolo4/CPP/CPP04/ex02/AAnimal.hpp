/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:14:54 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 19:14:55 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>
# include "Brain.hpp"

class AAnimal {
	public:
		AAnimal(void);
		AAnimal(const AAnimal &to_copy);
		AAnimal &operator=(const AAnimal &to_copy);
		virtual ~AAnimal(void);

		std::string getType(void) const;
		void setType(std::string type);

		virtual void makeSound(void) const = 0;

	protected:
		std::string type;
};

#endif // AANIMAL_HPP