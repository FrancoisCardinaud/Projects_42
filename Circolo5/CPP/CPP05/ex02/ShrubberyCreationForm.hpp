/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:25:21 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 19:25:22 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& to_copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &original);
		~ShrubberyCreationForm(void);

		void executeSuperClassForm(Bureaucrat const& executor) const;

	private:
		ShrubberyCreationForm(void);
};

#endif // SHRUBBERYCREATIONFORM_HPP