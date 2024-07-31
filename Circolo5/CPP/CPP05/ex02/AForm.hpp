/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:24:54 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 17:57:58 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <exception>
# include <string>
# include "Bureaucrat.hpp"

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat;

class AForm {
	public:
		AForm(std::string name, std::string target, int grade_to_sign, int grade_to_execute);
		AForm(AForm& other);
		AForm &operator=(AForm& original);
		virtual ~AForm(void);

		const std::string& getName(void) const;
		const std::string& getTarget(void) const;
		bool getSignState(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;

		void beSigned(Bureaucrat &bureaucrat);
		void execute(Bureaucrat const& executor) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string name;
		const std::string target;
		bool is_signed;
		const int grade_to_sign;
		const int grade_to_execute;
		AForm(void);
		virtual void executeSuperClassForm(Bureaucrat const& executor) const = 0;
};

std::ostream &operator<<(std::ostream &stream, AForm &forM);

#endif // AFORM_HPP