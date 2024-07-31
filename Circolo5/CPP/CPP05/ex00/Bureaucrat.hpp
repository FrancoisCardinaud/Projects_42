/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:24:25 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 18:16:36 by fcardina         ###   ########.fr       */
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

	void setGrade(int grade);

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

	void validateGrade(int grade);
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat &Bureaucrat);

#endif // BUREAUCRAT_HPP