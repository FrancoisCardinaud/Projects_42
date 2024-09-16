/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:24:43 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/16 21:03:24 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <string>
# include "Bureaucrat.hpp"

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Form {
    public:
        Form(void);
        Form(const Form &other);
        Form(std::string name, int grade_to_sign, int grade_to_execute);
        Form &operator=(const Form &other);
        ~Form(void);

        const std::string &getName(void) const;
        bool getSignState(void) const;
        int getGradeToSign(void) const;
        int getGradeToExecute(void) const;

        void beSigned(const Bureaucrat &bureaucrat);

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
        bool is_signed;
        const int grade_to_sign;
        const int grade_to_execute;
};

std::ostream &operator<<(std::ostream &stream, Form &form);

#endif // FORM_HPP
