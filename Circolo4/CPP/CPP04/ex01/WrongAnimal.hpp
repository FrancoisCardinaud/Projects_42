/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:13:19 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 19:13:20 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal {
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &to_copy);
		WrongAnimal &operator=(const WrongAnimal &to_copy);
		~WrongAnimal(void);

		std::string getType(void) const;
		void setType(std::string type);

		void makeSound(void) const;

	protected:
		std::string type;
};

#endif // WRONGANIMAL_HPP