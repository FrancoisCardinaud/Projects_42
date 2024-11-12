/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:31:10 by fcardina          #+#    #+#             */
/*   Updated: 2024/11/12 17:45:01 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <exception>

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe &operator=(const PmergeMe& other);
        ~PmergeMe();

        void sortVec(int argc, char **argv);
        void sortList(int argc, char **argv);

        class InvalidElementException : public std::exception {
            public:
                virtual const char* what() const throw();  
        };
};

#endif
