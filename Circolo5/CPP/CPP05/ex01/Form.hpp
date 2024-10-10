/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:16:49 by fcardina          #+#    #+#             */
/*   Updated: 2024/10/10 15:16:50 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <string>
# include <iostream>

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat;

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

std::ostream &operator<<(std::ostream &stream, const Form &form);

#endif // FORM_HPP
