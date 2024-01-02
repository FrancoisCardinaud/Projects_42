/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:15:01 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 19:15:02 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain {
	public:
		Brain(void);
		Brain(const Brain &to_copy);
		Brain &operator=(const Brain &to_copy);
		~Brain(void);

	private:
		std::string ideas[100];
};

#endif // BRAIN_HPP