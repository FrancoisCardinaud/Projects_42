/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:47:32 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/16 20:52:42 by fcardina         ###   ########.fr       */
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
        AForm(const AForm& to_copy);
        AForm& operator=(const AForm& original);
        virtual ~AForm();

        const std::string& getName() const;
        const std::string& getTarget() const;
        bool getSignState() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat& bureaucrat);
        void execute(const Bureaucrat& executor) const;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

    private:
        const std::string name;
        const std::string target;
        bool is_signed;
        const int grade_to_sign;
        const int grade_to_execute;

        AForm();  // Private default constructor to prevent uninitialized forms
        virtual void executeSuperClassForm(const Bureaucrat& executor) const = 0;
};

std::ostream& operator<<(std::ostream& stream, const AForm& form);

#endif // AFORM_HPP
