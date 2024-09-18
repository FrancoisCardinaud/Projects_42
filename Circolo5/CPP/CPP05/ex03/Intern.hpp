/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:25:38 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/18 15:35:08 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern {
    public:
        // Constructors and Destructor
        Intern(void);
        Intern(const Intern &other);
        ~Intern(void);

        // Operator Overload
        Intern& operator=(const Intern &assign);

        // Member Function to Create Forms
        AForm *makeForm(const std::string &name, const std::string &target);
};

#endif // INTERN_HPP
