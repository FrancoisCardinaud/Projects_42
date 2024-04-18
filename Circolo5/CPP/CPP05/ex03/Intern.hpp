/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:25:38 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 19:25:39 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern {
	public:
		Intern(void);
		Intern(const Intern &to_copy);
		~Intern(void);

		Intern& operator=(const Intern &assign);

		AForm *makeForm(std::string name, std::string target);		
};

#endif // INTERN_HPP