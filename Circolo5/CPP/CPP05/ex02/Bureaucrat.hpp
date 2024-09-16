/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:47:36 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/16 20:51:04 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat& to_copy);
    Bureaucrat(std::string name, int grade);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    const std::string& getName() const;
    int getGrade() const;

    void setGrade(int new_grade);
    void incrementGrade();
    void decrementGrade();

    void signForm(const std::string& form_name, bool is_signed) const;
    void executeForm(const AForm& form) const;

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

private:
    const std::string name;
    int grade;
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bureaucrat);

#endif // BUREAUCRAT_HPP
