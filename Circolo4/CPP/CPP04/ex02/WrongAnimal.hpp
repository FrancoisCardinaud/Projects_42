/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:15:21 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 19:15:21 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
using std::string;

class WrongAnimal {
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &to_copy);
		WrongAnimal &operator=(const WrongAnimal &to_copy);
		~WrongAnimal(void);

		string getType(void) const;
		void setType(string type);

		void makeSound(void) const;

	protected:
		string type;
};

#endif // WRONGANIMAL_HPP