/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:31:00 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 19:31:01 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <exception>

class RPN {
    public:
        RPN(void);
        RPN(const RPN &to_copy);
        RPN &operator=(const RPN &to_copy);
        ~RPN(void);

        static bool valid_expression(const std::string& expr);
        static long long calculate(const std::string& expr);

        class NoResultException : public std::exception {
            public:
                virtual const char* what() const throw();  
        };

        class DivisionByZeroException : public std::exception {
            public:
                virtual const char* what() const throw();  
        };
};

#endif // RPN_HPP