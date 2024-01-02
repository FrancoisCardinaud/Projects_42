/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:13:24 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 19:13:25 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat(void);
		WrongCat(const WrongCat &to_copy);
		WrongCat &operator=(const WrongCat &to_copy);
		~WrongCat(void);

		void makeSound(void) const;
};

#endif // WRONGCAT_HPP