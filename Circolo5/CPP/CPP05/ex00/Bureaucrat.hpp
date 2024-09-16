/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:24:25 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/16 19:01:11 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat
{
  public:
	Bureaucrat(void);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat(std::string name, int grade);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat(void);

	const std::string &getName(void) const;
	int getGrade(void) const;
	void incrementGrade(void);
	void decrementGrade(void);

	class GradeTooHighException : public std::exception
	{
		public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const throw();
	};

  private:
	const std::string _name;
	int _grade;

	void validateGrade(int grade) const;
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &bureaucrat);

#endif // BUREAUCRAT_HPP
